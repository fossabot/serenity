#include <serenity/2d/painter.hpp>

using namespace serenity;
using namespace serenity::graphics;

namespace serenity::twod {

Painter::Painter(Renderer *r)
    : Sup(r)
{}

auto Painter::loadImage(const char *path) -> SDL_Texture* {
    auto surface = SDL_LoadBMP(path);
    if(!surface) return nullptr;
    auto tex = SDL_CreateTextureFromSurface(dynamic_cast<Renderer*>(parent())->renderer(), surface);
    SDL_DestroySurface(surface);
    manage([&](){SDL_DestroyTexture(tex);});
    return tex;
}

auto Painter::rectangle(float x, float y, float w, float h) -> SDL_FRect {
    SDL_FRect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    return rect;
}

void Painter::draw(SDL_Texture* tex, const SDL_FRect *dest) {
    auto r = dynamic_cast<Renderer*>(parent());
    if(!r) return;
    SDL_RenderTexture(r->renderer(), tex, nullptr, dest);
}


}
