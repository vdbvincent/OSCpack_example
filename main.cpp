
#include <QApplication>
#include <stdlib.h>
#include <stdio.h>
#include "controlleurclass.h"
#include "oscpackclass.h"
#include <QVector>
#include <QMap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int port_rec = 0;
    QVector<int> v_portEmi;

    // Gestion du lancement avec le debugger
    if (argc < 2)
    {
        port_rec = 1000;
    }
    else
    {
        port_rec = atoi(argv[1]);
        if (port_rec < 1000 || port_rec > 1010)
            port_rec = 1000;
    }

    // Creation d'un vecteur de ports d'émission
    // [1000] -> [1005]
    // Exclue le port de reception
    for (int i = 0; i < 10; i++)
    {
        if (i+1000 != port_rec)
            v_portEmi.push_back(i+1000);
    }

    /* Données d'entrée parsées depuis un fichier XML.
       Représentation des controlleurs dans un vecteur de map

      map 1
      ["type"] = ["slider"]
      ["name"] = ["name_1"]
      ["value"] = ["0"]

      map 2
      ["type"] = ["dial"]
      ["name"] = ["name_2"]
      ["value"] = ["0"]

    */
    QVector<QMap<QString, QString>> vec;
    QMap<QString, QString> tmp;
    tmp["type"] = "slider";
    tmp["name"] = "name1";
    tmp["value"] = "0";
    vec.push_back(tmp);
    tmp["type"] = "dial";
    tmp["name"] = "name2";
    tmp["value"] = "0";
    vec.push_back(tmp);
    tmp["type"] = "button";
    tmp["name"] = "name3";
    tmp["value"] = "0";
    vec.push_back(tmp);
    tmp["type"] = "slider";
    tmp["name"] = "name4";
    tmp["value"] = "0";
    vec.push_back(tmp);
    tmp["type"] = "dial";
    tmp["name"] = "diale2";
    tmp["value"] = "0";
    vec.push_back(tmp);


    // Creation du controlleur
    controlleurClass ctl;
    ctl.create(vec);
    ctl.display();

    // Creation du oscpack
    oscPackClass::getinst(&ctl, v_portEmi, port_rec);

    return a.exec();
}
