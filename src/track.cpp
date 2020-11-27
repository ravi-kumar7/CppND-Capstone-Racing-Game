#include "track.h"

Track::Track(int screen_width, int screen_height, float increment) : GameObject(ObjectType::track, screen_width, screen_height, 0, 0, screen_width, screen_height)
{
  _trackSpeedIncrement = increment;
  speed = 5.0f;
}

void Track::UpdatePosition()
{
  if (pos_y > getScreenHeight())
  {
    pos_y = 0;
    speed += _trackSpeedIncrement;
  }
  pos_y += speed;
}