/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:08:01 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:59:36 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "NetworkModule.hpp"

NetworkModule::NetworkModule() {
}

NetworkModule::NetworkModule(int pos, int gpos) : _pos(pos), _gpos(gpos) {
	this->_module = "NETWORK";

	refresh();
}

NetworkModule::~NetworkModule() {
}

NetworkModule::NetworkModule(NetworkModule const & src) {
	*this = src;
}

NetworkModule & NetworkModule::operator=(NetworkModule const & rfs) {
	this->_module = rfs._module;
    this->_info = rfs._info;
	this->_pos = rfs._pos;
    this->_gpos = rfs._gpos;
	return (*this);
}

void NetworkModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void NetworkModule::refresh() {
	system("top -l 1 | grep \"Network\" | awk '{print $2\" \"$3\" \"$4\" \"$5\" \"$6}' > ./logs/netlog");

    std::ifstream ifs("./logs/netlog");
    std::string buff;
	try {
		if (!ifs.is_open())
			throw std::exception();
	}
	catch(std::exception& e) {
		std::cerr << e.what() << "(" << getName() << ")" << ": Failed on openning file" << std::endl;
		exit(1);
	}
	
    std::getline(ifs, buff);
    this->_info = buff;
	ifs.close();
}

std::string NetworkModule::getName() const {
	return (this->_module);
}

int	    NetworkModule::getPos() const {
    return (this->_pos);
}

int	    NetworkModule::getGPos() const {
    return (this->_gpos);
}

std::string NetworkModule::getInfo() const {
	return (this->_info);
}

int	    NetworkModule::getSize(std::string const name) const {
	return (name.length());
}