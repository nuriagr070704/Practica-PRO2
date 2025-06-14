#ifndef PLATFORM_HH
#define PLATFORM_HH

#include <vector>
#include "goomba.hh"
#include "window.hh"

class Platform {
 private:
    /**
     * @brief Limites de la plataforma
     */
    int left_, right_, top_, bottom_;
    /**
     * @brief Goomba propio de cada plataforma
     */
    Goomba goomba_;

	static const std::vector<std::vector<int>> platform_texture_;

 public:
    /**
     * @brief Constuye una plataforma por defecto
     */
    Platform() : left_(0), right_(0), top_(0), bottom_(0), goomba_(pro2::Pt{0,0}) {}

    /**
     * @brief Contruye una plataforma a partir de otra
     * 
     * @param other Plataforma que se quiere copiar
     */
    Platform(const Platform& other)
        : left_(other.left_),
        right_(other.right_),
        top_(other.top_),
        bottom_(other.bottom_),
        goomba_(other.goomba_) {}

    /**
     * @brief Contruye una plataforma
     * 
     * @param left Lado izquierdo de la plataforma
     * @param right Lado derecho de la plataforma
     * @param top Lado superior de la plataforma
     * @param bottom Lado inferior de la plataforma
     */
    Platform(int left, int right, int top, int bottom)
        : left_(left), right_(right), top_(top), bottom_(bottom), goomba_(pro2::Pt{left, top}) {}

    /**
     * @brief Dibuja el objeto de Platform
     * 
     * @param window Ventana del juego
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Determina si unas coordenadas han traspasado la plataforma
     * 
     * @param plast Ultima posicion
     * @param pcurr Posicion actual
     * 
     * @return `true` si ha traspado, sino `false` 
     */
    bool has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Actualiza la plataforma
     * 
     * @param window Ventana del juego
     */
    void update(pro2::Window& window);
    
    /**
     * @brief Devuelve la posicion del Goomba
     * 
     * @return `pro2::Pt` con la posicion del Goomba
     */
    pro2::Pt get_goomba_pos() {
        return goomba_.pos();
    }

    /**
     * @brief Suma tiempo de cooldown para que el Goomba tarde en matar
     */
    void goomba_kills() {
        goomba_.add_fbk(20);
    }

    /**
     * @brief Devuelve si el Goomba puede volver a matar o no
     * 
     * @return `true` si puede volver a matar, sino `false`
     */
    bool can_goomba_kill() {
        return goomba_.can_kill();
    }

    /**
     * @brief Devuelve la coordenada y del top de la plataforma
     * 
     * @return `int` con la coordenada top
     */
    int top() const {
        return top_;
    }

    /**
     * @brief Devuelve el rectangulo donde esta la plataforma
     * 
     * @return `pro2::Rect` con el rectangulo que ocupa
     */
    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }
};

#endif