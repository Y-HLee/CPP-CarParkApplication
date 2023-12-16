#include <iostream>
#include <fstream>
#include <string>
#include "classes_definition.hpp"

/*
  main.cpp
  Author: Yuan Lee <yl20aak@herts.ac.uk>
  Created: 3/12/2023
*/

/**
   Main program that take a file as command line argument
   and output parking statistic depending on the day
*/

int main(int argc, char* argv[]){

  if (argc < 2 ){
    std::cerr << "Usage: " 
              << "car park application \n"
              << "Please provide a file to run the program";
     exit(1);
  };

  std::string file_name = argv[1];
  std::ifstream my_file(file_name);
  std::string line;
  std::string current_day;

  getline(my_file, line);
  current_day = line;

  int day = stoi(current_day.substr(0,2));
  int month = stoi(current_day.substr(3,2));
  int year = stoi(current_day.substr(6,4));
  Date date = {day,month,year};

  Parking parking(date);

  while (getline(my_file, line)){

    if (line.length() == 10) {
      
      std::string day_report_name =  current_day.substr(0,2) + current_day.substr(3,2)
	                             + current_day.substr(6,4) + ".txt";
      
      std::ofstream output_file(day_report_name);

      output_file << "Total takings for that day: "
	          << "£"
	          << parking.total_day_takings() << "\n";

      output_file << "Total number of cars: "
	          << parking.total_number_vehicle_type("car") << "\n"
	          << "Total number of vans: "
	          << parking.total_number_vehicle_type("van") << "\n";

      output_file << "Total takings for cars: "
	          << "£"
	          << parking.total_day_takings_for_vehicle_type("car") << "\n"
                  << "Total takings for vans: "
	          << "£"
	          << parking.total_day_takings_for_vehicle_type("van") << "\n";


      output_file << "Number of cars turned away: "
	          << parking.turned_away("car") << "\n"
	          << "Number of vans turned away: "
	          << parking.turned_away("van");

      parking.clear_parking();
      int day = stoi(line.substr(0,2));
      int month = stoi(line.substr(3,2));  
      int year = stoi(line.substr(6,4));
      Date date = {day,month,year};
      parking.date = date;
      current_day = line;

    }

    else if (line.substr(12,2) == "IN"){

      std::string vehicle_type = line.substr(0,3); 
      std::string registration = line.substr(4,7);
      int hours = stoi(line.substr(15,2));
      int minutes = stoi(line.substr(18,2));
      Time time_in = {hours, minutes};
      
      parking.vehicle_drive_in(registration, time_in, vehicle_type);
    }

    else if (line.substr(12,3) == "OUT"){
      
      std::string registration = line.substr(4,7);
      int hours = stoi(line.substr(16,2));
      int minutes = stoi(line.substr(19,2));
      Time time_out = {hours, minutes};

      parking.vehicle_drive_out(registration, time_out);
    }
  }

  my_file.close();
 
  return 0;
  
}


