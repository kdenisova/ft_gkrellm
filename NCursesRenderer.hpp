/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesRenderer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:17:57 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/01 14:17:58 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCursesRenderer_H
# define NCursesRenderer_H

#include <ncurses.h>
#include <unistd.h>
# include <iostream>
# include "IMonitorDisplay.hpp"

# include "OSInfoModule.hpp"
# include "HostNameModule.hpp"

class NCursesRenderer : public IMonitorDisplay {

private:
    WINDOW  *_win;
    int     _n; //amount of modules

public:

	NCursesRenderer();
	~NCursesRenderer();
    NCursesRenderer(NCursesRenderer const & src);
	NCursesRenderer & operator=(NCursesRenderer const & rfs);

    void render(OSInfoModule *);
    void render(HostNameModule *);

    void    update();
};

#endif
