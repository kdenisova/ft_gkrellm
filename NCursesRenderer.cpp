
#include <string>
#include "NCursesRenderer.hpp"
#include "HostNameModule.hpp"
#include "OSInfoModule.hpp"

NCursesRenderer::NCursesRenderer() {
	this->_x = 6 * 10 + 4;
	this->_y = 44;
	cbreak();
	nodelay(stdscr, TRUE);
	initscr(); // Initialize the NCursesRenderer
	noecho();
	timeout(1);
	keypad(stdscr, true);
	curs_set(FALSE); // Don't display a cursor

	this->_win = newwin(this->_x, this->_y, 0, 0);
	refresh();
	box(this->_win, 0, 0);
	mvwprintw(this->_win, 1, this->_y / 2 - 6, "*FT_GKRELLM*");
	mvwprintw(this->_win, 2, 1, "__________________________________________");
	wrefresh(this->_win);
}

void NCursesRenderer::render(HostNameModule *m) {
	mvwprintw(this->_win, 3, this->_y / 2 - m->getSize(m->getName()) / 2, const_cast<char*>(m->getName().c_str()));
	mvwprintw(this->_win, 4, 0, "");
	mvwprintw(this->_win, 5, this->_y / 2 - m->getSize(m->getHostName()) / 2, const_cast<char*>(m->getHostName().c_str()));
	mvwprintw(this->_win, 12, 1, "__________________________________________");
	wrefresh(this->_win);
}

void NCursesRenderer::render(OSInfoModule *m) {
	mvwprintw(this->_win, 13, this->_y / 2 - m->getSize(m->getName()) / 2, const_cast<char*>(m->getName().c_str()));
	mvwprintw(this->_win, 14, 0, "");
	mvwprintw(this->_win, 15, this->_y / 2 - m->getSize(m->getType()) / 2, const_cast<char*>(m->getType().c_str()));
	mvwprintw(this->_win, 16, 0, "");
	mvwprintw(this->_win, 17, this->_y / 2 - m->getSize(m->getRelease()) / 2, const_cast<char*>(m->getRelease().c_str()));
	mvwprintw(this->_win, 22, 1, "__________________________________________");
	
	
	wrefresh(this->_win);
}

void NCursesRenderer::render(DateTimeModule *m) {
	mvwprintw(this->_win, 23, this->_y / 2 - m->getSize(m->getName()) / 2, const_cast<char*>(m->getName().c_str()));
	mvwprintw(this->_win, 24, 0, "");
	mvwprintw(this->_win, 25, this->_y / 2 - m->getSize(m->getDate()) / 2, const_cast<char*>(m->getDate().c_str()));
	mvwprintw(this->_win, 32, 1, "__________________________________________");
	wrefresh(this->_win);
}

void NCursesRenderer::render(CPUModule *m) {
	mvwprintw(this->_win, 33, this->_y / 2 - m->getSize(m->getName()) / 2, const_cast<char*>(m->getName().c_str()));
	mvwprintw(this->_win, 34, 0, "");
	mvwprintw(this->_win, 35, this->_y / 2 - m->getSize(m->getInfo()) / 2, const_cast<char*>(m->getInfo().c_str()));
	mvwprintw(this->_win, 42, 1, "__________________________________________");
	wrefresh(this->_win);
}

void NCursesRenderer::render(RAMModule *m) {
	mvwprintw(this->_win, 43, this->_y / 2 - m->getSize(m->getName()) / 2, const_cast<char*>(m->getName().c_str()));
	mvwprintw(this->_win, 44, 0, "");
	mvwprintw(this->_win, 45, this->_y / 2 - m->getSize(m->getInfo()) / 2, const_cast<char*>(m->getInfo().c_str()));
	mvwprintw(this->_win, 52, 1, "__________________________________________");
	wrefresh(this->_win);
}

void NCursesRenderer::render(NetworkModule *m) {
	mvwprintw(this->_win, 53, this->_y / 2 - m->getSize(m->getName()) / 2, const_cast<char*>(m->getName().c_str()));
	mvwprintw(this->_win, 54, 0, "");
	mvwprintw(this->_win, 55, this->_y / 2 - m->getSize(m->getInfo()) / 2, const_cast<char*>(m->getInfo().c_str()));
	wrefresh(this->_win);
}


NCursesRenderer::~NCursesRenderer() {
	endwin();
}

NCursesRenderer::NCursesRenderer(NCursesRenderer const & src) {
	*this = src;
}

NCursesRenderer & NCursesRenderer::operator=(NCursesRenderer const & rfs) {
	(void)rfs;
	return (*this);
}

