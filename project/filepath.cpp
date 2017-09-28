#include "filepath.h"

FilePath::FilePath()
{

}

string FilePath::find_file_path() {
    if(!initialized)
        init();
    string result = Bash::exec("cd backup ; git status");
    return result;
}
