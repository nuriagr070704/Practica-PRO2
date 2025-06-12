#ifndef GAME_HH
#define GAME_HH

#include <vector>
#include <set>
#include <list>
#include "life.hh"
#include "mario.hh"
#include "platform.hh"
#include "window.hh"
#include "finder.hh"

class Game {
    Mario                 mario_;
    std::list<Life> lifes_;
    // std::vector<Life> lifes_; //hacer lista para eliminar las vidas al cojerlas
    std::list<Platform> platforms_;
    
    Finder<Platform> finder_platform_; //objeto finder para las plataformas
    Finder<Life> finder_life_; //objeto finder para las vidas
    std::set<Platform*> printed_platforms_; //set que guarda la referencia a las plataformas que se van a imprimir
    std::set<Life*> printed_lifes_; //set que guarda la referencia a las vidas que se van a imprimir

    bool finished_;
    bool is_winning_;
    bool pause_;
    float float_value = 2.0f;
    float float_max_min = 2.0f;
    float float_interval = 0.5f;

    void process_keys(pro2::Window& window);
    void update_objects(pro2::Window& window, pro2::Rect visible_window);
    void update_camera(pro2::Window& window);

 public:
    Game(int width, int height, int platforms_num, int lifes_num, int goombas_num);

    void update(pro2::Window& window);
    void paint(pro2::Window& window);

    bool is_finished() const {
        return finished_;
    }

    bool has_won() const {
        return is_winning_;
    }

 private:
    static constexpr int sky_blue = 0x5c94fc;
};

#endif