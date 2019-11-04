/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:08:38 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:08:38 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_H
# define OSINFOMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class OSInfoModule : public IMonitorModule {

private:

	OSInfoModule();
	std::string _module;
	std::string	_type;
    std::string	_release;
	int			_pos;
	int			_gpos;
	
public:
    OSInfoModule(int pos, int gpos);
	virtual ~OSInfoModule();
	OSInfoModule(OSInfoModule const & src);
	OSInfoModule & operator=(OSInfoModule const & rfs);

	std::string getName() const;
	int			getPos() const;
	int   		getGPos() const;
	std::string getType() const;
    std::string getRelease() const;

	void 		render(class IMonitorDisplay *);
	void 		refresh();
    int			getSize(std::string const name) const;

};

#endif