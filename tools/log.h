#ifndef LOG_H
#define LOG_H
#include "baseclass.h"
#include "iostream"
#include "fstream"
#include "string"

class Log : public BaseClass
{
    public:

        Log();  // default constructor
        Log(Log &obj);
        Log(std::string fileName); // string passing constructor
        ~Log(); // destructor
        void operator=(Log &obj);

        std::string get_file_name();
        bool open_truncate();
        bool open_append();

        bool close();
        bool flush();
        bool is_open();

        // overloaded handler operator
        Log& operator<<(const std::string str);
        Log& operator<<(const int integer);
        Log& operator<<(const char character);
        Log& operator<<(const float floatingPoint);
        Log& operator<<(const double doublePoint);
        Log& operator<<(const wchar_t wideChar);

    private:

        // The file handler.
        std::ofstream fh;

        std::string fN;
};


#endif // LOG_H
