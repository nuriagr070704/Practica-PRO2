#include "game.hh"
#include "utils.hh"
using namespace pro2;

Game::Game(int width, int height, int platforms_num, int lifes_num)
    : mario_({width / 2, 150}, Keys::Left, Keys::Right, Keys::Up),
      platforms_{
          Platform(100, 300, 200, 211),
          Platform(0, 200, 250, 261),
          Platform(250, 400, 150, 161),
      },
      flag_({400, 127}, false),
      pause_(false),
      finished_(false),
      game_finished_(false),
      final_({300, 50}) {

    for (int i = 0; i < lifes_num; ++i) {
      int x = 230 + i * 100;
      int y = (i%2 == 0) ? 100 : (100 + 30);
      lifes_.push_back(Life({x, y}, false));
    }
    
    for (int i = 1; i < platforms_num; i++) platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 161));

    for (Platform& plat : platforms_) finder_platform_.add(&plat);

    for (Life& life : lifes_) finder_life_.add(&life);
}

void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) {
      finished_ = true;
      return;
    }
    if (!game_finished_ && window.was_key_pressed(Keys::P)) {
      pause_ = !pause_;
      return;
    }
}

void Game::update_objects(pro2::Window& window, Rect visible_window) {
  mario_.update(window, platforms_);
  if (mario_.get_lifes() == 0) {
    final_.has_won(false);
    game_finished_ = true;
    pause_ = true;
  }

  flag_.update(window, mario_);
  if (flag_.is_taken()) {
    final_.has_won(true);
    game_finished_ = true;
    pause_ = true;
  }

  printed_platforms_ = finder_platform_.query(visible_window);
  printed_lifes_ = finder_life_.query(visible_window);

  for (Platform* plat : printed_platforms_) plat->update(window);

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
  };
  
  process_keys(window);
  if (!pause_) {
    update_objects(window, visible_window);
    update_camera(window);
    
  }
}

void Game::paint(pro2::Window& window) {
  window.clear(sky_blue);

  flag_.paint(window);

  for (const Platform* p : printed_platforms_) p->paint(window);

  for (const Life* l : printed_lifes_) if (!l->is_taken()) l->paint(window);

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

  if (game_finished_) {
    final_.set_pt(window.camera_center());
    final_.paint(window);
  }
}