/*
 * envVariable.cc
 *
 *  Created on: 24 Sep 2013
 *      Author: lnetherton
 */

#include "envVariable.h"
#include <stdlib.h>
#include <string.h>

using namespace std;

EnvVariable::EnvVariable(string name) : m_name(name), m_type(NONE) {}

EnvVariable::~EnvVariable() {
}

const std::string& EnvVariable::set(const string& val) {
    m_type = STRING;
    m_valString = val;
    return val;
}

const int& EnvVariable::set(const int& val) {
    m_type = INT;
    m_valInt = val;
    return val;
}

void EnvVariable::send() {
    if (m_type == NONE) {
        return;
    }

    string deploy = m_name + "=";

    switch (m_type) {
        case STRING:
            deploy += m_valString;
            break;
        case INT:
            deploy += "1";
            break;
        default:
            return;
    }

    char dep[MAX_ENV_LENGTH];
    strcpy(dep,deploy.c_str());
    int ret = putenv(dep);

    ret = ret;
}
