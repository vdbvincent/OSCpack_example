#ifndef BUTTONVIEWCLASS_H
#define BUTTONVIEWCLASS_H

#include <QPushButton>
#include <QLabel>
#include "baseviewclass.h"

class ButtonViewClass : public BaseviewClass
{
private:
    QPushButton * m_button;
    QLabel * m_label;
    bool bClicked;

public:
    ButtonViewClass();
    ~ButtonViewClass();
    void majValue(int p_value);
};

#endif // BUTTONVIEWCLASS_H
