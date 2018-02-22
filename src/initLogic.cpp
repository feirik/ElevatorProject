#include "initLogic.h"

/*
 Takes an vector of type ElevatorFloor class as input, no return
 Prompts user for the number of floors to be added to vector
 Adds the number of floors classes to vector
 */
void setNumberOfFloors(std::vector<ElevatorFloor> *floors)
{
    int numberOfFloors;
    
    do
    {
        std::cout << "Enter the number of floors for the elevator (miniumum 2, maximum 1000): ";
        std::cin >> numberOfFloors;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    while(numberOfFloors < 2 || numberOfFloors > 1000);
    
    for(int i = 0; i < numberOfFloors; ++i)
    {
        floors->push_back(i);
    }
    LOG(INFO) << "INIT: Created " << numberOfFloors << " floors.";
}
