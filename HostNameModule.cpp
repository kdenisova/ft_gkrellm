
#include <unistd.h>
#include <string>
#include "HostNameModule.hpp"

HostNameModule::HostNameModule() {
    this->_module = "HOSTNAME";

    char buff[50];

    gethostname(buff, sizeof(buff) - 1);
    this->_host = buff;
    //if ((gethostname(buff, sizeof(buff) - 1) != 0)
}

HostNameModule::~HostNameModule() {
}

HostNameModule::HostNameModule(HostNameModule const & src) {
	*this = src;
}

HostNameModule & HostNameModule::operator=(HostNameModule const & rfs) {
	this->_module = rfs._module;
    this->_host = rfs._host;
	return (*this);
}

std::string HostNameModule::getName() const {
    return (this->_module);
}

std::string HostNameModule::getHostName() const {
    return (this->_host);
}

int	    HostNameModule::getSize(std::string const name) const {
    return (name.length());
}