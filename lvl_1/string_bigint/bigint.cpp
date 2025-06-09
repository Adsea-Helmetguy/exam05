#include "bigint.hpp"

bigint::bigint()
{
	//initalise
	this->_string = "0";
}

bigint::bigint(unsigned int value)
{
	std::ostringstream oss;
	oss << value;

	this->_string = oss.str();
}

bigint::bigint(const std::string& str)
{
    this->_string = str;
}

bigint::bigint(const bigint& original)
{
	*this = original;
}

bigint::~bigint() {}



//getter
std::string	bigint::getArbiter_value() const
{
	return (this->_string);
}







//----------------------------------------
//               Additions               |
//----------------------------------------
bigint	bigint::operator+(const bigint& other) const
{
	std::stringstream ss1(other.getArbiter_value());
	std::stringstream ss2(this->getArbiter_value());
	unsigned int val1, val2;
	bigint	copy(*this);

	ss1 >> val1;
	ss2 >> val2;

	unsigned int result = val1 + val2;
	std::ostringstream oss;
	oss << result;

	return bigint(oss.str());
}

// bigint	operator+(unsigned int value)
// {

// }

// bigint	operator+(std::string str) const;

//----------------------------------------
//               Comparsion              |
//----------------------------------------

//----------------------------------------
//            Operators(=/==)()          |
//----------------------------------------
bigint&	bigint::operator=(const bigint& other)
{
	if (this == &other)
		return (*this);

	this->_string = other._string;
	return (*this);
}











//outside of bigint class
std::ostream&	operator<<(std::ostream& out, const bigint& v)
{
	out << "{" << v.getArbiter_value() << "}" << std::endl;
	return (out);
}