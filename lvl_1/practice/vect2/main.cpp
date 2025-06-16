#include "vect2.hpp"

//clear && c++ main.cpp vect2.cpp vect2.hpp && valgrind --leak-check=full --show-leak-kinds=all ./a.out
int	main(void)
{
	vect2		v1;
	vect2		v2(1, 2);
	const vect2	v3(v2);
	vect2		v4 = v2;
	int			tester = 0;

	std::cout << "v1: " << v1 << std::endl;
	v1[1] = 12;//This is where i failed
	std::cout << "v1 = " << v1 << std::endl;
	std::cout << "v2 = " << v2 << std::endl;
	std::cout << "v3 = " << v3 << std::endl;
	std::cout << "v4 = " << v4 << std::endl;

	std::cout << std::endl;
	// std::cout << "tester = " << tester++ << std::endl;//uses copy
	// std::cout << "tester = " << tester << std::endl;
	// std::cout << "tester = " << ++tester << std::endl;//adds immediately
	// std::cout << "tester = " << tester << std::endl;
	std::cout << std::endl;
	std::cout << "v4++ = " << v4++ << std::endl;// 1, 2
	std::cout << "v4 (now) = " << v4 << std::endl;// 2, 3
	std::cout << "++v4 = " << ++v4 << std::endl;// 3, 4
	std::cout << "v4-- = " << v4-- << std::endl;// 2, 3
	std::cout << "v4 (now) = " << v4 << std::endl;// 2, 3
	std::cout << "--v4 = " << --v4 << std::endl;// 1, 2

	std::cout << "[Personal Test] v1 == v1-> " << (v1 == v1) << std::endl;
	std::cout << "[Personal Test] v1 == v1-> " << (v1 == v2) << std::endl;
	std::cout << "[Personal Test] v1 != v2-> " << (v1 != v2) << std::endl;
	std::cout << "[Personal Test] v1 != v1-> " << (v1 != v1) << std::endl;

	std::cout << "v2 += v3-> " << v2 += v3 << std::endl;// 2, 4
	// std::cout << "v1 -= v2-> " << v1 -= v2 << std::endl;// -2, -4
	// std::cout << "v2 = v3 + v3-> " << v2 = v3 + v3 << std::endl;// 3, 6
	// std::cout << "v2 = 3 * v2-> " << v2 = 3 * v2 << std::endl;// 9, 18
	// std::cout << "v2 += v2 += v3> " << v2 += v2 += v3 << std::endl;// 20, 40
	// std::cout << "v1 = v1 - v1 + v1 " << v1 = v1 - v1 + v1 << std::endl;

	// std::cout << "v1: " << v1 << std::endl;
	// std::cout << "v2: " << v1 << std::endl;
	// std::cout << "-v2: " << v1 << std::endl;

	// v1[1] = 12;//This is where i failed
	// std::cout << "v1[1]: " << v1[1] << std::endl;
	
	// std::cout << "v1 = v3-> " << (v1 == v3) << std::endl;
	// std::cout << "v1 == v1-> " << (v1 == v1) << std::endl;
	// std::cout << "v1 != v3-> " << (v1 != v3) << std::endl;
}

