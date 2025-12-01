#include "Shapes.hpp"
#include <iostream>

Shape::Shape() {}
Shape::~Shape() {}

Circle::Circle(const Vector2D &center, double radius)
{
    m_center = center;
    m_radius = radius;
}

// circle display override
std::ostream &Circle::display(std::ostream &os) const
{
    os << "Circle(" << m_center.getX() << "," << m_center.getY() << "; " << m_radius << ")";
    return os;
}

void Circle::translate(const Vector2D &v)
{
    m_center += v;
}

// print destrying then display what is being destroyed
Circle::~Circle()
{
    std::cout << "Destroying: ";
    display(std::cout);
    std::cout << std::endl;
}

Triangle::Triangle(const Vector2D &p1, const Vector2D &p2, const Vector2D &p3)
{
    m_points[0] = p1;
    m_points[1] = p2;
    m_points[2] = p3;
}

std::ostream &Triangle::display(std::ostream &os) const
{
    // display each of the points inside parenthesis
    os << "Triangle(";
    for (int i = 0; i < 3; ++i)
    {
        os << m_points[i].getX() << "," << m_points[i].getY();
        if (i < 2)
            os << "; ";
    }
    os << ")";
    return os;
}

void Triangle::translate(const Vector2D &v)
{
    for (int i = 0; i < 3; ++i)
        m_points[i] += v;
}

Triangle::~Triangle()
{
    std::cout << "Destroying: ";
    display(std::cout);
    std::cout << std::endl;
}
