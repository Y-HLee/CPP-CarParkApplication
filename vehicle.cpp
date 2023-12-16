#include "classes_definition.hpp"

/*
  vehicle.cpp
  Author: Yuan Lee <yl20aak@herts.ac.uk>
  Created: 2/12/2023
*/

/**
   Vehicle constructor which set information with registration,
   time in and vehicle type.
*/
Vehicle::Vehicle (std::string registration, Time time_in,
		  std::string vehicle_type){

  this->registration = registration;
  this->time_in = time_in;
  this->vehicle_type = vehicle_type;
  
}

/**
   Calculate the total time parked.
   Using the time out to work out the time difference in mintues
   from the time in when the vehicle object is constructed.
   Time in hours will always be less than time out hours
   using the 24 time format, so I do time out hours take
   away from time in hours, same with minutes.
   Else if time in minutes is bigger than time out minutes I
   do 60 - the time in minutes than add the time out minutes
   decrement the hour.
   @param time out to work out the time difference
   @return time out in minutes
*/
int Vehicle::calculate_total_time_parked(Time time_out) {
  
  int hours = 0;
  int minutes = 0;

  if (time_in.hours <= time_out.hours){
    
    hours = time_out.hours - time_in.hours;
    
  }
  
  if (time_in.minutes <= time_out.minutes){
    
    minutes = time_out.minutes - time_in.minutes;
  }

  else {
    
    minutes = (60 - time_in.minutes) + time_out.minutes;
    hours--;
    
  }
  
  return (hours * 60) + minutes;
  
}

/**
   Get registration
   @return registration
*/

std::string Vehicle::get_registration(){

  return registration; 
}

/**
   Get time in
   @return time in
*/
Time Vehicle::get_time_in(){

  return time_in;
}

/**
   Get vehicle type
   @return vehicle type
*/
std::string Vehicle::get_vehicle_type(){

  return vehicle_type;
}


