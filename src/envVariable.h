/*
 * envVariable.h
 *
 *  Created on: 24 Sep 2013
 *      Author: lnetherton
 */

#ifndef ENVVARIABLE_H_
#define ENVVARIABLE_H_


#define MAX_ENV_LENGTH 256

#include <string>

class EnvVariable {
public:
    EnvVariable(std::string name);
    virtual ~EnvVariable();
    void send();
    const std::string& set(const std::string& val);
    const int& set(const int& val);


    const std::string& operator=(const std::string& rhs) { return set(rhs); }
    const int& operator=(const int& rhs) { return set(rhs); }


    enum Type { NONE, STRING, INT };

protected:
    std::string m_name;
    Type m_type;

    std::string m_valString;
    int m_valInt;
};

#endif /* ENVVARIABLE_H_ */
