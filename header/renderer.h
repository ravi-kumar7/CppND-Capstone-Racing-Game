#ifndef RENDERER_H
#define RENDERER_H

#include <memory>
#include <deque>
#include "SDL.h"
#include "player.h"
#include "track.h"
#include "vehicle.h"

class Renderer
{
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(Player const player, Track const track, std::deque<std::shared_ptr<Vehicle>> const &vehicles);
  void UpdateWindowTitle(int score, int fps);

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  SDL_Surface *sdl_surface;
  SDL_Surface *sdl_player_surface;
  SDL_Surface *sdl_player_dead_surface;
  SDL_Surface *sdl_truck_surface;
  SDL_Surface *sdl_van_surface;
  SDL_Surface *sdl_taxi_surface;
  SDL_Surface *sdl_car_surface;
  SDL_Surface *sdl_ambulance_surface;
  SDL_Surface *sdl_audi_surface;
  SDL_Surface *sdl_bigtruck_surface;
  SDL_Surface *sdl_track_surface;
  SDL_Surface *sdl_gameover_surface;

  SDL_Texture *sdl_texture;
  SDL_Texture *sdl_player_texture;
  SDL_Texture *sdl_player_dead_texture;
  SDL_Texture *sdl_truck_texture;
  SDL_Texture *sdl_van_texture;
  SDL_Texture *sdl_car_texture;
  SDL_Texture *sdl_taxi_texture;
  SDL_Texture *sdl_ambulance_texture;
  SDL_Texture *sdl_audi_texture;
  SDL_Texture *sdl_bigtruck_texture;
  SDL_Texture *sdl_track_texture;
  SDL_Texture *sdl_gameover_texture;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif