#ifndef VEHICLE_H
#define VEHICLE_H
#include "gameobject.h"
#include "player.h"

class Vehicle: public GameObject{
    public:
    enum class VehicleType{
        Truck,
        Van,
        Taxi,
        Car,
        Ambulance,
        Audi,
        BigTruck
    };
    Vehicle(VehicleType type,int screen_width, int screen_height, int x, int y, int width, int height);
    VehicleType getVehicleType(){return _type;};
    bool CheckCollision(Player &player);
    private:
    void UpdatePosition() override;
    VehicleType _type;
};

#endif