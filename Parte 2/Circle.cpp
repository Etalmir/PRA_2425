#include "Circle.h"
#include <cmath>

Circle::Circle() : Shape(), center(Point2D(0.0, 0.0)), radius(1.0) {}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const{
    return center;
}

void Circle:: set_center(const Point2D& c){
    center = c;
}

double Circle::get_radius() const{
    return radius;
}

void Circle::set_radius(double r){
    radius = r;
}

std::string Circle::get_color() const{
    return Shape::getColor();
}

void Circle::set_color(const std::string& c){
    Shape::setColor(c);
}

double Circle::area() const{
    return M_PI * radius * radius;
}
    
double Circle::perimeter() const{
    return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY){
    center.x += incX;
    center.y += incY;
}

std::ostream& operator<<(std::ostream& out, const Circle& circle){
    out << "Círculo de color " << circle.get_color() << ", centro en " << circle.get_center() << " y radio " << circle.get_radius() << ". Área: " << circle.area() << ", Perímetro: " << circle.perimeter();
    return out;
}

// Reaprovechamos el operador << para imprimir, usamos *this para indicar que se trata del círculo actual.
void Circle::print() const{
    std::cout << *this << std::endl;
}

