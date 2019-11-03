
#ifndef RAMMODULE_H
# define RAMMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class RAMModule : public IMonitorModule {

private:

	std::string _module;
	std::string _info;
	int			_pos;

public:
	RAMModule(int pos);
	virtual ~RAMModule();
	RAMModule(RAMModule const & src);
	RAMModule & operator=(RAMModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	std::string getInfo() const;
	int			getSize(std::string const name) const;

};

#endif