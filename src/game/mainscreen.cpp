#include "mainscreen.h"

Mainscreen::Mainscreen(Vector2 dimension)
{
    player = {400, 280, 40, 40};

    mDimension = dimension;
    mCamera = {0};
    mCamera.target = (Vector2){player.x + 20.0f, player.y + 20.0f};
    mCamera.offset = (Vector2){dimension.x / 2.0f, dimension.y / 2.0f};
    mCamera.rotation = 0.0f;
    mCamera.zoom = 1.0f;

    int spacing = 0;

    for (int i = 0; i < MAX_BUILDINGS; i++)
    {
        buildings[i].width = (float)GetRandomValue(50, 200);
        buildings[i].height = (float)GetRandomValue(100, 800);
        buildings[i].y = dimension.y - 130.0f - buildings[i].height;
        buildings[i].x = -6000.0f + spacing;

        spacing += (int)buildings[i].width;

        buildColors[i] = (Color){GetRandomValue(200, 240), GetRandomValue(200, 240), GetRandomValue(200, 250), 255};
    }
    // print the number of buildings
    fmt::print("Number of buildings: {}\n", MAX_BUILDINGS);
}

Mainscreen::~Mainscreen()
{
}

void Mainscreen::Update()
{
    if (IsKeyDown(KEY_RIGHT))
        player.x += 2;
    else if (IsKeyDown(KEY_LEFT))
        player.x -= 2;

    // Camera target follows player
    mCamera.target = (Vector2){player.x + 20, player.y + 20};

    // Camera rotation controls
    if (IsKeyDown(KEY_A))
        mCamera.rotation--;
    else if (IsKeyDown(KEY_S))
        mCamera.rotation++;

    // Limit camera rotation to 80 degrees (-40 to 40)
    if (mCamera.rotation > 40)
        mCamera.rotation = 40;
    else if (mCamera.rotation < -40)
        mCamera.rotation = -40;

    // Camera zoom controls
    mCamera.zoom += ((float)GetMouseWheelMove() * 0.05f);

    if (mCamera.zoom > 3.0f)
        mCamera.zoom = 3.0f;
    else if (mCamera.zoom < 0.1f)
        mCamera.zoom = 0.1f;

    // Camera reset (zoom and rotation)
    if (IsKeyPressed(KEY_R))
    {
        mCamera.zoom = 1.0f;
        mCamera.rotation = 0.0f;
    }
}

void Mainscreen::Draw()
{
    ClearBackground(RAYWHITE);
    BeginMode2D(mCamera);
    DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);

    for (int i = 0; i < MAX_BUILDINGS; i++)
        DrawRectangleRec(buildings[i], buildColors[i]);

    DrawRectangleRec(player, RED);

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