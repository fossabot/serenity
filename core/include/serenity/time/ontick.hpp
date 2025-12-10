#pragma once
#include <serenity/component.hpp>
#include <serenity/passthrough.hpp>
#include <functional>

namespace serenity {
namespace time {
class TimerSystem;

using OnTick = serenity::Passthrough<TimerSystem>;

}
}