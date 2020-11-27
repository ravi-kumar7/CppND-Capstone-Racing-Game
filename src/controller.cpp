#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "player.h"

void Controller::HandleInput(bool &running, Player &player) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
      case SDLK_LEFT:
        player.direction = GameObject::Direction::kLeft;
        break;
      case SDLK_RIGHT:
        player.direction = GameObject::Direction::kRight;
        break;
      }
    }
  }
}