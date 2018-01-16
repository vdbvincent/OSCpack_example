#include "slidermodelclass.h"

SliderModelClass::SliderModelClass(QString p_name) : BaseModelClass(p_name)
 , m_iValue(0)
{
}

void SliderModelClass::majValue(int p_value)
{
    m_iValue = p_value;
}
