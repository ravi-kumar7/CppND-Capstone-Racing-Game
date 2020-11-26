#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle(VehicleType type,int screen_width, int screen_height, int x, int y, int width, int height)
: GameObject(ObjectType::vehicle,screen_width, screen_height, x,y, width, height){
_type = type;
speed = 1.0f; 

}

bool Vehicle::CheckCollision(Player &player){
  if(pos_y - 100 == getScreenHeight())
    return false;
  int width = player.pos_x + player.getWidth();
  int vehicleWidth = pos_x + getWidth();
  return (pos_y + getHeight())> player.pos_y  && ((pos_x < player.pos_x && player.pos_x <vehicleWidth  ) || (pos_x < width && width <  vehicleWidth) || pos_x == player.pos_x || vehicleWidth == width);
}

void Vehicle::UpdatePosition(){
  this->pos_y += speed;
}