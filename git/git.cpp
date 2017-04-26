#include "git.h"

/*	The Git class is used for interaction with the Git repository.
 * Git contains a vector of Strings of the files to be uploaded to git.
 * Git class also contains method to upload and download files, add files,
 * commit, pull, move files to the git repository, push files,
 * convert files, and merge.
 * */

//setting git repo backup to current repo
string Git::repo = "ssh://spr2017_l1g3@139.147.9.185/home/spr2017_l1g3/backup.git";
string Git::name = "backup";
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
    result = Bash::exec("cd " + name + " ; pwd");
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

//return repo if initialized
string Git::get_name() {
    if(!initialized)
        init();
    return name;
}

//set repo to specified file path (as string)
void Git::set_name(string n) {
    if(!initialized)
        init();
    name = n;
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
    string result = Bash::exec("cd " + name + " ; git status");
    return result;
}

//method that makes vector of strings of all files within a directory via -ls
vector<string> Git::find_all_files(string pathName) {
    pathName = escape_spaces(pathName);
    //cout << "PATH" << pathName << endl;

    string result = Bash::exec("cd " + pathName + " ; " +"ls");
    vector<string> retVector;
    //cout << Bash::exec("cd " + pathName + " ; pwd") << endl;
    if(escape_spaces(Bash::exec("cd " + pathName + " ; pwd")).find(pathName) != string::npos) {
        stringstream ss(result);
        string final;
        while(getline(ss,final,'\n'))
        {
            retVector.push_back(final);
        }
    }
    return retVector;
}

//find entire file path by inputting file name
string Git::find_file_path(string fileName) {
    string result = Bash::exec("find . -name " + fileName);
    return result;
}

//Remove spaces from path name
string Git::escape_spaces(string str) {
    size_t pos = str.find(" ");
    while(pos != string::npos) {
        str.insert(pos, "\\");
        pos = str.find(" ", pos+2);
    }
    return str;
}

//push local changes
bool Git::push() {
    //cout << "push" << endl;
    if(!initialized)
        init();
    for(unsigned i = 0; i < files.size(); i++) {
        string cmd = "cp -f " + files.at(i) + " " + name + "/" ;
        Bash::exec(cmd);
        //cout << cmd << endl;
    }
    string result = Bash::exec("cd " + name + " ; git add .");
    result += Bash::exec("cd " + name + " ; git commit -m 'Committing'");
    result += Bash::exec("cd " + name + " ; git push");
    //cout << result << endl;
    if(result.find("nothing to commit") != string::npos || result.find("fatal") != string::npos || result.find("error") != string::npos) {
        return false;
    }
    return true;
}

//pull remote changes and merge into local
bool Git::pull() {
    //cout << "pull" << endl;
    if(!initialized)
        init();
    string result = Bash::exec("cd " + name + " ; git pull");
    if(result.find("fatal") != string::npos || result.find("error") != string::npos) {
        return false;
    }

    string names = Bash::exec("cd " + name + " ; ls");
    //vector<string> files;
    string token;
    istringstream iss(names);
    while(getline(iss, token, '\n')) {
        //cout << "AAA" << token << "AAA" << endl;
        files.push_back(token);
    }

    for(unsigned i = 0; i < files.size(); i++) {
        string cmd = "cp -f " + name + "/" + files.at(i) + " ./" ;
        Bash::exec(cmd);
    }
    return true;
}

//do a hard reset
bool Git::reset() {
    if(!initialized) {
        return init(); //"Did not reset because the repository was not initialized."
    } else {
        string result = Bash::exec("cd " + name + " ; git reset --hard origin/master");
        if(result.find("done") == string::npos && result.find("fatal") != string::npos) {
            return false;
        }
        return true;
    }
}
