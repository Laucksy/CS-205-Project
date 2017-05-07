#include "configuration.h"
using namespace std;

/* Default constructor
 */
Configuration::Configuration() {
    filePath = ""; //Default filepath
    fileName = "config.txt"; //Hardcoded filename (option 1)
    read(); //Loads file data into map
}

/* Copy constructor
 */
Configuration::Configuration(Configuration &obj) {
    configMap = obj.configMap;
    filePath = obj.filePath;
    fileName = obj.fileName;
    read(); //Loads file data into map
}

/* Constructor if the user wants to pass a file name
 * param: string fn, the name of the file
 */
Configuration::Configuration(string fn) {
    filePath = "";
    fileName = fn;
    read(); //Loads file data into map
}

/* Constructor if the user wants to pass a file name
 * param: string fn, the name of the file
 */
Configuration::Configuration(string fp, string fn) {
    filePath = fp;
    fileName = fn;
    read(); //Loads file data into map
}

/* Default destructor
 */
Configuration::~Configuration() {
    write(); //Writes map data to file
}

/* Copy assignment
 */
void Configuration::operator=(Configuration &obj) {
    configMap = obj.configMap;
    filePath = obj.filePath;
    fileName = obj.fileName;
    read(); //Loads file data into map
}

/* Returns the value in the map for a given key
 * param: string key, the key to search for in the map
 * return: the value for the given key
 */
string Configuration::get_config(string key) {
    if(configMap.find(key) != configMap.end())
        return configMap.find(key)->second;
    else
        return ""; //Returns empty string if key isn't found
}

/* Sets the value for a key, overwriting a value if the key already exists.
 * param: key to add
 * param: value to add
 */
void Configuration::set_config(string key, string value) {
    configMap[key] = value;
}

/* Gets the file path
 * return: file path
 */
string Configuration::get_file_path() {
    return filePath;
}

/* Gets the file name
 * return: file name
 */
string Configuration::get_file_name() {
    return fileName;
}

/* Sets the file path
 * param: file path
 */
void Configuration::set_file_path(string fp) {
    filePath = fp;
}

/* Sets the file name
 * param: file name
 */
void Configuration::set_file_name(string fn) {
    fileName = fn;
}

/* Reads the file and puts the data into a map
 */
void Configuration::read() {
    try {
        string line;
        ifstream file(filePath + fileName); //Open the file
        if(file.is_open()) {
            configMap.clear(); //Empty the map
            while(getline(file,line)) { //Loops through each line of the file
                stringstream ss(line);
                string item;
                vector<string> tokens;
                while(getline(ss, item, delim)) {
                    tokens.push_back(item); //Separates line into key and value
                }
                cout << tokens.size() << "," << tokens[0] << "," << tokens[1] << "\n";
                configMap[tokens[0]] = tokens[1]; //Add key/value pair to map
            }
            file.close();
        }
    } catch(exception &e) {
        cout << e.what() << "\n";
    }
}

/* Write from the map to the file
 */
void Configuration::write() {
    try {
        ofstream file;
        file.open(filePath + fileName, ios::out); //Open the file
        for(map<string,string>::iterator iter=configMap.begin(); iter!=configMap.end(); ++iter) //Iterate through all map elements
            file << iter->first << delim << iter->second << '\n'; //Write key/value to file separated by delimeter
        file.close();
    } catch(exception &e) {
        cout << e.what() << "\n";
    }
}
