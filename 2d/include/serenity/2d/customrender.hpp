#pragma once
#include <serenity/core.hpp>
#include <functional>

namespace serenity {
namespace d2 {
class Renderer;

using CustomRender = serenity::Passthrough<Renderer>;

}
}