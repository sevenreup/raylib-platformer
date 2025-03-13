#pragma once

#include "raylib.h"
#include "core/scene.h"
#include "mainscreen.h"
#include <fmt/core.h>
#include "core/coordinator.h"
#include <random>
#include <chrono>

#include "core/systems/physics_system.h"
#include "core/systems/render_system.h"

#include "core/components/camera.h"

class Game
{
private:
    Vector2 mDimension;
    Scene *mMainScreen;

public:
    Game(float screenWidth, float screenHeight);
    ~Game();

    void Run();
};