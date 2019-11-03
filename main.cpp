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
#include <fstream>
#include "NCursesRenderer.hpp"
#include "GUIRender.hpp"

std::vector<IMonitorModule*> getSelectedModules(int *size) {
	std::ifstream ifs("config");
	try {
		if (!ifs.is_open())
			throw std::exception();
	}
	catch(std::exception& e) {
		std::cerr << e.what() << ": config file does not find" << std::endl;
		exit (1);
	}

	std::string buff;
	std::vector<IMonitorModule*> m;

	while (std::getline(ifs, buff)) {
		if (buff.compare("+HOSTNAME") == 0) {
			m.push_back(new HostNameModule(*size));
			*size += 6;
		}
		if (buff.compare("+OSINFO") == 0) {
			m.push_back(new OSInfoModule(*size));
			*size += 6;
		}
		if (buff.compare("+DATE/TIME") == 0)
		{
			m.push_back(new DateTimeModule(*size));
			*size += 4;
		}
		if (buff.compare("+CPU") == 0) {
			m.push_back(new CPUModule(*size));
			*size += 17;
		}
		if (buff.compare("+RAM") == 0) {
			m.push_back(new RAMModule(*size));
			*size += 4;
		}	
		if (buff.compare("+NETWORK") == 0) {
			m.push_back(new NetworkModule(*size));
			*size += 4;
		}
		if (buff.compare("+DISKS") == 0) {
			m.push_back(new DisksModule(*size));
			*size += 4;
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

		std::vector<IMonitorModule*> modules = getSelectedModules(&size);
		if (mode.compare("-t") == 0) {
			display = new NCursesRenderer(size);
		} else if (mode.compare("-g") == 0) {
			display = new GUIRender();
		} 
		int key;
		for (;;) {
			key = getch();
			if (key == 27)
				break ;

			for (std::vector<IMonitorModule*>::iterator it = modules.begin(); it != modules.end(); it++) {
				(*it)->refresh();
				(*it)->render(display);
			}

			usleep(1000000);
		}
		delete display;
	}
	else {
		putUsage(argv[0]);
		return (0);
	}
	
	
	

	//std::cout << size << std::endl;
	// int key;
	// while (display->isOpen()) {
	// 	display->tick();

	// 	key = getch();
	// 	if (key == 27)
	// 		break;

	// 	for (std::vector<IMonitorModule*>::iterator it = modules.begin(); it != modules.end(); it++) {
	// 		(*it)->refresh();
	// 		(*it)->render(display);
	// 	}

		//usleep(1000000);
	//}

	
	

	return (0);
}