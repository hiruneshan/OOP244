#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
    class CC {
    private:

        char* m_cardHolderName;
        short int m_CVV;
        short int m_expMonth;
        short int m_expYr;
        unsigned long long m_creditCardNo;

        void display(const char* name, unsigned long long number, short expYear, short expMon =12, short cvv =24) const;
        bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon = 12, short expYear =24) const;
        void prnNumber(unsigned long long CCnum)const;

    public :
        void set();
        void cleanUp();
        bool isEmpty() const;
        void set(const char* cc_name,
            unsigned long long cc_no,
            short m_cvv,
            short m_expMon = 12,
            short m_expYear = 24);
        void display() const;
    };



}
#endif // !SENECA_CC_H_