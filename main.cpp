/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:47:41 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/14 11:12:57 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "includes/NCursesRenderer.hpp"
#include "includes/GUIRender.hpp"

std::vector<IMonitorModule*> getSelectedModules(int *size, int *gsize) {
	std::ifstream ifs("config");
	try {
		if (!ifs.is_open())
			throw std::exception();
	}
	catch(std::exception& e) {
		std::cerr << e.what() << ": config file not found" << std::endl;
		exit (1);
	}

	std::string buff;
	std::vector<IMonitorModule*> m;

	while (std::getline(ifs, buff)) {
		if (buff.compare("+HOSTNAME") == 0) {
			m.push_back(new HostNameModule(*size, *gsize));
			*size += 6;
			*gsize += 170;
		}
		if (buff.compare("+OSINFO") == 0) {
			m.push_back(new OSInfoModule(*size, *gsize));
			*size += 6;
			*gsize += 170;
		}
		if (buff.compare("+DATE/TIME") == 0)
		{
			m.push_back(new DateTimeModule(*size, *gsize));
			*size += 4;
			*gsize += 120;
		}
		if (buff.compare("+CPU") == 0) {
			m.push_back(new CPUModule(*size, *gsize));
			*size += 17;
			*gsize += 460;
		}
		if (buff.compare("+RAM") == 0) {
			m.push_back(new RAMModule(*size, *gsize));
			*size += 4;
			*gsize += 120;
		}	
		if (buff.compare("+NETWORK") == 0) {
			m.push_back(new NetworkModule(*size, *gsize));
			*size += 4;
			*gsize += 120;
		}
		if (buff.compare("+DISKS") == 0) {
			m.push_back(new DisksModule(*size, *gsize));
			*size += 4;
			*gsize += 120;
		}	
	}
	
	ifs.close();
	return (m);
}

void putUsage(char *str) {
	std::cout << "usage: " << str << " [-tg]" << std::endl << std::endl;
	std::cout << " t : text mode" << std::endl;
	std::cout << " g : graphical mode" << std::endl << std::endl;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		putUsage(argv[0]);
		return (0);
	}
	std::string mode = argv[1];

	IMonitorDisplay* display;

	if (mode.compare("-t") == 0 || mode.compare("-g") == 0) {
		int size = 3;
		int gsize = 0;
		std::vector<IMonitorModule*> modules = getSelectedModules(&size, &gsize);

		if (mode.compare("-t") == 0) {
			display = new NCursesRenderer(size);
		} else if (mode.compare("-g") == 0) {
			display = new GUIRender(gsize);
		} else {
			putUsage(argv[0]);
			return (0);
		}

		while (display->isOpen()) {
			display->tick();
			
			int key;
			key = getch();
			if (key == 27)
				break ;
			for (std::vector<IMonitorModule*>::iterator it = modules.begin(); it != modules.end(); it++) {
				(*it)->refresh();
				(*it)->render(display);
			}
		}

		for (std::vector<IMonitorModule*>::iterator it = modules.begin(); it != modules.end(); it++) {	
			delete (*it);
		}

		delete display;
	}
	else {
		putUsage(argv[0]);
		return (0);
	}
	return (0);
}