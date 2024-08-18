#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>

#include "GameObject.h"
#include "Point2D.h"

using namespace std;

class Building : public GameObject {
 private:
  unsigned int trainer_count = 0;

 public:
  Building();
  Building(char in_code, int in_Id, Point2D in_loc);

  virtual ~Building();

  bool Update();

  bool ShouldBeVisible();

  void AddOneTrainer();

  void ShowStatus();

  void RemoveOneTrainer();
};

#endif