#include "player.h"

#define G 400
#define PLAYER_JUMP_SPD 350.0f
#define PLAYER_HOR_SPD 200.0f

Player::Player(/* args */)
{
    position = (Vector2){400, 280};
    mSpeed = 0;
    mCanJump = false;
    mRect = {position.x, position.y, 40, 40};
}

Player::~Player()
{
}

void Player::Update(float delta)
{
    if (IsKeyDown(KEY_LEFT))
        position.x -= PLAYER_HOR_SPD * delta;
    if (IsKeyDown(KEY_RIGHT))
        position.x += PLAYER_HOR_SPD * delta;
    if (IsKeyDown(KEY_SPACE) && mCanJump)
    {
        mSpeed = -PLAYER_JUMP_SPD;
        mCanJump = false;
    }
}

void Player::Draw()
{
    Rectangle playerRect = {position.x - 20, position.y - 40, 40, 40};
    DrawRectangleRec(playerRect, RED);
}

void Player::Unload()
{
    // Unload player resources
}
