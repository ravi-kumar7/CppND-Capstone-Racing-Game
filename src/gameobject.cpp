#include "gameobject.h"
#include <cmath>
#include <iostream>

void GameObject::Update() {
  UpdatePosition();
}

void GameObject::UpdatePosition() {
  switch (direction) {
    case Direction::kUp:
      pos_y -= speed;
      break;

    case Direction::kDown:
      pos_y += speed;
      break;

    case Direction::kLeft:
      pos_x -= speed;
      break;

    case Direction::kRight:
      pos_x += speed;
      break;
    
    case Direction::kNone:
      break;
  }
  
}

