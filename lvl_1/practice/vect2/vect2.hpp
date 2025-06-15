#include <string>
#include <iostream>
#include <ostream>
#include <vector>

class vect2
{
	private:
		std::vector<int>	_container; 
	public:
		vect2();
		vect2(int v1, int v2);
		vect2(const vect2& original);//copy assignment
		~vect2();

	//getter and setter
	void	setContainer_element();
	int		getContainer_element(int array);

	

	//operators
	// +
	// -
	// *
	// []
	int		operator[](int array_access) const;
	int&	operator[](int array_access);
};

std::ostream&	operator<<(std::ostream& out, const vect2& value);
