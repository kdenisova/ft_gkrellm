

#ifndef NetworkModule_H
# define NetworkModule_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class NetworkModule : public IMonitorModule {

private:

	std::string _module;
	std::string _info;

public:
	NetworkModule();
	virtual ~NetworkModule();
	NetworkModule(NetworkModule const & src);
	NetworkModule & operator=(NetworkModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	std::string getInfo() const;
	int			getSize(std::string const name) const;

};

#endif