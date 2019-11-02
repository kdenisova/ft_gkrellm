

#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule() {
	this->_module = "DATE/TIME";

	refresh();
}

DateTimeModule::~DateTimeModule() {
}

DateTimeModule::DateTimeModule(DateTimeModule const & src) {
	*this = src;
}

DateTimeModule & DateTimeModule::operator=(DateTimeModule const & rfs) {
	this->_module = rfs._module;
	this->_date = rfs._date;
	return (*this);
}

void DateTimeModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void DateTimeModule::refresh() {
	char buf[29];
	
    std::time_t time = std::time(nullptr);
    std::strftime(buf, sizeof(buf), "%a %b %e %T %Z %Y", std::localtime(&time));

	this->_date = buf;
}

std::string DateTimeModule::getName() const {
	return (this->_module);
}

std::string DateTimeModule::getDate() const {
	return (this->_date);
}

int	    DateTimeModule::getSize(std::string const name) const {
	return (name.length());
}