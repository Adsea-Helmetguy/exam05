#include <string>
#include <iostream>
#include <ostream>

class	bigint
{
	private:
		unsigned int _arbiter;
		//store as an array of string not number

	public:
		bigint();
		bigint(unsigned int value);
		bigint(const bigint& original);
		~bigint();

		//getter function
		unsigned int	getArbiter_value() const;
		//addtion
			// +
			bigint	operator+(const bigint& other) const;
			bigint	operator+(unsigned int value) const;
			// +=
			bigint	operator+=(const bigint& other);
			bigint	operator+=(unsigned int value);
			// ++
			bigint	operator++(void);
			bigint	operator++(int);
		//comparison
			// >
			bool	operator>(unsigned int value);
			bool	operator>(const bigint& compare);
			// <
			bool	operator<(const bigint& compare);
			bool	operator<(unsigned int value);
			// << -digitshift-
			bigint	operator<<(size_t n) const;
			// >> -digitshift-
			bigint	operator>>(size_t n) const;
			// <<= -digitshift-
			bigint	operator<<=(size_t n);
			// >>= -digitshift-
			bigint	operator>>=(size_t n);
			// operator=()
			bigint&	operator=(const bigint& other);// Copy Assignment Operator
			bigint&	operator=(unsigned int value);
			// ==
			bool	operator==(const bigint& other);
			bool	operator==(unsigned int value);
			// !=
			bool	operator!=(const bigint& other);
			bool	operator!=(unsigned int value);
			// <=
			bool	operator<=(const bigint& other);
			bool	operator<=(unsigned int value);
			// >=
			bool	operator>=(const bigint& other);
			bool	operator>=(unsigned int value);
};

std::ostream& operator<<(std::ostream& out, const bigint& value);
