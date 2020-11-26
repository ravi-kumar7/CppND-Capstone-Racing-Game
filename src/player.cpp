
#include "player.h"
#include <cmath>
#include <iostream>

 Player:: Player(int screen_width, int screen_height, int x, int y, int width, int height) : GameObject(ObjectType::player,screen_width, screen_height, x,y, width, height)
 {  
  speed =10.0f;
 }


 void Player::UpdatePosition() {
  switch (direction) {
    case Direction::kLeft:
      if((pos_x - speed)>=0)
      {
      this->pos_x -= speed;
      }
       else
      {
      this->pos_x=0;
      }
      direction= Direction::kNone;
      break;

    case Direction::kRight:
      if((pos_x + speed)<getScreenWidth()-50)
      {
      this->pos_x += speed;
      }
      else
      {
      this->pos_x=getScreenWidth()-50;
      }
      direction= Direction::kNone;
      break;
    
    case Direction::kNone:
      break;
  }
  
}
      