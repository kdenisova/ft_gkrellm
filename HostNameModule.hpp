/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostNameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:06:28 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:06:29 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_H
# define HOSTNAMEMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class HostNameModule : public IMonitorModule {

private:

	HostNameModule();
	std::string _module;
	std::string	_host;
	std::string	_user;
	int			_pos;
	int 		_gpos;

public:

    HostNameModule(int pos, int gpos);
	virtual ~HostNameModule();
	HostNameModule(HostNameModule const & src);
	HostNameModule & operator=(HostNameModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	int			getGPos() const;
	std::string getHostName() const;
	std::string getUserName() const;
    int			getSize(std::string const name) const;

};

#endif