#include "Renderer.hpp"

#include <iostream>

#include <display/impl/Window.hpp>

namespace display
{

bool Renderer::initialize(IWindow& window)
{
    if (window.getBackendType() != BackendType::kSdl)
    {
        return false;
    }

    auto sdlWindow = static_cast<Window&>(window).mWindowHolder->object;
    auto renderer  = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cerr << "Could not create renderer " << SDL_GetError() << std::endl;
        return false;
    }

    mRendererHolder = std::make_unique<sdl_abstraction::SdlObjectHolder<SDL_Renderer*>>(renderer, SDL_DestroyRenderer);

    return true;
}

void Renderer::clear(core::Color const& color)
{
    SDL_SetRenderDrawColor(
            *mRendererHolder,
            static_cast<Uint8>(color.r),
            static_cast<Uint8>(color.g),
            static_cast<Uint8>(color.g),
            static_cast<Uint8>(color.a));

    clear();
}

void Renderer::clear()
{
    SDL_RenderClear(*mRendererHolder);
}

void Renderer::applyColor(core::Color const& color)
{
    SDL_SetRenderDrawColor(*mRendererHolder, color.r, color.g, color.b, color.a);
}

void Renderer::draw(objects::IGameObject& gameObject)
{
    auto objectType = gameObject.getObjectType();
    switch (::objects::ObjectType::kRectangle)
    {
        case objects::ObjectType::kRectangle:
            drawRect(gameObject);
            break;
        case objects::ObjectType::kCircle:
            // assert
            return;
        default:
            return;
    }
}

void Renderer::drawRect(objects::IGameObject& gameObject)
{
    auto const& color      = gameObject.getColor();
    auto const& position   = gameObject.getPosition();
    auto const& dimensions = gameObject.getDimension();

    SDL_Rect rect{ .x = static_cast<int>(position.x),
                   .y = static_cast<int>(position.y),
                   .w = static_cast<int>(dimensions.width),
                   .h = static_cast<int>(dimensions.height) };

    applyColor(color);

    SDL_RenderFillRect(*mRendererHolder, &rect);
}

void Renderer::commit()
{
    SDL_RenderPresent(*mRendererHolder);
}

}  // namespace display