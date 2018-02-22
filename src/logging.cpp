#include "logging.h"

INITIALIZE_EASYLOGGINGPP

/*
 Takes no input, no return
 Initializes easylogging++ with default settings, then turns off logging messages 
 to console
 */
void initLogging()
{
    el::Configurations conf;
    
    conf.setToDefault();
    
    conf.setGlobally(el::ConfigurationType::ToStandardOutput, "false");
    
    el::Loggers::reconfigureLogger("default", conf);
}