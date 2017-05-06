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

string Bash::copy(Assignment *assignment, string fn) {
    //Bash::exec("cp " + Git::escape_spaces(name) + " " + Git::escape_spaces(pwd));
    //string simpleFileName = name.substr(name.find_last_of("/"));
    string assignmentName = "";
    for(unsigned i = 0; i < assignment->stu->section->assignList.size(); i++) {
        for(unsigned j = 0; j < assignment->stu->section->assignList.at(i)->list.size(); j++) {
            if(assignment == assignment->stu->section->assignList.at(i)->list.at(j)) {
                assignmentName = assignment->stu->section->assignList.at(i)->name;
            }
        }
    }
    string path = "";
    if(assignmentName == "") {
        path = "files/" + assignment->stu->section->name + "/" + to_string(time(0)) + "/" + assignment->stu->name;
    } else {
        path = "files/" + assignment->stu->section->name + "/" + assignmentName + "/" + assignment->stu->name;
    }
    //path = Git::escape_spaces(path);
    make_dirs(path);
    //cout << "Done with make dirs" << endl;
    exec("cp " + Git::escape_spaces(fn) + " " + Git::escape_spaces(path));
    //return exec("pwd") + "/" + path + "/" + fn.substr(fn.find_last_of("/")+1);
    return "/" + path + "/" + fn.substr(fn.find_last_of("/")+1);
}

/* Creates directories for the files if they don't exist already
 * Precondition - fn is the relative path of the
 * new directory from the working directory */
/*void Bash::make_dirs(string fn) {
    fn = Git::escape_spaces(fn);
    int firstIndex = 0;
    int secondIndex = fn.find_first_of("/");
    string cumulativeFN = "";
    while(exec("cd " + fn + " ; pwd") != fn) {
        string subFN = "";
        try {
            subFN = fn.substr(firstIndex,secondIndex-firstIndex);
        } catch(...) {return;}
        if(cumulativeFN.length() > 0 && cumulativeFN.at(cumulativeFN.length()-1) == '/') {
            cumulativeFN = cumulativeFN.substr(0,cumulativeFN.length()-1);
        }
        if(subFN != "" && exec("cd " + cumulativeFN + " ; cd " + subFN + " ; pwd") == exec("cd " + cumulativeFN + " ; pwd")) {
            //if(subFN.length() > 0 && subFN.at(0) == '/') {
                //subFN = subFN.substr(1);
            //}
            subFN = "";
            string dirPath = cumulativeFN + "/" + subFN;
            cout << cumulativeFN << "\n" << subFN << "\n" << dirPath << endl;
            if(dirPath.length() > 0 && dirPath.at(0) == '/') {
                dirPath = dirPath.substr(1);
            }
            if(dirPath.length() > 2) {
                exec("mkdir " + dirPath);
            }
        }
        try {
            cout << "try1" << endl;
            firstIndex = secondIndex;
            secondIndex = fn.find_first_of("/", secondIndex+1);
            cumulativeFN = fn.substr(0,secondIndex);
            cout << "try2" << endl;
        } catch(...) {
            return;
        }
    }
}*/

void Bash::make_dirs(string fn) {
    fn = Git::escape_spaces(fn);
    //cout << "Init filename " << fn << endl;
    size_t index = fn.find_first_of("/");
    string cumulativeFN = "";
    while(index < fn.length()) {
        cumulativeFN = fn.substr(0,index);
        exec("mkdir " + cumulativeFN);
        index = fn.find_first_of("/", index+1);
        if(index == string::npos) {
            //cout << "Make the directory " << fn << endl;
            exec("mkdir " + fn);
            return;
        }
    }
}
