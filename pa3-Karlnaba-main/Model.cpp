#include <stdlib.h>

#include <iostream>

#include "GameObject.h"
#include "Model.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"

using namespace std;

Model::Model() {
  time = 0;
  Point2D trainer_location1;
  trainer_location1.x = 5;
  trainer_location1.y = 1;
  trainer_ptrs[0] = new Trainer("Ash", 1, 'T', 1, trainer_location1);
  object_ptrs[0] = trainer_ptrs[0];

  Point2D trainer_location2;
  trainer_location2.x = 10;
  trainer_location2.y = 1;
  trainer_ptrs[1] = new Trainer("Misty", 2, 'T', 2, trainer_location2);
  object_ptrs[1] = trainer_ptrs[1];

  Point2D center_location1;
  center_location1.x = 1;
  center_location1.y = 20;
  center_ptrs[0] = new PokemonCenter(1, 1, 100, center_location1);
  object_ptrs[2] = center_ptrs[0];

  Point2D center_location2;
  center_location2.x = 10;
  center_location2.y = 20;
  center_ptrs[1] = new PokemonCenter(2, 2, 200, center_location2);
  object_ptrs[3] = center_ptrs[1];

  Point2D gym_location1;
  gym_location1.x = 0;
  gym_location1.y = 0;
  gym_ptrs[0] = new PokemonGym(10, 1, 2, 3, 1, gym_location1);
  object_ptrs[4] = gym_ptrs[0];

  Point2D gym_location2;
  gym_location2.x = 5;
  gym_location2.y = 5;
  gym_ptrs[1] = new PokemonGym(20, 5, 7.5, 4, 2, gym_location2);
  object_ptrs[5] = gym_ptrs[1];

  num_objects = 6;
  num_trainers = 2;
  num_centers = 2;
  num_gyms = 2;

  cout << "Model default constructed" << endl;
}

Model::~Model() {
  for (int i = 0; i < 6; i++) {
    delete object_ptrs[i];
  }
}

Trainer* Model::GetTrainerPtr(int id) {
  bool matches;
  for (int i = 0; i < num_trainers; i++) {
    if (id == trainer_ptrs[i]->GetId()) {
      matches = true;
      return trainer_ptrs[i];
    } else {
      matches = false;
    }
  }
  if (matches == false) {
    return 0;
  }
}

PokemonCenter* Model::GetPokemonCenterPtr(int id) {
  bool matches;
  for (int i = 0; i < 10; i++) {
    if (id == center_ptrs[i]->GetId()) {
      matches = true;
      return center_ptrs[i];
    } else {
      matches = false;
    }
  }
  if (matches == false) {
    return 0;
  }
}

PokemonGym* Model::GetPokemonGymPtr(int id) {
  bool matches;
  for (int i = 0; i < 10; i++) {
    if (id == gym_ptrs[i]->GetId()) {
      matches = true;
      return gym_ptrs[i];
    } else {
      matches = false;
    }
  }
  if (matches == false) {
    return 0;
  }
}

bool Model::Update() {
  bool gyms_beat[10];
  bool all_gyms_beat;
  int count_gym = 0;
  for (int i = 0; i < num_gyms; i++) {
    gyms_beat[i] = gym_ptrs[i]->passed();
  }
  for (int i = 0; i < num_gyms; i++) {
    if (gyms_beat[i] == true) {
      count_gym++;
    } else if (gyms_beat[i] == false) {
      all_gyms_beat = false;
    }
  }
  if (count_gym == num_gyms) {
    all_gyms_beat = true;
  }
  if (all_gyms_beat == true) {
    cout << "GAME OVER: You win! All battles done!" << endl;
    exit(0);
  }

  bool fainted[10];
  bool all_fainted;
  int count_fainted = 0;
  for (int i = 0; i < num_trainers; i++) {
    fainted[i] = trainer_ptrs[i]->HasFainted();
  }
  for (int i = 0; i < num_trainers; i++) {
    if (fainted[i] == true) {
      count_fainted++;
    } else if (fainted[i] == false) {
      all_fainted = false;
    }
  }
  if (count_fainted == num_trainers) {
    all_fainted = true;
  }
  if (all_fainted == true) {
    cout << "GAME OVER: You lose! All of your Trainers' pokemon have fainted!"
         << endl;
    exit(0);
  }

  bool istrue[10];
  time++;
  for (int i = 0; i < num_objects; i++) {
    istrue[i] = object_ptrs[i]->Update();
  }
  for (int i = 0; i < num_objects; i++) {
    if (istrue[i] == true) {
      return true;
    }
  }
}

void Model::Display(View& view) {
  cout << "Time: " << time << endl;
  for (int i = 0; i < num_objects; i++) {
    view.Plot(object_ptrs[i]);
  }
}

void Model::ShowStatus() {
  cout << "Time: " << time << endl;
  ;

  for (int i = 0; i < num_objects; i++) {
    object_ptrs[i]->ShowStatus();
  }
}
