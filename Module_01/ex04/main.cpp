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

int main(int argc, char **argv)
{
    if (argc != 4)
	{
		std::cout << "Unexpected input" << std::endl;
		return (0);
	}
	std::fstream file;
	std::ofstream file1;
	std::string a = argv[2];
	std::string b = argv[3];
	file.open(argv[1]);
	if (!file) 
	{
		std::cout << "The file does not exist" << std::endl;
		return (0);
	}
	strcat(argv[1],".replace");
	file1.open(argv[1]);
	std::string line;
	while (getline(file, line))
	{
		line = replace_line(line, a, b);
		file1 << line << std::endl;
	}
	file.close();
	file1.close();
	return (0);
}
