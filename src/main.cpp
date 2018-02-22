#include "logging.h"
#include "initLogic.h"
#include "runLogic.h"
#include "securityLogic.h"

int main(int argc, const char * argv[])
{
    initLogging();
    
    std::vector<ElevatorFloor> floors;
    Elevator elevator;
    User user;
    
    setNumberOfFloors(&floors);
    restrictTopFloor(&floors);
    
    do
    {
        if(!user.getElevatorStatus())
        {
            enterElevator(&user);
        }
        
        selectFloor(floors, &elevator);
    }
    while(accessFloor(floors, elevator, &user));
    
    return 0;
}
