#pragma once

#include "raylib.h"
#include "core/scene.h"
#include "mainscreen.h"
#include <fmt/core.h>
#include "core/coordinator.h"
#include "core/components.h"
#include <random>
#include <chrono>

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