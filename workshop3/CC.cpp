#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

    void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const {
        char lname[31]{};
        strcpy(lname, name, 30);
        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | "; 
        prnNumber(number);
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expMon << "/";
        cout.width(2);
        cout << expYear << " |" << endl;
        cout.unsetf(ios::right);
    }


    bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const
    {

        bool valid = false;

        if (name == nullptr || strlen(name) <= 2) {
            return valid;
        }

        if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) {
            return valid;
        }

        if (cvv < 100 || cvv > 999) {
            return valid;
        }

        if (expMon < 1 || expMon > 12) {
            return valid;
        }

        if (expYear < 24 || expYear > 32) {
            return valid; 
        }
        return !valid;
    }

   

    void CC::prnNumber(unsigned long long no) const {
        cout << no / 1000000000000ull << " ";
        no %= 1000000000000ull;
        cout.fill('0');
        cout.width(4);
        cout.setf(ios::right);
        cout << no / 100000000ull << " ";
        no %= 100000000ull;
        cout.width(4);
        cout << no / 10000ull << " ";
        no %= 10000ull;
        cout.width(4);
        cout << no;
        cout.unsetf(ios::right);
        cout.fill(' ');
    }

    void CC::set()
    {
        m_cardHolderName = nullptr;
        m_CVV = 0;
        m_expMonth = 0;
        m_expYr = 0;
        m_creditCardNo = 0;
    }

    void CC::cleanUp()
    {
        freeMem(m_cardHolderName);
        set();
    }

    bool CC::isEmpty() const
    {
        return m_cardHolderName == nullptr;
        
    }

    void CC::set(const char* cc_name, unsigned long long cc_no, short m_cvv, short m_expMon, short m_expYear)
    {
        cleanUp();

        if (validate(cc_name, cc_no, m_cvv, m_expMon, m_expYear)) {
            alocpy(m_cardHolderName,cc_name);

            m_CVV = m_cvv;
            m_expMonth = m_expMon;
            m_expYr = m_expYear;
            m_creditCardNo = cc_no;
        }
    }

    void CC::display() const
    {
        if (isEmpty()) {
            cout << "Invalid Credit Card Record\n";
        }
        else {
            display(m_cardHolderName,m_creditCardNo,m_expYr,m_expMonth,m_CVV);
        }
    }

}