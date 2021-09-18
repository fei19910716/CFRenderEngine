#pragma once

#include "Systems/Base/System.h"
#include "Components/Primitive/Triangle.h"

CFENGINE_RENDER_START
class TriangleSystem : public System{
public:

    TriangleSystem();

    std::shared_ptr<Renderer> update(entt::registry &registry, float dt) override;

private:
    QString vertexShader_ = ":/shader/primitive/primitive.vert";

    QString fragmentShader_ = ":/shader/primitive/primitive.frag";
};
CFENGINE_RENDER_END
