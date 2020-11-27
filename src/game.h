#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "player.h"
#include "track.h"
#include "vehicle.h"
#include "trafficgenerator.h"

class Game {
 public:
  Game(std::size_t screen_width, std::size_t screen_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
 private:
  Player player;
  Track track;
  TrafficGenerator _traffic_generator;

  int score{0};
  void Update();
};

#endif