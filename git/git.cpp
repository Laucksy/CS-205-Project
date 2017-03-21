#include "git.h"

string Git::repo = "ssh://spr2017_l1g3@139.147.9.185/home/spr2017_l1g3/backup.git";
bool Git::initialized = false;
vector<string> Git::files;

Git::Git() {

}

Git::~Git() {

}

void Git::init() {
    Bash::exec("git clone " + repo);
    Bash::exec("cd backup ; pwd");
    initialized = true;
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
    if(index < files.size())
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

string Git::push() {
    if(!initialized)
        init();
    for(unsigned i = 0; i < files.size(); i++) {
        string cmd = "cp " + files.at(i) + " backup/" ;
        Bash::exec(cmd);
    }
    string result = Bash::exec("cd backup ; git add .");
    result += Bash::exec("cd backup ; git commit -m 'Committing'");
    //cout << "AAAAA" << result << "AAAAA";
    result += Bash::exec("cd backup ; git push");
    return result;
}

string Git::pull() {
    if(!initialized)
        init();
    string result = Bash::exec("cd backup ; git pull");
    return result;
}

string Git::reset() {
    if(!initialized) {
        init();
        return "Did not reset because the repository was not initialized.";
    } else {
        string result = Bash::exec("cd backup ; git reset --hard");
        return result;
    }
}
