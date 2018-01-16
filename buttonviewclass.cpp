#include "buttonviewclass.h"

ButtonViewClass::ButtonViewClass() : BaseviewClass()
, bClicked(true)
{
    m_button = new QPushButton();
    m_button->setText("Cliquez moi !");

    m_label = new QLabel("Off");

    m_layout->addWidget(m_button);
    m_layout->addWidget(m_label);

    // Connexion du signal du button à la classe de base
    connect(m_button, SIGNAL(clicked(bool)), this, SLOT(valueChangeeInt(bool)));
}

ButtonViewClass::~ButtonViewClass()
{
    delete m_button;
    delete m_label;
}

void ButtonViewClass::majValue(int p_value)
{
    (void) p_value; // suppress unused parameter warning

    disconnect(m_button, SIGNAL(clicked(bool)), 0, 0);
    if (bClicked)
    {
        m_button->setChecked(true);
        m_label->setText("On");
        bClicked = false;
    }
    else
    {
        m_button->setChecked(false);
        m_label->setText("Off");
        bClicked = true;
    }
    connect(m_button, SIGNAL(clicked(bool)), this, SLOT(valueChangeeInt(bool)));
}
