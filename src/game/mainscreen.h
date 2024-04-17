#pragma once

#include "core/scene.h"
#include "raylib.h"

class Mainscreen : public Scene
{
    private:
    Vector2 mDimension;
    Camera2D mCamera;
public:
    Mainscreen(Vector2 dimension);
    ~Mainscreen();

    void Update();
    void Draw();
    void Unload();
};
