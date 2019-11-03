
#ifndef DISKSMODULE_H
# define DISKSMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class DisksModule : public IMonitorModule {

private:

	std::string _module;
	std::string _info;
	int			_pos;

public:
	DisksModule(int pos);
	virtual ~DisksModule();
	DisksModule(DisksModule const & src);
	DisksModule & operator=(DisksModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	std::string getInfo() const;
	int			getSize(std::string const name) const;

};

#endif