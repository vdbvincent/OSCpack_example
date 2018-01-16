#ifndef OSCCLASS_H
#define OSCCLASS_H

#include <QWidget>

/*
 *  \brief Class représenant une vue OSC
*/
class oscClass : public QWidget
{
    Q_OBJECT

protected:
    QString m_name;
    int m_value;
    bool m_bblockSignal;  // booleen permettant de bloquer la réception en boucle d'un signal émis

public:
    oscClass(QString p_name, int p_value);
    ~oscClass(void);
    void valueChangeeInt(int p_valeur);

public slots:
    void changerValeur(int p_valeur);

signals:
    void valueChangee(int p_valeur);
};

#endif // OSCCLASS_H
