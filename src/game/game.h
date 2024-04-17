#pragma once

#include "raylib.h"
#include "core/scene.h"

class Game
{
private:
    Vector2 mDimension;
    Scene *mMainScreen;
    void _gameLoop();

public:
    Game(float screenWidth, float screenHeight);
    ~Game();

    void Run();
};