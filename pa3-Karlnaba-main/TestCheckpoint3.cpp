#include <iostream>

#include "Trainer.h"

using namespace std;

int main() {
  Point2D point;
  point.x = 5;
  point.y = 5;

  Point2D point2;
  point2.x = 19;
  point2.y = 19;

  Trainer trainer3("Adrian", 3, 'T', 2, point);

  // trainer3.StartMoving(point2);

  PokemonGym* gym;
  PokemonGym gym2(100, 2, 3.0, 5, 2, point2);
  gym = &gym2;

  trainer3.StartMovingToGym(gym);

  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.StartBattling(1);
  trainer3.ShowStatus();
  trainer3.Update();

  PokemonCenter* center;
  Point2D point3;
  point3.x = 2;
  point3.y = 2;
  PokemonCenter center1(4, 2, 30, point3);
  center = &center1;
  trainer3.StartMovingToCenter(center);
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.Stop();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.StartRecoveringHealth(1);
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.ShowStatus();
  trainer3.Update();
  trainer3.Update();
}