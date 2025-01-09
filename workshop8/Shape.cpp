#include "Shape.h"
using namespace std;
namespace seneca {

	ostream& operator<<(ostream& ostr, const Shape& other)
	{
		 other.draw(ostr);
		 return ostr;
	}
	istream& operator>>(istream& istr, Shape& other)
	{
		other.getSpecs(istr);
		return istr;
	}
}