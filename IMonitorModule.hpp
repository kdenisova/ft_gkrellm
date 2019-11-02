
#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H

# include <iostream>

class IMonitorModule {

private:

    IMonitorModule(IMonitorModule const & src);
	IMonitorModule & operator=(IMonitorModule const & rfs);

public:
    IMonitorModule();
	virtual ~IMonitorModule() {}
    
    virtual std::string getName() const = 0;
    
};

#endif