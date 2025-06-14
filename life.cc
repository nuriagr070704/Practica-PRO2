#include "life.hh"
#include "utils.hh"
using namespace std;
using namespace pro2;

// const int r = pro2::red; // rojo
const int g = 0x00FF00; // verde
const int w = 0xFFFFFF; // blanco
const int b = pro2::black; // negro (ojos)
const int _ = -1; // transparente

const vector<vector<int>> Life::life_sprite_normal_ = {
    {_, _, _, _, _, w, g, g, w, _, _, _, _, _},
    {_, _, g, w, w, w, g, g, w, w, w, g, _, _},
    {_, _, g, w, w, g, g, g, g, w, w, g, _, _},
    {_, w, g, g, g, g, g, g, g, g, g, g, w, _},
    {_, w, w, g, g, w, w, w, w, g, g, w, w, _},
    {w, w, w, g, w, w, w, w, w, w, g, w, w, w},
    {w, w, w, g, w, w, w, w, w, w, g, w, w, w},
    {w, w, g, g, w, w, w, w, w, w, g, g, w, w},
    {g, g, g, g, g, w, w, w, w, g, g, g, g, g},
    {g, g, g, g, g, g, g, g, g, g, g, g, g, g},
    {_, g, g, w, w, b, w, w, b, w, w, g, g, _},
    {_, _, w, w, w, b, w, w, b, w, w, w, _, _},
    {_, _, w, w, w, w, w, w, w, w, w, w, _, _},
    {_, _, _, w, w, w, w, w, w, w, w, _, _, _},
};

void Life::paint(pro2::Window& window) const {
    const Pt top_left = {pos_.x - 6, pos_.y - 15};
    paint_sprite(window, top_left, life_sprite_normal_, false);
}

void Life::update(pro2::Window& window, Mario& mario, int float_value) {
    Pt pos_mario = mario.pos();
    if (pos_mario.x >= pos_.x - 7 && pos_mario.x <= pos_.x + 7) {
        if (pos_mario.y >= pos_.y - 7 && pos_mario.y <=  pos_.y + 7) {
            taken_ = true;
            mario.add_life();
            std::cout << "vidas de mario: " << mario.get_lifes() << std::endl;
        }
    }
    pos_.y += float_value;
}