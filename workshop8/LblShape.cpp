
#include "LblShape.h"
#include "Utils.h"
using namespace std;
namespace seneca {

	const char* LblShape::label()const
	{
		return m_label;
	}

	LblShape::LblShape()
	{
		if (m_label != nullptr) {
			m_label = nullptr;
		}
	}

	LblShape::LblShape(const char* label)
	{
		ut.alocpy(m_label, label);
	}

	void LblShape::getSpecs(std::istream& istr)
	{
		char buffer[81];
		istr.getline(buffer, 80, ',');
		ut.alocpy(m_label, buffer);
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
	}
}