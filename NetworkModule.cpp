
#include <fstream>
#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "NetworkModule.hpp"

NetworkModule::NetworkModule() {
	this->_module = "NETWORK";

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
	system("top -l 1 | grep \"Network\" | awk '{print $2\" \"$3\" \"$4\" \"$5\" \"$6}' > netlog");

    std::ifstream ifs("netlog");
    std::string buff;
    std::getline(ifs, buff);
    this->_info = buff;
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