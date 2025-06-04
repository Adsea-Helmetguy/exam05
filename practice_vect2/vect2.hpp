#include <string>
#include <iostream>
#include <ostream>
#include <vector>

//info std::vector

class vect2
{
	private:
		std::vector<int>	_container;

	public:
		vect2();
		vect2(int v1, int v2);
		vect2(const vect2& original);
		~vect2();

		//getter function:
		int	getContainer_element(int value) const;

		//Operators
		vect2&	operator=(const vect2& other);//copy assignment operator

};

// << operator
std::ostream& operator<<(std::ostream& out, const vect2& v);
