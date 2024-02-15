#include "Whatever.hpp"

int main(void)
{
    {
        int a = 2;
        int b = 10;
        std::cout << "a: " << a << ", b: " << b << std::endl;
        swap(a, b);

        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "max: " << max(a, b) << std::endl;
        std::cout << "min: " << min(a, b) << std::endl;
        std::cout << "-------------" << std::endl;

        float   c = -2.4;
        float   d = -2.5;
        std::cout << "c: " << c << ", d: " << d << std::endl;
        swap(c, d);

        std::cout << "c: " << c << ", d: " << d << std::endl;
        std::cout << "max: " << max(c, d) << std::endl;
        std::cout << "min: " << min(c, d) << std::endl;

        std::cout << "-------------" << std::endl;
        std::string e = "apple";
        std::string f = "banana";
        std::cout << "e: " << e << ", f: " << f << std::endl;
        swap(e, f);

        std::cout << "e: " << e << ", f: " << f << std::endl;
        std::cout << "max: " << max(f, e) << std::endl;
        std::cout << "min: " << min(f, e) << std::endl;
    }
    {
        std::cout << "\n\nMAIN SUBJECT \n" << std::endl;
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    return 0;
}