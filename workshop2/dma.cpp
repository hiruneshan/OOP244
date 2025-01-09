#include <iostream>
#include <cstring>
#include "dma.h"
using namespace std;
namespace seneca {


	void reverse()
	{
		double* array = nullptr;
		int val;
		cout << "Enter the number of double values:\n";
		cout << "> ";
	
		cin >> val;
		array = new double[val];

		

		for (int i = 0; i < val; i++) {
			cout << (i + 1) << "> ";
			cin >> array[i];
		
		}

		for (int i = val - 1; i >= 0; i--) {
			cout << array[i];
			cout << "\n";
		}

		delete[] array;
	}

	Contact* getContact()
	{
		Contact* contactInfo = new Contact;

		cout << "Name: ";
		cin >> contactInfo->m_name;

		cout << "Last name: ";
		cin >> contactInfo -> m_lastname;

		cout << "Phone number: ";;
		cin >> contactInfo -> m_phoneNumber;

		cin.ignore(1000, '\n');

		return contactInfo;
	}

	void display(Contact& C)
	{
		cout << C.m_name << " " << C.m_lastname << "," << " +" << C.m_phoneNumber << "\n";
	}

	void deallocate(Contact* C)
	{
		if (C != nullptr) {
			delete C;
			C = nullptr;
		}
	}

	void setEmpty(Contact& C)
	{

		memset(C.m_name, '\0', sizeof(C.m_name));
		memset(C.m_lastname, '\0', sizeof(C.m_lastname));
		C.m_phoneNumber = 0;
	}
	

}