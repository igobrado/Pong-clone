#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL.h>

#include <functional>
#include <memory>

#include <display/common/Common.hpp>
#include <display/interface/IRenderer.hpp>
#include <display/interface/IWindow.hpp>
#include <io/WindowEventListener.hpp>

namespace display
{

class Window
    : public IWindow
    , public event::WindowEventListener
{
public:
    friend class Renderer;

    Window(uint32_t const width, uint32_t const height);
    bool initialize() override;

    void clear(core::Color const& color) override;
    void clear() override;

    void draw(objects::IGameObject& object) override;
    void commit() override;

    bool        shouldClose();
    BackendType getBackendType() override;

protected:
    void onCloseEvent() override;

private:
    struct WindowSize
    {
        uint32_t mWidth, mHeight;
    } mWindowDefs;

    std::unique_ptr<sdl_abstraction::SdlObjectHolder<SDL_Window*>> mWindowHolder;
    std::unique_ptr<IRenderer>                                     mRenderer;
    std::atomic_bool                                               mShouldClose;
};

}  // namespace display

#endif  // !IWINDOW_HPP
