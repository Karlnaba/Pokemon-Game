#include <iostream>

#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"

using namespace std;

int main() {
  Point2D point1;
  cout << "Point 1 is " << point1 << endl;

  Point2D point2;
  point2.x = 1.2;
  point2.y = 3.4;
  cout << "Point 2 is " << point2 << endl;

  double distance;
  distance = GetDistanceBetween(point1, point2);
  cout << "The distance is " << distance << endl;

  Point2D ResultOfAddOperator;
  Vector2D vector1;
  vector1.x = 2;
  vector1.y = 4;
  ResultOfAddOperator = point2 + vector1;
  cout << "The result of the addition operator is " << ResultOfAddOperator
       << endl;

  Point2D point3;
  point3.x = 1;
  point3.y = 1;
  Vector2D ResultOfSubtractOperator;
  ResultOfSubtractOperator = point2 - point3;
  cout << "The result of the subtraction operator is "
       << ResultOfSubtractOperator << endl;

  Vector2D vector2;
  cout << "Vector 1 is " << vector1 << endl;
  cout << "Vector 2 is " << vector2 << endl;

  double d = 5;
  Vector2D ResultOfMultiplicationOperator = vector1 * d;
  cout << "The result of the multiplication operator is "
       << ResultOfMultiplicationOperator << endl;

  Vector2D ResultOfDivisionOperator = vector1 / d;
  cout << "The result of the division operator is " << ResultOfDivisionOperator
       << endl;

  ResultOfDivisionOperator = vector1 / 0;
  cout << "The result of the division operator when divided by 0 is "
       << ResultOfDivisionOperator << endl;

  GameObject player1('c');
  GameObject player2(point2, 3, 'd');

  Point2D LocationPlayer2 = player2.GetLocation();
  cout << "The location of player 2 is " << LocationPlayer2 << endl;

  int IdPlayer2;
  IdPlayer2 = player2.GetId();
  cout << "The ID of player 2 is " << IdPlayer2 << endl;

  char StatePlayer2;
  StatePlayer2 = player2.GetState();
  cout << "The state of player 2 is " << StatePlayer2;
  player2.ShowStatus();
}