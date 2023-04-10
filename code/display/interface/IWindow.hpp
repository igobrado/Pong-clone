#ifndef IWINDOW_HPP
#define IWINDOW_HPP

#include <display/common/Common.hpp>
#include <display/interface/IGameObject.hpp>

namespace display
{

enum class BackendType
{
    kSdl,
    kOpengl
    // ...
};

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual bool initialize() = 0;

    virtual void clear(core::Color const& color) = 0;
    virtual void clear()                         = 0;

    virtual void draw(objects::IGameObject& object) = 0;
    virtual void commit()                           = 0;

    virtual BackendType getBackendType() = 0;
};

}  // namespace display

#endif  // !IWINDOW_HPP
