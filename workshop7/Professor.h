#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include <iostream>
#include "Employee.h"
using namespace std;

namespace seneca {
	class Professor : public Employee {
		char* m_subName = nullptr;
		int m_numSections;
		double devPay() const;

	public:
		Professor();
		Professor(const char* name, const char* subject, int numSections, int empNumber, double salary);
		Professor(Professor& other) = delete;
		Professor& operator=(Professor& other) = delete;
		~Professor();

		istream& read(istream& istr = cin);
		ostream& write(ostream& ostr = cout) const;
		ostream& title(ostream& ostr = cout)const;
	};
	ostream& operator<<(ostream& ostr, const Professor& other);
	istream& operator>>(istream& istr, Professor& other);
	

}

#endif