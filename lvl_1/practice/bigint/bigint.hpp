#include <string>
#include <iostream>
#include <ostream>
#include <sstream>

class bigint
{
	private:
		std::string	_arbiter;
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const std::string& str);
		bigint(const bigint& original);
		~bigint();
	
	//getter and setter
	std::string	get_arbiter() const;

	//operators
	// +
	bigint	operator+(const bigint& other) const;
	bigint	operator+(unsigned int value) const;
	// ++
	// +=
	bigint	operator+=(const bigint& other);
	bigint	operator+=(unsigned int value);
	// -
	// --
};

std::ostream&	operator<<(std::ostream& out, const bigint& other);
