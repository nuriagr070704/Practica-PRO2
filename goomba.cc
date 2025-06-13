#include "goomba.hh"
#include "utils.hh"
using namespace std;
using namespace pro2;

//enlazar un goomba a una plataforma

// colors
const int o = 0xFFA500; // naranja
const int m = 0x964B00; // marron
const int w = 0xFFFFFF; // blanco
const int b = pro2::black; // negro (ojos)
const int _ = -1; // transparente

const vector<vector<int>> Goomba::goomba_sprite_normal_ = {
    {_, _, _, _, _, o, o, o, o, o, o, _, _, _, _, _},
    {_, _, _, _, o, o, o, o, o, o, o, o, _, _, _, _},
    {_, _, _, o, o, o, o, o, o, o, o, o, o, _, _, _},
    {_, _, o, b, b, o, o, o, o, o, o, b, b, o, _, _},
    {_, o, o, o, w, b, o, o, o, o, b, w, o, o, _, _},
    {_, o, o, o, w, b, b, b, b, b, b, w, o, o, o, _},
    {o, o, o, o, w, b, w, o, o, w, b, w, o, o, o, o},
    {o, o, o, o, w, w, w, o, o, w, w, w, o, o, o, o},
    {o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o},
    {_, o, o, o, o, m, m, m, m, m, m, o, o, o, o, _},
    {_, _, _, _, m, m, m, m, m, m, m, m, _, _, _, _},
    {_, _, b, b, m, m, m, m, m, m, m, m, b, b, _, _},
    {_, b, b, b, b, b, m, m, m, m, b, b, b, b, b, _},
    {_, _, b, b, b, b, b, _, _, b, b, b, b, b, _, _},
};

void Goomba::update(pro2::Window& window, int start, int end) {
    pro2::Pt aux_pos = pos_;
    if(pos_.x == start) { //ir hacia la derecha
        pos_.x += 1;
    } else if (pos_.x == end) { //ir hacia la izquierda
        pos_.x -= 1;
    } else if (pos_.x > prepos_.x) { // ir hacia la derecha
        pos_.x += 1;
    } else if (pos_.x < prepos_.x) { //ir hacia la izquierda
        pos_.x -= 1;
    }
    prepos_ = aux_pos;
    if (fbk_ > 0) add_fbk(-1);
}

void Goomba::paint(pro2::Window& window) const {
    const Pt top_left = {pos_.x - 6, pos_.y - 13};
    paint_sprite(window, top_left, goomba_sprite_normal_, true);
}