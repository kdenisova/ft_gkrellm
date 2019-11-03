/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:47:41 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/01 11:47:58 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "NCursesRenderer.hpp"

std::vector<IMonitorModule*> getSelectedModules() {
	std::vector<IMonitorModule*> m;
	m.push_back(new OSInfoModule());
	m.push_back(new HostNameModule());
	m.push_back(new DateTimeModule());
	m.push_back(new CPUModule());
	m.push_back(new RAMModule());
	m.push_back(new NetworkModule());
	m.push_back(new DisksModule());

	return (m);
}

int main() {
	NCursesRenderer win;

	std::vector<IMonitorModule*> modules = getSelectedModules();
	
	int key;
	for (;;) {
		key = getch();
		if (key == 27)
			break ;

		for (std::vector<IMonitorModule*>::iterator it = modules.begin(); it != modules.end(); it++) {
			(*it)->refresh();
			(*it)->render(&win);
		}
		usleep(1000000);
	}

	return (0);
}
