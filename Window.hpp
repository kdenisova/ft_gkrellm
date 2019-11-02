/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:17:57 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/01 14:17:58 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

#include <ncurses.h>
#include <iostream>
#include <unistd.h>
# include <iostream>

class Window {

private:

    int     _n; //amount of modules

public:

	Window();
	~Window();
    Window(Window const & src);
	Window & operator=(Window const & rfs);

    void    update();
};

#endif
