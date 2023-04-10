#include "Window.hpp"

#include <iostream>

#include <display/impl/Renderer.hpp>

namespace display
{

Window::Window(uint32_t const width, uint32_t const height)
    : event::WindowEventListener{ { event::EventType::kWindowClose, event::KeyCodes::kInvalid } }
    , mWindowHolder{ nullptr }
    , mWindowDefs{ width, height }
    , mShouldClose{ false }
{
}

bool Window::initialize()
{

    auto window = SDL_CreateWindow(
            "My application",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            mWindowDefs.mWidth,
            mWindowDefs.mHeight,
            SDL_WINDOW_SHOWN);

    if (!window)
    {
        std::cerr << "Could not create window " << SDL_GetError() << std::endl;
        return false;
    }

    mWindowHolder = std::make_unique<sdl_abstraction::SdlObjectHolder<SDL_Window*>>(window, SDL_DestroyWindow);
    mRenderer     = std::make_unique<Renderer>();

    return mRenderer->initialize(*this);
}

void Window::clear(core::Color const& color)
{
    mRenderer->clear(color);
}

void Window::clear()
{
    mRenderer->clear();
}

void Window::draw(objects::IGameObject& object)
{
    mRenderer->draw(object);
}

void Window::commit()
{
    mRenderer->commit();
}

bool Window::shouldClose()
{
    return mShouldClose;
}

BackendType Window::getBackendType()
{
    return BackendType::kSdl;
}

void Window::onCloseEvent()
{
    mShouldClose.store(true);
}

}  // namespace display