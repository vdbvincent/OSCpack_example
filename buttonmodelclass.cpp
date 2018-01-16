#include "buttonmodelclass.h"

ButtonModelClass::ButtonModelClass(QString p_name) : BaseModelClass(p_name)
 , m_iValue(0)
{

}

void ButtonModelClass::majValue(int p_value)
{
    m_iValue = p_value;
}
