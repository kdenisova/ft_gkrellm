
#include <string>
#include "Window.hpp"
#include "HostNameModule.hpp"
#include "OSInfoModule.hpp"

Window::Window() {
	this->_n = 6;
	cbreak();
	nodelay(stdscr, TRUE);
	initscr(); // Initialize the window
	noecho();
	timeout(1);
	keypad(stdscr, true);
	curs_set(FALSE); // Don't display a cursor

	WINDOW *win = newwin(10 * this->_n + 4, 30, 0, 0);
	refresh();
	box(win, 0, 0);
	mvwprintw(win, 1, 9, "*FT_GKRELLM*");
	mvwprintw(win, 2, 1, "____________________________");
	
	HostNameModule host;
	
	mvwprintw(win, 3, 15 - host.getSize(host.getName()) / 2, const_cast<char*>(host.getName().c_str()));
	mvwprintw(win, 4, 0, "");
	mvwprintw(win, 5, 15 - host.getSize(host.getHostName()) / 2, const_cast<char*>(host.getHostName().c_str()));
	mvwprintw(win, 12, 1, "____________________________");

	OSInfoModule os;

	mvwprintw(win, 13, 15 - os.getSize(os.getName()) / 2, const_cast<char*>(os.getName().c_str()));
	mvwprintw(win, 14, 0, "");
	mvwprintw(win, 15, 15 - os.getSize(os.getType()) / 2, const_cast<char*>(os.getType().c_str()));
	mvwprintw(win, 16, 0, "");
	mvwprintw(win, 17, 15 - os.getSize(os.getRelease()) / 2, const_cast<char*>(os.getRelease().c_str()));

	mvwprintw(win, 22, 1, "____________________________");
	mvwprintw(win, 32, 1, "____________________________");
	mvwprintw(win, 42, 1, "____________________________");
	mvwprintw(win, 52, 1, "____________________________");
	wrefresh(win);
	
	
	int key;

	for (;;) {
		key = getch();
		if (key == 27)
			break ;
		usleep(500000/3);
	}
}

Window::~Window() {
	endwin();
}

Window::Window(Window const & src) {
	*this = src;
}

Window & Window::operator=(Window const & rfs) {
	(void)rfs;
	return (*this);
}

