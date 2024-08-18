#include <cmath>
#include <iostream>

#include "Point2D.h"
using namespace std;

Point2D::Point2D() {
  x = 0.0;
  y = 0.0;
}
Point2D::Point2D(double in_x, double in_y) {
  x = in_x;
  y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2) {
  double squares =
      ((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y));
  return sqrt(squares);
}

ostream &operator<<(ostream &output, Point2D &p1) {
  output << "(" << p1.x << ", " << p1.y << ")";
  return output;
}

Point2D operator+(Point2D &p1, Vector2D &v1) {
  Point2D point;
  point.x = p1.x + v1.x;
  point.y = p1.y + v1.y;

  return point;
}

Vector2D operator-(Point2D &p1, Point2D &p2) {
  Vector2D vector;
  vector.x = p1.x - p2.x;
  vector.y = p1.y - p2.y;

  return vector;
}
