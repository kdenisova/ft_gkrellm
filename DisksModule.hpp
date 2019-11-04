/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisksModule.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:04:51 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:04:52 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISKSMODULE_H
# define DISKSMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class DisksModule : public IMonitorModule {

private:

	DisksModule();
	std::string _module;
	std::string _info;
	int			_pos;
	int 		_gpos;

public:

	DisksModule(int pos, int gpos);
	virtual ~DisksModule();
	DisksModule(DisksModule const & src);
	DisksModule & operator=(DisksModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	int			getGPos() const;
	std::string getInfo() const;
	int			getSize(std::string const name) const;

};

#endif