/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:47:41 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/01 11:47:58 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "NCursesRenderer.hpp"

int main() {
	NCursesRenderer win;

	OSInfoModule os;
	HostNameModule ho;
	DateTimeModule da;
	CPUModule cp;
	RAMModule ra;
	NetworkModule ne;

	int key;
	for (;;) {
		key = getch();
		if (key == 27)
			break ;
		
		ho.refresh();
		ho.render(&win);
		
		os.refresh();
		os.render(&win);

		da.refresh();
		da.render(&win);

		cp.refresh();
		cp.render(&win);

		ra.refresh();
		ra.render(&win);

		ne.refresh();
		ne.render(&win);
		usleep(1000000);
	}

	return (0);
}
