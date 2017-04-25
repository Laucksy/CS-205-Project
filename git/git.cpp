#include "git.h"

/*	The Git class is used for interaction with the Git repository.
 * Git contains a vector of Strings of the files to be uploaded to git.
 * Git class also contains method to upload and download files, add files,
 * commit, pull, move files to the git repository, push files,
 * convert files, and merge.
 * */

//setting git repo backup to current repo
string Git::repo = "ssh://spr2017_l1g3@139.147.9.185/home/spr2017_l1g3/backup.git";
bool Git::initialized = false;
vector<string> Git::files;

Git::Git() {

}

Git::~Git() {

}

/*initialize git by cloning repo and entering into backup such
that the backup exists within the path*/
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

//return repo if initialized
string Git::get_repo() {
    if(!initialized)
        init();
    return repo;
}

//set repo to specified file path (as string)
void Git::set_repo(string r) {
    if(!initialized)
        init();
    repo = r;
}

//add new file via file path to vector of files
void Git::add_file(string path) {
    files.push_back(path);
}

//return specified file within contained vector of files
string Git::get_file(int index) {
    if((unsigned int)index < files.size())
        return files.at(index);
    else
        return "";
}

//return initialization status
string Git::status() {
    if(!initialized)
        init();
    string result = Bash::exec("cd backup ; git status");
    return result;
}

//method that makes vector of strings of all files within a directory via -ls
vector<string> Git::find_all_files(string pathName) {
    string result = Bash::exec("cd " + pathName + " ; " +"ls");
    cerr << Bash::exec("pwd") << endl;
    stringstream ss(result);
    string final;
    vector<string> retVector;
    while(getline(ss,final,'\n'))
    {
        retVector.push_back(final);
    }
    return retVector;
}

//find entire file path by inputting file name
string Git::find_file_path(string fileName) {
    string result = Bash::exec("find . -name " + fileName);
    return result;
}

//push local changes
bool Git::push() {
    cout << "push" << endl;
    if(!initialized)
        init();
    for(unsigned i = 0; i < files.size(); i++) {
        string cmd = "cp -f " + files.at(i) + " backup/" ;
        cout << Bash::exec(cmd) << endl;
        cout << cmd << endl;
    }
    string result = Bash::exec("cd backup ; git add .");
    result += Bash::exec("cd backup ; git commit -m 'Committing'");
    result += Bash::exec("cd backup ; git push");
    cout << result << endl;
    if(result.find("nothing to commit") != string::npos || result.find("fatal") != string::npos || result.find("error") != string::npos) {
        return false;
    }
    return true;
}

//pull remote changes and merge into local
bool Git::pull() {
    cout << "pull" << endl;
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
        string cmd = "cp -f backup/" + files.at(i) + " ./" ;
        Bash::exec(cmd);
    }
    return true;
}

//do a hard reset
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
