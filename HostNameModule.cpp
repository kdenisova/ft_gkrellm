/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostNameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:03:12 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:03:17 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <unistd.h>
#include <string>
#include "HostNameModule.hpp"

HostNameModule::HostNameModule(int pos) : _pos(pos) {
    this->_module = "HOSTNAME";

    char buff[50];

    gethostname(buff, sizeof(buff) - 1);
    this->_host = "Hostname: ";
    this->_host += buff;

    system("whoami > userlog");

    std::ifstream ifs("userlog");
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

std::string HostNameModule::getHostName() const {
    return (this->_host);
}

std::string HostNameModule::getUserName() const {
    return (this->_user);
}

int	    HostNameModule::getSize(std::string const name) const {
    return (name.length());
}