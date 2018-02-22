#include "User.h"

void User::setElevatorStatus(bool UserElevatorStatus)
{
    m_InElevator = UserElevatorStatus;
}

bool User::getElevatorStatus() const
{
    return m_InElevator;
}