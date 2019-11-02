
#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay() {
}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const & src) {
	*this = src;
}

IMonitorDisplay & IMonitorDisplay::operator=(IMonitorDisplay const & rfs) {
	(void)rfs;
	return (*this);
}