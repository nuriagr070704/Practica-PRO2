#ifndef FINAL_HH
#define FINAL_HH

#include <iostream>
#include <vector>
#include "window.hh"
/**
 * @brief Esta clase sirve para imprimir por pantalla un mensaje si se ha perdido o ganado el juego
 */
class Final {
 private:
    /**
     * @brief Posicion de la bandera
     */
    pro2::Pt pos_;
    /**
     * @brief `true` si se ha ganado, sino `false`
     */
    bool won_ = false;

    static const std::vector<std::vector<int>> sprite_lose_;
    static const std::vector<std::vector<int>> sprite_win_;
    
 public:
    /**
     * @brief Contruye un objeto de tipo `Final`
     * 
     * @param pos Posicion de donde estara el cartel
     */
    Final(pro2::Pt pos) : pos_(pos) {}

    /**
     * @brief Edita la posicion al acabar el juego
     * 
     * @param coordenates Coordenadas del cartel
     */
    void set_pt(pro2::Pt coordenates) {
        coordenates.x -= 30;
        pos_ = coordenates;
    }

    /**
     * @brief Edita si se ha ganado o no
     * 
     * @param user_won `true` si hemos ganado, sino `false`
     */
    void has_won(bool user_won) {
        won_ = user_won;
    }

    /**
     * @brief Dibuja el objeto de Final
     * 
     * @param window Ventana del juego
     */
    void paint(pro2::Window& window) const;
};

#endif