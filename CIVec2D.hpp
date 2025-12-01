#ifndef CIVEC2D_HPP
#define CIVEC2D_HPP

class CIVec2D {
public:
  CIVec2D(int x, int y);

  int x() const { return m_x; }
  int y() const { return m_y; }

  friend bool operator==(const CIVec2D & lhs, const CIVec2D & rhs);
  friend bool operator!=(const CIVec2D & lhs, const CIVec2D & rhs);

  friend CIVec2D operator+(const CIVec2D & lhs, const CIVec2D & rhs);
  friend CIVec2D operator-(const CIVec2D & lhs, const CIVec2D & rhs);
  friend CIVec2D operator*(const CIVec2D & lhs, int rhs);
  friend CIVec2D operator*(int lhs, const CIVec2D & rhs);
  friend CIVec2D operator/(const CIVec2D & lhs, int rhs);

private:
  const int m_x, m_y;
};

#endif
