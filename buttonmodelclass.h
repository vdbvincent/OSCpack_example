#ifndef BUTTONMODELCLASS_H
#define BUTTONMODELCLASS_H

#include "basemodelclass.h"

class ButtonModelClass : public BaseModelClass
{
private:
    int m_iValue;

public:
    ButtonModelClass(QString p_name);
    void majValue(int p_value);
};

#endif // BUTTONMODELCLASS_H
