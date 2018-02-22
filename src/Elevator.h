#pragma once

/*
 Class representing a physical elevator that can move between floors
 */
class Elevator
{
private:
    int m_FloorLevel;
    
    // Constant elevator speed in meters per second
    const double m_ElevatorSpeed = 2.0;
    
public:
    Elevator() : m_FloorLevel(0)
    {
    }
    
    Elevator(int floorLevel) : m_FloorLevel(floorLevel)
    {
    }
    
    void setFloorLevel(int floorLevel);
    int getFloorLevel() const;
    
    double getElevatorSpeed() const;
    
};
