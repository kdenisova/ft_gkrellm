/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisksModule.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:04:44 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 17:01:24 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "DisksModule.hpp"

DisksModule::DisksModule() {
}

DisksModule::DisksModule(int pos, int gpos) : _pos(pos), _gpos(gpos) {
	this->_module = "DISKS";

	refresh();
}

DisksModule::~DisksModule() {
}

DisksModule::DisksModule(DisksModule const & src) {
	*this = src;
}

DisksModule & DisksModule::operator=(DisksModule const & rfs) {
	this->_module = rfs._module;
	this->_info = rfs._info;
	this->_pos = rfs._pos;
    this->_gpos = rfs._gpos;
	return (*this);
}

void DisksModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void DisksModule::refresh() {
	system("top -l 1 | grep \"Disks\" | awk '{print $2\" \"$3\" \"$4\" \"$5}' > ./logs/disklog");

	std::ifstream ifs("./logs/disklog");

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

std::string DisksModule::getName() const {
	return (this->_module);
}

int	    DisksModule::getPos() const {
    return (this->_pos);
}

int	    DisksModule::getGPos() const {
    return (this->_gpos);
}

std::string DisksModule::getInfo() const {
	return (this->_info);
}

int	    DisksModule::getSize(std::string const name) const {
	return (name.length());
}