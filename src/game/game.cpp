#include "game.h"
#include "mainscreen.h"
#include <fmt/core.h>

Game::Game(float screenWidth, float screenHeight)
{
    mDimension = (Vector2){screenWidth, screenHeight};
    mMainScreen = new Mainscreen(mDimension);
}

Game::~Game()
{
    delete mMainScreen;
}

void Game::Run()
{
    _gameLoop();
}

void Game::_gameLoop()
{
    InitWindow(mDimension.x, mDimension.y, "raylib [core] example - basic screen manager");

    fmt::print("Hello World!\n");

    while (!WindowShouldClose())
    {
        mMainScreen->Update();
        BeginDrawing();
        ClearBackground(LIME);
        mMainScreen->Draw();
        EndDrawing();
    }

    CloseWindow();
}