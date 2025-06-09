#include "bigint.hpp"

int	main(void)
{
	const bigint	a(42);
	bigint			b(21), c, d(1337), e(d);
	
	//All are in base10
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << "\"(a + b)\"--> " << (a + b) << std::endl;
	std::cout << "\"(c += a)\"--> " << (c += a) << std::endl;
	// std::cout << "\"(d <<= 2)\"--> " << (d <<= 2) << std::endl;
	std::cout << "\"((b << 10) + 42)\"--> " << ((b << 10) + 42) << std::endl;


	bigint			test;
	std::cout << "Value of TEST-> " << test << std::endl;
	test++;
	test++;
	std::cout << "Value of new *TEST-> " << test << std::endl;


	bigint x(1234);
	std::cout << "\"(x << 2)\"--> " << (x << 2) << "\n";   // prints 123400
	std::cout << "\"(x >> 2)\"--> " << (x >> 2) << "\n";   // prints   12
}