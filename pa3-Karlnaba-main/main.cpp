#include <iostream>

#include "Building.h"
#include "GameCommand.h"
#include "GameObject.h"
#include "Model.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Vector2D.h"

using namespace std;

int main() {
  srand((unsigned int)time(NULL));
  Model model;
  View view;
  char command;
  int id_trainer;
  int id_center;
  int id_gym;
  double x;
  double y;
  int input1;
  double input2;
  double input3;
  double input4;
  Point2D point;
  unsigned int potion_amount;
  unsigned int battle_amount;
  bool keep_going = true;

  model.ShowStatus();
  view.Clear();
  model.Display(view);
  view.Draw();

  while (keep_going == true) {
    cout << "Enter command: ";
    cin >> command;

    switch (command) {
      case 'm': {
        cin >> input1 >> input2 >> input3;
        point.x = input2;
        point.y = input3;
        id_trainer = input1;
        DoMoveCommand(model, id_trainer, point);
      } break;
      case 'c': {
        cin >> input1 >> input2;
        id_trainer = input1;
        id_center = static_cast<int>(input2);
        DoMoveToCenterCommand(model, id_trainer, id_center);
      } break;
      case 'g': {
        cin >> input1 >> input2;
        id_trainer = input1;
        id_gym = static_cast<int>(input2);
        DoMoveToGymCommand(model, id_trainer, id_gym);
      } break;
      case 's': {
        cin >> input1;
        id_trainer = input1;
        DoStopCommand(model, id_trainer);
      } break;
      case 'p': {
        cin >> input1 >> input2;
        id_trainer = input1;
        potion_amount = static_cast<unsigned int>(input2);
        DoRecoverInCenterCommand(model, id_trainer, potion_amount);
      } break;
      case 'b': {
        cin >> input1 >> input2;
        id_trainer = input1;
        battle_amount = static_cast<unsigned int>(input2);
        DoBattleCommand(model, id_trainer, battle_amount);
      } break;
      case 'a': {
        DoAdvanceCommand(model, view);
      } break;
      case 'r': {
        DoRunCommand(model, view);
      } break;
      case 'q': {
        keep_going = false;
      } break;
    }
  }
}
