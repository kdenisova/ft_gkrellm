

#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "CPUModule.hpp"

CPUModule::CPUModule() {
	this->_module = "CPU";

    char info[100];
    size_t size = 100;

    sysctlbyname("machdep.cpu.brand_string", &info, &size, NULL, 0);
    this->_info = info;
	refresh();
}

CPUModule::~CPUModule() {
}

CPUModule::CPUModule(CPUModule const & src) {
	*this = src;
}

CPUModule & CPUModule::operator=(CPUModule const & rfs) {
	this->_module = rfs._module;
    this->_info = rfs._info;
	return (*this);
}

void CPUModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void CPUModule::refresh() {
}

std::string CPUModule::getName() const {
	return (this->_module);
}

std::string CPUModule::getInfo() const {
	return (this->_info);
}

int	    CPUModule::getSize(std::string const name) const {
	return (name.length());
}