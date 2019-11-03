

#ifndef DATETIMEMODULE_H
# define DATETIMEMODULE_H

# include <iostream>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class DateTimeModule : public IMonitorModule {

private:

	std::string _module;
	std::string	_date;
	int			_pos;

public:
    DateTimeModule(int pos);
	virtual ~DateTimeModule();
	DateTimeModule(DateTimeModule const & src);
	DateTimeModule & operator=(DateTimeModule const & rfs);

	void 		render(class IMonitorDisplay *);
	void		refresh();
	std::string getName() const;
	int			getPos() const;
	std::string getDate() const;
    int			getSize(std::string const name) const;

};

#endif