#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "gameobject.h"

class Player:public GameObject {
 public:

  Player(int screen_width, int screen_height,int x, int y, int width, int height);
  bool alive{true};

 private:
  void UpdatePosition() override;
};

#endif