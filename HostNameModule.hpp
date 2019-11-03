
#ifndef HOSTNAMEMODULE_H
# define HOSTNAMEMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class HostNameModule : public IMonitorModule {

private:

	std::string _module;
	std::string	_host;
	std::string	_user;
	

public:
    HostNameModule();
	virtual ~HostNameModule();
	HostNameModule(HostNameModule const & src);
	HostNameModule & operator=(HostNameModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	std::string getHostName() const;
	std::string getUserName() const;
    int			getSize(std::string const name) const;

};

#endif