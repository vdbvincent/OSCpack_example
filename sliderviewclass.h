#ifndef SLIDERVIEWCLASS_H
#define SLIDERVIEWCLASS_H

#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>

#include "baseviewclass.h"

class SliderViewClass : public BaseviewClass
{
private:
    QSlider * m_slider;
    QLabel * m_label;

    int min;
    int max;

public:
    SliderViewClass();
    ~SliderViewClass();
    void majValue(int p_value);
};

#endif // SLIDERVIEWCLASS_H
