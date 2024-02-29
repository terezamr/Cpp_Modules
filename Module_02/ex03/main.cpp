#include "Point.hpp"

// fix: return false if the point is a vertex or edge

int	main(void)
{
	Point const a;
	Point const b(4,0);
	Point const c(0,4);
	Point const d(0.1,3);

	bool question = bsp(a, b, c, d);
	if (question == true)
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point isn't in the triangle" << std::endl;
	return 0;
}
