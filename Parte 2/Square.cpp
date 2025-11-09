#include "Square.h"

bool Square::check(const Point2D* vertices) {
    double side = Point2D::distance(vertices[0], vertices[1]);
    // Devolvemos si todo los lados son de la misma distancia.
    return (Point2D::distance(vertices[1], vertices[2]) == side &&
            Point2D::distance(vertices[2], vertices[3]) == side &&
            Point2D::distance(vertices[3], vertices[0]) == side);
}

// Constructor base
Square::Square() : Rectangle() {}

// Constructor con parámetros
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    // Si no es válido, lamzamos una excepción
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
}

void Square::set_vertices(const Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
    // SI es válido, llamamos al setter de la clase padre
    Rectangle::set_vertices(vertices);
}

std::ostream& operator<<(std::ostream& out, const Square& square){
    out << "Color del cuadrado: " << square.color << ", Vertices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i){
        out << square.get_vertex(i);
        if (i < Rectangle::N_VERTICES - 1){
            out << ", ";
        }
    }
    out << ")" << std::endl;
    return out;
}