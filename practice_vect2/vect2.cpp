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

//remember, 'this' is always a pointer
vect2::vect2(const vect2& original)
{
	*this = original;
}

vect2::~vect2() {}

int	vect2::getContainer_element(int value) const
{
	return (this->_container[value]);
}

vect2&	vect2::operator=(const vect2& other)
{
	if (this == &other)
		return (*this);
	this->_container = other._container;
		return (*this);
}

std::ostream& operator<<(std::ostream& out, const vect2& v)
{
	out << "{" << v.getContainer_element(0) << ", " << v.getContainer_element(1) << "}" << std::endl;
	return (out);
};
