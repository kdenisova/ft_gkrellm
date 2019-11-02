
#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

# include <iostream>
# include "OSInfoModule.hpp"
# include "HostNameModule.hpp"
# include "DateTimeModule.hpp"
# include "CPUModule.hpp"
# include "RAMModule.hpp"
# include "NetworkModule.hpp"

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

};

#endif