#include "trafficgenerator.h"

TrafficGenerator::TrafficGenerator(int screen_width, int screen_height, long delay)
{
    this->screen_height = screen_height;
    this->screen_width = screen_width;
    _vehicle_dist = std::uniform_int_distribution<int>(1, 7);
    _pos_dist = std::uniform_int_distribution<int>(1, 3);
    _rng = std::mt19937(_rd());
    _lastVehicleTime = std::chrono::system_clock::now();
    _delay = delay;
}

void TrafficGenerator::GenerateVehicle()
{
    long timeSinceLastSwitch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - _lastVehicleTime).count();
    if (timeSinceLastSwitch < _delay)
        return;
    int vehicleIndex = _vehicle_dist(_rng);
    while(vehicleIndex==prevVehicleIndex){
        vehicleIndex = _vehicle_dist(_rng);
    }
    int vehicle_pos = _pos_dist(_rng) * 100;
    switch (vehicleIndex)
    {
    case 1:
    {
        std::shared_ptr<Vehicle> _truck = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Truck, screen_width, screen_height, 0, -120, 55, 110));
        _truck->pos_x = vehicle_pos;
        vehicles.push_back(_truck);
        break;
    }
    case 2:
    {
        std::shared_ptr<Vehicle> _car = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Car, screen_width, screen_height, 0, -120, 40, 80));
        _car->pos_x = vehicle_pos;
        vehicles.push_back(_car);
        break;
    }
    case 3:
    {
        std::shared_ptr<Vehicle> _van = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Van, screen_width, screen_height, 0, -120, 60, 110));
        _van->pos_x = vehicle_pos;
        vehicles.push_back(_van);
        break;
    }
    case 4:
    {
        std::shared_ptr<Vehicle> _taxi = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Taxi, screen_width, screen_height, 0, -120, 40, 77));
        _taxi->pos_x = vehicle_pos;
        vehicles.push_back(_taxi);
        break;
    }
    case 5:
    {
        std::shared_ptr<Vehicle> ambulance = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Ambulance, screen_width, screen_height, 0, -120, 50, 110));
        ambulance->pos_x = vehicle_pos;
        vehicles.push_back(ambulance);
        break;
    }
    case 6:
    {
        std::shared_ptr<Vehicle> audi = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Audi, screen_width, screen_height, 0, -120, 40, 90));
        audi->pos_x = vehicle_pos;
        vehicles.push_back(audi);
        break;
    }
    case 7:
    {
        std::shared_ptr<Vehicle> truck = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::BigTruck, screen_width, screen_height, 0, -120, 50, 140));
        truck->pos_x = vehicle_pos;
        vehicles.push_back(truck);
        break;
    }
    }
    _delay -= 10;
    prevVehicleIndex = vehicleIndex; 
    _lastVehicleTime = std::chrono::system_clock::now();
}
