#include "game.hh"
#include "utils.hh"
using namespace pro2;

//preguntar cuantas vidas, plataformas, enemigos quiere
Game::Game(int width, int height, int platforms_num, int lifes_num, int goombas_num)
    : mario_({width / 2, 150}, Keys::Left, Keys::Right, Keys::Up),
      lifes_{
        Life({375, 100}, false),
        Life({150, 230}, false),
        Life({190, 100}, false),
      },
      platforms_{
          Platform(100, 300, 200, 211),
          Platform(0, 200, 250, 261),
          Platform(250, 400, 150, 161),
      },
      pause_(false),
      finished_(false) {

    for (int i = 0; i < lifes_num; ++i) {
      //horizontalmente entre 0(left) y el infimito supongo(right)
      //verticalmente entre 150(top) y 261(bottom)
      //hacer random
      lifes_.push_back(Life({0,0}, false));
    }//hacer lo mismo para las plataformas
    //y a ver como me las apaño para hacerlo con los goombas porque van ligados a las plataformas
    //hacer que las plataforas se generen automaticamente
    //ver si estan cogidas con una matriz o con un map donde la clave sea el pri
    for (int i = 1; i < 2000000; i++) {
      platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 161));
    }

    for (const Platform& plat : platforms_) finder_platform_.add(&plat); // añadir la referencia de todas las plataformas a su respectivo finder

    for (const Life& life : lifes_) finder_life_.add(&life); // añadir la referncia de todas las vidas a su respectivo finder
}

void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) {
      finished_ = true;
      return;
    }
    if (window.was_key_pressed(Keys::P)) {
      pause_ = !pause_;
      return;
    }
}

void Game::update_objects(pro2::Window& window) {
  //poner aqui las teclas de los personajes
  mario_.update(window, platforms_);

  for (auto it = lifes_.begin(); it != lifes_.end(); ++it) {
    it->update(window, mario_, float_value);
    if (it->is_taken()) lifes_.erase(it);
  }
  if (float_value == float_max_min || float_value == -float_max_min) {
    float_interval = -(float_interval);
    float_value += float_interval;
  } else {
    float_value += float_interval;
  }
}

void Game::update_camera(pro2::Window& window) {
  const Pt pos = mario_.pos();
  const Pt cam = window.camera_center();

  const int left = cam.x - window.width() / 4;
  const int right = cam.x + window.width() / 4;
  const int top = cam.y - window.height() / 4;
  const int bottom = cam.y + window.height() / 4;

  int dx = 0, dy = 0;
  if (pos.x > right) {
    dx = pos.x - right;
  } else if (pos.x < left) {
    dx = pos.x - left;
  }
  if (pos.y < top) {
    dy = pos.y - top;
  } else if (pos.y > bottom) {
    dy = pos.y - bottom;
  }

  window.move_camera({dx, dy});
}

void Game::update(pro2::Window& window) {
  Pt center = window.camera_center();
  Rect visible_window = {
    center.x - window.width() /2,
    center.y - window.height() /2,
    center.x + window.width() /2,
    center.y + window.height() /2
  }; // objeto Rect con las dimensiones de la pantalla visible
  
  printed_platforms_ = finder_platform_.query(visible_window); // guardamos las plataformas que actualmente se ven por pantalla
  printed_lifes_ = finder_life_.query(visible_window); // guardamos las vidas que actualmente se ven por pantalla
  
  process_keys(window);
  if (!pause_) {
    update_objects(window);
    update_camera(window);
  }
}

void Game::paint(pro2::Window& window) {
  window.clear(sky_blue);

  for (const Platform* p : printed_platforms_) { // imprimimos por pantalla solo las plataformas que se ven
    p->paint(window);
  }

  for (const Life* l : printed_lifes_) { // imprimimos por pantalla solo las vidas que se ven
    if (!l->is_taken())
      l->paint(window);
  }

  mario_.paint(window);

  const Pt cam = window.camera_center();
  const int left = cam.x - window.width()/2;
  const int right = cam.x + window.width()/2;
  const int top = cam.y - window.height()/2;
  const int bottom = cam.y + window.height()/2;
  paint_hline(window, left, right-1, top);
  paint_hline(window, left, right-1, bottom-1);
  paint_vline(window, left, top, bottom-1);
  paint_vline(window, right-1, top, bottom-1);
}