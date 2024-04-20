#pragma once

#include "raylib.h"

class Player
{
private:
    float mSpeed;
    bool mCanJump;

    Rectangle mRect;

public:
    Vector2 position;
    Player();
    ~Player();

    void Update(float delta);
    void Draw();
    void Unload();
};