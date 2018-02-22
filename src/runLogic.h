#pragma once

#include <iostream>
#include <vector>

#include "Elevator.h"
#include "ElevatorFloor.h"
#include "User.h"

#include "timeLogic.h"
#include "securityLogic.h"

void enterElevator(User *user);

void selectFloor(const std::vector<ElevatorFloor>& floors, Elevator *elevator);

void moveElevatorUp(const int floorLevel, double floorDelay, Elevator *elevator);

void moveElevatorDown(const int floorLevel, double floorDelay, Elevator *elevator);

bool accessFloor(const std::vector<ElevatorFloor>& floors, const Elevator& elevator, User *user);
