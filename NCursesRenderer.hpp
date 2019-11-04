/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesRenderer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:07:54 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:07:54 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSESRENDERER_H
# define NCURSESRENDERER_H

#include <ncurses.h>
#include <unistd.h>
# include <iostream>
# include "IMonitorDisplay.hpp"

# include "OSInfoModule.hpp"
# include "HostNameModule.hpp"

class NCursesRenderer : public IMonitorDisplay {

private:

    NCursesRenderer();
    WINDOW  *_win;
    int     _x;
    int     _y;

public:

	NCursesRenderer(int size);
	~NCursesRenderer();
    NCursesRenderer(NCursesRenderer const & src);
	NCursesRenderer & operator=(NCursesRenderer const & rfs);

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
