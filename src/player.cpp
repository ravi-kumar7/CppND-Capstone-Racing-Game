
#include "player.h"
#include <cmath>
#include <iostream>

Player::Player(int screen_width, int screen_height, int x, int y, int width, int height) : GameObject(ObjectType::player, screen_width, screen_height, x, y, width, height)
{
  speed = 15.0f;
}

void Player::UpdatePosition()
{
  switch (direction)
  {
  case Direction::kLeft:
    if ((pos_x - speed) >= 0)
    {
      this->pos_x -= speed;
    }
    else
    {
      this->pos_x = 0;
    }
    direction = Direction::kNone;
    break;

  case Direction::kRight:
  {
    // rightLimit is calculated by subtracting vehicle width from total screen width
    int rightLimit = getScreenWidth() - getWidth();
    if ((pos_x + speed) < rightLimit)
    {
      this->pos_x += speed;
    }
    else
    {
      this->pos_x = rightLimit;
    }
    direction = Direction::kNone;
    break;
  }
  case Direction::kNone:
    break;
  }
}
