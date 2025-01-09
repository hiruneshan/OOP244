#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999 && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    
    Account::operator bool() const
    {
        return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
    }

    Account::operator int() const
    {
        return m_number;
    }

    Account::operator double() const
    {
        return m_balance;
    }

    bool Account::operator~() const
    {
        return m_number == 0;
    }

    Account& Account::operator=(const int val)
    {
        if (~*this) {

            if (val >= 10000 && val <= 99999) {

                m_number = val;
            }
            else {
                setEmpty();
            }
        }

        return *this;
    }

    Account& Account::operator=(Account& val)
    {
        if (~*this && val.m_number >= 10000 && val.m_number <= 99999) {

            m_number = val.m_number;
            m_balance = val.m_balance;

            val.m_number = 0;
            val.m_balance = 0;
        }

        return *this;
    }

    Account& Account::operator+=(const double bal)
    {
        if (*this && bal >= 0) {

            m_balance += bal;
        }
        
        return *this;
    }

    Account& Account::operator-=(const double val)
    {
        if (*this && val > 0 && m_balance >= val) {

            m_balance -= val;
        }

        return *this;
    }

    Account& Account::operator<<(Account& other)
    {
        if (*this && other && this != &other) {

            m_balance += other.m_balance;
            other.m_balance = 0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& other)
    {
        if (*this && other && this != &other) {

            other.m_balance += m_balance;
            m_balance = 0;

        }
        return *this;
    }

  

    

    double operator+(const Account& rightOper, const Account& leftOper)
    {
        double balanceOfTwo = 0.0;

        if (rightOper && leftOper) {

            balanceOfTwo = double(rightOper) + double(leftOper);

            return balanceOfTwo;
        }
        return 0;
    }

    double operator+=(double& leftOper, const Account& rightOper)
    {
        leftOper += double(rightOper) ;
        return leftOper;
    }

}

