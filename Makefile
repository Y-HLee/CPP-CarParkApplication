CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Wextra -Wpedantic

.PHONY: all
all: car_park_application

check: car_park_application_test

car_park_application: main.cpp car_and_van.o parking.o vehicle.o
	$(CXX) $(CXXFLAGS) -o $@ $^

car_park_application_test: car_park_application_test.cpp car_and_van.o parking.o vehicle.o
	$(CXX) $(CXXFLAGS) -o $@ $^

car_and_van.o: car_and_van.cpp classes_definition.hpp
	$(CXX) $(CXXFLAGS) -c $<

vehicle.o: vehicle.cpp classes_definition.hpp
	$(CXX) $(CXXFLAGS) -c $<

parking.o: parking.cpp classes_definition.hpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm *.o
	rm *.txt
	rm car_park_application
	rm car_park_application_test
