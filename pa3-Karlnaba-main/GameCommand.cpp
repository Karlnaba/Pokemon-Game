#include <iostream>

#include "GameCommand.h"

using namespace std;

void DoMoveCommand(Model& model, int trainer_id, Point2D p1) {
  PokemonGym* current_gym;
  PokemonCenter* current_center;
  Trainer* train = model.GetTrainerPtr(trainer_id);
  if (train != 0) {
    if (train->GetState() == 3) {
      current_center = train->GetCurrentCenter();
      current_center->RemoveOneTrainer();

    } else if (train->GetState() == 4) {
      current_gym = train->GetCurrentGym();
      current_gym->RemoveOneTrainer();
    }
    cout << "Moving " << train->GetName() << " to " << p1 << endl;
    train->StartMoving(p1);
  } else {
    cout << "Error: Please enter a valid command!" << endl;
  }
}

void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id) {
  Trainer* train = model.GetTrainerPtr(trainer_id);
  PokemonCenter* center = model.GetPokemonCenterPtr(center_id);
  PokemonGym* current_gym;
  PokemonCenter* current_center;
  if (train != 0 || center != 0) {
    if (train->GetState() == 3) {
      current_center = train->GetCurrentCenter();
      current_center->RemoveOneTrainer();

    } else if (train->GetState() == 4) {
      current_gym = train->GetCurrentGym();
      current_gym->RemoveOneTrainer();
    }
    cout << "Moving " << train->GetName() << " to pokemon center "
         << center->GetId() << endl;
    train->StartMovingToCenter(center);
  } else {
    cout << "Error: Please enter a valid command!" << endl;
  }
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id) {
  Trainer* train = model.GetTrainerPtr(trainer_id);
  PokemonGym* gym = model.GetPokemonGymPtr(gym_id);
  PokemonGym* current_gym;
  PokemonCenter* current_center;
  if (train != 0 || gym != 0) {
    if (train->GetState() == 3) {
      current_center = train->GetCurrentCenter();
      current_center->RemoveOneTrainer();

    } else if (train->GetState() == 4) {
      current_gym = train->GetCurrentGym();
      current_gym->RemoveOneTrainer();
    }
    cout << "Moving " << train->GetName() << " to gym " << gym->GetId() << endl;
    train->StartMovingToGym(gym);
  } else {
    cout << "Error: Please enter a valid command!" << endl;
  }
}

void DoStopCommand(Model& model, int trainer_id) {
  Trainer* train = model.GetTrainerPtr(trainer_id);
  if (train != 0) {
    cout << "Stopping " << train->GetName() << endl;
    train->Stop();
  } else {
    cout << "Error: Please enter a valid command!" << endl;
  }
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles) {
  Trainer* train = model.GetTrainerPtr(trainer_id);
  if (train != 0) {
    cout << train->GetName() << " is battling" << endl;
    train->StartBattling(battles);
  } else {
    cout << "Error: Please enter a valid command!" << endl;
  }
}

void DoRecoverInCenterCommand(Model& model, int trainer_id,
                              unsigned int potions_needed) {
  Trainer* train = model.GetTrainerPtr(trainer_id);
  if (train != 0) {
    cout << "Recovering " << train->GetName() << "'s Pokemon's health" << endl;
    train->StartRecoveringHealth(potions_needed);
  } else {
    cout << "Error: Please enter a valid command!" << endl;
  }
}

void DoAdvanceCommand(Model& model, View& view) {
  model.Update();
  cout << "Advancing one tick." << endl;
  model.ShowStatus();
  view.Clear();
  model.Display(view);
  view.Draw();
}

void DoRunCommand(Model& model, View& view) {
  int count = 1;
  bool update = model.Update();
  while (count < 5 && update != true) {
    update = model.Update();
    count++;
  }
  model.Display(view);
  cout << "Advancing to next event." << endl;
  model.ShowStatus();
  view.Clear();
  model.Display(view);
  view.Draw();
}