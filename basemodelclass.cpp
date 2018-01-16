#include "basemodelclass.h"

BaseModelClass::BaseModelClass(QString p_name) : QWidget()
, m_name(p_name)
{
}


BaseModelClass::~BaseModelClass()
{
}

// slot externe
void BaseModelClass::changerValeur(int p_valeur)
{
    majValue(p_valeur);
    valueChangeeInt(p_valeur);
}

// slot interne
void BaseModelClass::valueChangeeInt(int p_valeur)
{
    emit valueChangee(p_valeur);
}
