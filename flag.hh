#ifndef FLAG_HH
#define FLA_HH

#include <iostream>
#include <vector>
#include "mario.hh"
#include "window.hh"

class Flag {
 private:
    /**
     * @brief Posicion de la bandera
     */
    pro2::Pt pos_;
    
    /**
     * @brief `bool` de si la bandera se ha tocado o no
     */
    bool taken_;

    static const std::vector<std::vector<int>> flag_sprite_normal_;
    static const std::vector<std::vector<int>> flag_sprite_win_;
    
 public:
    /**
     * @brief Contruye un objeto de tipo `Flag`
     * 
     * @param pos Posicion de donde estara la bandera
     * @param taken Si la bandera se ha tocado o no, normalmente al crearla no se habra tocado aun
     */
    Flag(pro2::Pt pos, bool taken) : pos_(pos), taken_(taken) {}

    /**
     * @brief Dibuja el obejto de Flag
     * 
     * @param window Ventana del juego
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Devuelve si el objeto se ha cogido
     * 
     * @return `true` si se ha cogido, sino `false`
     */
    bool is_taken() const {
        return taken_;
    }

    /**
     * @brief Actuliza el objeto de Flag
     * 
     * @param window Ventana del juego
     * @param mario Objeto Mario
     */
    void update(pro2::Window& window, Mario& mario);
};

#endif