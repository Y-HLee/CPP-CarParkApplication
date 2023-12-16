#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "classes_definition.hpp"



TEST_CASE("Creating car constructor", "[vehicle]")
{
  Car car1("sy22mcb", {6,02}, "car");

  CHECK(car1.get_registration() == "sy22mcb");
  CHECK_FALSE(car1.get_registration() == "ed17eq");
  CHECK(car1.get_vehicle_type() == "car");
  CHECK_FALSE(car1.get_vehicle_type() == "van");
}


TEST_CASE("Creating van constructor", "[vehicle]")
{
  Van van1("ed17eqv", {6,21}, "van");

  CHECK(van1.get_registration() == "ed17eqv");
  CHECK_FALSE(van1.get_registration() == "sy22mcb");
  CHECK(van1.get_vehicle_type() == "van");
  CHECK_FALSE(van1.get_vehicle_type() == "car");
}

TEST_CASE("calculating total time parked for cars", "[vehicle]")
{
  Car car1("sy22mcb", {6,02}, "car");
  Time time_out1{8,56};
  
  Car car2("cm29xsl", {6,04}, "car");
  Time time_out2{6,56};
  
  Car car3("mq03zwr", {7,14}, "car");
  Time time_out3{9,42};

  Car car4("ft50wrr", {12,01}, "car");
  Time time_out4{14,01};

  Car car5("nz90dyo", {20,38}, "car");
  Time time_out5{23,00};
    
  CHECK(car1.calculate_total_time_parked(time_out1) == 174);
  CHECK(car2.calculate_total_time_parked(time_out2) == 52);
  CHECK(car3.calculate_total_time_parked(time_out3) == 148);
  CHECK(car4.calculate_total_time_parked(time_out4) == 120);
  CHECK(car5.calculate_total_time_parked(time_out5) == 142);
}

TEST_CASE("calculating total time parked for vans", "[vehicle]")
{
  Van van1("ed17eqv", {6,21}, "van");
  Time time_out1{6,56};

  Van van2("za44anx", {6,57}, "van");
  Time time_out2{10,25};

  Van van3("ox70qxx", {15,48}, "van");
  Time time_out3{18,40};
  
  Van van4("tb53fdy", {19,20}, "van");
  Time time_out4{19,48};

  Van van5("iw24cvf", {18,29}, "van");
  Time time_out5{22,17};
  

  CHECK(van1.calculate_total_time_parked(time_out1) == 35);
  CHECK(van2.calculate_total_time_parked(time_out2) == 208);
  CHECK(van3.calculate_total_time_parked(time_out3) == 172);
  CHECK(van4.calculate_total_time_parked(time_out4) == 28);
  CHECK(van5.calculate_total_time_parked(time_out5) == 228);
}

TEST_CASE("calculating day taking from cars", "[car]")
{
  Car car1("sy22mcb", {6,02}, "car");
  Time time_out1{8,56};
  
  Car car2("cm29xsl", {6,04}, "car");
  Time time_out2{6,56};
  
  Car car3("mq03zwr", {7,14}, "car");
  Time time_out3{9,42};

  Car car4("ft50wrr", {12,01}, "car");
  Time time_out4{14,01};

  Car car5("nz90dyo", {20,38}, "car");
  Time time_out5{23,00};

  CHECK(car1.day_taking(time_out1) == 3);
  CHECK_FALSE(car1.day_taking(time_out1) == 1.50);
  CHECK(car2.day_taking(time_out2) == 1);
  CHECK(car3.day_taking(time_out3) == 3);
  CHECK(car4.day_taking(time_out4) == 2);
  CHECK(car5.day_taking(time_out5) == 3);
}

TEST_CASE("calculating day taking from vans", "[van]")
{
  Van van1("ed17eqv", {6,21}, "van");
  Time time_out1{6,56};

  Van van2("za44anx", {6,57}, "van");
  Time time_out2{10,25};

  Van van3("ox70qxx", {15,48}, "van");
  Time time_out3{18,40};
  
  Van van4("tb53fdy", {19,20}, "van");
  Time time_out4{19,48};

  Van van5("iw24cvf", {18,29}, "van");
  Time time_out5{22,17}; 

  CHECK(van1.day_taking(time_out1) == 1.50);
  CHECK_FALSE(van1.day_taking(time_out1) == 1);
  CHECK(van2.day_taking(time_out2) == 6);
  CHECK(van3.day_taking(time_out3) == 4.5);
  CHECK(van4.day_taking(time_out4) == 1.50);
  CHECK(van5.day_taking(time_out5) == 6);
}

