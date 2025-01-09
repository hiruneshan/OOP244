#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"


namespace seneca {

    class Line : public LblShape{
        // Length of the line
        int m_length;
    public:
        // Default constructor
        Line() :LblShape(), m_length{ 0 } {}

        // Constructor that initializes label and length
        Line(const char* label, int length);

        // Draws the line, using the label and length
        void getSpecs(std::istream& istr);

        // Gets specifications of the line (label and length) from input
        void draw(std::ostream& ostr = std::cout)const;
    };

}

#endif // !SENECA_LINE_H