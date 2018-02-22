#include "securityLogic.h"

/*
 Takes inputs of vector of type ElevatorFloor class address
 No return
 Prompts user to restrict access to top floor
 If user restricts, calls setPassword and sets floor restrictedStatus to true
 */
void restrictTopFloor(std::vector<ElevatorFloor> *floors)
{
    int input;
    
    do
    {
        std::cout << "---Do you want to password protect the top floor?---" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        
    }while(input < 1 || input > 2);
    
    if(input == 1)
    {
        floors->back().setRestrictedStatus(true);
        setPassword();
        LOG(INFO) << "User selected to password protect the top floor.";
    }
    else
    {
        LOG(INFO) << "User selected to not password protect the top floor";
        return;
    }
}

/*
 Takes a string as input
 Returns an int
 Generates a hash from the input string
 Not great for short passwords
 Structure found on stack overflow, adapted to program
 */
int hashFunction(std::string inputString)
{
    int seed = 134;
    unsigned long hash = 0;
    for(int i = 0; i < static_cast<int>(inputString.length()); ++i)
    {
        hash = (hash*seed)+inputString[i];
    }
    
    return hash % INT_MAX;
}

/*
 Takes no input, no return
 Prompts user to enter a password
 Writes the hashed password to file
 */
void setPassword()
{
    std::string word;
    std::cout << "Enter the password for the top floor (no constraints): ";
    std::cin >> word;
    std::cout << "The password was set to be: " << word << std::endl;
    writePWHashToFile(word);
}

/*
 Takes a string as inout
 Outputs string input message to file
 */
void writePWHashToFile(std::string inputString)
{
    std::ofstream myfile;
    myfile.open ("password.txt", std::ios_base::ate);
    myfile << hashFunction(inputString) << "\n" << std::endl;
    myfile.close();
}

/*
 Takes no input
 Converts string in file to int
 Returns int converted from string in file
 */
int readPWHashFromFile()
{
    std::string hashedString;
    
    std::ifstream myfile;
    myfile.open ("password.txt");
    if(!myfile.fail())
    {
        std::getline(myfile, hashedString);
        myfile.close();
    }
    int hashedInt = std::stoi(hashedString);
    
    return hashedInt;
}

