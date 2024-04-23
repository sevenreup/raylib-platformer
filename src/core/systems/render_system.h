#pragma once

#include <core/components/renderable.h>
#include <core/models.h>
#include <core/coordinator.h>

class RenderSystem : public System
{
private:
    /* data */
public:
    void Init();

    void Update(float dt);
};