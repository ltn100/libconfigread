/*
 * libConfigReader.h
 *
 *  Created on: 23 Sep 2013
 *      Author: lnetherton
 */

#ifndef LIBCONFIGREADER_H_
#define LIBCONFIGREADER_H_

#include <libconfig.h++>
#include <string>
#include <map>


class LibConfigReader {
public:
    LibConfigReader();
    virtual ~LibConfigReader();

    void loadConfigFile(std::string filename);
    std::map<std::string,std::string> getPathContents(std::string path="");

private:
    libconfig::Config m_cfg;
};

#endif /* LIBCONFIGREADER_H_ */
