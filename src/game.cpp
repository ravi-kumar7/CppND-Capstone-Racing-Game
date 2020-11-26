#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t screen_width, std::size_t screen_height)
    : 
      player(screen_width,screen_height,screen_width/2,screen_height+100, 50, 97),
      track(420,640),
      _traffic_generator(screen_width,screen_height),
      engine(dev()),
      random_w(0, static_cast<int>(screen_width)),
      random_h(0, static_cast<int>(screen_height)) {
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, player);
    Update();
    renderer.Render(player, track, _traffic_generator.vehicles);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceEnemy() {
  int x, y;

  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    break;
  }
}

void Game::Update() {
  if (!player.alive) return;
  player.Update();
  track.Update();
  _traffic_generator.GenerateVehicle();
  for(auto vehicle: _traffic_generator.vehicles)
  {
    vehicle->Update();
    if(vehicle->pos_y - 200 > vehicle->getScreenHeight()){
        vehicle ->pos_y=0;
        _traffic_generator.vehicles.pop_front();
    }
    if(vehicle->CheckCollision(player)){
      player.alive = false;
      break;
    }
  }
}

int Game::GetScore() const { return score; }