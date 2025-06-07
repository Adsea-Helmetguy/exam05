#include "bigint.hpp"

bigint::bigint()
{
	//initalise
	this->_arbiter = 0;
}

bigint::bigint(unsigned int value)
{
	this->_arbiter = value;
}

bigint::bigint(const bigint& original)
{
	*this = original;
}

bigint::~bigint() {}



//getter
unsigned int	bigint::getArbiter_value() const
{
	return (this->_arbiter);
}







//----------------------------------------
//            Operators+()               |
//----------------------------------------
bigint	bigint::operator+(const bigint& other) const
{
	bigint	copy(*this);

	copy._arbiter += other._arbiter;
	return (copy);
}

bigint	bigint::operator+(unsigned int value) const
{
	bigint	copy(*this);

	copy._arbiter += value;
	return (copy);
}

//	Operators+=()
bigint	bigint::operator+=(const bigint& other)
{
	this->_arbiter += other._arbiter;
	return (*this);
}

bigint	bigint::operator+=(unsigned int value)
{
	this->_arbiter += value;
	return (*this);
}

//Operators++()
bigint	bigint::operator++(void)
{
	this->_arbiter += 1;
	return (*this);
}

bigint	bigint::operator++(int)
{
	bigint	copy(*this);

	this->_arbiter += 1;
	return (copy);
}

//----------------------------------------
//            Operators(>/<)()           |
//----------------------------------------
bool	bigint::operator>(unsigned int value)
{
	//Greater-than
	if (this->_arbiter > value)
		return (true);
	return (false);
}

bool	bigint::operator>(const bigint& compare)
{
	//Greater-than
	if (this->_arbiter > compare._arbiter)
		return (true);
	return (false);
}

bool	bigint::operator<(unsigned int value)
{
	//lesser-than
	if (this->_arbiter < value)
		return (true);
	return (false);
}

bool	bigint::operator<(const bigint& compare)
{
	//lesser-than
	if (this->_arbiter < compare._arbiter)
		return (true);
	return (false);
}

bigint	bigint::operator<<(size_t n) const
{
	// Shift left by n digits (base 10)
	bigint result = *this;

	for (size_t i = 0; i < n; ++i)
		result._arbiter /= 10;
	return (result);
}

bigint	bigint::operator>>(size_t n) const
{
	//shift right by n digits (base 10)
	bigint result = *this;

	for (size_t i = 0; i < n; ++i)
		result._arbiter *= 10;
	return (result);
}

bigint	bigint::operator<<=(size_t n)
{
	// Shift left by n digits (base 10)
	for (size_t i = 0; i < n; ++i)
		this->_arbiter /= 10;
	return (*this);
}

bigint	bigint::operator>>=(size_t n)
{
	//shift right by n digits (base 10)
	for (size_t i = 0; i < n; ++i)
		this->_arbiter *= 10;
	return (*this);
}


//----------------------------------------
//            Operators(=/==)()          |
//----------------------------------------
bigint&	bigint::operator=(const bigint& other)
{
	if (this == &other)
		return (*this);

	this->_arbiter = other._arbiter;
	return (*this);
}

bigint&	bigint::operator=(unsigned int value)
{
	this->_arbiter = value;
	return (*this);
}

bool	bigint::operator==(const bigint& other)
{
	if (this == &other)
		return (true);
	if (this->_arbiter == other._arbiter)
		return (true);
	return (false);
}

bool	bigint::operator==(unsigned int value)
{
	if (this->_arbiter == value)
		return (true);

	return (false);
}

bool	bigint::operator!=(const bigint& other)
{
	if (this != &other)
		return (true);
	if (this->_arbiter != other._arbiter)
		return (true);
	return (false);
}

bool	bigint::operator!=(unsigned int value)
{
	if (this->_arbiter != value)
		return (true);

	return (false);
}

bool	bigint::operator<=(const bigint& other)
{
	if (this <= &other)
		return (true);
	if (this->_arbiter <= other._arbiter)
		return (true);
	return (false);
}

bool	bigint::operator<=(unsigned int value)
{
	if (this->_arbiter <= value)
		return (true);

	return (false);
}

bool	bigint::operator>=(const bigint& other)
{
	if (this >= &other)
		return (true);
	if (this->_arbiter >= other._arbiter)
		return (true);
	return (false);
}

bool	bigint::operator>=(unsigned int value)
{
	if (this->_arbiter >= value)
		return (true);

	return (false);
}













//outside of bigint class
std::ostream&	operator<<(std::ostream& out, const bigint& v)
{
	out << "{" << v.getArbiter_value() << "}" << std::endl;
	return (out);
}