#pragma once

#include "core/scene.h"
#include "raylib.h"
#include <fmt/core.h>

#define MAX_BUILDINGS 100

class Mainscreen : public Scene
{
private:
    Vector2 mDimension;
    Camera2D mCamera;
    Rectangle player;
    Rectangle buildings[MAX_BUILDINGS] = {0};
    Color buildColors[MAX_BUILDINGS] = {0};

public:
    Mainscreen(Vector2 dimension);
    ~Mainscreen();

    void Update();
    void Draw();
    void Unload();
};
