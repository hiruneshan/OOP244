/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// Date 2024-9-11
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name                   Date            Reason
// Hiru Neshan Wijemanne  11/05/2024
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca {
    Utils ut;

    char* Utils::alocpy(const char* src) const {
        char* des{};
        return alocpy(des, src);
    }

    char* Utils::alocpy(char*& des, const char* src)const {
        delete[] des;
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }
    char* Utils::strcpy(char* des, const char* src)const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0);
        return des;
    }
    int Utils::strlen(const char* str)const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    bool Utils::isspace(char ch)const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) {
            cstring++;
        }
        return cstring && *cstring == 0;
    }
    
    // added on 11/14/2024 
   // foolproof entry.
    int Utils::getInt()
    {
        bool valid = false;
        int num;

        do {
            cin >> num; 

            if (cin.fail()) {
                cin.clear(); 

                if (cin.peek() == '\n') { 
                    cout << "You must enter a value:" << endl;
                }
                else { 
                    cout << "Invalid integer:" << endl;
                }
            }
            else if (cin.peek() == '\n') { 
                cout << "You must enter a value:" << endl;
            }
            else if (cin.peek() != '\n') { 
                cout << "Only an integer please:" << endl;
            }
            else {
                valid = true;
            }

            cin.ignore(100000, '\n'); 

        } while (!valid);

        return num;
    }
    

    int Utils::getInt(int min, int max)
    {
        int num;
        bool valid = false;
        do {
            num = getInt();

            if (num < min || num > max) {
                cout << "Invalid value: [" << min << " <= value <= " << max << "], try again:" << endl;
            }
            else {
                valid = true;
            }
        } while (!valid);

        return num;
    }

   

}