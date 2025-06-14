#ifndef LIFE_HH
#define LIFE_HH

#include <iostream>
#include <vector>
#include "mario.hh"
#include "window.hh"

class Life {
 private:
    /**
     * @brief Posicion de la vida
     */
    pro2::Pt pos_;
    
    /**
     * @brief `bool` de si la vida esta cogida o no
     */
    bool taken_;
    
 public:
    /**
     * @brief Contruye un objeto de tipo `Life`
     * 
     * @param pos Posicion de donde estara la vida
     * @param taken Si la vida esta cogida o no, normalmente al crearla no lo estara
     */
    Life(pro2::Pt pos, bool taken) : pos_(pos), taken_(taken) {}

    /**
     * @brief Dibuja el obejto de Life
     * 
     * @param window Ventana del juego
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Devuelve la posicion de la vida
     * 
     * @return `pro2::Pt` con la coordenada del objeto vida
     */
    pro2::Pt pos() const {
        return pos_;
    }

    /**
     * @brief Edita la coordenada `y` del objeto vida
     * 
     * @param y Coordenada `y` a cambiar
     */
    void set_y(int y) {
        pos_.y = y;
    }

    /**
     * @brief Cambia el valor del objeto a cogido cuando Mario lo toca
     */
    void taken() {
        taken_ = true;
    }

    /**
     * @brief Devuelve si el objeto se ha cogido
     * 
     * @return `true` si se ha cogido, sino `false`
     */
    bool is_taken() const {
        return taken_;
    }

    /**
     * @brief Devuelve el rectangulo que ocupa el objeto
     * 
     * @return `pro2::Rect` con las coordenadas del rectangulo
     */
    pro2::Rect get_rect() const {
        return {pos_.x-6, pos_.y-15, pos_.x+7, pos_.y-2};
    }

    /**
     * @brief Actuliza el objeto de Life
     * 
     * @param window Ventana del juego
     * @param mario Objeto Mario
     * @param float_value Valor con el que se cambia la posicion vertical del objeto vida para que floten
     */
    void update(pro2::Window& window, Mario& mario, int float_value);
 private:
    static const std::vector<std::vector<int>> life_sprite_normal_;
};

#endif