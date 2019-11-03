
#include <fstream>
#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "DisksModule.hpp"

DisksModule::DisksModule() {
	this->_module = "DISKS";

	refresh();
}

DisksModule::~DisksModule() {
}

DisksModule::DisksModule(DisksModule const & src) {
	*this = src;
}

DisksModule & DisksModule::operator=(DisksModule const & rfs) {
	this->_module = rfs._module;
	this->_info = rfs._info;
	return (*this);
}

void DisksModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void DisksModule::refresh() {
	system("top -l 1 | grep \"Disks\" | awk '{print $2\" \"$3\" \"$4\" \"$5}' > disklog");

	std::ifstream ifs("disklog");
	std::string buff;
	std::getline(ifs, buff);
	this->_info = buff;
}

std::string DisksModule::getName() const {
	return (this->_module);
}

std::string DisksModule::getInfo() const {
	return (this->_info);
}

int	    DisksModule::getSize(std::string const name) const {
	return (name.length());
}