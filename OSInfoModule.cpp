

#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule(int pos) : _pos(pos){
    this->_module = "OSINFO";


    this->_type = "Type: ";
    this->_release = "Release: ";

    char type[100];
    char release[100];
    size_t size = 100;

    sysctlbyname("kern.ostype", &type, &size, NULL, 0);
    this->_type += type;
    sysctlbyname("kern.osrelease", &release, &size, NULL, 0);
    this->_release += release;
}

OSInfoModule::~OSInfoModule() {
}

OSInfoModule::OSInfoModule(OSInfoModule const & src) {
	*this = src;
}

OSInfoModule & OSInfoModule::operator=(OSInfoModule const & rfs) {
	this->_module = rfs._module;
    this->_type = rfs._type;
    this->_release = rfs._release;
	return (*this);
}

void OSInfoModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void OSInfoModule::refresh() {
}

std::string OSInfoModule::getName() const {
    return (this->_module);
}

int	    OSInfoModule::getPos() const {
    return (this->_pos);
}

std::string OSInfoModule::getType() const {
    return (this->_type);
}

std::string OSInfoModule::getRelease() const {
    return (this->_release);
}

int	    OSInfoModule::getSize(std::string const name) const {
    return (name.length());
}