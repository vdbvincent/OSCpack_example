#ifndef BASEMODELCLASS_H
#define BASEMODELCLASS_H

#include <QWidget>
#include <QString>

/*
 *  \brief Class de base d'un modèle de données
*/
class BaseModelClass : public QWidget
{
    Q_OBJECT

protected:
    QString m_name;
public:
    BaseModelClass(QString p_name);
    ~BaseModelClass();

    virtual void majValue(int p_value) = 0;

public slots:
    void changerValeur(int p_valeur);

protected slots:
    void valueChangeeInt(int p_valeur);
signals:
    void valueChangee(int p_valeur);
};

#endif // BASEMODELCLASS_H
