#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
#include "constants.h"

namespace seneca {
	class Menu; // telling the compiler that menu is a class that will be defined later 
	class MenuItem {
		friend class Menu;

		char* m_menuContent = nullptr;
		size_t m_numOfIndentations;
		size_t m_sizeOfIndentation;
		int m_menuItemNum;

		MenuItem(const char* content, int indentation, int sizeIdentation, int rowNum);
		MenuItem(const MenuItem& other) = delete;
		MenuItem& operator=(const MenuItem& other) = delete;
		virtual ~MenuItem();
		operator bool()const;
		std::ostream& display(std::ostream& ostr = std::cout)const;

	};
	class Menu {
		unsigned int m_indentationNum;
		unsigned int m_indentationSize;
		unsigned int m_numOfItems;
		
		MenuItem m_title;
		MenuItem m_exitOption; 
		MenuItem m_entryPrompt;

		// array of MenuItem Pointers ( pointing to the class MenuItem)
		MenuItem* m_menuItems[MaximumNumberOfMenuItems]{};

	public:
		Menu(const char* title, const char* exitOption = "Exit", unsigned int indentationNum = 0, unsigned int indentationSize = 3, const char* entryPrompt = "> ")
			: m_indentationNum(indentationNum),
			m_indentationSize(indentationSize),
			m_numOfItems(0),
			m_title(title, indentationNum, indentationSize, -1),
			m_exitOption(exitOption, indentationNum, indentationSize, 0),
			m_entryPrompt(entryPrompt, indentationNum, indentationSize, -1),
			m_menuItems{} {};


		Menu& operator<<(const char* itemContent);
		Menu(const Menu& other) = delete;
		Menu& operator=(const Menu& other) = delete;
		~Menu();
		size_t select() const;

	};
	size_t operator<<(std::ostream& ostr, const Menu& m);

}
#endif // !SENECA_MENU_H