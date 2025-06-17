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


//getters and setters
int		vect2::getcontainer_element(int array) const
{
	return (this->_container[array]);
}

void	vect2::setcontainer_element(int array, int value)
{
	this->_container[array] = value;
	this->_container[array] = value;
}

//operators
	// +
	vect2	vect2::operator+(int value) const
	{
		vect2	copy(*this);

		copy._container[0] += value;
		copy._container[1] += value;
		return (copy);
	}

	vect2	vect2::operator+(const vect2& other) const
	{
		vect2	copy(*this);

		copy._container[0] += other.getcontainer_element(0);
		copy._container[1] += other.getcontainer_element(1);
		return (copy);
	}
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
	vect2&	vect2::operator+=(int value)
	{
		this->_container[0] += value;
		this->_container[1] += value;
		return (*this);
	}

	vect2&	vect2::operator+=(const vect2& other)
	{
		this->_container[0] += other.getcontainer_element(0);
		this->_container[1] += other.getcontainer_element(1);
		return (*this);
	}
	// -
	vect2	vect2::operator-(int value) const
	{
		vect2	copy(*this);
	
		copy._container[0] -= 1;
		copy._container[1] -= 1;
		return (copy);
	}
	vect2	vect2::operator-(const vect2& other) const
	{
		vect2	copy(*this);

		copy._container[0] -= other.getcontainer_element(0);
		copy._container[1] -= other.getcontainer_element(1);
		return (copy);
	}
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
	// -=
	vect2&	vect2::operator-=(int value)
	{
		this->_container[0] -= value;
		this->_container[1] -= value;
		return (*this);
	}

	vect2&	vect2::operator-=(const vect2& other)
	{
		this->_container[0] -= other._container[0];
		this->_container[1] -= other._container[1];
		return (*this);
	}


	// *
	vect2	vect2::operator*(int value) const
	{
		vect2	copy(*this);
	
		copy._container[0] *= value;
		copy._container[1] *= value;
		return (copy);
	}

	vect2	vect2::operator*(const vect2& other) const
	{
		vect2	copy(*this);
	
		copy._container[0] -= other._container[0];
		copy._container[1] -= other._container[1];
		return (copy);
	}

	//[]
	int		vect2::operator[](int array) const
	{
		return (this->_container[array]);
	}

	int&	vect2::operator[](int array)
	{
		return (this->_container[array]);
	}

	// =
	vect2& vect2::operator=(const vect2& other)
	{
		if (this != &other) // always good to check self-assignment
			this->_container = other._container;
		return (*this);
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


vect2	operator*(int value, const vect2& other)
{
	vect2	copy(other);

	copy.setcontainer_element(0, (copy.getcontainer_element(0) * value));
	copy.setcontainer_element(1, (copy.getcontainer_element(1) * value));
	return (copy);
}

std::ostream&	operator<<(std::ostream& out, const vect2& other)
{
	out << "{" << other[0] << ", " << other[1] << "}";
	return (out);
}