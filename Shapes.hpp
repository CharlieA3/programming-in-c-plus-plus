#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "Vector2D.hpp"
#include <ostream>

/*
 * Base class for a polymorphic shape.
 *
 * It must not be possible to instatiate an Shape (it should be
 * abstract), and all member functions, other than constructors and
 * destructors, must be unimplemented.
 * Any constructors or destructors must have empty implementations.
 * Shape must have no member variables.
 *
 * Given Shape o, Vector2D v, std::ostream os, the following should be defined:
 *  o.display(os): streams shape description (not followed by a newline) to given stream and returns stream
 *  o.translate(v): translates shape by v
 */
class Shape
{
public:
  Shape();
  virtual ~Shape();

  virtual std::ostream &display(std::ostream &os) const = 0;
  virtual void translate(const Vector2D &v) = 0;
};

/*
 * Circle shape class; subclass of Shape.
 *
 * Circle description format "Circle(cx,cy; radius)"
 *
 * When destructed, displays "Destroying: ", followed by the shape description, then a newline.
 */
class Circle : public Shape
{
public:
  Circle(const Vector2D &center, double radius);
  std::ostream &display(std::ostream &os) const override;
  void translate(const Vector2D &v) override;
  ~Circle() override;

private:
  Vector2D m_center; // center point of circle
  double m_radius;   // radius of circle
};

/*
 * Triangle shape class; subclass of Shape.
 *
 * Stores the points in an array.
 *
 * Triangle description format: "Triangle(ax,ay; bx,by; cx,cy)"
 *
 * When destructed, displays "Destroying: ", followed by the shape description, then a newline.
 */
class Triangle : public Shape
{
public:
  Triangle(const Vector2D &p1, const Vector2D &p2, const Vector2D &p3);
  std::ostream &display(std::ostream &os) const override;
  void translate(const Vector2D &v) override;
  ~Triangle() override;

private:
  Vector2D m_points[3]; // array containing points
};

#endif
