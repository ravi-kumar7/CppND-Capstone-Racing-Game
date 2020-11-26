#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <random>
#include "SDL.h"

enum ObjectType
{
  object,
  player,
  vehicle,
  track
};

class GameObject {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight, kNone };
  GameObject(ObjectType objectType,int screen_width, int screen_height, int posx, int posy, int width, int height)
      : object_Type(objectType),
        _screen_width(screen_width),
        _screen_height(screen_height),
        _width(width),
        _height(height),
        pos_x(posx),
        pos_y(posy){
         
        }
  ObjectType getType()const  { return object_Type; }
  int getScreenWidth() const {return _screen_width;}
  int getScreenHeight() const {return _screen_height;}
  int getWidth() const {return _width;}
  int getHeight() const {return _height;}
  Direction direction = Direction::kNone;
  void Update();
  float speed{0.1f};
  float pos_x;
  float pos_y;
  

 private:
  virtual void UpdatePosition();
  ObjectType object_Type;
  int _screen_width;
  int _screen_height;
  int _height;
  int _width;
};

#endif