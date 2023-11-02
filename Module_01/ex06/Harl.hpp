#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>

class Harl {
	private:
		void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
	public:
		void    complain(std::string level);
};

typedef void (Harl::*t_func)(void);

#endif