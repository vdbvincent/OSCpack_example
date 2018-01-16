#ifndef OSCPACKCLASS_H
#define OSCPACKCLASS_H

#include <QString>

#include "controlleurclass.h"
#include "osc/osc/OscOutboundPacketStream.h"
#include "osc/ip/UdpSocket.h"
#include "osc/ip/PacketListener.h"
#include "osc/osc/OscReceivedElements.h"
#include "osc/osc/OscPacketListener.h"

#include <QThread>
#include <QVector>
#include <QPair>
#include <algorithm>

#define OUTPUT_BUFFER_SIZE 128

/**
 *  \brief Classe singleton
 */
class oscPackClass : public QThread
{
private:
    static oscPackClass * m_inst;
    UdpTransmitSocket * transmitSocket;
    int port_emetteur;
    int port_recepteur;
    QVector<UdpTransmitSocket *> vudpTrans;

    oscPackClass(controlleurClass * p_ctl, QVector<int> vport, int portB);
    void run();

public:
    controlleurClass * ctl;

    ~oscPackClass(void);
    void init(void);
    void sendMsg(QString p_source, QString p_arg);
    static oscPackClass * getinst(controlleurClass * p_ctl = nullptr, QVector<int> vport = QVector<int>(), int portB = 1235);
    static void releaseinst(void);
};

class myoscUdpListener : public osc::OscPacketListener //PacketListener//osc::OscPacketListener
{
public:
    virtual void ProcessMessage( const osc::ReceivedMessage& m, const IpEndpointName& remoteEndpoint )
    {
        (void) remoteEndpoint; // suppress unused parameter warning

        try
        {
            QString source(m.AddressPattern());
            osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
            const char * svalue;
            args >> svalue >> osc::EndMessage;
            oscPackClass::getinst()->ctl->recv(source, strtol(svalue, nullptr, 10));
        }
        catch( osc::Exception& e )
        {
            // any parsing errors such as unexpected argument types, or
            // missing arguments get thrown as exceptions.
        }
    }
};
#endif // OSCPACKCLASS_H
