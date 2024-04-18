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

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        mMainScreen->Update();
        BeginDrawing();
        mMainScreen->Draw();
        EndDrawing();
    }

    CloseWindow();
}