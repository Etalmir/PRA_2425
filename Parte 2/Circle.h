#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include "Point2D.h"
#include <iostream>

class Circle : public Shape{
    private:
        Point2D center;
        double radius;

    public:
        Circle();
        Circle(std::string color, Point2D center, double radius);
        Point2D get_center() const; 
        std::string get_color() const;
        void set_center(const Point2D& c);
        double get_radius() const;
        void set_radius(double r);
        void set_color(const std::string& c);
        double area() const override;
        double perimeter() const override;
        void translate(double incX, double incY) override;
        void print() const override;
        friend std::ostream& operator<<(std::ostream& out, const Circle& circle);
};

#endif