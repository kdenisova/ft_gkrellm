
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