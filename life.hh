#ifndef LIFE_HH
#define LIFE_HH

#include <iostream>
#include <vector>
#include "mario.hh"
#include "window.hh"

class Life {
 private:
    pro2::Pt pos_;
    bool taken_;
    
 public:
    Life(pro2::Pt pos, bool taken) : pos_(pos), taken_(taken) {}

    void paint(pro2::Window& window) const;

    pro2::Pt pos() const {
        return pos_;
    }

    void set_y(int y) {
        pos_.y = y;
    }

    void taken() {
        taken_ = true;
    }

    bool is_taken() {
        return taken_;
    }

    void update(pro2::Window& window, Mario& platforms, int float_value);
 private:
    static const std::vector<std::vector<int>> life_sprite_normal_;
};

#endif