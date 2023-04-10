#include <SDL.h>

#include <display/impl/Rectangle.hpp>
#include <display/impl/Window.hpp>
#include <game/Player.hpp>
#include <game/Pong.hpp>
#include <io/EventObserver.hpp>

int main(int argc, char* argv[])
{
    Pong p;
    p.run();

    return 0;
}
