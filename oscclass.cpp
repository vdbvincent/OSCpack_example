#include "oscclass.h"
#include "oscpackclass.h"

oscClass::oscClass(QString p_name, int p_value) : QWidget()
, m_name(p_name)
, m_value(p_value)
, m_bblockSignal(false)
{
}

oscClass::~oscClass(void)
{
}

// slot externe
void oscClass::changerValeur(int p_valeur)
{
    if (m_bblockSignal)
        m_bblockSignal = false;
    else
    {
        m_value = p_valeur;
        // emission de la nouvelle valeur
        oscPackClass::getinst()->sendMsg(m_name, QString::number(m_value));
    }
}

// slot interne
void oscClass::valueChangeeInt(int p_valeur)
{
    m_bblockSignal =  true;
    m_value = p_valeur;
    emit valueChangee(p_valeur);
}
