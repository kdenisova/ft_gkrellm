/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:06:53 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/14 11:12:57 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/IMonitorModule.hpp"

IMonitorModule::IMonitorModule() {
}

IMonitorModule::IMonitorModule(IMonitorModule const & src) {
	*this = src;
}

IMonitorModule & IMonitorModule::operator=(IMonitorModule const & rfs) {
	(void)rfs;
	return (*this);
}