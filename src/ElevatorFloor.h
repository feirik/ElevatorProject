#pragma once

/*
 Class representing a physical elevator floor that can be accessed from an elevator
 */
class ElevatorFloor
{
private:
    bool m_RestrictedAccess;
    int m_FloorNumber;
    
    // Distance between floors in meters
    const double m_ElevatorFloorHeight = 3.0;
    
public:
    ElevatorFloor(int floorNumber) : m_RestrictedAccess(0), m_FloorNumber(floorNumber)
    {
    }
    
    int getFloorNumber() const;
    bool getRestrictedStatus() const;
    double getFloorHeight() const;
    
    void setRestrictedStatus(bool restrictedFlag);
};
