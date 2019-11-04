/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostNameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:03:12 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 17:02:10 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <unistd.h>
#include <string>
#include "HostNameModule.hpp"

HostNameModule::HostNameModule() {
}

HostNameModule::HostNameModule(int pos, int gpos) : _pos(pos), _gpos(gpos) {
    this->_module = "HOSTNAME";

    char buff[50];

    gethostname(buff, sizeof(buff) - 1);
    this->_host = "Hostname: ";
    this->_host += buff;

    system("whoami > ./logs/userlog");

    std::ifstream ifs("./logs/userlog");
    
    try {
		if (!ifs.is_open())
			throw std::exception();
	}
	catch(std::exception& e) {
		std::cerr << e.what() << "(" << getName() << ")" << ": Failed on openning file" << std::endl;
		exit(1);
	}

    std::string user;
    std::getline(ifs, user);
    this->_user = "Username: " + user;
    ifs.close();
}

HostNameModule::~HostNameModule() {
}

HostNameModule::HostNameModule(HostNameModule const & src) {
	*this = src;
}

HostNameModule & HostNameModule::operator=(HostNameModule const & rfs) {
	this->_module = rfs._module;
    this->_host = rfs._host;
    this->_user = rfs._user;
    this->_pos = rfs._pos;
    this->_gpos = rfs._gpos;
	return (*this);
}

void HostNameModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void HostNameModule::refresh() {
}

std::string HostNameModule::getName() const {
    return (this->_module);
}

int	    HostNameModule::getPos() const {
    return (this->_pos);
}

int	    HostNameModule::getGPos() const {
    return (this->_gpos);
}

std::string HostNameModule::getHostName() const {
    return (this->_host);
}

std::string HostNameModule::getUserName() const {
    return (this->_user);
}

int	    HostNameModule::getSize(std::string const name) const {
    return (name.length());
}