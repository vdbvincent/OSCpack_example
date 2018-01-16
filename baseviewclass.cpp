#include "baseviewclass.h"

BaseviewClass::BaseviewClass() : QWidget()
, m_iValue(0)
, m_bblockSignal(false)
{
    m_layout = new QVBoxLayout();
}

void BaseviewClass::changerValeur(int p_valeur)
{
    if (m_bblockSignal)
        m_bblockSignal = false;
    else
        majValue(p_valeur);
}

void BaseviewClass::valueChangeeInt(int p_valeur)
{
    m_bblockSignal = true;
    majValue(p_valeur);
    emit valueChangee(p_valeur);
}
void BaseviewClass::valueChangeeInt(bool p_valeur)
{
    (void) p_valeur; // suppress unused parameter warning
    valueChangeeInt(0);
}

QVBoxLayout * BaseviewClass::get_layout(void)
{
    return m_layout;
}
