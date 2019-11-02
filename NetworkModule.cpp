

#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "NetworkModule.hpp"

NetworkModule::NetworkModule() {
	this->_module = "NETWORK";

    this->_info = "";
	refresh();
}

NetworkModule::~NetworkModule() {
}

NetworkModule::NetworkModule(NetworkModule const & src) {
	*this = src;
}

NetworkModule & NetworkModule::operator=(NetworkModule const & rfs) {
	this->_module = rfs._module;
    this->_info = rfs._info;
	return (*this);
}

void NetworkModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void NetworkModule::refresh() {
}

std::string NetworkModule::getName() const {
	return (this->_module);
}

std::string NetworkModule::getInfo() const {
	return (this->_info);
}

int	    NetworkModule::getSize(std::string const name) const {
	return (name.length());
}