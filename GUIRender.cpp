/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIRender.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:05:10 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:05:11 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "GUIRender.hpp"
#include "HostNameModule.hpp"
#include "OSInfoModule.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

GUIRender::GUIRender() {
    this->_x = 700;
    this->_y = 1600;
    this->_window.create(sf::VideoMode(this->_x, this->_y), "ft_gkrelmm");

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
    this->_window.clear(sf::Color(150, 150, 150));
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
    text4.setString("____________________________________________");
    text4.setCharacterSize(28);
    text4.setFillColor(sf::Color::Black);
    text4.setStyle(sf::Text::Bold);
    text4.setPosition(0, 130);

    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
    this->_window.draw(text4);
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
    text4.setString("____________________________________________");
    text4.setCharacterSize(28);
    text4.setFillColor(sf::Color::Black);
    text4.setStyle(sf::Text::Bold);
    text4.setPosition(0, 300);

    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
    this->_window.draw(text4);

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
    text3.setString("____________________________________________");
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(0, 420);

    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
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

    // sf::Text text3;
    // text3.setFont(this->_font);
    // text3.setString("                                         ");
    // text3.setCharacterSize(28);
    // text3.setFillColor(sf::Color::Black);
    // text3.setStyle(sf::Text::Bold);
    // text3.setPosition(10, 560);
    
    sf::Text text4;
    text4.setFont(this->_font);
    text4.setString(m->getUsage() + "  ");
    text4.setCharacterSize(28);
    text4.setFillColor(sf::Color::Black);
    text4.setStyle(sf::Text::Bold);
    text4.setPosition(10, 560);

    sf::Text text5;
    text5.setFont(this->_font);
    text5.setString("____________________________________________");
    text5.setCharacterSize(28);
    text5.setFillColor(sf::Color::Black);
    text5.setStyle(sf::Text::Bold);
    text5.setPosition(0, 590);

    this->_window.draw(text);
    this->_window.draw(text2);
    //this->_window.draw(text3);
    this->_window.draw(text4);
    this->_window.draw(text5);

	
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
}

void GUIRender::render(RAMModule *m) {
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, 630);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getInfo());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, 680);

    sf::Text text3;
    text3.setFont(this->_font);
    text3.setString("____________________________________________");
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(0, 710);

    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
}

void GUIRender::render(NetworkModule *m) {
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, 750);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getInfo());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, 800);

    sf::Text text3;
    text3.setFont(this->_font);
    text3.setString("____________________________________________");
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(0, 830);

    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
}

void GUIRender::render(DisksModule *m) {
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, 870);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getInfo());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, 920);

    sf::Text text3;
    text3.setFont(this->_font);
    text3.setString("____________________________________________");
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(0, 950);

    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
}

bool GUIRender::isOpen() {
    return this->_window.isOpen();
}

void GUIRender::tick() {
    this->_window.display();
    this->_window.clear(sf::Color(150, 150, 150));

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

