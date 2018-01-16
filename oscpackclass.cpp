#include "oscpackclass.h"

#define ADDRESS "127.0.0.1"

oscPackClass * oscPackClass::m_inst = nullptr;

oscPackClass::oscPackClass(controlleurClass *p_ctl, QVector<int> vport, int portB)
: QThread()
, port_recepteur(portB)
{
    ctl = p_ctl;
    for (QVector<int>::iterator it = vport.begin(); it != vport.end(); it++)
    {
        vudpTrans.push_back(new UdpTransmitSocket(IpEndpointName(ADDRESS, *it)));
    }
}

oscPackClass::~oscPackClass(void)
{
    delete transmitSocket;
    for (int i = 0; i < vudpTrans.size(); i++)
    {
        delete vudpTrans.at(i);
    }
}

oscPackClass * oscPackClass::getinst(controlleurClass * p_ctl, QVector<int> vport, int portB)
{
    if (m_inst == nullptr)
    {
        m_inst = new oscPackClass(p_ctl, vport, portB);
        m_inst->start();
    }

    return m_inst;
}

void oscPackClass::releaseinst(void)
{
    delete m_inst;
    m_inst = nullptr;
}

/*
 * p_source = "slider"
 * p_arg    = "12"
*/
void oscPackClass::sendMsg(QString p_source, QString p_arg)
{
    char buffer[OUTPUT_BUFFER_SIZE];
    osc::OutboundPacketStream p(buffer, OUTPUT_BUFFER_SIZE);

    p << osc::BeginBundleImmediate
      << osc::BeginMessage(p_source.toStdString().c_str())
      << p_arg.toStdString().c_str()
      << osc::EndMessage
      << osc::EndBundle;

    for (int i = 0; i < vudpTrans.size(); i++)
    {
        vudpTrans.at(i)->Send(p.Data(), p.Size());
    }
}

void oscPackClass::run(void)
{
    myoscUdpListener listener;
    UdpListeningReceiveSocket s(IpEndpointName(/*IpEndpointName::ANY_ADDRESS*/ADDRESS, port_recepteur), &listener);

    s.RunUntilSigInt();
}
