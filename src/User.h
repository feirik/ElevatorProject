#pragma once

/*
 Class representing a physical user that can use an elevator
 */
class User
{
private:
    bool m_InElevator;
public:
    User() : m_InElevator(0)
    {
    }
    
    void setElevatorStatus(bool UserElevatorStatus);
    bool getElevatorStatus() const;
};
