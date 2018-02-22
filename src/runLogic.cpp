#include "runLogic.h"

/*
 Takes a User class as input, no return
 Prompts user to enter elevator
 Puts user in elevator regardless of choice updating ElevatorStatus in class User
 */
void enterElevator(User *user)
{
    int input;
    
    do
    {
        std::cout << "---CHOICES, ENTER A NUMBER and PRESS ENTER---" << std::endl;
        std::cout << "1. Enter the elevator" << std::endl;
        std::cout << "2. Try to slooowly get away..." << std::endl;
        
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        
    }while(input < 1 || input > 2);
    
    if(input == 1)
    {
        std::cout << "You entered the elevator." << std::endl;
    }
    if(input == 2)
    {
        std::cout << "The bouncer made you enter the elevator." << std::endl;
    }
    LOG(INFO) << "User entered the elevator.";
    user->setElevatorStatus(1);
}

/*
 Takes inputs of vector of type ElevatorFloor class, Elevator class address
 Prompts the user for which floor to move the elevator to
 Exits function if choice is same floor as elevator is currently at
 Otherwise calls moveElevatorUp or moveElevatorDown
 */
void selectFloor(const std::vector<ElevatorFloor>& floors, Elevator *elevator)
{
    int bottomFloor = floors.front().getFloorNumber();
    int topFloor = floors.back().getFloorNumber();
    
    // Linear physics formula, speed = distance / time -> solved for time
    double floorDelay = floors.front().getFloorHeight() / elevator->getElevatorSpeed();
    
    int floorLevel;
    
    do
    {
        std::cout << "Enter the floor number you want to travel to" <<
                     " (minimum " << bottomFloor <<
                     ", maximum " << topFloor << "):" << std::endl;
        
        std::cin >> floorLevel;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    while(floorLevel < bottomFloor || floorLevel > topFloor);
    
    LOG(INFO) << "User selected floor number " << floorLevel << ".";
    
    if(floorLevel == elevator->getFloorLevel())
    {
        std::cout << "Strange choice, nothing happened. The bouncer gave you a stern look." << std::endl;
        LOG(INFO) << "User selected to travel to same floor as elevator currently is at.";
    }
    
    if(floorLevel > elevator->getFloorLevel())
    {
        moveElevatorUp(floorLevel, floorDelay, elevator);
        LOG(INFO) << "Elevator moved up to floor level " << floorLevel << ".";
    }
    
    if(floorLevel < elevator->getFloorLevel())
    {
        moveElevatorDown(floorLevel, floorDelay, elevator);
        LOG(INFO) << "Elevator moved down to floor level " << floorLevel << ".";
    }
}

/*
 Takes inputs of an int floorLevel, double floorDelay (time between floors) and Elevator class address
 No return
 Outputs elevator travel statuses to console
 Updates Elevator class with new floor level
 */
void moveElevatorUp(const int floorLevel, double floorDelay, Elevator *elevator)
{
    std::cout << "Elevator has started moving..." << std::endl;
    
    // Status messages starting at first new floor after elevator starts moving,
    // inclusvie destination floor
    for(int i = elevator->getFloorLevel()+1; i <= floorLevel; ++i)
    {
        sleep(floorDelay*1000);
        std::cout << "Elevator is at floor " << i << "..." << std::endl;
    }
    
    std::cout << "Elevator has stopped." << std::endl;
    elevator->setFloorLevel(floorLevel);
}

/*
 Takes inputs of an int floorLevel, double floorDelay (time between floors) and Elevator class address
 No return
 Outputs elevator travel statuses to console
 Updates Elevator class with new floor level
 */
void moveElevatorDown(const int floorLevel, double floorDelay, Elevator *elevator)
{
    std::cout << "Elevator has started moving..." << std::endl;
    
    for(int i = elevator->getFloorLevel()-1; i >= floorLevel; --i)
    {
        sleep(floorDelay*1000);
        std::cout << "Elevator is at floor " << i << "..." << std::endl;
    }
    
    std::cout << "Elevator has stopped." << std::endl;
    elevator->setFloorLevel(floorLevel);
}

/*
 Takes inputs of vector of type ElevatorFloor class, Elevator class, User class address
 Returns a boolean representing if program should terminate
 Prompts user for different choices: access floor, stay in elevator, exit program
 Access floor prompts user for password if floor is restricted
 Stay in elevator lets program continue
 Exit program returns 0, signaling program to end in main()
 */
bool accessFloor(const std::vector<ElevatorFloor>& floors, const Elevator& elevator, User *user)
{
    int input;
    
    do
    {
        std::cout << "---CHOICES, ENTER A NUMBER and PRESS ENTER---" << std::endl;
        std::cout << "1. Access the floor." << std::endl;
        std::cout << "2. Stay in the elevator." << std::endl;
        std::cout << "3. Exit program." << std::endl;
        
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        
    }while(input < 1 || input > 3);
    
    if(input == 1)
    {
        int restrictedFlag = floors.at(elevator.getFloorLevel()).getRestrictedStatus();
        
        // Floor is password protected
        if(restrictedFlag)
        {
            std::string word;
            
            std::cout << "Floor is restricted, enter the password: " << std::endl;
            std::cin >> word;
            
            // Comparing hashed input with stored hash from file
            if(hashFunction(word) == readPWHashFromFile())
            {
                std::cout << "You were granted access to floor " <<
                floors.at(elevator.getFloorLevel()).getFloorNumber() << "." << std::endl;
                
                LOG(INFO) << "User accessed restricted floor successfully.";
                user->setElevatorStatus(0);
            }
            else
            {
                std::cout << "Access denied." << std::endl;
                LOG(INFO) << "User denied access to restricted floor, password mismatch.";
            }
        }
        // Floor is not password protected
        else
        {
            std::cout << "You were granted access to floor " <<
            floors.at(elevator.getFloorLevel()).getFloorNumber() << "." << std::endl;
            
            LOG(INFO) << "User accessed unrestriced floor.";
            user->setElevatorStatus(0);
        }
        // Continue program
        return 1;
    }
    if(input == 2)
    {
        std::cout << "You stayed in the elevator at floor level " <<
        floors.at(elevator.getFloorLevel()).getFloorNumber() << "." << std::endl;
        
        LOG(INFO) << "User selected to stay in elevator";
        return 1;
    }
    if(input == 3)
    {
        LOG(INFO) << "User selected to exit the program.";
    }
    // Default case to end program as well as for input == 3 (Exit program)
    return 0;
}