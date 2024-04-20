#include "game/game.h"

int main()
{
    const float screenWidth = 800;
    const float screenHeight = 450;
    Game game = Game(screenWidth, screenHeight);
    game.Run();
    return 0;
}