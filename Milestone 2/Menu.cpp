#include <iostream>
#include "Menu.h"
#include "Utils.h"
#include "Constants.h"

using namespace std;
namespace seneca {

	MenuItem::MenuItem(const char* content, int indentation, int sizeIndentation, int rowNum)
	{
		if (content == nullptr || ut.strlen(content) == 0 || ut.isspace(content) || indentation > 4 || sizeIndentation > 4 || rowNum > MaximumNumberOfMenuItems) {

			m_menuContent = nullptr;
			m_numOfIndentations = 0;
			m_sizeOfIndentation = 0;
			m_menuItemNum = 0;
		}
		else {
			ut.alocpy(m_menuContent, content);
			m_numOfIndentations = indentation;
			m_sizeOfIndentation = sizeIndentation;
			m_menuItemNum = rowNum;

		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_menuContent;
		m_menuContent = nullptr;
	}

	MenuItem::operator bool() const
	{
		return m_menuContent != nullptr;
	}

	std::ostream& MenuItem::display(std::ostream& ostr) const
	{
		if (m_menuContent != nullptr && ut.strlen(m_menuContent) > 0 && !ut.isspace(m_menuContent) && m_menuItemNum <= MaximumNumberOfMenuItems) {



			for (size_t i = 0; i < m_numOfIndentations; ++i) {
				for (size_t j = 0; j < m_sizeOfIndentation; ++j) {
					ostr << " ";
				}
			}

			if (m_menuItemNum >= 0) {
				ostr.width(2);
				ostr << m_menuItemNum << "- ";
			}

			bool leadingSpace = false;
			for (int i = 0; i < ut.strlen(m_menuContent); ++i) {
				if (!leadingSpace) {
					if (!ut.isspace(m_menuContent[i])) {
						leadingSpace = true;
						ostr << m_menuContent[i];
					}
				}
				else {
					ostr << m_menuContent[i];
				}
			}
		}
		else {

			ostr << "??????????";
		}

		return ostr;
	}


	//MS-2

	//adding an item
	Menu& Menu::operator<<(const char* itemContent)
	{
		if (m_numOfItems < MaximumNumberOfMenuItems) {

			
			m_menuItems[m_numOfItems] = new MenuItem(itemContent, m_indentationNum, m_indentationSize, m_numOfItems + 1);
			m_numOfItems++;

		}

		return *this;
	}

	Menu::~Menu()
	{

		for (size_t i = 0; i < m_numOfItems; i++) {
			delete m_menuItems[i];
			m_menuItems[i] = nullptr;
		}
	}

	size_t Menu::select() const
	{

		if (m_title)
			m_title.display() << endl;


		// Display regular menu items 
		for (size_t i = 0; i < m_numOfItems; i++) {
			if (m_menuItems[i]) {  // Check if item exists
				m_menuItems[i]->display();
				cout << endl;
			}
		}

		

		m_exitOption.display() << endl;
		m_entryPrompt.display();

		return ut.getInt(0, m_numOfItems);
	}

	size_t operator<<(std::ostream& ostr, const Menu& m)
	{
		size_t userChoice = 0;
		if (&ostr == &cout) {

			 userChoice = m.select();
			 return userChoice;
		}
		else {
			return 0;
		}
	}
}

