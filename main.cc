#include <vector>
#include "game.hh"
#include "window.hh"

using namespace std;

const int WIDTH = 480, HEIGHT = 320;
const int ZOOM = 2;
const int FPS = 48;

int main() {
    int platforms_num = 0, lifes_num = 0, goombas_num = 0;
    cout << "Cuantas plataformas quieres en el juego?" << endl;
    cin >> platforms_num;
    cout << "Cuantas vidas quieres en el juego?" << endl;
    cin >> lifes_num;
    
    pro2::Window window("Mario Pro 2", WIDTH, HEIGHT, ZOOM);
    window.set_fps(FPS);

    Game game(WIDTH, HEIGHT, platforms_num, lifes_num);

    while (window.next_frame() && !game.is_finished()) {
        game.update(window);
        game.paint(window);
    }

    if (game.is_finished()) {
        if (game.has_won()) {//print win screen
            cout << "has ganado" << endl;
        } else {//print lose screen
            cout << "has perdido" << endl;
        }
    }
}