TEST_CASE("drive in car and counter", "[parking]")
{
  Parking parking({01,10,2023});

  parking.vehicle_drive_in("sy22mcb", {6,02}, "car");
  parking.vehicle_drive_in("cm29xsl", {6,04}, "car");
  parking.vehicle_drive_in("mq03zwr", {7,14}, "car");
  CHECK(parking.car_counter == 3);

  parking.vehicle_drive_in("ed17eqv", {6,21}, "van");
  parking.vehicle_drive_in("za44anx", {6,57}, "van");
  parking.vehicle_drive_in("ox70qxx", {15,48}, "van");
  parking.vehicle_drive_in("tb53fdy", {19,20}, "van");
  CHECK(parking.van_counter == 4);
  
}

TEST_CASE("spaces left and turned away", "[parking]")
{
  Parking parking({01,10,2023});

  parking.vehicle_drive_in("sy22mcb", {6,02}, "car");
  parking.vehicle_drive_in("cm29xsl", {6,04}, "car");
  parking.vehicle_drive_in("mq03zwr", {7,14}, "car");

  REQUIRE(parking.spaces_left("car") == TRUE);
  CHECK(parking.car_counter == 3);

  parking.vehicle_drive_in("ed17eqv", {6,21}, "van"); //1
  parking.vehicle_drive_in("za44anx", {6,57}, "van"); //2
  parking.vehicle_drive_in("ox70qxx", {15,48}, "van"); //3
  parking.vehicle_drive_in("tb53fdy", {19,20}, "van"); //4 
  parking.vehicle_drive_in("ed17eqv", {6,21}, "van"); //5 
  parking.vehicle_drive_in("za44anx", {6,57}, "van"); //6
  parking.vehicle_drive_in("ox70qxx", {15,48}, "van"); //7 
  parking.vehicle_drive_in("tb53fdy", {19,20}, "van"); //8 
  parking.vehicle_drive_in("ed17eqv", {6,21}, "van"); //9
  parking.vehicle_drive_in("za44anx", {6,57}, "van"); //10
  parking.vehicle_drive_in("ox70qxx", {15,48}, "van"); //11
  parking.vehicle_drive_in("tb53fdy", {19,20}, "van"); //12
  parking.vehicle_drive_in("ed17eqv", {6,21}, "van"); //13 
  parking.vehicle_drive_in("za44anx", {6,57}, "van"); //14
  parking.vehicle_drive_in("ox70qxx", {15,48}, "van"); //15
  parking.vehicle_drive_in("tb53fdy", {19,20}, "van"); //16
  parking.vehicle_drive_in("ed17eqv", {6,21}, "van"); //17
  parking.vehicle_drive_in("za44anx", {6,57}, "van"); //18 
  parking.vehicle_drive_in("ox70qxx", {15,48}, "van"); //19
  parking.vehicle_drive_in("tb53fdy", {19,20}, "van"); //20
  parking.vehicle_drive_in("ox70qxx", {15,48}, "van"); //21
  parking.vehicle_drive_in("tb53fdy", {19,20}, "van"); //22
   
  REQUIRE(parking.spaces_left("van") == FALSE);
  CHECK(parking.van_counter == 20);
  CHECK(parking.van_turned_away == 2);
  
}

TEST_CASE("vehicle drive out and total taking for that vehicle type and takings for both", "[parking]")
{
  Parking parking({01,10,2023});
  
  parking.vehicle_drive_in("sy22mcb", {6,02}, "car");
  parking.vehicle_drive_out("sy22mcb", {8,56});
			    
  parking.vehicle_drive_in("cm29xsl", {6,04}, "car");
  parking.vehicle_drive_out("cm29xsl", {6,56});


  parking.vehicle_drive_in("ed17eqv", {6,21}, "van");
  parking.vehicle_drive_out("ed17eqv", {6,56});
			    
  parking.vehicle_drive_in("za44anx", {6,57}, "van");
  parking.vehicle_drive_out("za44anx", {10,25});

  CHECK(parking.cars_takings == 4);
  CHECK(parking.total_day_takings_for_vehicle_type("car") == 4);
  CHECK(parking.vans_takings == 7.50);
  CHECK(parking.total_day_takings_for_vehicle_type("van") == 7.50);
  CHECK(parking.total_day_takings() == 11.50);
  
}

