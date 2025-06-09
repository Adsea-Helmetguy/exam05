#include <string>
#include <iostream>
#include <ostream>
#include <sstream>  // Required for stringstream

class	bigint
{
	private:
		std::string _string;
		//store as an array of string not number

	public:
		// Constructors
		bigint();                    // defaults to 0
		bigint(unsigned int n);     // constructs from int
		bigint(const std::string& str_argument); // constructs from string
		bigint(const bigint& original);   // copy constructor
		~bigint();

		//getter function
		std::string	getArbiter_value() const;
		//addtion
			// +
			// +=
			// ++
		//comparison
			// >
			// <
			// << -digitshift-
			// >> -digitshift-
			// <<= -digitshift-
			// >>= -digitshift-
			// operator=()// Copy Assignment Operator
			// ==
			// !=
			// <=
			// >=
};

std::ostream& operator<<(std::ostream& out, const bigint& value);
