#include <serenity/core.hpp>
#include <serenity/2d.hpp>

using namespace serenity;
using serenity::time::TimerSystem;
using namespace serenity::math;

namespace serenity {
namespace twod {

void CollisionBox::init(Sup *) {
    if(!_size) {
        auto sp = getComponent<Sprite>();
        if(!sp) return;

        _size = sp->size();
    }
}
void CollisionBox::update(Sup *s) {
    if(mode == Movable) {
        auto t = dynamic_cast<TimerSystem*>(s);
        if(!t) return;

        auto tr = getComponent<Transform>();
        if(!tr) return;

        for(auto box : findParent<Game>()->children<CollisionBox>(true)) {
            if(box != this && box->mode != PassThrough && box->mode != DoNotAvoid && overlaps(box)) {
                while(overlaps(box)) tr->rollback();
            }
        }
    }
}

auto CollisionBox::rect() -> Vec4f {
    auto tr = getComponent<Transform>();
    if(!tr || !_size) return vec4(0, 0, 0, 0);
    return vec4(tr->position(), *_size);
}

bool CollisionBox::hasCollision() {
    auto g = findParent<Game>();
    auto boxes = g->children<CollisionBox>(true);

    for(auto box : boxes) {
        if(box != this && box->mode != PassThrough && overlaps(box)) {
            return true;
        }
    }

    return false;
}

bool CollisionBox::overlaps(Vec2f point) {
    return collision::overlaps(rect(), vec4(point, vec2<float>(0, 0)));
}
bool CollisionBox::overlaps(CollisionBox* other) {
    return collision::overlaps(rect(), other->rect());
}

}
}
