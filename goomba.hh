#ifndef GOOMBA_HH
#define GOOMBA_HH

#include <iostream>
#include <vector>
#include "window.hh"

class Goomba {
    private:
        pro2::Pt    pos_;
        pro2::Pt    prepos_;
        pro2::Pt    speed_ = {0, 0};
        pro2::Pt    accel_ = {0, 0};
        int         accel_time_ = 0;

        bool alive_ = true;

        static const std::vector<std::vector<int>> goomba_sprite_normal_;

    public:
        Goomba(pro2::Pt pos) : pos_(pos) {}

        void paint(pro2::Window& window) const;

        pro2::Pt pos() {
            return pos_;
        }

        void kill() {
            alive_ = false;
        }

        bool is_alive() const {
            return alive_;
        }

        void set_x(int x) {
            pos_.x = x;
        }

        void update(pro2::Window& window, int start, int end);
};

#endif