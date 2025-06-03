//must support addition, substraction and multiplication!
#include "vect2.hpp"

vect2::vect2()
{
    this->_container.push_back(0);
    this->_container.push_back(0);
}

vect2::vect2(int v1, int v2)
{
    this->_container.push_back(v1);
    this->_container.push_back(v2);
}

vect2::vect2(const vect2& original)
{
    *this = original;
}

vect2::~vect2() {}

int vect2::getContainer_elements(int array) const
{
    return (this->_container[array]);
}


// Addition OPERATORS
    vect2	vect2::operator+(int add)
    {
        vect2 copy(*this);
    
        copy._container[0] += add;
        copy._container[1] += add;
        return (copy);
    }

    vect2	vect2::operator+(const vect2 addon)
    {
        vect2 copy(*this);

        copy._container[0] += addon._container[0];
        copy._container[1] += addon._container[1];
        return (copy);
    }


    vect2&	vect2::operator++(void)
    {
        this->_container[0] += 1;
        this->_container[1] += 1;
        return (*this);
    } 

    vect2	vect2::operator++(int)
    {
        vect2 copy(*this);

        this->_container[0] += 1;
        this->_container[1] += 1;
        return (copy);
    }

// substraction OPERATORS
    vect2	vect2::operator-(int minus)
    {
        vect2 copy(*this);
    
        copy._container[0] -= minus;
        copy._container[1] -= minus;
        return (copy);
    }

    vect2	vect2::operator-(const vect2 minuson)
    {
        vect2 copy(*this);

        copy._container[0] -= minuson._container[0];
        copy._container[1] -= minuson._container[1];
        return (copy);
    }


    vect2&	vect2::operator--(void)
    {
        this->_container[0] -= 1;
        this->_container[1] -= 1;
        return (*this);
    } 

    vect2	vect2::operator--(int)
    {
        vect2	copy(*this);

        this->_container[0] -= 1;
        this->_container[1] -= 1;
        return (copy);
    }


// multiplication OPERATORS
    vect2	vect2::operator*(int multi)
    {
        vect2 copy(*this);
    
        copy._container[0] *= multi;
        copy._container[1] *= multi;
        return (copy);
    }

    vect2	vect2::operator*(const vect2 &addon)
    {
        vect2 copy(*this);

        copy._container[0] -= addon._container[0];
        copy._container[1] -= addon._container[1];
        return (copy);
    }


//Equal (==) OPERATORS
    vect2& vect2::operator=(const vect2& original)
    {
        if (this == &original)//need to add & because 'this' is a pointer
            return (*this); // handle self-assignment

        // add in the container value
        this->_container = original._container;
        return (*this);
    }

    bool	vect2::operator==(const vect2& other) const
    {
        if ((this->getContainer_elements(0) == other.getContainer_elements(0)) && 
            (this->getContainer_elements(1) == other.getContainer_elements(1)))
        {
            std::cout << "THE TRUTH RETURNED!--> " << std::flush;
            return (true); // handle self-assignment
        }
        return (false);
    }

    bool	vect2::operator!=(const vect2& other) const
    {
        if ((this->getContainer_elements(0) != other.getContainer_elements(0)) && 
            (this->getContainer_elements(1) != other.getContainer_elements(1)))
        {
            std::cout << "THE TRUTH RETURNED!--> " << std::flush;
            return (true); // handle self-assignment
        }
        return (false);
    }


//  all three plus equal (+/-/*)=
    vect2   vect2::operator+=(int add)
    {
        vect2 copy(*this);
    
        copy._container[0] += add;
        copy._container[1] += add;

        return (copy);
    }

    vect2   vect2::operator+=(const vect2 &addon)
    {
        vect2 copy(*this);

        copy._container[0] += addon.getContainer_elements(0);
        copy._container[1] += addon.getContainer_elements(1);

        return (copy);
    }

    vect2   vect2::operator-=(int minus)
    {
        vect2 copy(*this);
    
        copy._container[0] -= minus;
        copy._container[1] -= minus;

        return (copy);
    }

    vect2   vect2::operator-=(const vect2 &minuson)
    {
        vect2 copy(*this);

        copy._container[0] -= minuson.getContainer_elements(0);
        copy._container[1] -= minuson.getContainer_elements(1);

        return (copy);
    }

    vect2   vect2::operator*=(int multi)
    {
        vect2 copy(*this);
    
        copy._container[0] *= multi;
        copy._container[1] *= multi;

        return (copy);
    }

    vect2   vect2::operator*=(const vect2 &multion)
    {
        vect2 copy(*this);

        copy._container[0] *= multion.getContainer_elements(0);
        copy._container[1] *= multion.getContainer_elements(1);

        return (copy);
    }

std::ostream& operator<<(std::ostream& out, const vect2& v)
{
	out << "{" << v.getContainer_elements(0) << ", " << v.getContainer_elements(1) << "}" << std::endl;
	return (out);
}
