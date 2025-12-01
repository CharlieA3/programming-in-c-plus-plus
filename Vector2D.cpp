#include "Vector2D.hpp"
#include <stdexcept>
using namespace std;

// default constructor
Vector2D::Vector2D() : m_x(0.0), m_y(0.0) {}

// copy construction - making a new object from an existing one, not modifying the one I am copying from
// will be called when I have Vector2D b = a (a already exists)
Vector2D::Vector2D(const Vector2D &v)
{
    m_x = v.m_x;
    m_y = v.m_y;
}

Vector2D::Vector2D(double d1, double d2)
{
    m_x = d1;
    m_y = d2;
}

void Vector2D::setX(double d)
{
    m_x = d;
}

void Vector2D::setY(double d)
{
    m_y = d;
}

double Vector2D::getX() const
{
    return m_x;
}

double Vector2D::getY() const
{
    return m_y;
}

// *  os << v1: streams x and y separated by a comma, returns ostream
// friend so anybody can use this operator to perform functions on these variables
std::ostream &operator<<(std::ostream &os, const Vector2D &v)
{
    os << v.m_x << "," << v.m_y;
    return os;
}

double Vector2D::operator[](int i) const
{
    if (i != 0 && i != 1)
        throw std::out_of_range("Index out of range");
    // accessing through the getter function becasue those return const versions of the x and y values of this object
    // these functions are implicity using (*this) object
    return i ? getY() : getX();
}

double &Vector2D::operator[](int i)
{
    if (i != 0 && i != 1)
        throw std::out_of_range("Index out of range");
    // accessing the values directly to return reference to the non-const values of this object
    return i ? m_y : m_x;
}

//  *  v1 = v2: element-wise assignment
// this is void becasue the this object is v1, and the one we are giving to the operator is v2 so we are just modifying v1 (or this) directly
Vector2D &Vector2D::operator=(const Vector2D &v)
{
    // we don't want to change what is inside v, just read those values and set it to this object
    if (&v != this)
    {
        setX(v.getX());
        setY(v.getY());
    }
    return *this;
}

//  *  v1 == v2; v1 != v2: element-wise (in)equality comparison
// I do pass by const reference here because I don't want to make a copy and waste space, but I still want to access the elements without risking changing them
bool Vector2D::operator==(const Vector2D &v) const
{
    return (m_x == v.m_x && m_y == v.m_y);
}

bool Vector2D::operator!=(const Vector2D &v) const
{
    return !(*this == v);
}

//  *  -v: element-wise negation
Vector2D Vector2D::operator-() const
{
    return Vector2D(-m_x, -m_y);
}

//  *  v1 += v2, v1 + v2, v1 -= v2, v1 - v2: element-wise addition or subtraction
Vector2D &Vector2D::operator+=(const Vector2D &v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &v)
{
    m_x -= v.m_x;
    m_y -= v.m_y;
    return *this;
}

// want to create a new vector here because if you have multiple additions and modify one of the ones you passed in, you're cooked, same with subtract
Vector2D Vector2D::operator+(const Vector2D &v) const
{
    Vector2D result = *this;
    result += v;
    return result;
}

// not returning a reference here because the result is created inside the function so when we leave it, it could lead to undefined behavior
Vector2D Vector2D::operator-(const Vector2D &v) const
{
    Vector2D result = *this;
    result -= v;
    return result;
}

//  *  v *= d, v * d, d * v, v /= d, v / d: element-wise multiplication or division; throws std::invalid_argument on division by 0
Vector2D &Vector2D::operator*=(const Vector2D &v)
{
    m_x *= v.m_x;
    m_y *= v.m_y;
    return *this;
}

Vector2D &Vector2D::operator/=(const Vector2D &v)
{
    if (v.m_x == 0 || v.m_y == 0)
        throw std::invalid_argument("Division by zero");
    m_x /= v.m_x;
    m_y /= v.m_y;
    return *this;
}

Vector2D &Vector2D::operator*=(double d)
{
    m_x *= d;
    m_y *= d;
    return *this;
}

Vector2D &Vector2D::operator/=(double d)
{
    if (d == 0)
        throw std::invalid_argument("Division by zero");
    m_x /= d;
    m_y /= d;
    return *this;
}

Vector2D Vector2D::operator*(const Vector2D &v) const
{
    Vector2D result = *this;
    result *= v;
    return result;
}

Vector2D Vector2D::operator*(double d) const
{
    return Vector2D(m_x * d, m_y * d);
}

Vector2D Vector2D::operator/(const Vector2D &v) const
{
    Vector2D result = *this;
    result /= v;
    return result;
}

Vector2D Vector2D::operator/(double d) const
{
    if (d == 0)
        throw std::invalid_argument("Division by zero");
    return Vector2D(m_x / d, m_y / d);
}

// non-member function for scalar * vector
Vector2D operator*(double d, const Vector2D &v)
{
    return v * d;
}
