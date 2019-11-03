

#ifndef OSINFOMODULE_H
# define OSINFOMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class OSInfoModule : public IMonitorModule {

private:

	std::string _module;
	std::string	_type;
    std::string	_release;
	int			_pos;
	
public:
    OSInfoModule(int pos);
	virtual ~OSInfoModule();
	OSInfoModule(OSInfoModule const & src);
	OSInfoModule & operator=(OSInfoModule const & rfs);

	std::string getName() const;
	int			getPos() const;
	std::string getType() const;
    std::string getRelease() const;

	void 		render(class IMonitorDisplay *);
	void 		refresh();
    int			getSize(std::string const name) const;

};

#endif