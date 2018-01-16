#include "sliderviewclass.h"

#include <QString>

SliderViewClass::SliderViewClass() : BaseviewClass()
, min(0)
, max(100)
{
    m_slider = new QSlider();
    m_slider->setMinimum(min);
    m_slider->setMaximum(max);
    m_slider->setValue(0);

    m_label = new QLabel("0");

    m_layout->addWidget(m_slider);
    m_layout->addWidget(m_label);

    // Connexion du signal du slider à la classe de base
    connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(valueChangeeInt(int)));

}

SliderViewClass::~SliderViewClass()
{
    delete m_slider;
    delete m_label;
}

void SliderViewClass::majValue(int p_value)
{
    disconnect(m_slider, SIGNAL(valueChanged(int)), 0, 0);
    m_slider->setValue(p_value);
    m_label->setText(QString::number(p_value));
    connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(valueChangeeInt(int)));
}


