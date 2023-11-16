#include "Replace.hpp"

std::string	replace_line(std::string line, std::string str, std::string rep)
{
	int i = line.find(str, 0);
	size_t len = str.size();
	while (i >= 0)
	{
		line.erase(i, len);
		line.insert(i, rep);
		i = line.find(str, i + rep.size());
		i = line.find(str, i);
	}
	return (line);
}

void	replace(int argc, char **argv)
{
	std::fstream file;
	std::ofstream file1;
	std::string a = argv[2];
	std::string b = argv[3];
	file.open(argv[1]);
	std::string line0;
	if (!file) 
	{
		std::cout << "The file does not exist" << std::endl;
		return ;
	}
	getline(file, line0);
	if (line0 == "\0")
	{
		std::cout << "Empty file" << std::endl;
		file.close();
		return ;
	}
	strcat(argv[1],".replace");
	file1.open(argv[1]);

	line0 = replace_line(line0, a, b);
	file1 << line0 << std::endl;

	std::string line;
	while (getline(file, line))
	{
		line = replace_line(line, a, b);
		file1 << line << std::endl;
	}
	file.close();
	file1.close();
}
