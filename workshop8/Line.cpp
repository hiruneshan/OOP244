#include <iomanip>
#include "Line.h"
#include "Utils.h"
using namespace std;
namespace seneca {

	Line::Line(const char* label, int length):LblShape(label)
	{
		m_length = length;
		if (m_length < ut.strlen(label)){
			m_length = ut.strlen(label);
		}
	}
	void Line::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(10000, '\n');
	}
	void Line::draw(std::ostream& ostr) const
	{
		if (m_length > 0 && label() != nullptr) {
			ostr << label() << endl;

			for (int i = 0; i < m_length; i++) {
				ostr << "=";
			}
		}
	}
}