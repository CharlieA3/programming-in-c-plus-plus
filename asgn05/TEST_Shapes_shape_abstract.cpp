#include "Shapes.hpp"
#include <type_traits>
using namespace std;

int
main() {
  static_assert(is_abstract<Shape>(), "Shape must be abstract.");
}
