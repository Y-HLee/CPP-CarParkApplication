#include "classes_definition.hpp" 


/*
  car_and_van.cpp
  Author: Yuan Lee <yl20aak@herts.ac.uk>
  Created: 2/12/2023
*/

/**
   Setting the static variables
*/
double Car::price_per_hour = 1.00;
int Car::max_spaces = 1000;

double Van::price_per_hour = 1.50;
int Van::max_spaces = 20; 

/**
   Car constructor which holds information about registration,
   time in and what vehicle type it is
*/
Car::Car (std::string registration, Time time_in, std::string vehicle_type)
  : Vehicle(registration, time_in, vehicle_type){
  
}

/**
   Calculate day taking by using calculate total time parked to calculate
   the time parked in minutes than dividing by 60 to find out the hours
   before timing it by the price per hour
   @param time out to calculate the total time parked
   @return the taking for the amount of time parked
*/

double Car::day_taking(Time time_out) {

  int total_time_parked = Vehicle::calculate_total_time_parked(time_out);

  return ceil(total_time_parked/60.0) * price_per_hour;

}

/**
   Van constructor which holds information about registration,
   time in and what vehicle type it is
*/
Van::Van (std::string registration, Time time_in, std::string vehicle_type)
  : Vehicle(registration, time_in, vehicle_type){    
}

/**
   Calculate day taking by using calculate total time parked to calculate
   the time parked in minutes than dividing by 60 to find out the hours
   before timing it by the price per hour
   @param time out to calculate the total time parked
   @return the taking for the amount of time parked
*/
double Van::day_taking(Time time_out) {

  int total_time_parked = Vehicle::calculate_total_time_parked(time_out);

  return ceil(total_time_parked/60.0) * price_per_hour;

}

