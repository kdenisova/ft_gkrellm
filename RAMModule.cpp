

#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "RAMModule.hpp"

RAMModule::RAMModule() {
	this->_module = "RAM";

    this->_info = "";
	refresh();
}

RAMModule::~RAMModule() {
}

RAMModule::RAMModule(RAMModule const & src) {
	*this = src;
}

RAMModule & RAMModule::operator=(RAMModule const & rfs) {
	this->_module = rfs._module;
    this->_info = rfs._info;
	return (*this);
}

void RAMModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void RAMModule::refresh() {
}

std::string RAMModule::getName() const {
	return (this->_module);
}

std::string RAMModule::getInfo() const {
	return (this->_info);
}

int	    RAMModule::getSize(std::string const name) const {
	return (name.length());
}