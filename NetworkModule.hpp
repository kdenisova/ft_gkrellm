

#ifndef NetworkModule_H
# define NetworkModule_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class NetworkModule : public IMonitorModule {

private:

	std::string _module;
	std::string _info;
	int			_pos;

public:
	NetworkModule(int pos);
	virtual ~NetworkModule();
	NetworkModule(NetworkModule const & src);
	NetworkModule & operator=(NetworkModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	std::string getInfo() const;
	int			getSize(std::string const name) const;

};

#endif