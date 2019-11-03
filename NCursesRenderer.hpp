
#ifndef NCursesRenderer_H
# define NCursesRenderer_H

#include <ncurses.h>
#include <unistd.h>
# include <iostream>
# include "IMonitorDisplay.hpp"

# include "OSInfoModule.hpp"
# include "HostNameModule.hpp"

class NCursesRenderer : public IMonitorDisplay {

private:
    WINDOW  *_win;
    int     _x;
    int     _y;

public:

	NCursesRenderer(int size);
	~NCursesRenderer();
    NCursesRenderer(NCursesRenderer const & src);
	NCursesRenderer & operator=(NCursesRenderer const & rfs);

    void render(HostNameModule *);
    void render(OSInfoModule *);
    void render(class DateTimeModule *);
    void render(class CPUModule *);
    void render(class RAMModule *);
    void render(class NetworkModule *);
    void render(class DisksModule *);

    bool isOpen();
    void tick();
    void putBoard(int pos);
};

#endif
