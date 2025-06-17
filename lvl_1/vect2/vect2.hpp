#include <string>
#include <vector>
#include <iostream>
#include <ostream>

class vect2
{
	private:
		std::vector<int>		_container;

	public:
		vect2();
		vect2(int v1, int v2);
		vect2(const vect2& original);
		~vect2();
	
	//getter and setter
	int		getcontainer_element(int array) const;
	void	setcontainer_element(int array, int value);

	//operators()
	// +
	vect2	operator+(int value) const;
	vect2	operator+(const vect2& other)const;
	// ++
	vect2	operator++(int);
	vect2	operator++(void);
	// +=
	vect2&	operator+=(int value);
	vect2&	operator+=(const vect2& other);
	// -
	vect2	operator-(int value) const;
	vect2	operator-(const vect2& other) const;
	// --
	vect2	operator--(int);
	vect2	operator--(void);
	// -=
	vect2&	operator-=(int value);
	vect2&	operator-=(const vect2& other);
	// *
	vect2	operator*(int value) const;
	vect2	operator*(const vect2& other) const;

	// []
	int		operator[](int array) const;
	int&	operator[](int array);

	// =
	vect2&	operator=(const vect2& other);
	// ==
	bool	operator==(const vect2& other) const;
	bool	operator!=(const vect2& other) const;
};

vect2	operator*(int value, const vect2& other);
std::ostream&	operator<<(std::ostream& out, const vect2& other);
