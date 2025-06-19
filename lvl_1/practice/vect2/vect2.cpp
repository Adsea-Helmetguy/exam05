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


//getters
int		vect2::getcontainer_element(int array) const
{
	return (this->_container[array]);
}

//operators
	// +
	// ++
	vect2	vect2::operator++(int)
	{
		vect2	copy(*this);
	
		this->_container[0] += 1;
		this->_container[1] += 1;
		return (copy);
	}

	vect2	vect2::operator++(void)
	{
		this->_container[0] += 1;
		this->_container[1] += 1;
		return (*this);
	}

	// +=
	vect2	vect2::operator+=(int value)
	{
		this->_container[0] += value;
		this->_container[1] += value;
		return (*this);
	}

	vect2	vect2::operator+=(const vect2& other)
	{
		this->_container[0] += other._container[0];
		this->_container[1] += other._container[1];
		return (*this);
	}
	// -
	// --
		vect2	vect2::operator--(int)
	{
		vect2	copy(*this);
	
		this->_container[0] -= 1;
		this->_container[1] -= 1;
		return (copy);
	}

	vect2	vect2::operator--(void)
	{
		this->_container[0] -= 1;
		this->_container[1] -= 1;
		return (*this);
	}
	// *

	//[]
	int		vect2::operator[](int array) const
	{
		return (this->_container[array]);
	}

	int&	vect2::operator[](int array)
	{
		return (this->_container[array]);
	}

	// ==
	bool	vect2::operator==(const vect2& other) const
	{
		if (this->_container[0] == other._container[0] && this->_container[1] == other._container[1])
			return (true);
		return (false);
	}

	// !=
	bool	vect2::operator!=(const vect2& other) const
	{
		if (this->_container[0] != other._container[0] || this->_container[1] != other._container[1])
			return (true);
		return (false);
	}



std::ostream&	operator<<(std::ostream& out, const vect2& other)
{
	out << "{" << other[0] << ", " << other[1] << "}";
	return (out);
}