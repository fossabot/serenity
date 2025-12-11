#include <optional>
#include <string>
#include <serenity/core.hpp>
#include <serenity/graphics.hpp>
#include <serenity/2d.hpp>
#include <SDL3/SDL.h>

using namespace std;
using namespace serenity;
using namespace serenity::graphics;
using namespace serenity::math;

namespace serenity {
namespace twod {

Spritesheet::Spritesheet(serenity::Entity *e, const char *imageName, serenity::math::Vec2f imageSize)
    : Component(e)
    , _image(imageName)
    , _imageSize(imageSize)
{}

void Spritesheet::init(Sup *s) {
    auto r = dynamic_cast<Renderer*>(s);
    if(!r) return;
    auto p = r->findChild<Painter>();
	tex = p->loadImage(_image);
}

auto Spritesheet::name() -> optional<string> {
    return _image;
}

auto Spritesheet::load(serenity::math::Vec2i position) -> Sprite* {
    return new Sprite((Entity*)parent(), this, position * _imageSize, _imageSize);
}

}
}
