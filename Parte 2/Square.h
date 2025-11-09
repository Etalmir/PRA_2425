#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"
#include "Point2D.h"
#include <ostream>

class Square : public Rectangle {
    private:
        static bool check(const Point2D* vertices);
    
    public:
        // Constructores
        Square();
        Square(std::string color, Point2D* vertices);

        // Setters
        void set_vertices(const Point2D* vertices);

        // Operadores
        friend std::ostream& operator<<(std::ostream& out, const Square& square); // Sobrecarga del operador de salida
};

#endif