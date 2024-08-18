#include <iostream>

#include "Building.h"
#include "GameObject.h"

using namespace std;
// place the constructors below
Building::Building() : GameObject('B') {
  std::cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc)
    : GameObject(in_loc, in_Id, in_code) {
  display_code = in_code;
  location = in_loc;
  id_num = in_Id;
  std::cout << "Building constructed" << endl;
}

// WE PLACE THE PUBLIC MEMBER FUNCTIONS BELOW

void Building::AddOneTrainer() { trainer_count++; }

void Building::RemoveOneTrainer() { trainer_count--; }

bool Building::ShouldBeVisible() { return true; }

bool Building::Update() { cout << "Building updated" << endl; }

Building::~Building() { cout << "Building destructed" << endl; }

void Building::ShowStatus() {
  std::cout << display_code << id_num << "Located at" << location << endl;

  if (trainer_count == 1) {
    std::cout << trainer_count << "The trainer is in this building" << endl;
  } else
    std::cout << trainer_count << "Trainers are in this builidng" << endl;
}