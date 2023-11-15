#ifndef REPLACE_H
#define REPLACE_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>

std::string	replace_line(std::string line, std::string str, std::string rep);
void		replace(int argc, char **argv);

#endif