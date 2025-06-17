#include "bigint.hpp"

bigint::bigint()
{
	this->_arbiter.push_back('0');
}

bigint::bigint(unsigned int num)
{
	this->_arbiter.clear();
	std::ostringstream	ss;
	ss << num;

	this->_arbiter.assign(ss.str());
}

bigint::bigint(const std::string& str)
{
	if (str.empty())
	{
		this->_arbiter = "0";
		return ;
	}

	size_t	first_non_zero = str.find_first_not_of('0');
	if (first_non_zero == std::string::npos)
		this->_arbiter = "0"; // all zeros or empty
	else
		this->_arbiter = str.substr(first_non_zero);
}

bigint::bigint(const bigint& original)
{
	*this = original;
}

bigint::~bigint() {}

//getter and setter
std::string bigint::get_arbiter() const
{
	return(this->_arbiter);
}


//operators
// +
bigint	bigint::operator+(const bigint& other) const
{
	bigint	copy(*this);

	std::string	ss1 = this->_arbiter;
	std::string ss2 = other._arbiter;

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
	copy._arbiter = result;
	return (copy);
}

bigint	bigint::operator+(unsigned int value) const
{
	bigint	copy(value);

	return (*this + copy);
}
// ++
// +=
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




//<< / >>



//outside class
std::ostream&	operator<<(std::ostream& out, const bigint& other)
{
	out << "{" << other.get_arbiter() << "}";
	return (out);
}