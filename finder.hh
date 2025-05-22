#ifndef FINDER_HH
#define FINDER_HH

#include <vector>
#include "platform.hh"
#include "life.hh"

template <typename T>
class Finder {
private:
    std::set<const T*> elements;
    //map de T* a un set de Pt
    //otro map de Pt a set de punteros

    static bool rects_intersect(pro2::Rect rect, pro2::Rect object) { //static porque no depende del estado interno del objeto
        if (rect.left > object.right || rect.right < object.left || rect.top > object.bottom || rect.bottom < object.top) return false;
        return true;
    }

public:
    Finder() {}

    void add(const T *t) {
        elements.insert(t);
    }

    void update(const T *t) {
        elements.erase(t);
        elements.insert(t);
    }

    void remove(const T *t) {
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
    std::set<const T *> query(pro2::Rect rect) const {
        std::set<const T*> objects;
        typename std::set<const T*>::const_iterator it;
        for (it = elements.begin(); it != elements.end(); ++it) {
            if (rects_intersect(rect, (*it)->get_rect())) {
                objects.insert(*it);
            }
        }
        return objects;
    }
};

#endif