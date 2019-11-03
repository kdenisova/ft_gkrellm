
#include <string>
#include "GUIRender.hpp"
#include "HostNameModule.hpp"
#include "OSInfoModule.hpp"
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>

GUIRender::GUIRender() {
    this->_window.create(sf::VideoMode(600, 1600), "ft_gkrelmm");

    sf::RectangleShape module(sf::Vector2f(600, 200));
    module.setFillColor(sf::Color::White);

    if (!this->_font.loadFromFile("Roboto-Regular.ttf"))
    {
        std::cout << "no font!" << std::endl;
    }

    sf::Text text;
    text.setFont(this->_font);
    text.setString("*FT_GKRELLM*");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
   
    /*
    while (this->_window.isOpen())
    {
        sf::Event event;
        while (this->_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->_window.close();
        }

        _window.clear(sf::Color(150, 150, 150));
        //window.draw(module);
        _window.draw(text);

        this->_window.display();
    }
    */

    // this->_x = 47;
	// this->_y = 44;
	// cbreak();
	// nodelay(stdscr, TRUE);
	// initscr(); // Initialize the GUIRender
	// noecho();
	// timeout(1);
	// keypad(stdscr, true);
	// curs_set(FALSE); // Don't display a cursor

	// this->_win = newwin(this->_x, this->_y, 0, 0);
	// refresh();
	// box(this->_win, 0, 0);
	// mvwprintw(this->_win, 1, this->_y / 2 - 6, "*FT_GKRELLM*");
	// mvwprintw(this->_win, 2, 1, "__________________________________________");
	// wrefresh(this->_win);
}

void GUIRender::render(HostNameModule *m) {
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);

    this->_window.clear(sf::Color(150, 150, 150));
    this->_window.draw(text);
    this->_window.display();

	// mvwprintw(this->_win, 3, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	// mvwprintw(this->_win, 5, this->_y / 2 - m->getSize(m->getHostName()) / 2, m->getHostName().c_str());
	// mvwprintw(this->_win, 7, this->_y / 2 - m->getSize(m->getUserName()) / 2, m->getUserName().c_str());
	// mvwprintw(this->_win, 8, 1, "__________________________________________");
	// wrefresh(this->_win);
}

void GUIRender::render(OSInfoModule *m) {
     m->getName();
	// mvwprintw(this->_win, 9, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	// mvwprintw(this->_win, 11, this->_y / 2 - m->getSize(m->getType()) / 2, m->getType().c_str());
	// mvwprintw(this->_win, 13, this->_y / 2 - m->getSize(m->getRelease()) / 2, m->getRelease().c_str());
	// mvwprintw(this->_win, 14, 1, "__________________________________________");
	// wrefresh(this->_win);
}

void GUIRender::render(DateTimeModule *m) {
     m->getName();
	// mvwprintw(this->_win, 15, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	// mvwprintw(this->_win, 17, this->_y / 2 - m->getSize(m->getDate()) / 2, m->getDate().c_str());
	// mvwprintw(this->_win, 18, 1, "__________________________________________");
	// wrefresh(this->_win);
}

void GUIRender::render(CPUModule *m) {
     m->getName();
	// mvwprintw(this->_win, 19, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	// mvwprintw(this->_win, 21, this->_y / 2 - m->getSize(m->getInfo()) / 2, m->getInfo().c_str());
	// mvwprintw(this->_win, 23, 15, "                            ");
	// mvwprintw(this->_win, 23, this->_y / 2 - m->getSize(m->getUsage()) / 2, m->getUsage().c_str());
	
	// std::list<float> chart = m->getLastUsage(this->_y - 2);
	// int pos;
	// int i = 1;
	// for (std::list<float>::iterator it = chart.begin(); it != chart.end(); it++) {
	// 	pos = (*it * 10) / 100 + 1;
	// 	for (int j = 0; j < 10; j++) {
	// 		mvwprintw(this->_win, 33 - j, i, " ");
	// 	}
	// 	for (int j = 0; j < pos; j++) {
	// 		mvwprintw(this->_win, 33 - j, i, "|");
	// 	}
	// 	i++;
	// }
	
	// mvwprintw(this->_win, 34, 1, "__________________________________________");
	// wrefresh(this->_win);
}

void GUIRender::render(RAMModule *m) {
     m->getName();
	// mvwprintw(this->_win, 35, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	// mvwprintw(this->_win, 37, this->_y / 2 - m->getSize(m->getInfo()) / 2, m->getInfo().c_str());
	// mvwprintw(this->_win, 38, 1, "__________________________________________");
	// wrefresh(this->_win);
}

void GUIRender::render(NetworkModule *m) {
     m->getName();
	// mvwprintw(this->_win, 39, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	// mvwprintw(this->_win, 41, this->_y / 2 - m->getSize(m->getInfo()) / 2, m->getInfo().c_str());
	// mvwprintw(this->_win, 42, 1, "__________________________________________");
	// wrefresh(this->_win);
}

void GUIRender::render(DisksModule *m) {
     m->getName();
	// mvwprintw(this->_win, 43, this->_y / 2 - m->getSize(m->getName()) / 2, m->getName().c_str());
	// mvwprintw(this->_win, 45, this->_y / 2 - m->getSize(m->getInfo()) / 2, m->getInfo().c_str());
	// //mvwprintw(this->_win, 46, 1, "__________________________________________");
	// wrefresh(this->_win);
}

bool GUIRender::isOpen() {
    return this->_window.isOpen();
}

void GUIRender::tick() {
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            this->_window.close();
        }
    }

    _window.clear(sf::Color(150, 150, 150));
    this->_window.display();
}

GUIRender::~GUIRender() {
	//endwin();
}

GUIRender::GUIRender(GUIRender const & src) {
	*this = src;
}

GUIRender & GUIRender::operator=(GUIRender const & rfs) {
	(void)rfs;
	return (*this);
}

