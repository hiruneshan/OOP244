/***********************************************************************
// OOP244 Project, milestone 2 : tester program
//
// File	ms2.cpp
// Version 1.1
// Date 2024-10-11
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 1.1             11-06           fixed switch bug
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Menu.h"
using namespace std;
using namespace seneca;
void test2();
void test1();
void appDemo();

int main() {
    size_t selection{};

    Menu ms2("Milestone 2");
    ms2 << "Run Test 1" << "Run Test 2" << "Final Milestone Application Demo";
    do {
        selection = ms2.select();
        switch (selection) {
        case 0:
            cout << "Have a good day!" << endl;
            break;
        case 1: {
            test1();
            break;
        }
        case 2:
            test2();
            break;
        case 3:
            appDemo();
            break;
        default:
            cout << "This should never happen!" << endl;
        }
    } while (selection);
    return 0;
}
void test1() {
    char option[] = "Option A";
    Menu test1("Test 1, Options Menu", "Return", 1);
    for (size_t i = 0; i < 30; i++) {
        test1 << option;
        option[7]++;
    }
    while (cout << test1);
}
void test2() {
    size_t selection{};
    Menu test2("Test 2, Selection test", "Return", 1);
    Menu subMenu(nullptr, "Back to test 2", 2, 4);
    test2 << "Option 1" << "Option 2 with Submenu" << "Option 3";
    subMenu << "Sub-option 1" << "Sub-option 2";
    do {
        selection = test2.select();
        switch (selection) {
        case 1:
            cout << "Option one selected." << endl;
            break;
        case 2:
            while (cout << subMenu) {
                cout << "Staying in Submenu!" << endl;
            }
            break;
        case 3:
            cout << "Option three selected." << endl;
        case 0:
            break;
        default:
            cout << "This should never happen!" << endl;
            break;
        }
    } while (selection);

}
void appDemo() {
    size_t appSel{}, ordSel{};
    Menu appMenu("Seneca Resturant", "End Program");
    appMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
    Menu orderMenu("Order Menu", "Back to main menu", 1);
    orderMenu << "Food" << "Drink";
    cout << endl << "***********************************************************************" << endl;

    do {
        switch (appSel = appMenu.select()) {
        case 1:
            do {
                switch (ordSel = orderMenu.select()) {
                case 1:
                    cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                        "Start Food Ordering Process!!!\n"
                        "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
                    break;
                case 2:
                    cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                        "Start Drink Ordering Process!!!\n"
                        "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
                    break;
                }
            } while (ordSel);
            break;
        case 2:
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                "Print the Bill for customer!!!\n"
                "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
            break;
        case 3:
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                "Start a new bill!!!\n"
                "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
            break;
        case 4:
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                "List all the foodsd!!!\n"
                "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
            break;
        case 5:
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                "List all the drinks!!!\n"
                "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
            break;
        }
    } while (appSel);
    cout << "End Final Milestone Demo **********************************************" << endl;
}