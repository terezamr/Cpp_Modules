#include "Bureaucrat.hpp"

// duvidas
// forma canonica aplica se? exeption classes?
// confirmar necessidade try and catch quando nao se usa o int?

int main(void)
{
    Bureaucrat b("Bu", 2);
    std::cout << b;
    b.decrementGrade();
    std::cout << b;
    b.incrementGrade();
    std::cout << b;
    b.incrementGrade();
    std::cout << b;
    b.incrementGrade();
    std::cout << b;

    Bureaucrat d("Du", 149);
    std::cout << d;
    d.decrementGrade();
    std::cout << d;
    d.decrementGrade();
    std::cout << d;
    return 0;
}
