#include "bigint.hpp"

bigint::bigint()
{
	//initalise
	this->_string = "0";
}

bigint::bigint(unsigned int value)
{
	std::stringstream ss;

	this->_string = value;
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
//               Additions               |
//----------------------------------------

//----------------------------------------
//               Comparsion              |
//----------------------------------------

//----------------------------------------
//            Operators(=/==)()          |
//----------------------------------------












//outside of bigint class
std::ostream&	operator<<(std::ostream& out, const bigint& v)
{
	out << "{" << v.getArbiter_value() << "}" << std::endl;
	return (out);
}