#include <fmt/core.h>
#include "raylib.h"
#include "game/game.h"

int main()
{
    Game game = Game();
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    fmt::print("Hello World!\n");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}