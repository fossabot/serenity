#pragma once
#include <serenity/core.hpp>
#include <serenity/2d.hpp>
#include <serenity/input.hpp>
#include <iostream>

using namespace std;
using namespace serenity;
using namespace serenity::math;
using namespace serenity::time;
using namespace serenity::graphics;
using namespace serenity::twod;
using namespace serenity::input;

class Player : public Entity {
	float speed = 4;
public:
	Player(Game *g, Spritesheet *sprites) : Entity(g, "smiley") {
		auto tr = new Transform(this);
		new OnTick(this, OnTick::none, [this, tr](TimerSystem *) {
			auto k = keyboard::state();

			if(k[SDL_SCANCODE_W]) tr->translate(0, -speed);
			if(k[SDL_SCANCODE_A]) tr->translate(-speed, 0);
			if(k[SDL_SCANCODE_S]) tr->translate(0, speed);
			if(k[SDL_SCANCODE_D]) tr->translate(speed, 0);

			if(k[SDL_SCANCODE_Q]) findParent<Game>()->findChild<Renderer>()->quit();
	    	});

	    	sprites->load(this, vec2(0, 5));
	}
};