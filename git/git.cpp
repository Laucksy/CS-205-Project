#include "git.h"

string Git::repo = "ssh://spr2017_l1g3@139.147.9.185/home/spr2017_l1g3/backup.git";
bool Git::initialized = false;
vector<string> Git::files;

Git::Git() {

}

Git::~Git() {

}

bool Git::init() {
    string result = Bash::exec("git clone " + repo);
    if(result.find("done") == string::npos && result.find("fatal") != string::npos) {
        initialized = false;
        return false;
    }
    result = Bash::exec("cd backup ; pwd");
    if(result.find("No such file or directory") != string::npos) {
        initialized = false;
        return false;
    }
    initialized = true;
    return true;
}

string Git::get_repo() {
    if(!initialized)
        init();
    return repo;
}

void Git::set_repo(string r) {
    if(!initialized)
        init();
    repo = r;
}

void Git::add_file(string path) {
    files.push_back(path);
}

string Git::get_file(int index) {
    if((unsigned int)index < files.size())
        return files.at(index);
    else
        return "";
}

string Git::status() {
    if(!initialized)
        init();
    string result = Bash::exec("cd backup ; git status");
    return result;
}

string Git::find_file_path(string fileName) {
    string result = Bash::exec("find . -name " + fileName);
    return result;
}

bool Git::push() {
    if(!initialized)
        init();
    for(unsigned i = 0; i < files.size(); i++) {
        string cmd = "cp " + files.at(i) + " backup/" ;
        Bash::exec(cmd);
    }
    string result = Bash::exec("cd backup ; git add .");
    result += Bash::exec("cd backup ; git commit -m 'Committing'");
    result += Bash::exec("cd backup ; git push");
    if(result.find("nothing to commit") != string::npos || result.find("fatal") != string::npos || result.find("error") != string::npos) {
        return false;
    }
    return true;
}

bool Git::pull() {
    if(!initialized)
        init();
    string result = Bash::exec("cd backup ; git pull");
    if(result.find("fatal") != string::npos || result.find("error") != string::npos) {
        return false;
    }

    string names = Bash::exec("cd backup ; ls");
    //vector<string> files;
    string token;
    istringstream iss(names);
    while(getline(iss, token, '\n')) {
        //cout << "AAA" << token << "AAA" << endl;
        files.push_back(token);
    }

    for(unsigned i = 0; i < files.size(); i++) {
        string cmd = "cp backup/" + files.at(i) + " ./" ;
        Bash::exec(cmd);
    }
    return true;
}

bool Git::reset() {
    if(!initialized) {
        return init(); //"Did not reset because the repository was not initialized."
    } else {
        string result = Bash::exec("cd backup ; git reset --hard origin/master");
        if(result.find("done") == string::npos && result.find("fatal") != string::npos) {
            return false;
        }
        return true;
    }
}
