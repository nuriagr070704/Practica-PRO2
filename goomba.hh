#ifndef LIFE_HH
#define LIFE_HH

#include <iostream>
#include <vector>
#include "mario.hh"
#include "window.hh"

class Goomba {
    private:
        pro2::Pt pos_;

        static const std::vector<std::vector<int>> goomba_sprite_normal_;

    public:
        Goomba(pro2::Pt pos) : pos_(pos) {}

        void paint(pro2::Window& window) const;

        pro2::Pt pos() {
            return pos_;
        }

        void set_x(int x) {
            pos_.x = x;
        }

        void update(pro2::Window& window, Mario& mario, int steps);
};

#endif