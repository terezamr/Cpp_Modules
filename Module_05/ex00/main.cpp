
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("A", 150);
    std::cout << a;

    Bureaucrat b("B", 1);
    std::cout << b;

    try 
    {
        Bureaucrat c("C", 151);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    
    try 
    {
        Bureaucrat d("D", 0);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    
    try 
    {
        Bureaucrat e("E", 5);
        std::cout << e;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "\n--------A------------" << std::endl;
    try 
    {
        a.decrementGrade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << a;

    try 
    {
        a.incrementGrade();
        a.incrementGrade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << a;

    std::cout << "\n--------B------------" << std::endl;
    try 
    {
        b.incrementGrade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << b;

    try 
    {
        b.decrementGrade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << b;

    return (0);
}
