/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:08:22 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:08:25 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_H
# define NETWORKMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class NetworkModule : public IMonitorModule {

private:

	NetworkModule();
	std::string _module;
	std::string _info;
	int			_pos;
	int 		_gpos;

public:

	NetworkModule(int pos, int gpos);
	virtual ~NetworkModule();
	NetworkModule(NetworkModule const & src);
	NetworkModule & operator=(NetworkModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	int			getGPos() const;
	std::string getInfo() const;
	int			getSize(std::string const name) const;

};

#endif