#pragma once

#include <SDL3/SDL.h>
#include <sup.hpp>
#include <serenity/graphics.hpp>

namespace serenity {
namespace twod {

class Painter : public Sup {
public:
	Painter(serenity::graphics::Renderer *);

	auto loadImage(const char *path) -> SDL_Texture*;
	auto rectangle(float x, float y, float w, float h) -> SDL_FRect;

	void draw(SDL_Texture*, const SDL_FRect*);
};

}
}