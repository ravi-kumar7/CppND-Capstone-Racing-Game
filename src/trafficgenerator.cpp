#include "trafficgenerator.h"

TrafficGenerator::TrafficGenerator(int screen_width, int screen_height){
    _truck = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Truck,screen_width,screen_height,0,0,55,110));
    _van = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Van,screen_width,screen_height,0,0,60,110));
    _taxi = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Taxi,screen_width,screen_height,0,0,50,77));
    _car = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Car,screen_width,screen_height,0,0,45,80));
    _vehicle_dist = std::uniform_int_distribution<int>(1,4);
    _pos_dist = std::uniform_int_distribution<int>(1,screen_height);
    _rng = std::mt19937(_rd());
    _lastVehicleTime = std::chrono::system_clock::now();
}

void TrafficGenerator::GenerateVehicle(){
    int vehicleIndex = _vehicle_dist(_rng);
    int vehicle_pos = _pos_dist(_rng);
    long timeSinceLastSwitch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - _lastVehicleTime).count();
    if(timeSinceLastSwitch < 2000)
       return;
    std::cout<<vehicleIndex <<" " << vehicle_pos <<std::endl;
    switch (vehicleIndex)
    {
    case 1:
        _truck->pos_x = vehicle_pos; 
        vehicles.push_back(_truck);
        break;
    case 2:
        _car->pos_x = vehicle_pos;
        vehicles.push_back(_car);
        break;
    case 3:
        _van->pos_x = vehicle_pos;
        vehicles.push_back(_van);
        break;
    case 4:
        _taxi->pos_x = vehicle_pos;
        vehicles.push_back(_taxi);
        break;
    }
    _lastVehicleTime = std::chrono::system_clock::now();
}


