#ifndef IRENDERER_HPP
#define IRENDERER_HPP

#include <SDL.h>

#include <display/common/Common.hpp>
#include <display/interface/IGameObject.hpp>
#include <display/interface/IWindow.hpp>

namespace display
{

class IRenderer
{
public:
    virtual ~IRenderer() = default;

    virtual bool initialize(IWindow& window) = 0;

    virtual void clear(core::Color const& color)      = 0;
    virtual void clear()                              = 0;
    virtual void applyColor(core::Color const& color) = 0;

    virtual void draw(objects::IGameObject& gameObject) = 0;
    virtual void commit()                               = 0;
};

}  // namespace display

#endif  // !IRENDERER_HPP
