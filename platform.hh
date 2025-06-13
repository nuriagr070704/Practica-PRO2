#ifndef PLATFORM_HH
#define PLATFORM_HH

#include <vector>
#include "goomba.hh"
#include "window.hh"

class Platform {
 private:
    int left_, right_, top_, bottom_;
    Goomba goomba_;

	static const std::vector<std::vector<int>> platform_texture_;

 public:
    Platform() : left_(0), right_(0), top_(0), bottom_(0), goomba_(pro2::Pt{0,0}) {}

    Platform(const Platform& other)
        : left_(other.left_),
        right_(other.right_),
        top_(other.top_),
        bottom_(other.bottom_),
        goomba_(other.goomba_) {}

    Platform(int left, int right, int top, int bottom)
        : left_(left), right_(right), top_(top), bottom_(bottom), goomba_(pro2::Pt{left, top}) {}

    void paint(pro2::Window& window) const;
    bool has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const;
    bool is_pt_inside(pro2::Pt pt) const;

    void update(pro2::Window& window);
    
    pro2::Pt get_goomba_pos() {
        return goomba_.pos();
    }

    void goomba_kills() {
        goomba_.add_fbk(20);
    }

    bool can_goomba_kill() {
        return goomba_.can_kill();
    }

    int top() const {
        return top_;
    }

    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }
};

#endif