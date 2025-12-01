#include "CIVec2D.hpp"
#include <stdexcept>

CIVec2D::CIVec2D(int x, int y):
  m_x(x),
  m_y(y)
{
}

bool operator==(const CIVec2D & lhs, const CIVec2D & rhs) {
  return lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y;
}

bool operator!=(const CIVec2D & lhs, const CIVec2D & rhs) {
  return !(lhs == rhs);
}

CIVec2D operator+(const CIVec2D & lhs, const CIVec2D & rhs) {
  return CIVec2D(lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y);
}

CIVec2D operator-(const CIVec2D & lhs, const CIVec2D & rhs) {
  return CIVec2D(lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y);
}

CIVec2D operator*(const CIVec2D & lhs, int rhs) {
  return CIVec2D(lhs.m_x * rhs, lhs.m_y * rhs);
}

CIVec2D operator*(int lhs, const CIVec2D & rhs) {
  return CIVec2D(lhs * rhs.m_x, lhs * rhs.m_y);
}

CIVec2D operator/(const CIVec2D & lhs, int rhs) {
  if (rhs == 0) {
    throw std::invalid_argument("division by zero");
  }

  return CIVec2D(lhs.m_x / rhs, lhs.m_y / rhs);
}
