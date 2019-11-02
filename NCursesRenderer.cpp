
#include <string>
#include "NCursesRenderer.hpp"
#include "HostNameModule.hpp"
#include "OSInfoModule.hpp"

NCursesRenderer::NCursesRenderer() {
	this->_n = 6;
	cbreak();
	nodelay(stdscr, TRUE);
	initscr(); // Initialize the NCursesRenderer
	noecho();
	timeout(1);
	keypad(stdscr, true);
	curs_set(FALSE); // Don't display a cursor

	this->_win = newwin(10 * this->_n + 4, 30, 0, 0);
	refresh();
	box(this->_win, 0, 0);
	mvwprintw(this->_win, 1, 9, "*FT_GKRELLM*");
	mvwprintw(this->_win, 2, 1, "____________________________");
	wrefresh(this->_win);
}

void NCursesRenderer::render(OSInfoModule *m) {
	mvwprintw(this->_win, 13, 15 - m->getSize(m->getName()) / 2, const_cast<char*>(m->getName().c_str()));
	mvwprintw(this->_win, 14, 0, "");
	mvwprintw(this->_win, 15, 15 - m->getSize(m->getType()) / 2, const_cast<char*>(m->getType().c_str()));
	mvwprintw(this->_win, 16, 0, "");
	mvwprintw(this->_win, 17, 15 - m->getSize(m->getRelease()) / 2, const_cast<char*>(m->getRelease().c_str()));

	mvwprintw(this->_win, 22, 1, "____________________________");
	mvwprintw(this->_win, 32, 1, "____________________________");
	mvwprintw(this->_win, 42, 1, "____________________________");
	mvwprintw(this->_win, 52, 1, "____________________________");
	wrefresh(this->_win);
}

void NCursesRenderer::render(HostNameModule *m) {
	mvwprintw(this->_win, 3, 15 - m->getSize(m->getName()) / 2, const_cast<char*>(m->getName().c_str()));
	mvwprintw(this->_win, 4, 0, "");
	mvwprintw(this->_win, 5, 15 - m->getSize(m->getHostName()) / 2, const_cast<char*>(m->getHostName().c_str()));
	mvwprintw(this->_win, 12, 1, "____________________________");
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

