#include "knobmodelclass.h"

KnobModelClass::KnobModelClass(QString p_name) : BaseModelClass(p_name)
, m_iValue(0)
{

}

void KnobModelClass::majValue(int p_value)
{
    m_iValue = p_value;
}
