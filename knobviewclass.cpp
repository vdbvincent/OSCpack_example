#include "knobviewclass.h"
#include <QString>

KnobViewClass::KnobViewClass() : BaseviewClass()
, min(0)
, max(100)
{
    m_dial = new QDial();
    m_dial->setMinimum(min);
    m_dial->setMaximum(max);
    m_dial->setValue(0);

    m_label = new QLabel("0");

    m_layout->addWidget(m_dial);
    m_layout->addWidget(m_label);

    // Connection du sinal du dial à la classe de base
    connect(m_dial, SIGNAL(valueChanged(int)), this, SLOT(valueChangeeInt(int)));
}

void KnobViewClass::majValue(int p_value)
{
    disconnect(m_dial, SIGNAL(valueChanged(int)), 0, 0);
    m_dial->setValue(p_value);
    m_label->setText(QString::number(p_value));
    connect(m_dial, SIGNAL(valueChanged(int)), this, SLOT(valueChangeeInt(int)));
}
