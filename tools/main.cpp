#include "configuration.h"
#include "iostream"
#include "log.h"
using namespace std;

int main(int argc, char *argv[])
{
    /*Configuration Code*/
    Configuration config;
    //config.set_config("name", "erik laucks");
    //config.set_config("age", "17");
    //config.set_config("archetype", "nerd");
    config.write();
    cout << "\n";
    config.read();


    //Log Code
    Log logger("testFile.txt");
    logger.open_truncate();
    logger << 679;
    string hemp = "Werds";
    logger << hemp;
    logger << "CheeseQ's" << true << "bull";
    logger << 'a';
    logger << true;
    logger << 56.2234790354;
    logger.close();
    logger.flush();

    Log copyLog(logger);
    copyLog.open_truncate();
    copyLog << "This overwrites";
    copyLog.close();
    copyLog.flush();

    return 0;
}
