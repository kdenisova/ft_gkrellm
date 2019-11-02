
#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

# include <iostream>

class IMonitorDisplay {

private:

    IMonitorDisplay(IMonitorDisplay const & src);
	IMonitorDisplay & operator=(IMonitorDisplay const & rfs);

public:
    IMonitorDisplay();
	virtual ~IMonitorDisplay() {}
    
};

#endif