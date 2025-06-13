#ifndef MARIO_HH
#define MARIO_HH

#include <iostream>
#include <vector>
#include <list>
#include "platform.hh"
#include "window.hh"

class Mario {
 private:
    pro2::Pt pos_, last_pos_;
    pro2::Pt speed_ = {0, 0};
    pro2::Pt accel_ = {0, 0};
    int      accel_time_ = 0;

    int left_;
    int right_;
    int up_;

    bool grounded_ = false;
	bool looking_left_ = false;

    int lifes_ = 1;//imprimir vidas al acabar el juego

	void apply_physics_();
	
 public:
    Mario(pro2::Pt pos, int left, int right, int up)
    : pos_(pos), last_pos_(pos), left_(left), right_(right), up_(up) {}

    void paint(pro2::Window& window) const;

    pro2::Pt pos() const {
        return pos_;
    }

    void set_y(int y) {
        pos_.y = y;
    }

    bool is_grounded() const {
        return grounded_;
    }

    void set_grounded(bool grounded) {
        grounded_ = grounded;
        if (grounded_) {
            speed_.y = 0;
        }
    }

    void toggle_grounded() {
        set_grounded(!grounded_);
    }

    void jump();

    void add_life() {
        lifes_++;
        std::cout << "vidas al sumar: " << lifes_ << std::endl;
    }

    int get_lifes() {
        return lifes_;
    }

    void update(pro2::Window& window, std::list<Platform>& platforms);

 private:
    static const std::vector<std::vector<int>> mario_sprite_normal_;
};

#endif