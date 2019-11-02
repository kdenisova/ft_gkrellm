
#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule() {
}

IMonitorModule::IMonitorModule(IMonitorModule const & src) {
	*this = src;
}

IMonitorModule & IMonitorModule::operator=(IMonitorModule const & rfs) {
	(void)rfs;
	return (*this);
}