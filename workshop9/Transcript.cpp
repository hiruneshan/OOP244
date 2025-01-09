/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.coo
// Version 1.0
// Date 2024-11-18
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                    Date            Reason
// Hiru Neshan Wijemanne   11/24/2024
***********************************************************************/
#include <iostream>
#include "Transcript.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	Transcript::Transcript(const char* studentName, size_t studentNum)
	{
		ut.alocpy(m_studentName, studentName);
		m_studentNum = studentNum;
	}
	Transcript::Transcript(const Transcript& other):Marks(other)
	{
		ut.alocpy(m_studentName, other.m_studentName);
		m_studentNum = other.m_studentNum;
	}
	Transcript& Transcript::operator=(const Transcript& other)
	{
		if (this != &other) {
			Marks::operator=(other);// base class cpy assignment
			ut.alocpy(m_studentName, other.m_studentName);
			m_studentNum = other.m_studentNum;
		}
		return *this;
	}
	Transcript::~Transcript()
	{
		delete[] m_studentName;
	}
	std::ostream& Transcript::display(std::ostream& ostr) const
	{
		ostr << m_studentName << " (" << m_studentNum << ")" << endl;
		ostr << "--------------------------------------------------------------------------" << endl;

		Marks::display(ostr);
		return ostr;
	}
}