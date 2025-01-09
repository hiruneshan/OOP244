#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

    class Rectangle : public LblShape {
        int m_width;// Width of the rectangle
        int m_height;// Height of the rectangle

    public:
        // Default constructor
        Rectangle() :m_width{ 0 }, m_height{ 0 } {}

        // Constructor that initializes label, width, and height
        Rectangle(const char* label, int width, int height);

        // Draws the rectangle using the label, width, and height
        void draw(std::ostream& ostr) const;
        

        // Gets specifications of the rectangle (label, width, height) from input
        void getSpecs(std::istream& istr);
    };

}

#endif // !SENECA_RECTANGLE_H