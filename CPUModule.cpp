

#include <unistd.h>
#include <stdlib.h>
#include <fstream>
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
    //clear();
    system("top -l 1 | grep \"^CPU usage:\" | awk '{print $3}' > cpulog");

    std::ifstream ifs("cpulog");
    std::string buff;
    std::getline(ifs, buff);
    this->_data = "Usage: " + buff + "%";
    buff.erase(buff.length() - 1, buff.length());
    float usage;
    try {
		usage = static_cast<float>(std::stof(buff));
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
    this->_usage.push_back(usage);
}

std::string CPUModule::getName() const {
	return (this->_module);
}

std::string CPUModule::getInfo() const {
	return (this->_info);
}

std::string CPUModule::getData() const {
	return (this->_data);
}

std::list<float> CPUModule::getLastUsage(unsigned long n) {
    std::list<float> chart;

    //std::cout << this->_usage.size() << std::endl;
    if (this->_usage.size() <= n) {
        for (std::vector<float>::iterator it = this->_usage.begin(); it != this->_usage.end(); it++) {
             chart.push_back(*it);
        }
        return (chart);
    }
    for (unsigned long i = this->_usage.size() - n; i < this->_usage.size(); i++) {
         chart.push_back(this->_usage.at(i));
    }
    return (chart);
}

int	    CPUModule::getSize(std::string const name) const {
	return (name.length());
}