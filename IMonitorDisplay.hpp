/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <kdenisov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:06:44 by kdenisov          #+#    #+#             */
/*   Updated: 2019/11/03 16:06:45 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

# include <iostream>
# include "OSInfoModule.hpp"
# include "HostNameModule.hpp"
# include "DateTimeModule.hpp"
# include "CPUModule.hpp"
# include "RAMModule.hpp"
# include "NetworkModule.hpp"
# include "DisksModule.hpp"

class IMonitorDisplay {

private:

    IMonitorDisplay(IMonitorDisplay const & src);
	IMonitorDisplay & operator=(IMonitorDisplay const & rfs);

public:
    IMonitorDisplay();
	virtual ~IMonitorDisplay() {}
    
    //visitor pattern 
    virtual void render(class HostNameModule *) = 0;
    virtual void render(class OSInfoModule *) = 0;
    virtual void render(class DateTimeModule *) = 0;
    virtual void render(class CPUModule *) = 0;
    virtual void render(class RAMModule *) = 0;
    virtual void render(class NetworkModule *) = 0;
    virtual void render(class DisksModule *) = 0;

    virtual bool isOpen() = 0;
    virtual void tick() = 0;
};

#endif