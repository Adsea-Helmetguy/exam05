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
	if (str.empty())
	{
		this->_string = "0";
		return ;
	}

	size_t	first_non_zero = str.find_first_not_of('0');
	if (first_non_zero == std::string::npos)
		this->_string = "0"; // all zeros or empty
	else
		this->_string = str.substr(first_non_zero);
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
	bigint	copy(*this);

	std::string	ss1 = this->_string;
	std::string ss2 = other._string;

	if (ss2.length() > ss1.length())
		std::swap(ss1, ss2);
	
	std::string		result = "";
	int		i = ss1.length() - 1;
	int		j = ss2.length() - 1;
	int		carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		int	digit1 = i >= 0 ? ss1[i] - '0' : 0;
		int	digit2 = j >= 0 ? ss2[j] - '0' : 0;
		int	sum = digit1 + digit2 + carry;

		i--;
		j--;
		result.insert(result.begin(), (sum % 10) + '0');
		carry = sum / 10;
	}
	copy._string = result;
	return (copy);
}

bigint	bigint::operator+(unsigned int value) const
{
	// Convert the unsigned int to a bigint
	bigint copy(value); // This uses the new constructor: bigint(unsigned int val)

	// Now, simply reuse the existing bigint::operator+(const bigint& other)
	return (*this + copy);
}

bigint	bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return (*this);
}

bigint	bigint::operator+=(unsigned int value)
{
	*this = *this + value;
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
	if (this->_string.size() > other._string.size())
		return (true);
	if (this->_string.size() < other._string.size())
		return (false);

	std::string	x1 = this->_string;
	std::string	x2 = other._string;

	for (size_t i = 0; i < x1.size(); i++)
	{
		if (x1[i] != x2[i])
		{
			if (x1[i] > x2[i])
				return (true);
			else
				return (false);
		}
	}
	return (false);
}

bool	bigint::operator>(unsigned int value)
{
	bigint	other(value);
	if (this->_string.size() > other._string.size())
		return (true);
	if (this->_string.size() < other._string.size())
		return (false);

	std::string	x1 = this->_string;
	std::string	x2 = other._string;

	for (size_t i = 0; i < x1.size(); i++)
	{
		if (x1[i] != x2[i])
		{
			if (x1[i] > x2[i])
				return (true);
			else
				return (false);
		}
	}
	return (false);
}

bool	bigint::operator<(const bigint& other)
{
	if (this->_string.size() < other._string.size())
		return (true);
	if (this->_string.size() > other._string.size())
		return (false);

	std::string	x1 = this->_string;
	std::string	x2 = other._string;

	for (size_t i = 0; i < x1.size(); i++)
	{
		if (x1[i] != x2[i])
		{
			if (x1[i] < x2[i])
				return (true);
			else
				return (false);
		}
	}
	return (false);
}

bool	bigint::operator<(unsigned int value)
{
	bigint	other(value);
	if (this->_string.size() < other._string.size())
		return (true);
	if (this->_string.size() > other._string.size())
		return (false);

	std::string	x1 = this->_string;
	std::string	x2 = other._string;

	for (size_t i = 0; i < x1.size(); i++)
	{
		if (x1[i] != x2[i])
		{
			if (x1[i] < x2[i])
				return (true);
			else
				return (false);
		}
	}
	return (false);
}

bool	bigint::operator<=(const bigint& other)
{
	if ((*this < other) == true || (*this == other) == true)
		return (true);
	return (false);
}

bool	bigint::operator<=(unsigned int value)
{
	bigint	other(value);
	if ((*this < other) == true || (*this == other) == true)
		return (true);
	return (false);
}

bool	bigint::operator>=(const bigint& other)
{
	if ((*this > other) == true || (*this == other) == true)
		return (true);
	return (false);
}

bool	bigint::operator>=(unsigned int value)
{
	bigint	other(value);
	if ((*this > other) == true || (*this == other) == true)
		return (true);
	return (false);
}

bigint bigint::operator<<(unsigned int shift) const
{
	bigint	copy(*this);

	if (copy._string == "0")
		return (copy);

	copy._string.append(shift, '0');// append n zeros at the end
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
		copy._string.clear();
		copy._string.push_back('0');//you have cleared everything, add back a zero;
	}
	return (copy);
}

bigint bigint::operator<<=(unsigned int shift)
{
	if (this->_string == "0")
		return (*this);

	this->_string.append(shift, '0');// append n zeros at the end
	return (*this);
}

bigint	bigint::operator>>=(unsigned int shift)
{
	if (this->_string == "0")
		return (*this);

	if (this->_string.size() > shift)
		this->_string.erase(this->_string.begin() + (this->_string.size() - shift), this->_string.end());
	else
	{
		this->_string.clear();
		this->_string.push_back('0');//you have cleared everything, add back a zero;
	}
	return (*this);
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

bool	bigint::operator==(const bigint& other)
{
	if (this->_string == other._string)
		return (true);
	return (false);
}

bool	bigint::operator==(unsigned int shift)
{
	bigint	other(shift);

	if (this->_string == other._string)
		return (true);
	return (false);
}

bool	bigint::operator!=(const bigint& other)
{
	if (this->_string != other._string)
		return (true);
	return (false);
}

bool	bigint::operator!=(unsigned int shift)
{
	bigint	other(shift);

	if (this->_string != other._string)
		return (true);
	return (false);
}














//outside of bigint class
std::ostream&	operator<<(std::ostream& out, const bigint& v)
{
	out << "{" << v.getArbiter_value() << "}";
	return (out);
}
