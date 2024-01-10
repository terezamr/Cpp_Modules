#include "Form.hpp"

int main(void)
{
    Form f1("f1", 30, 2);
    std::cout << f1;
    std::cout << std::endl;

    Form f2("f2", 3, 2);
    std::cout << f1;
    std::cout << std::endl;

    Bureaucrat b("bu", 5);
    f1.beSigned(b);
    b.signForm(f1.getName(), f1.getSign());

    std::cout << std::endl;

    f2.beSigned(b);
    b.signForm(f2.getName(), f2.getSign());
}
