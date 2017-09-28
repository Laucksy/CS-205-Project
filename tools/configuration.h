#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "baseclass.h"
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "vector"
#include "map"
using namespace std;

class Configuration : public BaseClass
{
    public:
        Configuration();
        Configuration(Configuration &obj);
        Configuration(string fn);
        Configuration(string fp, string fn);
        ~Configuration();
        void operator=(Configuration &obj);

        string get_config(string key);
        void set_config(string key, string value);
        string get_file_path();
        string get_file_name();
        void set_file_path(string fp);
        void set_file_name(string fn);
        void read();
        void write();

    private:
        map<string,string> configMap;
        char delim = '|';
        string filePath;
        string fileName;
};

#endif // CONFIGURATION_H
