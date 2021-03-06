#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Road Racing Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  //Surface Initialization
  sdl_surface = SDL_LoadBMP("../img/bg.bmp");
  sdl_player_surface = SDL_LoadBMP("../img/Black_viper.bmp");
  sdl_truck_surface = SDL_LoadBMP("../img/Mini_truck.bmp");
  sdl_van_surface = SDL_LoadBMP("../img/Mini_van.bmp");
  sdl_car_surface = SDL_LoadBMP("../img/Car.bmp");
  sdl_taxi_surface = SDL_LoadBMP("../img/taxi.bmp");
  sdl_ambulance_surface = SDL_LoadBMP("../img/ambulance.bmp");
  sdl_audi_surface = SDL_LoadBMP("../img/audi.bmp");
  sdl_bigtruck_surface = SDL_LoadBMP("../img/truck.bmp");
  sdl_track_surface = SDL_LoadBMP("../img/road.bmp");
  sdl_gameover_surface = SDL_LoadBMP("../img/gameover.bmp");

  //Texture initialization
  sdl_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_surface);
  sdl_player_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_player_surface);
  sdl_truck_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_truck_surface);
  sdl_van_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_van_surface);
  sdl_car_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_car_surface);
  sdl_taxi_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_taxi_surface);
  sdl_ambulance_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_ambulance_surface);
  sdl_audi_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_audi_surface);
  sdl_bigtruck_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_bigtruck_surface);
  sdl_track_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_track_surface);
  sdl_gameover_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_gameover_surface);
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Player const player, Track const track, std::deque<std::shared_ptr<Vehicle>> const &vehicles)
{
  SDL_Rect block;
  // Clear screen
  //SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
  SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);

  //Render Track
  block.h = track.getHeight();
  block.w = track.getWidth();
  block.x = static_cast<int>(track.pos_x);
  block.y = static_cast<int>(track.pos_y);
  SDL_RenderCopy(sdl_renderer, sdl_track_texture, NULL, &block);
  block.x = static_cast<int>(track.pos_x);
  block.y = static_cast<int>(track.pos_y - track.getScreenHeight());
  SDL_RenderCopy(sdl_renderer, sdl_track_texture, NULL, &block);

  //Render traffic vehicles
  for (auto vehicle : vehicles)
  {
    block.h = vehicle->getHeight();
    block.w = vehicle->getWidth();
    block.x = static_cast<int>(vehicle->pos_x);
    block.y = static_cast<int>(vehicle->pos_y);
    switch (vehicle->getVehicleType())
    {
    case Vehicle::VehicleType::Truck:
      SDL_RenderCopy(sdl_renderer, sdl_truck_texture, NULL, &block);
      break;
    case Vehicle::VehicleType::Van:
      SDL_RenderCopy(sdl_renderer, sdl_van_texture, NULL, &block);
      break;
    case Vehicle::VehicleType::Taxi:
      SDL_RenderCopy(sdl_renderer, sdl_taxi_texture, NULL, &block);
      break;
    case Vehicle::VehicleType::Car:
      SDL_RenderCopy(sdl_renderer, sdl_car_texture, NULL, &block);
      break;
    case Vehicle::VehicleType::Ambulance:
      SDL_RenderCopy(sdl_renderer, sdl_ambulance_texture, NULL, &block);
      break;
    case Vehicle::VehicleType::Audi:
      SDL_RenderCopy(sdl_renderer, sdl_audi_texture, NULL, &block);
      break;
    case Vehicle::VehicleType::BigTruck:
      SDL_RenderCopy(sdl_renderer, sdl_bigtruck_texture, NULL, &block);
      break;
    default:
      break;
    }
  }
  //Render Player
  block.h = player.getHeight();
  block.w = player.getWidth();
  block.x = static_cast<int>(player.pos_x);
  block.y = static_cast<int>(player.pos_y);
  SDL_RenderCopy(sdl_renderer, sdl_player_texture, NULL, &block);

  if (!player.alive)
  {
    //Render Game Over Banner
    block.h = 60;
    block.w = 300;
    block.y = 200;
    block.x = screen_width / 2 - 150;
    SDL_RenderCopy(sdl_renderer, sdl_gameover_texture, NULL, &block);
  }
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps)
{
  std::string title{"Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
