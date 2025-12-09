#include <iostream>

#include <serenity/core.hpp>
#include <serenity/2d.hpp>

using namespace std;
using namespace std::chrono;
using namespace serenity;
using namespace serenity::time;
using namespace serenity::d2;

int main() {
    Game g;

    new OnTick(new Entity(&g, "ticker"), OnTick::none, [](TimerSystem *t) {
        cout << "Frame: "
             << t->delta().count()
             << "ms\n";
    });

    SDL_Surface *bmp;
    SDL_Texture *tex;

    new CustomRender(new Entity(&g, "lettuce"), [&](Renderer *r) {
        bmp = SDL_LoadBMP(LETTUCE_PATH);
        if(!bmp) {
            throw 1;
        }

        tex = SDL_CreateTextureFromSurface(r->renderer(), bmp);
        SDL_DestroySurface(bmp);
        if(!tex) {
            throw 1;
        }

        r->manage([&tex](){SDL_DestroyTexture(tex);});
    }, [&](Renderer *r) {
        SDL_RenderTexture(r->renderer(), tex, NULL, NULL);
    });

    (new TimerSystem(&g))->start<1>();

    (new Renderer(&g, "Serenity Example"))->run();

    g.findChild<TimerSystem>()->stop();

    return 0;
}
