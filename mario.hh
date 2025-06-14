#ifndef MARIO_HH
#define MARIO_HH

#include <iostream>
#include <vector>
#include <list>
#include "platform.hh"
#include "window.hh"

class Mario {
 private:
    /**
     * @brief Posicion de Mario
     */
    pro2::Pt pos_;
    /**
     * @brief Ultima posicion de Mario
     */
    pro2::Pt last_pos_;
    /**
     * @brief Velocidad con la que se mueve Mario
     */
    pro2::Pt speed_ = {0, 0};
    /**
     * @brief Aceleracion con la que se mueve Mario
     */
    pro2::Pt accel_ = {0, 0};
    /**
     * @brief Aceleracion al saltar
     */
    int      accel_time_ = 0;

    /**
     * @brief Numero de tecla para mover a Mario hacia la izquierda
     */
    int left_;

    /**
     * @brief Numero de tecla para mover a Mario hacia la derecha
     */
    int right_;

    /**
     * @brief Numero de tecla para hacer saltar a Mario
     */
    int up_;

    /**
     * @brief `true` si Mario esta en el suelo, sino `false`
     */
    bool grounded_ = false;

    /**
     * @brief Hacia donde mira Mario
     */
	bool looking_left_ = false;

    /**
     * @brief Cantidad de vidas que tiene Mario
     */
    int lifes_ = 1;//imprimir vidas al acabar el juego

    /**
     * @brief Hace que el Mario se caiga si no esta encima de una plataforma
     */
	void apply_physics_();
	
 public:
    /**
     * @brief Contruye un objeto Mario
     * 
     * @param pos Posicion donde estara Mario
     * @param left Valor de la tecla que mueve a Mario hacia la izquierda
     * @param right Valor de la tecla que mueve a Mario hacia la derecha
     * @param up Valor de la tecla que hace que Mario salte
     */
    Mario(pro2::Pt pos, int left, int right, int up)
    : pos_(pos), last_pos_(pos), left_(left), right_(right), up_(up) {}

    /**
     * @brief Dibuja el objeto de Mario
     * 
     * @param window Ventana del juego
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Devuelve la posicion de Mario
     * 
     * @return `pro2::Pt` con las coordenadas de Mario
     */
    pro2::Pt pos() const {
        return pos_;
    }

    /**
     * @brief Edita la coordenada vertical de Mario
     * 
     * @param y Nueva coordenada `y`
     */
    void set_y(int y) {
        pos_.y = y;
    }

    /**
     * @brief Devuelve si Mario esta en el suelo
     * 
     * @return `true` si esta en el suelo, sino `false`
     */
    bool is_grounded() const {
        return grounded_;
    }

    /**
     * @brief Cambia si Mario esta en el suelo o no
     * 
     * @param grounded Nuevo valor `bool` para grounded
     */
    void set_grounded(bool grounded) {
        grounded_ = grounded;
        if (grounded_) {
            speed_.y = 0;
        }
    }

    /**
     * @brief Cambia el valor de si esta en el suelo al opuesto
     */
    void toggle_grounded() {
        set_grounded(!grounded_);
    }

    /**
     * @brief Hace que Mario salte
     */
    void jump();

    /**
     * @brief Añade una vida a Mario
     */
    void add_life() {
        lifes_++;
    }

    /**
     * @brief Devuelve la cantidad de vidas que tiene Mario
     * 
     * @return `int` con la cantidad de vidas
     */
    int get_lifes() {
        return lifes_;
    }

    /**
     * @brief Actualiza el objeto de Mario
     * 
     * @param window Ventana del juego
     * @param platforms Referencia a las plataformas del juego
     */
    void update(pro2::Window& window, std::list<Platform>& platforms);

 private:
    static const std::vector<std::vector<int>> mario_sprite_normal_;
};

#endif