/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:04:28 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:04:30 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIMEMODULE_H
# define DATETIMEMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class DateTimeModule : public IMonitorModule {

private:

	DateTimeModule();
	std::string _module;
	std::string	_date;
	int			_pos;
	int 		_gpos;

public:

    DateTimeModule(int pos, int gpos);
	virtual ~DateTimeModule();
	DateTimeModule(DateTimeModule const & src);
	DateTimeModule & operator=(DateTimeModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	int			getGPos() const;
	std::string getDate() const;
    int			getSize(std::string const name) const;

};

#endif