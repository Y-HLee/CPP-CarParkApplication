#ifndef _CLASS_DEFINITION_HPP_
#define _CLASS_DEFINITION_HPP_
#include <string>
#include <vector>

/*
  class_definition.hpp
  Author: Yuan Lee <yl20aak@herts.ac.uk>
  Created: 2/12/2023
*/

/**
   A struct for constructing Time into hours and minutes.
*/

struct Time {
  
  int hours;
  int minutes;  
};

/**
   A struct for constructing Date into day, month and year.
*/

struct Date {

  int day;
  int month;
  int year;

};

/**
   vehicle base class which hold information about registration, time in and vehicle type.
*/

class Vehicle
{
  private:
    
   std::string registration;
   Time time_in;
   std::string vehicle_type;

  public:
   
   Vehicle(std::string registration, Time time_in, std::string vehicle_type);
   std::string get_registration();
   Time get_time_in();
   std::string get_vehicle_type(); 
   int calculate_total_time_parked(Time time_out);
   virtual ~Vehicle(){};
   virtual double day_taking(Time time_out) = 0;
};

/**
   car derived class from vehicle holding information about the price per hour and max spaces.
*/

class Car: public Vehicle
{
  public:
  
   static double price_per_hour;
   static int max_spaces;

   Car(std::string registration, Time time_in, std::string vehicle_type); 
   double day_taking(Time time_out);
  
};

/**
   van derived class from vehicle holding information about the price per hour and max spaces.
*/

class Van : public Vehicle
{
  public:
  
   static double price_per_hour;
   static int max_spaces;
  
   Van(std::string registration, Time time_in, std::string vehicle_type);
   
   double day_taking(Time time_out);
};

/**
   Parking class holding information about the parking statistics.
*/

class Parking
{
  public:
   std::vector<Vehicle*> vehicles; //vector will be reflecting the current parking capacity  

   int van_counter; // overall van intake
   double vans_takings; // value progressively increases when a van is charged on the drive out
   int van_turned_away; // number of vans turned away

   int car_counter; // overall car intake
   double cars_takings;  // value progressively increases when a car is charged on the drive out
   int car_turned_away; // number of cars turned away
  
   Date date; 
   
   Parking(Date date);
   ~Parking();
   void vehicle_drive_in(std::string registration, Time time_in, std::string vehicle_type);
   void vehicle_drive_out(std::string registartion, Time time_out);
   int find_vehicle(std::string registration);
   double total_day_takings();
   int total_number_vehicle_type(std::string vehicle_type);
   double total_day_takings_for_vehicle_type(std::string vehicle_type);
   bool spaces_left(std::string vehicle_type); 
   int turned_away(std::string vehicle_type);
   void clear_parking();  
   
};
#endif
