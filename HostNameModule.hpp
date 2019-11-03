
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
	int			_pos;

public:
    HostNameModule(int pos);
	virtual ~HostNameModule();
	HostNameModule(HostNameModule const & src);
	HostNameModule & operator=(HostNameModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	std::string getHostName() const;
	std::string getUserName() const;
    int			getSize(std::string const name) const;

	
};

#endif