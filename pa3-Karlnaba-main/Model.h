#ifndef MODEL_H
#define MODEL_H
#include <iostream>

#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "View.h"

using namespace std;

class Model {
 public:
  Model();
  virtual ~Model();
  Trainer* GetTrainerPtr(int);
  PokemonCenter* GetPokemonCenterPtr(int);
  PokemonGym* GetPokemonGymPtr(int);
  bool Update();
  void Display(View&);
  void ShowStatus();

 private:
  int time;
  GameObject* object_ptrs[10];
  int num_objects;
  Trainer* trainer_ptrs[10];
  int num_trainers;
  PokemonCenter* center_ptrs[10];
  int num_centers;
  PokemonGym* gym_ptrs[10];
  int num_gyms;
};

#endif