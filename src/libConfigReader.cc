/*
 * libConfigReader.cc
 *
 *  Created on: 23 Sep 2013
 *      Author: lnetherton
 */

#include "libConfigReader.h"


using namespace libconfig;
using namespace std;

LibConfigReader::LibConfigReader() {

}

LibConfigReader::~LibConfigReader() {

}


void LibConfigReader::loadConfigFile(string filename) {
    // Read the config file
    try {
      m_cfg.readFile(filename.c_str());
    }
    catch(const FileIOException &fioex) {
        return;
    }
    catch(ParseException &pex) {
        return;
    }

    //Setting s = m_cfg.getRoot();

    printf("getting root\n");
    map<string,string> contents = getPathContents("");
    for (map<string,string>::iterator i=contents.begin(); i != contents.end(); i++) {
        printf("%s, %s\n", i->first.c_str(), i->second.c_str());
    }
    printf("returning");
}

map<string,string> LibConfigReader::getPathContents(string path) {
    map<string,string> contents;

    if (path.empty()) {
        for (int i=0; i<m_cfg.getRoot().getLength(); i++) {
            contents[m_cfg.getRoot()[i].getName()] = m_cfg.getRoot()[i].getLength();
            printf("%u\n", m_cfg.getRoot()[i].getLength());
        }
    } else {

    }
}



int main(int argc, char** argv) {

    LibConfigReader lconf;

    lconf.loadConfigFile(argv[1]);

    return 0;
}
