#ifndef SHAPE_H
#define SHAPE_H
#include <ostream>
#include "Point2D.h"

class Shape{
    protected:
        std::string color;
    
    public:
        Shape();
        Shape(const std::string& color);
        std::string getColor() const;
        void setColor(const std::string& c);
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual void translate(double incX, double incY) = 0;
        virtual void print() const = 0;
};

#endif