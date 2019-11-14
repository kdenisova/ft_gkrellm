/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIRender.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:05:18 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:49:32 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIRENDER_H
# define GUIRENDER_H

#include <ncurses.h>
#include <unistd.h>
# include <iostream>
# include "IMonitorDisplay.hpp"
# include "OSInfoModule.hpp"
# include "HostNameModule.hpp"
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>

class GUIRender : public IMonitorDisplay {

private:

	GUIRender();
	sf::RenderWindow	_window;
	sf::Font 			_font;
	int     			_x;
	int    				_y;

public:

	GUIRender(int gsize);
	~GUIRender();
	GUIRender(GUIRender const & src);
	GUIRender & operator=(GUIRender const & rfs);

	void render(HostNameModule *);
	void render(OSInfoModule *);
	void render(class DateTimeModule *);
	void render(class CPUModule *);
	void render(class RAMModule *);
	void render(class NetworkModule *);
	void render(class DisksModule *);

	bool isOpen();
	void tick();
	void putBoard(int pos);
};

#endif
