#include "track.h"

Track:: Track(int screen_width, int screen_height) : GameObject(ObjectType::track,screen_width, screen_height,0,0, screen_width, screen_height)
 {  
  speed =3.0f;
 }

 void Track::UpdatePosition() {
  if(pos_y > getScreenHeight())
      pos_y =0;
  pos_y += speed;
}