#ifndef FINDER_HH
#define FINDER_HH

#include <vector>
#include "platform.hh"
#include "life.hh"

template <typename T>
/**
 * @brief Esta clase sirve para optimizar los objetos que se imprimen por pantalla
 */
class Finder {
private:
    /**
     * @brief Set que guarda los elementos
     */
    std::set<T*> elements;

    /**
     * @brief Inspecciona dos rectangles per veure si s'intersecten o no
     * 
     * @param rect Objecte tipus `Rect` finestra
     * @param object Objecte tipus `Rect` que volem saber si és dins de l'altre
     * 
     * @returns Retorna `true` si l'objecte esta dins la finestra i `false` en cas contrari
     */
    static bool rects_intersect(pro2::Rect rect, pro2::Rect object) {
        if (rect.left > object.right || rect.right < object.left || rect.top > object.bottom || rect.bottom < object.top) return false;
        return true;
    }

public:
    /**
     * @brief Contruye un objeto finder
     */
    Finder() {}

    /**
     * @brief Añade un objeto al finder
     * 
     * @param t Objeto a añadir
     */
    void add(T *t) {
        elements.insert(t);
    }

    /**
     * @brief Actualiza el objeto del finder
     * 
     * @param t Objeto a actualizar
     */
    void update(T *t) {
        elements.erase(t);
        elements.insert(t);
    }

    /**
     * @brief Elimina un objeto del finder
     * 
     * @param t Objeto a eliminar
     */
    void remove(T *t) {
        elements.erase(t);
    }

    /**
     * @brief Retorna el conjunt d'objectes amb rectangles 
     *        total o parcialment dins de `rect`.
     *
     * Si el nombre de rectangles del contenidor és `n`, el 
     * cost de l'algorisme ha de ser O(log n).
     *
     * @param rect El rectangle de cerca
     *
     * @returns Un conjunt de punters a objectes que tenen un 
     *          rectangle parcial o totalment dins de `rect`
     */
    std::set<T*> query(pro2::Rect rect) const {
        std::set<T*> objects;
        typename std::set<T*>::const_iterator it;
        for (it = elements.begin(); it != elements.end(); ++it) {
            if (rects_intersect(rect, (*it)->get_rect())) {
                objects.insert(*it);
            }
        }
        return objects;
    }
};

#endif