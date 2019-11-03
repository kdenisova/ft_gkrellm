

#ifndef TOPLISTENER_H
# define TOPLISTENER_H

# include <iostream>

class TopListener {

private:

public:
    TopListener();
	virtual ~TopListener();
	TopListener(TopListener const & src);
	TopListener & operator=(TopListener const & rfs);

    int start() const;
    int stop() const;
};

#endif