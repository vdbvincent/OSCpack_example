#ifndef FABRIQUECLASS_H
#define FABRIQUECLASS_H

#include <QString>
#include <QMap>

/*
 * \brief Classe template permettant la fabrique d'objets
*/

template <class Obj, class Key=QString>
class fabriqueClass
{
private:
    static QMap<Key, Obj *> m_map;

public:
    fabriqueClass();
    ~fabriqueClass();

    // Méthode permettant d'enregistrer un nouvel objet dans la map
    void Register(Key p_cle, Obj * p_obj);

    // Méthode permattant de retourner le pointeur de l'objet dont le
    // nom est passé en paramètre
    Obj * Get(const Key & p_cle);
};


template <class Obj, class Key> QMap<Key, Obj *> fabriqueClass<Obj, Key>::m_map = QMap<Key, Obj*>();

template <class Obj, class Key> fabriqueClass<Obj, Key>::fabriqueClass()
{

}

template <class Obj, class Key> fabriqueClass<Obj, Key>::~fabriqueClass()
{
    for (typename QMap<Key, Obj*>::iterator it = m_map.begin(); it != m_map.end(); it++)
    {
        if (it.value() != nullptr)
        {
            delete it.value();
        }
    }
}

template <class Obj, class Key> void fabriqueClass<Obj, Key>::Register(Key p_cle, Obj * p_obj)
{
    if (m_map.find(p_cle) == m_map.end())
    {
        m_map[p_cle] = p_obj;
    }
}

template <class Obj, class Key> Obj * fabriqueClass<Obj, Key>::Get(const Key & p_cle)
{
    if (m_map.find(p_cle) != m_map.end())
    {
        return m_map[p_cle];
    }
    return nullptr;
}

#endif // FABRIQUECLASS_H
