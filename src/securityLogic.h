#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "ElevatorFloor.h"
#include "logging.h"

void restrictTopFloor(std::vector<ElevatorFloor> *floors);

int hashFunction(std::string inputString);

void setPassword();

void writePWHashToFile(std::string inputString);
int readPWHashFromFile();
