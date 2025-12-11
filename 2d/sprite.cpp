#include <serenity/core.hpp>
#include <serenity/graphics.hpp>
#include <serenity/2d.hpp>
#include <SDL3/SDL.h>

using namespace serenity;
using namespace serenity::graphics;
using namespace serenity::math;

namespace serenity {
namespace twod {

Sprite::Sprite(Entity *e, Spritesheet *sheet, Vec2f position, Vec2f size)
    : Component(e)
    , _sheet(sheet)
    , _pos(position)
    , _size(size)
    {}

void Sprite::update(Sup *s) {
    auto r = dynamic_cast<Renderer*>(s);
    if(!r) return;

    auto p = r->findChild<Painter>();
    auto tr = getComponent<Transform>();

    auto src = rectangle(_pos, _size);
	auto target = rectangle(tr->screenPosition(), _size);
	if(_sheet->tex) p->draw(_sheet->tex, &src, &target);
}

Sprite *Sprite::load(serenity::Entity *e, const char *imageName, serenity::math::Vec2f size) {
    auto sheet = e->findChild<Spritesheet>(imageName);
    if(!sheet) sheet = new Spritesheet(e, imageName, size);

    return sheet->load(e, vec2(0, 0));
}

}
}
