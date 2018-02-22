#include "ElevatorFloor.h"

int ElevatorFloor::getFloorNumber() const
{
    return m_FloorNumber;
}

bool ElevatorFloor::getRestrictedStatus() const
{
    return m_RestrictedAccess;
}

double ElevatorFloor::getFloorHeight() const
{
    return m_ElevatorFloorHeight;
}

void ElevatorFloor::setRestrictedStatus(bool restrictedFlag)
{
    m_RestrictedAccess = restrictedFlag;
}