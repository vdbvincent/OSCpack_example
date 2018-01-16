#ifndef KNOBMODELCLASS_H
#define KNOBMODELCLASS_H

#include "basemodelclass.h"

class KnobModelClass : public BaseModelClass
{
private:
    int m_iValue;

public:
    KnobModelClass(QString p_name);

    void majValue(int p_value);
};

#endif // KNOBMODELCLASS_H
