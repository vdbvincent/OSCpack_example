#ifndef SLIDERMODELCLASS_H
#define SLIDERMODELCLASS_H

#include "basemodelclass.h"

class SliderModelClass : public BaseModelClass
{
private:
    int m_iValue;

public:
    SliderModelClass(QString p_name);
    void majValue(int p_value);
};

#endif // SLIDERMODELCLASS_H
