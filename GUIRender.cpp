
#include <string>
#include "GUIRender.hpp"
#include "HostNameModule.hpp"
#include "OSInfoModule.hpp"
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>

GUIRender::GUIRender() {
    this->_x = 600;
    this->_y = 1600;
    this->_window.create(sf::VideoMode(this->_x, this->_y), "ft_gkrelmm");

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
   
}

void GUIRender::render(HostNameModule *m) {
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, 0);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getHostName());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, 50);

    sf::Text text3;
    text3.setFont(this->_font);
    text3.setString(m->getUserName());
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(10, 100);

    sf::Text text4;
    text4.setFont(this->_font);
    text4.setString("______________________________________");
    text4.setCharacterSize(28);
    text4.setFillColor(sf::Color::Black);
    text4.setStyle(sf::Text::Bold);
    text4.setPosition(0, 130);

    this->_window.clear(sf::Color(150, 150, 150));
    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
    this->_window.draw(text4);
    this->_window.display();
}

void GUIRender::render(OSInfoModule *m) {
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, 170);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getType());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, 220);

    sf::Text text3;
    text3.setFont(this->_font);
    text3.setString(m->getRelease());
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(10, 270);

    sf::Text text4;
    text4.setFont(this->_font);
    text4.setString("______________________________________");
    text4.setCharacterSize(28);
    text4.setFillColor(sf::Color::Black);
    text4.setStyle(sf::Text::Bold);
    text4.setPosition(0, 300);

    this->_window.clear(sf::Color(150, 150, 150));
    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
    this->_window.draw(text4);
    this->_window.display();

}

void GUIRender::render(DateTimeModule *m) {
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, 340);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getDate());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, 390);

    sf::Text text3;
    text3.setFont(this->_font);
    text3.setString("______________________________________");
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(0, 420);

    this->_window.clear(sf::Color(150, 150, 150));
    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
    this->_window.display();
}

void GUIRender::render(CPUModule *m) {
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, 460);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getInfo());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, 510);

    sf::Text text3;
    text3.setFont(this->_font);
    text3.setString(m->getUsage());
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(10, 560);

    sf::Text text4;
    text4.setFont(this->_font);
    text4.setString("______________________________________");
    text4.setCharacterSize(28);
    text4.setFillColor(sf::Color::Black);
    text4.setStyle(sf::Text::Bold);
    text4.setPosition(0, 590);

    this->_window.clear(sf::Color(150, 150, 150));
    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
    this->_window.draw(text4);
    this->_window.display();

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
    //this->_window.clear(sf::Color(150, 150, 150));
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            this->_window.close();
        }
    }
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

