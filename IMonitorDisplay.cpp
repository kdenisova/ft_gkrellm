/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:06:36 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:06:38 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay() {
}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const & src) {
	*this = src;
}

IMonitorDisplay & IMonitorDisplay::operator=(IMonitorDisplay const & rfs) {
	(void)rfs;
	return (*this);
}