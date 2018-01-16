#ifndef KNOBVIEWCLASS_H
#define KNOBVIEWCLASS_H

#include <QDial>
#include <QLabel>

#include "baseviewclass.h"

class KnobViewClass : public BaseviewClass
{
    QDial * m_dial;
    QLabel * m_label;

    int min;
    int max;

public:
    KnobViewClass();
    void majValue(int p_value);
};

#endif // KNOBVIEWCLASS_H
