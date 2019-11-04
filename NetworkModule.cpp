/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:08:01 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:08:02 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "NetworkModule.hpp"

NetworkModule::NetworkModule(int pos) : _pos(pos) {
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
	return (*this);
}

void NetworkModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void NetworkModule::refresh() {
	system("top -l 1 | grep \"Network\" | awk '{print $2\" \"$3\" \"$4\" \"$5\" \"$6}' > ./logs/netlog");

    std::ifstream ifs("./logs/netlog");
    std::string buff;
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

std::string NetworkModule::getInfo() const {
	return (this->_info);
}

int	    NetworkModule::getSize(std::string const name) const {
	return (name.length());
}