#include <serenity/core.hpp>
#include <serenity/2d.hpp>

using namespace serenity::time;
using namespace serenity::math;

namespace serenity {
namespace twod {

auto Transform::screenPosition(Camera *cam) -> Vec2f {
    if(!cam) return _position;
    return _position - cam->findChild<Transform>()->_position;
}

void Transform::position(Vec2f newPos) {
	_history.push_back(_position);
	while(_history.size() > 20) _history.erase(_history.begin());
	_position = newPos;
}

void Transform::rollback() {
    if(_history.empty()) return;

    _position = _history.back();
    _history.pop_back();
}

void Transform::update(Sup *s) {
    auto t = dynamic_cast<TimerSystem*>(s);
    if(!t) return;

    translate(delta);
}

}
}
