#ifndef GAME_HH
#define GAME_HH

#include <vector>
#include "mario.hh"
#include "life.hh"
#include "platform.hh"
#include "window.hh"

class Game {
    Mario                 mario_;
    // Mario                 mario2_;
    std::vector<Life> lifes_;
    std::vector<Platform> platforms_;

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