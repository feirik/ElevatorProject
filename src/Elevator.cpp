#include "Elevator.h"


void Elevator::setFloorLevel(int floorLevel)
{
    m_FloorLevel = floorLevel;
}

int Elevator::getFloorLevel() const
{
    return m_FloorLevel;
}

double Elevator::getElevatorSpeed() const
{
    return m_ElevatorSpeed;
}
