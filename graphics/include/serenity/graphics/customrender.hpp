#pragma once
#include <serenity/core.hpp>
#include <functional>

namespace serenity {
namespace graphics {
class Renderer;

using CustomRender = serenity::Passthrough<Renderer>;

}
}