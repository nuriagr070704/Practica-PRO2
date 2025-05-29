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
