/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:08:31 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/14 11:13:13 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "includes/OSInfoModule.hpp"

OSInfoModule::OSInfoModule() {
}

OSInfoModule::OSInfoModule(int pos, int gpos) : _pos(pos), _gpos(gpos){
    this->_module = "OSINFO";


    this->_type = "Type: ";
    this->_release = "Release: ";

    char type[100];
    char release[100];
    size_t size = 100;

    sysctlbyname("kern.ostype", &type, &size, NULL, 0);
    this->_type += type;
    sysctlbyname("kern.osrelease", &release, &size, NULL, 0);
    this->_release += release;
}

OSInfoModule::~OSInfoModule() {
}

OSInfoModule::OSInfoModule(OSInfoModule const & src) {
	*this = src;
}

OSInfoModule & OSInfoModule::operator=(OSInfoModule const & rfs) {
	this->_module = rfs._module;
    this->_type = rfs._type;
    this->_release = rfs._release;
    this->_pos = rfs._pos;
    this->_gpos = rfs._gpos;
	return (*this);
}

void OSInfoModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void OSInfoModule::refresh() {
}

std::string OSInfoModule::getName() const {
    return (this->_module);
}

int	    OSInfoModule::getPos() const {
    return (this->_pos);
}

int	    OSInfoModule::getGPos() const {
    return (this->_gpos);
}

std::string OSInfoModule::getType() const {
    return (this->_type);
}

std::string OSInfoModule::getRelease() const {
    return (this->_release);
}

int	    OSInfoModule::getSize(std::string const name) const {
    return (name.length());
}