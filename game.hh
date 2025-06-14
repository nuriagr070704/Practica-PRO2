#ifndef GAME_HH
#define GAME_HH

#include <vector>
#include <set>
#include <list>
#include "life.hh"
#include "mario.hh"
#include "platform.hh"
#include "flag.hh"
#include "window.hh"
#include "finder.hh"

class Game {
    /**
     * @brief Mario del juego
     */
    Mario                   mario_;
    /**
     * @brief Lista de vidas
     */
    std::list<Life>         lifes_;
    /**
     * @brief Lista de plataformas
     */
    std::list<Platform>     platforms_;
    /**
     * @brief Objeto de bandera
     */
    Flag                    flag_;
    
    /**
     * @brief Objeto finder para las plataformas
     */
    Finder<Platform>        finder_platform_;
    /**
     * @brief Objeto finder para las vidas
     */
    Finder<Life>            finder_life_;
    /**
     * @brief Set con las plataformas en pantalla
     */
    std::set<Platform*>     printed_platforms_;
    /**
     * @brief Set con las vidas en pantalla
     */
    std::set<Life*>         printed_lifes_;

    /**
     * @brief `true` si se ha presionado Esc
     */
    bool finished_;
    /**
     * @brief `true` si se acaba el juego de una manera convencional
     */
    bool game_finished_;
    /**
     * @brief `true` si mario sigue con vidas
     */
    bool is_winning_;
    /**
     * @brief `true` si el juego esta en pauss
     */
    bool pause_;

    /**
     * @brief Valor que se añade verticalmente a las vidas para que se actualizen
     */
    float float_value = 2.0f;
    /**
     * @brief Valor maximo que se mueven las vidas verticalmente
     */
    float float_max_min = 2.0f;
    /**
     * @brief Intervalo que se mueven las vidas en cada frame
     */
    float float_interval = 0.5f;

    /**
     * @brief Controla que teclas se pulsan para la pausa o cerrar el programa
     * 
     * @param window Ventana del juego
     */
    void process_keys(pro2::Window& window);
    /**
     * @brief Actualiza todos los objetos del juego
     * 
     * @param window Ventana del juego
     * @param visible_window Rectangulo visible del juego
     */
    void update_objects(pro2::Window& window, pro2::Rect visible_window);
    /**
     * @brief Actualiza la parte de la pantalla que se ve
     * 
     * @param window Ventana del juego
     */
    void update_camera(pro2::Window& window);

 public:
    /**
     * @brief Contruye el objeto `Game`
     * 
     * @param width Ancho de la pantalla que se abre
     * @param height Alto de la pantalla que se abre
     * @param platforms_num Numero de plataformas del juego
     * @param lifes_num Numero de vidas del juego
     */
    Game(int width, int height, int platforms_num, int lifes_num);

    /**
     * @brief Actualiza todo el juego. Usa los metodos privados de actualizacion para actualizar por separado
     */
    void update(pro2::Window& window);
    /**
     * @brief Dibuja todos los objetos del juego
     */
    void paint(pro2::Window& window);

    /**
     * @brief Devuelve si el juego ha acabado
     * 
     * @return `true` si el juego ha acabado, sino `false`
     */
    bool is_finished() const {
        return finished_;
    }

    /**
     * @brief Devuelve si hemos ganado el juego
     * 
     * @return `true` si hemos ganado, sino `false`
     */
    bool has_won() const {
        return is_winning_;
    }

 private:
    static constexpr int sky_blue = 0x5c94fc;
};

#endif