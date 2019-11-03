

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
	sf::RenderWindow _window;
	sf::Font _font;
	//WINDOW  *_win;
	// int     _x;
	// int     _y;

public:

	GUIRender();
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
};

#endif
