#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool()const;
        operator int()const;
        operator double()const;
        bool operator ~()const;
        Account& operator=(const int val);
        Account& operator=(Account& val);
        Account& operator+=(const double bal);
        Account& operator-=(const double val);
        Account& operator<<(Account& other);
        Account& operator>>(Account& other);
       
    };

    double operator+(const Account& rightOper, const Account& leftOper);
    double operator+=(double& leftOper, const Account& rightOper);

}
#endif // SENECA_ACCOUNT_H_