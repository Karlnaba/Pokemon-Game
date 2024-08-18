#include <iostream>

#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D() {
  x = 0.0;
  y = 0.0;
}
Vector2D::Vector2D(double in_x, double in_y) {
  x = in_x;
  y = in_y;
}

Vector2D operator*(Vector2D &v1, double d) {
  Vector2D vector;
  vector.x = v1.x * d;
  vector.y = v1.y * d;
  return vector;
}

Vector2D operator/(Vector2D &v1, double d) {
  Vector2D vector;
  if (d == 0) {
    return vector;
  } else {
    vector.x = v1.x / d;
    vector.y = v1.y / d;
    return vector;
  }
}

ostream &operator<<(ostream &output, Vector2D &v1) {
  output << "<" << v1.x << ", " << v1.y << ">";
  return output;
}
