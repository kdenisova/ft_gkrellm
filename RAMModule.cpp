
#include <fstream>
#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "RAMModule.hpp"

RAMModule::RAMModule(int pos) : _pos(pos) {
	this->_module = "RAM";

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
	system("top -l 1 | grep \"PhysMem\" | awk '{print $2\" \"$3\" \"$4\" \"$5\" \"$6\" \"$7}' > ramlog");

    std::ifstream ifs("ramlog");
    std::string buff;
    std::getline(ifs, buff);
    this->_info = buff;
}

std::string RAMModule::getName() const {
	return (this->_module);
}

int	    RAMModule::getPos() const {
    return (this->_pos);
}

std::string RAMModule::getInfo() const {
	return (this->_info);
}

int	    RAMModule::getSize(std::string const name) const {
	return (name.length());
}