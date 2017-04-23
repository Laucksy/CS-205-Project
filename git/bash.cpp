#include "bash.h"

/*Bash is used to execute the functionality of the Git class.
 * */
Bash::Bash() {

}

//Method to execute command line command and return result of command
//You can redirect stderr to stdout by appending "2>&1" to the command
string Bash::exec(string cmd) {
   array<char, 128> buffer;
   string result;
   shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
   if (!pipe) throw runtime_error("popen() failed!");
   while (!feof(pipe.get())) {
       if (fgets(buffer.data(), 128, pipe.get()) != NULL)
           result += buffer.data();
   }
   return result;
}
