#ifndef GOOMBA_HH
#define GOOMBA_HH

#include <iostream>
#include <vector>
#include "window.hh"

class Goomba {
    private:
        /**
         * @brief Posicion del Goomba
         */
        pro2::Pt    pos_;
        /**
         * @brief Posicion anterior del Goomba
         */
        pro2::Pt    prepos_;

        /**
         * @brief Son los frames que tienen que pasar antes de que el Goomba pueda volver a matar. 
         * Si no usamos esta variable el Goomba le quitaria demasiadas vida a Mario con solo tocarlo una vez.
         */
        int fbk_ = 0;

        static const std::vector<std::vector<int>> goomba_sprite_normal_;

    public:
        /**
         * @brief Contruye el objeto Goomba
         * 
         * @param pos Posicion donde se crea el Goomba
         */
        Goomba(pro2::Pt pos) : pos_(pos) {}

        /**
         * @brief Dibuja el objeto de Goomba
         * 
         * @param window Ventana del juego
         */
        void paint(pro2::Window& window) const;

        /**
         * @brief Devuelve la posicion del Goomba
         * 
         * @return Objeto `pro::Pt` con la posición
         */
        pro2::Pt pos() const {
            return pos_;
        }

        /**
         * @brief Editar la posicion horizontal del Goomba
         * 
         * @param x Nueva posición horizontal
         */
        void set_x(int x) {
            pos_.x = x;
        }

        /**
         * @brief Devuelve `true` o `false` dependiendo de si el Goomba puede matar a Mario
         * 
         * @return `boolean` indicando si el Goomba puede matar
         */
        bool can_kill() const {
            return fbk_ == 0;
        }

        /**
         * @brief Suma valores `int` a `fbk_`
         * 
         * @param n Valor que se va a sumar
         */
        void add_fbk(int n) {
            fbk_ += n;
        }

        /**
         * @brief Actualiza la posición del Goomba y si puede volver a matar o no
         * 
         * @param window Ventana del juego
         * @param start Coordenada x de la posicion inicial de la plataforma
         * @param end Coordenada x de la posicion final de la plataforma
         */
        void update(pro2::Window& window, int start, int end);
};

#endif