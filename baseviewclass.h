#ifndef BASEVIEWCLASS_H
#define BASEVIEWCLASS_H

#include <QWidget>
#include <QVBoxLayout>

/*
 *  \brief Class de base d'une vue
*/
class BaseviewClass : public QWidget
{
    Q_OBJECT

protected:
    int m_iValue;
    bool m_bblockSignal;  // booleen permettant de bloquer la réception en boucle d'un signal émis
    QVBoxLayout * m_layout;

public:
    BaseviewClass();
    QVBoxLayout * get_layout(void);
    virtual void majValue(int p_value) = 0;

public slots:
    void changerValeur(int p_valeur);

protected slots:
    void valueChangeeInt(int p_valeur);
    void valueChangeeInt(bool p_valeur);

signals:
    void valueChangee(int p_valeur);
};

#endif // BASEVIEWCLASS_H
