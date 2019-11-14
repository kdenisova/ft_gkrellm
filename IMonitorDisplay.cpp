/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:06:36 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/14 11:12:57 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay() {
}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const & src) {
	*this = src;
}

IMonitorDisplay & IMonitorDisplay::operator=(IMonitorDisplay const & rfs) {
	(void)rfs;
	return (*this);
}