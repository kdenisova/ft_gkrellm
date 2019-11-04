/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:03:58 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:04:07 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_H
# define CPUMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"
# include <vector>
# include <list>

class CPUModule : public IMonitorModule {

private:

	std::string 		_module;
	std::string 		_info;
	std::string			_usage;
	std::vector<float> 	_stat;
	int					_pos;

public:
	CPUModule(int pos);
	virtual ~CPUModule();
	CPUModule(CPUModule const & src);
	CPUModule & operator=(CPUModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	std::string getInfo() const;
	std::string getUsage() const;
	std::list<float> getLastUsage(unsigned long n);
	int			getSize(std::string const name) const;

};

#endif