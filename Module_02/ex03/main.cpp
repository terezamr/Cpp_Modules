#include "Point.hpp"

int	main(void)
{
	Point const a;
	Point const b(-20,0);
	Point const c(5,20);
	Point const d(-4,4);

	bool question = bsp(a, b, c, d);
	if (question == 1)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	return 0;
}
