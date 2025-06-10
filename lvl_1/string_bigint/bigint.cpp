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
	if (str[0] == std::string::npos)
    	this->_string = "0"; //if all are zeros
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
	std::string ss1 = this->_string;
	std::string ss2 = other._string;

	// Make sure ss1 is longer
	if (ss2.length() > ss1.length())
		std::swap(ss1, ss2);

	std::string	result = "";
	int	carry = 0;
	int	i = ss1.length() - 1;
	int	j = ss2.length() - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		int digit1 = i >= 0 ? ss1[i--] - '0' : 0;
		int digit2 = j >= 0 ? ss2[j--] - '0' : 0;
		int sum = digit1 + digit2 + carry;

		result.insert(result.begin(), (sum % 10) + '0');
		carry = sum / 10;
	}

	return bigint(result);
}

bigint	bigint::operator+(unsigned int value) const
{
	// Convert the unsigned int to a bigint
	bigint other_bigint(value); // This uses the new constructor: bigint(unsigned int val)

	// Now, simply reuse the existing bigint::operator+(const bigint& other)
	return (*this + other_bigint);
}

bigint	bigint::operator+=(const bigint& other)
{
	std::stringstream	ss1(this->getArbiter_value());
	std::stringstream	ss2(other.getArbiter_value());
	unsigned int	final_result, this_result, other_result;

	ss1 >> this_result;
	ss2 >> other_result;
	final_result = this_result + other_result;

	std::ostringstream	oss;
	oss << final_result;
	this->_string = oss.str();
	return (*this);
}

bigint	bigint::operator+=(unsigned int value)
{
	std::stringstream	ss1(this->getArbiter_value());
	unsigned int	final_result, this_result;

	ss1 >> this_result;
	final_result = this_result + value;

	std::ostringstream	oss;
	oss << final_result;
	this->_string = oss.str();
	return (*this);
}

bigint	bigint::operator++(void)
{
	*this += 1;
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint copy(*this);  // Store current state
	*this += 1;          // Reuse your +=
	return (copy);         // Return original
}


//----------------------------------------
//               Comparsion              |
//----------------------------------------
bool	bigint::operator>(const bigint& other)
{
	std::stringstream	ss1(this->getArbiter_value());
	std::stringstream	ss2(other.getArbiter_value());
	unsigned int	this_result, other_result;

	ss1 >> this_result;
	ss2 >> other_result;

	if (this_result > other_result)
		return (true);
	return (false);
}

bool	bigint::operator>(unsigned int value)
{
	std::stringstream	ss1(this->getArbiter_value());
	unsigned int	final_result, this_result;

	ss1 >> this_result;

	if (this_result > value)
		return (true);
	return (false);
}

bool	bigint::operator<(const bigint& other)
{
	std::stringstream	ss1(this->getArbiter_value());
	std::stringstream	ss2(other.getArbiter_value());
	unsigned int	this_result, other_result;

	ss1 >> this_result;
	ss2 >> other_result;

	if (this_result < other_result)
		return (true);
	return (false);
}

bool	bigint::operator<(unsigned int value)
{
	std::stringstream	ss1(this->getArbiter_value());
	unsigned int	final_result, this_result;

	ss1 >> this_result;

	if (this_result < value)
		return (true);
	return (false);
}

bigint bigint::operator<<(unsigned int shift) const
{
	bigint	copy(*this);

	if (copy._string == "0")
		return (copy);

	copy._string.append(shift, '0');  // append n zeros at the end
	return (copy);
}

bigint	bigint::operator>>(unsigned int shift) const
{
	bigint	copy(*this);

	if (copy._string == "0")
		return (copy);

	if (copy._string.size() > shift)
		copy._string.erase(copy._string.begin() + (copy._string.size() - shift), copy._string.end());
	else
	{
		copy._string.erase(copy._string.begin(), copy._string.end());
		copy._string.push_back('0');
	}
	return (copy);
}












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
	out << "{" << v.getArbiter_value() << "}";
	return (out);
}