

#ifndef CPUMODULE_H
# define CPUMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class CPUModule : public IMonitorModule {

private:

	std::string _module;
	std::string _info;

public:
	CPUModule();
	virtual ~CPUModule();
	CPUModule(CPUModule const & src);
	CPUModule & operator=(CPUModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	std::string getInfo() const;
	int			getSize(std::string const name) const;

};

#endif