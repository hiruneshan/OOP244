#include <iomanip>
#include "Rectangle.h"
#include "Utils.h"
using namespace std;
namespace seneca {

	Rectangle::Rectangle(const char* label, int width, int height):LblShape(label), m_width{ width }, m_height{height}
	{
		if (m_height < 3) {
			m_height = 3;
		}

		if (m_width < ut.strlen(label) + 2) {
			m_width = ut.strlen(label) + 2;
		}
	}
	void Rectangle::draw(std::ostream& ostr) const
	{
		if (m_width > 0 && m_height > 0) {
			//first line
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+" << endl;

			//second line
			ostr << "|";
			ostr.width(m_width - 2);
			ostr.fill(' ');
			ostr.setf(ios::left);
			ostr << label();
			ostr.unsetf(ios::left);
			ostr << "|" << endl;


			for (int i = 0; i < m_height - 3; i++) {

				ostr << "|";
				ostr.width(m_width - 2);
				ostr.fill(' ');
				ostr << "";
				ostr << "|" << endl;

			}
			//last line
			ostr << "+";

			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+";


		}
	}
	void Rectangle::getSpecs(istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore(1, ',');
		istr >> m_height;
		istr.ignore(10000, '\n');
	}
}