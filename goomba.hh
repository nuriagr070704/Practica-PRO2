#ifndef GOOMBA_HH
#define GOOMBA_HH

#include <iostream>
#include <vector>
#include "window.hh"

class Goomba {
    private:
        pro2::Pt    pos_;
        pro2::Pt    prepos_;

        int fbk_ = 0; //frames before kill -> cuenta atras antes de que pueda volver a quitar una vida

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

        bool can_kill() {
            return fbk_ == 0;
        }

        void add_fbk(int n) {
            fbk_ += n;
        }

        void update(pro2::Window& window, int start, int end);
};

#endif