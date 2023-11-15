#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "\nI cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "\nI think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    const char* levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    t_func fc[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    while (i < 4 && level != levels[i])
        i++;
    if (i < 4)
    {
		(this->*fc[i])();
        return ;
    }
    std::cout << "\nLevel doesn't exist." << std::endl;
}
