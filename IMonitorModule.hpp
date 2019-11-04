/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:06:59 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:49:32 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H

# include <iostream>
//# include "IMonitorDisplay.hpp"

class IMonitorModule {

private:

    IMonitorModule(IMonitorModule const & src);
	IMonitorModule & operator=(IMonitorModule const & rfs);

public:
    IMonitorModule();
	virtual ~IMonitorModule() {}
    
    virtual std::string getName() const = 0;
    virtual int         getPos() const = 0;
    virtual void        refresh() = 0;
    
    //visitor pattern
    virtual void        render(class IMonitorDisplay *) = 0;

};

#endif