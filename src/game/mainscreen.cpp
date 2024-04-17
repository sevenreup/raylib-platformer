#include "mainscreen.h"

Mainscreen::Mainscreen(Vector2 dimension)
{
    mDimension = dimension;
    mCamera = {0};
    mCamera.target = (Vector2){0, 0};
    mCamera.offset = (Vector2){dimension.x / 2.0f, dimension.y / 2.0f};
    mCamera.rotation = 0.0f;
    mCamera.zoom = 1.0f;
}

Mainscreen::~Mainscreen()
{
}

void Mainscreen::Update()
{
}

void Mainscreen::Draw()
{
    ClearBackground(BLACK);
    BeginMode2D(mCamera);
    DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);
    DrawLine((int)mCamera.target.x, -mDimension.y * 10, (int)mCamera.target.x, mDimension.y * 10, GREEN);
    DrawLine(-mDimension.x * 10, (int)mCamera.target.y, mDimension.x * 10, (int)mCamera.target.y, GREEN);
    EndMode2D();

    DrawText("SCREEN AREA", 640, 10, 20, RED);

    DrawRectangle(0, 0, mDimension.x, 5, RED);
    DrawRectangle(0, 5, 5, mDimension.y - 10, RED);
    DrawRectangle(mDimension.x - 5, 5, 5, mDimension.y - 10, RED);
    DrawRectangle(0, mDimension.y - 5, mDimension.x, 5, RED);

    DrawRectangle(10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(10, 10, 250, 113, BLUE);

    DrawText("Free 2d camera controls:", 20, 20, 10, BLACK);
    DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY);
    DrawText("- A / S to Rotate", 40, 80, 10, DARKGRAY);
    DrawText("- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY);
}

void Mainscreen::Unload()
{
}