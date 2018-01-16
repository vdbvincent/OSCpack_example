#include "controlleurclass.h"

#include "slidermodelclass.h"
#include "knobmodelclass.h"
#include "buttonmodelclass.h"

#include "sliderviewclass.h"
#include "knobviewclass.h"
#include "buttonviewclass.h"

#include "oscpackclass.h"


controlleurClass::controlleurClass(void)
 : facv(nullptr)
 , facm(nullptr)
 , faco(nullptr)
{
    m_layout = new QHBoxLayout(&fenetre);
}

controlleurClass::~controlleurClass(void)
{
    if (facv != nullptr)
    {
        delete facv;
        facv = nullptr;
    }
    if (facm != nullptr)
    {
        delete facm;
        facm = nullptr;
    }
    if (faco != nullptr)
    {
        delete faco;
        faco = nullptr;
    }
    if (m_layout != nullptr)
    {
        delete m_layout;
        m_layout = nullptr;
    }
}

void controlleurClass::create(QVector<QMap<QString, QString>> vec)
{
    // Creation des vues
    facv = new fabriqueClass<BaseviewClass>();
    // Creation des modeles
    facm = new fabriqueClass<BaseModelClass>();
    // Creation des vues osc
    faco = new fabriqueClass<oscClass>();

    for (int i = 0; i < vec.size(); i++)
    {
        // Recherche de la clé type
        if (vec.at(i).find("type") != vec.at(i).end())
        {
            bool bok = true;
            // Recherche du type
            if (vec.at(i)["type"].indexOf("slider") != -1)
            {
                facv->Register(vec.at(i)["name"], new SliderViewClass);
                facm->Register(vec.at(i)["name"], new SliderModelClass(vec.at(i)["name"]));
            }
            else if (vec.at(i)["type"].indexOf("dial") != -1)
            {
                facv->Register(vec.at(i)["name"], new KnobViewClass);
                facm->Register(vec.at(i)["name"], new KnobModelClass(vec.at(i)["name"]));
            }
            else if (vec.at(i)["type"].indexOf("button") != -1)
            {
                facv->Register(vec.at(i)["name"], new ButtonViewClass);
                facm->Register(vec.at(i)["name"], new ButtonModelClass(vec.at(i)["name"]));
            }
            else
                bok = false;

            if (bok)
            {
                faco->Register(vec.at(i)["name"], new oscClass(vec.at(i)["name"], 0));

                // fenetre
                m_layout->addLayout(facv->Get(vec.at(i)["name"])->get_layout());

                // Connexions vue vers modele
                connect(facv->Get(vec.at(i)["name"]), SIGNAL(valueChangee(int)), facm->Get(vec.at(i)["name"]), SLOT(changerValeur(int)));
                // Connexions modele vers vue
                connect(facm->Get(vec.at(i)["name"]), SIGNAL(valueChangee(int)), facv->Get(vec.at(i)["name"]), SLOT(changerValeur(int)));
                // Connexion modele vers osc
                connect(facm->Get(vec.at(i)["name"]), SIGNAL(valueChangee(int)), faco->Get(vec.at(i)["name"]), SLOT(changerValeur(int)));
                // Connexion osc vers modele
                connect(faco->Get(vec.at(i)["name"]), SIGNAL(valueChangee(int)), facm->Get(vec.at(i)["name"]), SLOT(changerValeur(int)));
            }
        }
    }
}


void controlleurClass::display(void)
{
    fenetre.show();
}

void controlleurClass::recv(QString p_source, int p_arg)
{
    oscClass * tmp = faco->Get(p_source);
    if (tmp != nullptr)
    {
        tmp->valueChangeeInt(p_arg);
    }
}
