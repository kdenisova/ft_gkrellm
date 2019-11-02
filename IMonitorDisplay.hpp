
#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

# include <iostream>
# include "OSInfoModule.hpp"
# include "HostNameModule.hpp"

class IMonitorDisplay {

private:

    IMonitorDisplay(IMonitorDisplay const & src);
	IMonitorDisplay & operator=(IMonitorDisplay const & rfs);

public:
    IMonitorDisplay();
	virtual ~IMonitorDisplay() {}
    
    //visitor pattern 
    virtual void render(class OSInfoModule *) = 0;
    virtual void render(class HostNameModule *) = 0;

};

#endif