/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:04:15 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/14 11:12:25 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string>
#include <sys/sysctl.h>
#include "includes/DateTimeModule.hpp"

DateTimeModule::DateTimeModule() {
}

DateTimeModule::DateTimeModule(int pos, int gpos) : _pos(pos), _gpos(gpos) {
	this->_module = "DATE/TIME";

	refresh();
}

DateTimeModule::~DateTimeModule() {
}

DateTimeModule::DateTimeModule(DateTimeModule const & src) {
	*this = src;
}

DateTimeModule & DateTimeModule::operator=(DateTimeModule const & rfs) {
	this->_module = rfs._module;
	this->_date = rfs._date;
	this->_pos = rfs._pos;
    this->_gpos = rfs._gpos;
	return (*this);
}

void DateTimeModule::render(IMonitorDisplay *d) {
   d->render(this);
}

void DateTimeModule::refresh() {
	char buf[29];
	
    std::time_t time = std::time(nullptr);
    std::strftime(buf, sizeof(buf), "%a %b %e %T %Z %Y", std::localtime(&time));

	this->_date = buf;
}

std::string DateTimeModule::getName() const {
	return (this->_module);
}

int	    DateTimeModule::getPos() const {
    return (this->_pos);
}

int	    DateTimeModule::getGPos() const {
    return (this->_gpos);
}

std::string DateTimeModule::getDate() const {
	return (this->_date);
}

int	    DateTimeModule::getSize(std::string const name) const {
	return (name.length());
}