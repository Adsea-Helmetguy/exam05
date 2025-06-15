#include "vect2.hpp"

vect2::vect2()
{
	this->_container.push_back(0);
	this->_container.push_back(0);
}

vect2::vect2(int v1, int v2)
{
	this->_container.push_back(v1);
	this->_container.push_back(v2);
}

vect2::vect2(const vect2& original)
{
	*this = original;
}

vect2::~vect2() {}



int		vect2::operator[](int array_access) const
{
	return (this->_container[array_access]);
}

int&	vect2::operator[](int array_access)
{
	return (this->_container[array_access]);
}

std::ostream&	operator<<(std::ostream& out, const vect2& value)
{
	out << "{" << value[0] << ", " << value[1] << "}";
	return (out);
};
