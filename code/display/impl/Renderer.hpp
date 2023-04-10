#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL.h>

#include <memory>

#include <display/common/Common.hpp>
#include <display/interface/IRenderer.hpp>

namespace display
{

class Renderer : public IRenderer
{
public:
    bool initialize(IWindow& window) override;

    void clear(core::Color const& color) override;
    void clear() override;
    void applyColor(core::Color const& color) override;

    void draw(objects::IGameObject& gameObject) override;
    void commit() override;

protected:
    void drawRect(objects::IGameObject& gameObject);

private:
    std::unique_ptr<sdl_abstraction::SdlObjectHolder<SDL_Renderer*>> mRendererHolder;
};

}  // namespace display
#endif  // RENDERER_HPP