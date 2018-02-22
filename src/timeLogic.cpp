#include "timeLogic.h"

/*
 Takes no input
 Returns the current time in milliseconds after year 1970 as a long long int
 */
long long int getCurTimeMs()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/*
 Takes no input
 Delays program execution for an integer delayMs amount of milliseconds
 */
void sleep(int delayMs)
{
    long long int currentTime = getCurTimeMs();
    while(getCurTimeMs() - currentTime < delayMs)
    {
        
    }
}