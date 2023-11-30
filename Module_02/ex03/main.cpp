#include "Point.hpp"

// problema : vetores perpendiculares
int	main(void)
{
	Point const a;
	Point const b(15,0);
	Point const c(-1,15);
	Point const d(1,1);

	bool question = bsp(a, b, c, d);
	std::cout << "final " << question << std::endl;
	if (question == 1)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	return 0;
}
