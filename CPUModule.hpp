

#ifndef CPUMODULE_H
# define CPUMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"
# include <vector>
# include <list>

class CPUModule : public IMonitorModule {

private:

	std::string _module;
	std::string _info;
	std::vector<float> _usage;
	std::string	_data;

public:
	CPUModule();
	virtual ~CPUModule();
	CPUModule(CPUModule const & src);
	CPUModule & operator=(CPUModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	std::string getInfo() const;
	std::string getData() const;
	std::list<float> getLastUsage(unsigned long n);
	int			getSize(std::string const name) const;

};

#endif