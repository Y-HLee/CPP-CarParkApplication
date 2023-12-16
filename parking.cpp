#include "classes_definition.hpp"
#include <vector>

/*
  parking.cpp
  Author: Yuan Lee <yl20aak@herts.ac.uk>
  Created: 6/12/2023
*/

/**
   Construct a parking with a given date.
   @param date of the parking
*/
Parking::Parking(Date date) {

  this->date = date;
  
  this->car_counter = 0;
  this->cars_takings = 0; 
  this->car_turned_away = 0;
  
  this->van_counter = 0;
  this->vans_takings = 0; 
  this->van_turned_away = 0;
}

/**
   Calculate the spacess left in the parking.
   Looping through counting the number of vehicles matching the vehicle type
   function parameter.
   If statement is called to see which vehicle type maximum spaces
   compare the counter to.
   @param vehicle type you want to find how many spaces is left
   @return how many spaces is left for car or van
*/
bool Parking::spaces_left(std::string vehicle_type){

  int counter = 0; 
  
  for (int i = 0 ; i < vehicles.size(); i++){
    if (vehicles[i]->get_vehicle_type() == vehicle_type)
      counter++;   
  }
  if (vehicle_type == "car")
    return (counter < Car::max_spaces);

  if (vehicle_type == "van")
    return (counter < Van::max_spaces);
  
}

/**
   Vehicle drive in creates the object depending on what what vehicle
   type it is, car or van.
   @param registration create object with this registration
   @param time in create object with this time in
   @param vehicle type create object with this vehicle type
*/
void Parking::vehicle_drive_in(std::string registration, Time time_in,
			       std::string vehicle_type) {

  if (vehicle_type == "car" && spaces_left(vehicle_type)){ 

    Car* car = new Car(registration, time_in, vehicle_type);

    vehicles.push_back(car);

    car_counter++;
      
  }
  else if (vehicle_type == "car" && !(spaces_left(vehicle_type))){

    car_turned_away++;
  }
  
  if (vehicle_type == "van" && spaces_left(vehicle_type)) {
    
    Van* van = new Van(registration,time_in, vehicle_type);

    vehicles.push_back(van);

    van_counter++;
  }

  else if (vehicle_type == "van" && !(spaces_left(vehicle_type))){

    van_turned_away++;
   }

}

/**
   Finding the index which represent the location in the vehicle vector
   @param registration of the vehicle we find to find the location
   @return the location of the index from the given registration
   @return false if it can not find it
*/

int Parking::find_vehicle(std::string registration) {

  for (int i = 0; i < vehicles.size(); i++){

    if (vehicles[i]->get_registration() == registration)

      return i;
  }

  return -1; 
  
}

/**
   Vehicle drive out uses find vehicle function to find the location
   of the vehicle object using the registration then work out the taking
   before assignning to whether it is car or van.
   @param registration to find if it match with the function find vehicle
   @param time out to give that vehicle at that location a time out
*/

void Parking::vehicle_drive_out(std::string registration, Time time_out) {
  
  if (Parking::find_vehicle(registration) != -1 ){
    
    int index = Parking::find_vehicle(registration);
    
    double day_taking = vehicles[index]->day_taking(time_out);

    if (vehicles[index]->get_vehicle_type() == "car"){
      cars_takings += day_taking;
    }

    if (vehicles[index]->get_vehicle_type() == "van"){
      vans_takings += day_taking; 
    }

    vehicles.erase(vehicles.begin() + index);
 
  }
  
}

/**
   Parking destructor iterate through the vehicle vector, delete and clear
*/
Parking::~Parking() {

  for (std::vector<Vehicle*>::iterator it = vehicles.begin();
       it != vehicles.end(); ++it) {
     Vehicle* vehicle = *it;
     delete vehicle;
  }
    vehicles.clear();
}

/**
   Statistic which return total day takings for each vehicle type
   @param vehicle type of the total takings
   @return cars takings
   @return vans takings
   
 */
double Parking::total_day_takings_for_vehicle_type(std::string vehicle_type){

  if (vehicle_type == "car"){
    return cars_takings;
  }

  if (vehicle_type == "van") {
    return vans_takings;
  }

}

/**
   Statistic to show the total of both vehicle type added together for that day
   @return total of day takings for both vehicle type
*/
double Parking::total_day_takings(){

  return total_day_takings_for_vehicle_type("van")
         + total_day_takings_for_vehicle_type("car");

}

/**
   Statistic to show the total number of each vehicle type in the car park
   for that day
   @return car counter for that day
   @return van counter for that day
*/

int Parking::total_number_vehicle_type(std::string vehicle_type){

  if (vehicle_type == "car"){
    return car_counter;
  }

  if (vehicle_type == "van") {
    return van_counter;
  }
}

/**
   Statistic to show the vehicle type turned away for that day
   @param vehicle type you want to know how many got turned away
   @return car turned away
   @return van turned away
*/
int Parking::turned_away(std::string vehicle_type){
  
  if (vehicle_type == "car"){
    return car_turned_away;
  }

  if (vehicle_type == "van") {
    return van_turned_away;
  }
  
}

/**
   Clear parking which clears the vehicle vector and reset all counters
   and takings to 0. 
*/
void Parking::clear_parking(){

  vehicles.clear();
  this->car_counter = 0;
  this->cars_takings = 0; 
  this->car_turned_away = 0;
  
  this->van_counter = 0;
  this->vans_takings = 0; 
  this->van_turned_away = 0;
  
} 


  
  
