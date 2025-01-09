#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include "Shape.h"

namespace seneca {

    class LblShape : public Shape{
        // Dynamically allocated label for the shape
        char* m_label = nullptr;
    protected:
        // Returns the label string for derived classes to access
        const char* label()const;
    public:
        // Default constructor
        LblShape();
       
        // Constructor with label initialization
        LblShape(const char* label);

        // Copy constructor and assignment operator are deleted to prevent copying
        LblShape(LblShape& other) = delete;
        LblShape& operator=(LblShape& other) = delete;

        // Reads label specifications from input stream
        void getSpecs(std::istream& istr);

        // Destructor to release dynamically allocated memory
         virtual ~LblShape();
    };
}

#endif // !SENECA_LABELEDSHAPE_H