#ifndef TRACK_H
#define TRACK_H
#include "gameobject.h"

class Track: public GameObject{
    
    public:
    Track(int screen_width, int screen_height);

    private:
    void UpdatePosition() override;
};

#endif