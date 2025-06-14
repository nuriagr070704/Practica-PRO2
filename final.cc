#include "final.hh"
#include "utils.hh"
using namespace std;
using namespace pro2;

const int w = 0xFFFFFF; // blanco
const int _ = -1; // transparente

const vector<vector<int>> Final::sprite_lose_ = {
    {_, _, w, w, w, w, w, _, _, _, w, w, w, _, _, _, w, w, _, _, _, w, w, _, w, w, w, w, w, w, w, _, _, _, _, _, _, _, _, _, _, w, w, w, w, w, _, _, w, w, _, _, _, w, w, _, w, w, w, w, w, w, w, _, w, w, w, w, w, w, _},
    {_, w, w, _, _, _, _, _, _, w, w, _, w, w, _, _, w, w, w, _, w, w, w, _, w, w, _, _, _, _, _, _, _, _, _, _, _, _, _, _, w, w, _, _, _, w, w, _, w, w, _, _, _, w, w, _, w, w, _, _, _, _, _, _, w, w, _, _, _, w, w},
    {w, w, _, _, _, _, _, _, w, w, _, _, _, w, w, _, w, w, w, w, w, w, w, _, w, w, _, _, _, _, _, _, _, _, _, _, _, _, _, _, w, w, _, _, _, w, w, _, w, w, _, _, _, w, w, _, w, w, _, _, _, _, _, _, w, w, _, _, _, w, w},
    {w, w, _, _, w, w, w, _, w, w, _, _, _, w, w, _, w, w, w, w, w, w, w, _, w, w, w, w, w, w, _, _, _, _, _, _, _, _, _, _, w, w, _, _, _, w, w, _, w, w, w, _, w, w, w, _, w, w, w, w, w, w, _, _, w, w, _, _, w, w, w},
    {w, w, _, _, _, w, w, _, w, w, w, w, w, w, w, _, w, w, _, w, _, w, w, _, w, w, _, _, _, _, _, _, _, _, _, _, _, _, _, _, w, w, _, _, _, w, w, _, _, w, w, w, w, w, _, _, w, w, _, _, _, _, _, _, w, w, w, w, w, _, _},
    {_, w, w, _, _, w, w, _, w, w, _, _, _, w, w, _, w, w, _, _, _, w, w, _, w, w, _, _, _, _, _, _, _, _, _, _, _, _, _, _, w, w, _, _, _, w, w, _, _, _, w, w, w, _, _, _, w, w, _, _, _, _, _, _, w, w, _, w, w, w, _},
    {_, _, w, w, w, w, w, _, w, w, _, _, _, w, w, _, w, w, _, _, _, w, w, _, w, w, w, w, w, w, w, _, _, _, _, _, _, _, _, _, _, w, w, w, w, w, _, _, _, _, _, w, _, _, _, _, w, w, w, w, w, w, w, _, w, w, _, _, w, w, w},
};

const vector<vector<int>> Final::sprite_win_ = {
    {w, w, _, _, _, _, w, w, _, _, w, w, w, w, w, _, _, w, w, _, _, _, w, w, _, _, _, _, _, _, _, _, _, w, w, _, _, _, w, w, _, w, w, w, w, w, w, _, w, w, _, _, _, w, w},
    {_, w, w, _, _, w, w, _, _, w, w, _, _, _, w, w, _, w, w, _, _, _, w, w, _, _, _, _, _, _, _, _, _, w, w, _, _, _, w, w, _, _, _, w, w, _, _, _, w, w, w, _, _, w, w},
    {_, _, w, w, w, w, _, _, _, w, w, _, _, _, w, w, _, w, w, _, _, _, w, w, _, _, _, _, _, _, _, _, _, w, w, _, _, _, w, w, _, _, _, w, w, _, _, _, w, w, w, w, _, w, w},
    {_, _, _, w, w, _, _, _, _, w, w, _, _, _, w, w, _, w, w, _, _, _, w, w, _, _, _, _, _, _, _, _, _, w, w, _, w, _, w, w, _, _, _, w, w, _, _, _, w, w, _, w, _, w, w},
    {_, _, _, w, w, _, _, _, _, w, w, _, _, _, w, w, _, w, w, _, _, _, w, w, _, _, _, _, _, _, _, _, _, w, w, w, w, w, w, w, _, _, _, w, w, _, _, _, w, w, _, w, w, w, w},
    {_, _, _, w, w, _, _, _, _, w, w, _, _, _, w, w, _, w, w, _, _, _, w, w, _, _, _, _, _, _, _, _, _, w, w, w, _, w, w, w, _, _, _, w, w, _, _, _, w, w, _, _, w, w, w},
    {_, _, _, w, w, _, _, _, _, _, w, w, w, w, w, _, _, _, w, w, w, w, w, _, _, _, _, _, _, _, _, _, _, _, w, _, _, _, w, _, _, w, w, w, w, w, w, _, w, w, _, _, _, w, w},
};

void Final::paint(pro2::Window& window) const {
    const Pt top_left = {pos_.x - 6, pos_.y - 15};
    if (!won_) paint_sprite(window, top_left, sprite_lose_, false);
    else paint_sprite(window, top_left, sprite_win_, false);
}