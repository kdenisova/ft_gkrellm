/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:08:48 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/14 11:13:13 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "includes/RAMModule.hpp"

RAMModule::RAMModule() {
}

RAMModule::RAMModule(int pos, int gpos) : _pos(pos), _gpos(gpos) {
	this->_module = "RAM";

	refresh();
}

RAMModule::~RAMModule() {
}

RAMModule::RAMModule(RAMModule const & src) {
	*this = src;
}

RAMModule & RAMModule::operator=(RAMModule const & rfs) {
	this->_module = rfs._module;
    this->_info = rfs._info;
	this->_pos = rfs._pos;
    this->_gpos = rfs._gpos;
	return (*this);
}

void RAMModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void RAMModule::refresh() {
	system("top -l 1 | grep \"PhysMem\" | awk '{print $2\" \"$3\" \"$4\" \"$5\" \"$6\" \"$7}' > ./logs/ramlog");

    std::ifstream ifs("./logs/ramlog");
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
    this->_info = buff;
	ifs.close();
}

std::string RAMModule::getName() const {
	return (this->_module);
}

int	    RAMModule::getPos() const {
    return (this->_pos);
}

int	    RAMModule::getGPos() const {
    return (this->_gpos);
}

std::string RAMModule::getInfo() const {
	return (this->_info);
}

int	    RAMModule::getSize(std::string const name) const {
	return (name.length());
}