#ifndef CONTROLLEURCLASS_H
#define CONTROLLEURCLASS_H

#include <QWidget>
#include <QObject>
#include <QString>

#include "fabriqueclass.h"
#include "baseviewclass.h"
#include "basemodelclass.h"
#include "oscclass.h"


/*
  * \brief Class controlleurClass permettant de mettre
  *        à jour les vues et modèle
*/
class controlleurClass : public QObject
{
    Q_OBJECT

private:
    fabriqueClass<BaseviewClass> * facv;
    fabriqueClass<BaseModelClass> * facm;
    fabriqueClass<oscClass> * faco;

    QWidget fenetre;
    QHBoxLayout * m_layout;

public:
    controlleurClass(void);
    ~controlleurClass(void);
    void create(QVector<QMap<QString, QString>> vec);
    void display(void);

    /*
     *  \brief Méthode permettant la réception de
     *         données du serveur OSC
    */
    void recv(QString p_source, int p_arg);

};

#endif // CONTROLLEURCLASS_H
