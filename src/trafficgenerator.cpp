#include "trafficgenerator.h"

TrafficGenerator::TrafficGenerator(int screen_width, int screen_height, long delay) : screen_height(screen_height),
                                                                                      screen_width(screen_width),
                                                                                      _rng(std::mt19937(_rd())),
                                                                                      _vehicle_dist(std::uniform_int_distribution<int>(1, 7)),
                                                                                      _pos_dist(std::uniform_int_distribution<int>(1, 3)),
                                                                                      _lastVehicleTime(std::chrono::system_clock::now()),
                                                                                      _delay(delay)
{
}

/* 
    This function will generate random vehicle after _delay seconds.
    After each iteration delay is reduced by 10 milliseconds
*/
void TrafficGenerator::GenerateVehicle()
{
    long timeSinceLastVehicle = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - _lastVehicleTime).count();
    if (timeSinceLastVehicle < _delay)
        return;
    int vehicleIndex = _vehicle_dist(_rng);
    // This loop will make sure that vehicle is not same as previous one.
    while (vehicleIndex == prevVehicleIndex)
    {
        vehicleIndex = _vehicle_dist(_rng);
    }
    //generate random position x on the track
    int vehicle_pos = _pos_dist(_rng) * 100;
    std::shared_ptr<Vehicle> vehicle;
    switch (vehicleIndex)
    {
    case 1:
        vehicle = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Truck, screen_width, screen_height, 0, -120, 55, 110));
        break;
    case 2:
        vehicle = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Car, screen_width, screen_height, 0, -120, 40, 80));
        break;
    case 3:
        vehicle = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Van, screen_width, screen_height, 0, -120, 60, 110));
        break;
    case 4:
        vehicle = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Taxi, screen_width, screen_height, 0, -120, 40, 77));
        break;
    case 5:
        vehicle = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Ambulance, screen_width, screen_height, 0, -120, 60, 110));
        break;
    case 6:
        vehicle = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::Audi, screen_width, screen_height, 0, -120, 40, 90));
        break;
    case 7:
        vehicle = std::shared_ptr<Vehicle>(new Vehicle(Vehicle::VehicleType::BigTruck, screen_width, screen_height, 0, -120, 60, 140));
        break;
    }
    vehicle->pos_x = vehicle_pos;
    vehicles.emplace_back(vehicle);
    _delay -= 10;
    prevVehicleIndex = vehicleIndex;
    _lastVehicleTime = std::chrono::system_clock::now();
}
