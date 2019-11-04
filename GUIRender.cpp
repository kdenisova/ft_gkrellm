/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIRender.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:05:10 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:47:15 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "GUIRender.hpp"
#include "HostNameModule.hpp"
#include "OSInfoModule.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

GUIRender::GUIRender() {
}

GUIRender::GUIRender(int gsize) {
    this->_x = 700;
    this->_y = gsize;
    this->_window.create(sf::VideoMode(this->_x, this->_y), "ft_gkrelmm");
    this->_window.setFramerateLimit(60);

    try {
		if (!this->_font.loadFromFile("Roboto-Regular.ttf"))
			throw std::exception();
	}
	catch(std::exception& e) {
		std::cerr << e.what() << "(GUIRender)" << ": Font not found" << std::endl;
		exit(1);
	}

    sf::Text text;
    text.setFont(this->_font);
    text.setString("*FT_GKRELLM*");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    this->_window.clear(sf::Color(201, 225, 210));
}

void GUIRender::render(HostNameModule *m) {
    int pos = m->getGPos();
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, pos);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getHostName());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, pos + 50);

    sf::Text text3;
    text3.setFont(this->_font);
    text3.setString(m->getUserName());
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(10, pos + 100);

    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
    putBoard(pos + 130);
}

void GUIRender::render(OSInfoModule *m) {
    int pos = m->getGPos();
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, pos);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getType());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, pos + 50);

    sf::Text text3;
    text3.setFont(this->_font);
    text3.setString(m->getRelease());
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(10, pos + 100);

    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text3);
    putBoard(pos + 130);

}

void GUIRender::render(DateTimeModule *m) {
    int pos = m->getGPos();
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, pos);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getDate());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, pos + 50);

    this->_window.draw(text);
    this->_window.draw(text2);
    putBoard(pos + 80);
}

void GUIRender::render(CPUModule *m) {
    int pos = m->getGPos();
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, pos);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getInfo());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, pos + 50);

    sf::Text text4;
    text4.setFont(this->_font);
    text4.setString(m->getUsage() + "  ");
    text4.setCharacterSize(28);
    text4.setFillColor(sf::Color::Black);
    text4.setStyle(sf::Text::Bold);
    text4.setPosition(10, pos + 100);

    this->_window.draw(text);
    this->_window.draw(text2);
    this->_window.draw(text4);
    
    // CPU chart

    int border_offset = 4;      // main form border size
    int bar_thickness = 17;     // chart bar thickness
    int interpolation = 2;     // Y-axis interpolation multiplier
    int base_line     = pos + 420;   // Y chart base line

    std::list<float> chart_data = m->getLastUsage((this->_x - border_offset)/bar_thickness);

    int offset = -bar_thickness;
    for (std::list<float>::iterator it = chart_data.begin(); it != chart_data.end(); it++) {
        int __height_px = (*it) * interpolation;
        sf::RectangleShape rec_bar(sf::Vector2f(bar_thickness, __height_px));
        rec_bar.setFillColor(sf::Color(18, 102, 87));
        rec_bar.move(offset+=bar_thickness, base_line - __height_px); // move this way <-<-<-<
        this->_window.draw(rec_bar);
    }
    putBoard(pos + 420);
}

void GUIRender::render(RAMModule *m) {
    int pos = m->getGPos();
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, pos);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getInfo());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, pos + 50);

    this->_window.draw(text);
    this->_window.draw(text2);
    putBoard(pos + 80);
}

void GUIRender::render(NetworkModule *m) {
    int pos = m->getGPos();
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, pos);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getInfo());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, pos + 50);

    this->_window.draw(text);
    this->_window.draw(text2);
    putBoard(pos + 80);
}

void GUIRender::render(DisksModule *m) {
    int pos = m->getGPos();
    sf::Text text;
    text.setFont(this->_font);
    text.setString(m->getName());
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(this->_x / 2 - m->getSize(m->getName()) * 10, pos);

    sf::Text text2;
    text2.setFont(this->_font);
    text2.setString(m->getInfo());
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(10, pos + 50);

    this->_window.draw(text);
    this->_window.draw(text2);
    putBoard(pos + 80);
}

bool GUIRender::isOpen() {
    return this->_window.isOpen();
}

void GUIRender::tick() {
    this->_window.display();
    this->_window.clear(sf::Color(201, 225, 210));

    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            this->_window.close();
        }
    }
}

void GUIRender::putBoard(int pos) {
    sf::Text text;
    text.setFont(this->_font);
    text.setString("____________________________________________");
    text.setCharacterSize(28);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(0, pos);
    this->_window.draw(text);
}

GUIRender::~GUIRender() {
	this->_window.close();
}

GUIRender::GUIRender(GUIRender const & src) {
	*this = src;
}

GUIRender & GUIRender::operator=(GUIRender const & rfs) {
    this->_font = rfs._font;
	this->_x = rfs._x;
	this->_y = rfs._y;
	return (*this);
}
