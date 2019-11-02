
#ifndef RAMMODULE_H
# define RAMMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class RAMModule : public IMonitorModule {

private:

	std::string _module;
	std::string _info;

public:
	RAMModule();
	virtual ~RAMModule();
	RAMModule(RAMModule const & src);
	RAMModule & operator=(RAMModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	std::string getInfo() const;
	int			getSize(std::string const name) const;

};

#endif