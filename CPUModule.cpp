/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:03:32 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 17:05:46 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sys/sysctl.h>
#include "CPUModule.hpp"

CPUModule::CPUModule(int pos) : _pos(pos) {
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
    this->_usage = rfs._usage;
    this->_stat = rfs._stat;
	return (*this);
}

void CPUModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void CPUModule::refresh() {
   
    system("top -l 1 | grep \"^CPU usage:\" | awk '{print $3}' > ./logs/cpulog");

    std::ifstream ifs("./logs/cpulog");

    try {
		if (!ifs.is_open())
			throw std::exception();
	}
	catch(std::exception& e) {
		std::cerr << e.what() << "(" << getName() << ")" << ": Failed on openning file" << std::endl;
		exit(1);
	}

    std::string buff;
    std::getline(ifs, buff);
    
    buff.erase(buff.length() - 1, buff.length());
    this->_usage = "Usage: " + buff + "%";
    float usage;
    try {
		usage = static_cast<float>(std::stof(buff));
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

    this->_stat.push_back(usage);
    ifs.close();
}

std::string CPUModule::getName() const {
	return (this->_module);
}

int	    CPUModule::getPos() const {
    return (this->_pos);
}

std::string CPUModule::getInfo() const {
	return (this->_info);
}

std::string CPUModule::getUsage() const {
	return (this->_usage);
}

std::list<float> CPUModule::getLastUsage(unsigned long n) {
    std::list<float> chart;

    if (this->_stat.size() <= n) {
        for (std::vector<float>::iterator it = this->_stat.begin(); it != this->_stat.end(); it++) {
             chart.push_back(*it);
        }
        return (chart);
    }
    for (unsigned long i = this->_stat.size() - n; i < this->_stat.size(); i++) {
         chart.push_back(this->_stat.at(i));
    }
    return (chart);
}

int	    CPUModule::getSize(std::string const name) const {
	return (name.length());
}