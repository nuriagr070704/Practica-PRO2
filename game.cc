#include "game.hh"
#include "utils.hh"
using namespace pro2;

Game::Game(int width, int height)
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
    for (int i = 1; i < 20; i++) {
      platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 161));
    }
}

void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) { //si se ha pulsado alguna vez
      finished_ = true;
      return;
    }
    if (window.was_key_pressed(Keys::P)) { //si es el que se ha pulsado
      pause_ = !pause_;
      return;
    }
}

void Game::update_objects(pro2::Window& window) {
  //poner aqui las teclas de los personajes
  mario_.update(window, platforms_);

  for (Life& l : lifes_) {
    if (!l.is_taken()) {
      l.update(window, mario_, float_value);
    }
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
  process_keys(window);
  if (!pause_) {
    update_objects(window);
    update_camera(window);
  }
}

void Game::paint(pro2::Window& window) {
  window.clear(sky_blue);

  for (const Platform& p : platforms_) {
    p.paint(window);
  }

  for (Life& l : lifes_) {
    if (!l.is_taken())
      l.paint(window);
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