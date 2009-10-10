/* 
 * File:   Communicator.cpp
 * Author: cjg
 * 
 * Created on 30 settembre 2009, 11.56
 */

#include <cstring>
#include "Communicator.h"
#include "AfUnixCommunicator.h"
#include "TcpCommunicator.h"

Communicator * Communicator::Create(ConfigFile::Element & config) {
    const char *type = config.GetValue("type").c_str();
    if(strcasecmp(type, "AfUnix") == 0)
        return new AfUnixCommunicator(config.GetValue("path"));
        else if(strcasecmp(type, "Tcp") == 0)
            return new TcpCommunicator(config.GetValue("hostname").c_str(),
                    config.GetShortValue("port"));
    else
        throw "Not a valid type!";
}

Communicator::~Communicator() {
}

