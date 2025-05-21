#ifndef GAME_HH
#define GAME_HH

#include <vector>
#include <set>
#include "mario.hh"
#include "life.hh"
#include "platform.hh"
#include "window.hh"
#include "finder.hh"

class Game {
    Mario                 mario_;
    std::vector<Life> lifes_; //hacer lista para eliminar las vidas al cojerlas
    std::vector<Platform> platforms_;
    
    Finder<Platform> finder_platform_;
    Finder<Life> finder_life_;
    std::set<const Platform*> printed_platforms_;
    std::set<const Life*> printed_lifes_;

    bool finished_;
    bool pause_;
    float float_value = 2.0f;
    float float_max_min = 2.0f;
    float float_interval = 0.5f;

    void process_keys(pro2::Window& window);
    void update_objects(pro2::Window& window);
    void update_camera(pro2::Window& window);

 public:
    Game(int width, int height);

    void update(pro2::Window& window);
    void paint(pro2::Window& window);

    bool is_finished() const {
        return finished_;
    }

 private:
    static constexpr int sky_blue = 0x5c94fc;
};

#endif