#include <iostream>
#include "Professor.h"
#include "Utils.h"



double seneca::Professor::devPay() const
{
	return (salary() * 0.01) * m_numSections;
}

seneca::Professor::Professor()
{
	m_subName = nullptr;
	m_numSections = 0;

}

seneca::Professor::Professor(const char* name, const char* subject, int numSections, int empNumber, double salary)
    : Employee(name, empNumber, salary), m_subName(ut.alocpy(subject)), m_numSections(numSections){}

seneca::Professor::~Professor()
{
	delete[] m_subName;
	m_subName = nullptr;
}

istream& seneca::Professor::read(istream& istr)
{
    
    Employee::read(istr);

    if (istr) {
        if (istr.peek() == ',') {
            istr.ignore();
        }
        char buffer[1024];
        istr.getline(buffer, 1024, ',');
        ut.alocpy(m_subName, buffer);

        istr >> m_numSections;
    }

    return istr;
  
    
}

ostream& seneca::Professor::write(ostream& ostr) const
{
    Employee::write(ostr);

    ostr << " ";
    char tempSubject[21] = {};  
    if (m_subName) {
        ut.strcpy(tempSubject, m_subName, 20); 
    }
   
    ostr.width(20);
    ostr.setf(ios::left);
    ostr.fill(' ');
    ostr << tempSubject;
    ostr.unsetf(ios::left);
    ostr << " | ";
    ostr.width(5);
    ostr.fill(' ');
    ostr.setf(ios::right);
    ostr << m_numSections;
    ostr.unsetf(ios::right);
    ostr << " | ";
    ostr.width(8);
    ostr.precision(2);
    ostr.setf(ios::fixed);
    ostr.setf(ios::right);
    ostr << devPay();
    ostr.unsetf(ios::right);
    ostr << " |";

    return ostr;

}

ostream& seneca::Professor::title(ostream& ostr) const
{
    Employee::title();
    cout << " Teaching Subject     | Sec # | $Dev Pay |";
    return ostr;
}

ostream& seneca::operator<<(ostream& ostr, const Professor& other)
{
    return other.write(ostr);
}

istream& seneca::operator>>(istream& istr, Professor& other)
{
    
    return other.read(istr);
}
