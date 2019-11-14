/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesRenderer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:07:15 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/14 11:15:16 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "includes/NCursesRenderer.hpp"

NCursesRenderer::NCursesRenderer() {
}

NCursesRenderer::NCursesRenderer(int size) {
	this->_x = size;
	this->_y = 52;
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
	putBoard(2);
	wrefresh(this->_win);
}

void NCursesRenderer::render(HostNameModule *m) {
	int pos = m->getPos();
	mvwprintw(this->_win, pos, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	mvwprintw(this->_win, pos + 2, this->_y / 2 - m->getSize(m->getHostName()) / 2, m->getHostName().c_str());
	mvwprintw(this->_win, pos + 4, this->_y / 2 - m->getSize(m->getUserName()) / 2, m->getUserName().c_str());
	if (pos + 5 < this->_x - 1)
		putBoard(pos + 5);
	wrefresh(this->_win);
}

void NCursesRenderer::render(OSInfoModule *m) {
	int pos = m->getPos();
	mvwprintw(this->_win, pos, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	mvwprintw(this->_win, pos + 2, this->_y / 2 - m->getSize(m->getType()) / 2, m->getType().c_str());
	mvwprintw(this->_win, pos + 4, this->_y / 2 - m->getSize(m->getRelease()) / 2, m->getRelease().c_str());
	if (pos + 5 < this->_x - 1)
		putBoard(pos + 5);
	wrefresh(this->_win);
}

void NCursesRenderer::render(DateTimeModule *m) {
	int pos = m->getPos();
	mvwprintw(this->_win, pos, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	mvwprintw(this->_win, pos + 2, this->_y / 2 - m->getSize(m->getDate()) / 2, m->getDate().c_str());
	if (pos + 3 < this->_x - 1)
		putBoard(pos + 3);
	wrefresh(this->_win);
}

void NCursesRenderer::render(CPUModule *m) {
	int pos = m->getPos();
	mvwprintw(this->_win, pos, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	mvwprintw(this->_win, pos + 2, this->_y / 2 - m->getSize(m->getInfo()) / 2, m->getInfo().c_str());
	mvwprintw(this->_win, pos + 4, 15, "                            ");
	mvwprintw(this->_win, pos + 4, this->_y / 2 - m->getSize(m->getUsage()) / 2, m->getUsage().c_str());
	std::list<float> chart = m->getLastUsage(this->_y - 2);
	int x;
	int i = 1;
	for (std::list<float>::iterator it = chart.begin(); it != chart.end(); it++) {
		x = (*it * 10) / 100 + 1;
		for (int j = 0; j < 10; j++) {
			mvwprintw(this->_win, (pos + 15) - j, i, " ");
		}
		for (int j = 0; j < x; j++) {
			mvwprintw(this->_win, (pos + 15) - j, i, "|");
		}
		i++;
	}
	if (pos + 16 < this->_x - 1)
		putBoard(pos + 16);
	wrefresh(this->_win);
}

void NCursesRenderer::render(RAMModule *m) {
	int pos = m->getPos();
	mvwprintw(this->_win, pos, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	mvwprintw(this->_win, pos + 2, this->_y / 2 - m->getSize(m->getInfo()) / 2, m->getInfo().c_str());
	if (pos + 3 < this->_x - 1)
		putBoard(pos + 3);
	wrefresh(this->_win);
}

void NCursesRenderer::render(NetworkModule *m) {
	int pos = m->getPos();
	mvwprintw(this->_win, pos, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	mvwprintw(this->_win, pos + 2, this->_y / 2 - m->getSize(m->getInfo()) / 2, m->getInfo().c_str());
	if (pos + 3 < this->_x - 1)
		putBoard(pos + 3);
	wrefresh(this->_win);
}

void NCursesRenderer::render(DisksModule *m) {
	int pos = m->getPos();
	mvwprintw(this->_win, pos, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	mvwprintw(this->_win, pos + 2, this->_y / 2 - m->getSize(m->getInfo()) / 2, m->getInfo().c_str());
	if (pos + 3 < this->_x - 1)
		putBoard(pos + 3);
	wrefresh(this->_win);
}

bool NCursesRenderer::isOpen() {
	return true;
}

void NCursesRenderer::tick() {
	usleep(1000000);
}

void NCursesRenderer::putBoard(int pos) {
	for (int i = 1; i < this->_y - 1; i ++) 
		mvwprintw(this->_win, pos, i, "_");
}

NCursesRenderer::~NCursesRenderer() {
	endwin();
}

NCursesRenderer::NCursesRenderer(NCursesRenderer const & src) {
	*this = src;
}

NCursesRenderer & NCursesRenderer::operator=(NCursesRenderer const & rfs) {
	this->_win = rfs._win;
	this->_x = rfs._x;
	this->_y = rfs._y;
	return (*this);
}

