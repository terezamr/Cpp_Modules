
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n---------------------" << std::endl;
    try 
    {
        Bureaucrat a("A", 150);
        std::cout << a;

        Bureaucrat b("B", 1);
        std::cout << b;

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
        Bureaucrat a("A", 150);
        a.decrementGrade();
        std::cout << a;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    try 
    {
        Bureaucrat a("A", 150);
        a.incrementGrade();
        a.incrementGrade();
        std::cout << a;
        a.decrementGrade();
        a.decrementGrade();
        a.decrementGrade();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "\n--------B------------" << std::endl;
    try 
    {
        Bureaucrat b("B", 1);
        b.incrementGrade();
        std::cout << b;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    try 
    {
        Bureaucrat b("B", 1);
        b.decrementGrade();
        std::cout << b;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    return (0);
}
