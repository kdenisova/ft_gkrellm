
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sys/sysctl.h>
#include <thread>
#include "TopListener.hpp"

TopListener::TopListener() {
}

TopListener::~TopListener() {
}

TopListener::TopListener(TopListener const & src) {
	*this = src;
}

TopListener & TopListener::operator=(TopListener const & rfs) {
	(void)rfs;
    return (*this);
}

void watch() {
    while(true) {
        system("top -l 1 | grep \"^CPU usage:\" | awk '{print $3}' > cpulog");
        usleep(1000);
    }
}

int TopListener::start() const {
    std::thread first (watch);
    first.detach();
    return 1;
}

int TopListener::stop() const {
    return 1;
}
