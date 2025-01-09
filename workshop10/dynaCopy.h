/***********************************************************************
// OOP244 workshop 10, dynaCopy module
//
// File	Name.h
// Version 1.0
// Date 2024-11-24
// Author: Hiru Neshan Wijemanne
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                   Date            Reason
///////////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H

namespace seneca {

	template <typename Type>
	Type* dynaCopy(const Type* sourceArr, int size) {

		Type* newArray{};
		newArray = new Type[size];
		for (int i = 0; i < size; i++) {
			newArray[i] = sourceArr[i];
		}
		return newArray;

	}

	template <typename Type>
	Type* dynaCopy(Type*& destinationArr, const Type* sourceArr, int size) {

		delete[] destinationArr;
		destinationArr = nullptr;

		destinationArr = new Type[size];
		
		for (int i = 0; i < size; i++) {
			destinationArr[i] = sourceArr[i];
		}

		return destinationArr;
	}

	template <typename Type>
	void prnArray(const Type& prnArr, int size) {
		for (int i = 0; i < size; i++) {
			std::cout << prnArr[i];

			if (i < size - 1) {
				std::cout << ",";
			}
		}

		std::cout << "\n"; // new line at the end
	}





	
}

#endif // !SENECA_DYNACOPY_H
