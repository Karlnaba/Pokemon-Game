#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iomanip>
#include <iostream>

#include "Point2D.h"
#include "Trainer.h"
#include "Vector2D.h"

using namespace std;

Trainer::Trainer() : GameObject('T') {
  speed = 5;
  is_at_center = false;
  is_IN_GYM = false;
  health = 20;
  experience = 0;
  PokeDollars = 0;
  battles_to_buy = 0;
  potions_to_buy = 0;
  name = "Default";
  current_center = 0;
  current_gym = 0;
  destination.x = 0.0;
  destination.y = 0.0;

  cout << "Trainer default constructed" << endl;
}

Trainer::Trainer(char in_code) : GameObject(in_code) {
  speed = 5;
  is_at_center = false;
  is_IN_GYM = false;
  health = 20;
  experience = 0;
  PokeDollars = 0;
  battles_to_buy = 0;
  potions_to_buy = 0;
  name = "Default";
  current_center = 0;
  current_gym = 0;
  destination.x = 0.0;
  destination.y = 0.0;
  cout << "Trainer constrcuted" << endl;
  state = STOPPED;
  display_code = in_code;
}

Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed,
                 Point2D in_loc)
    : GameObject(in_loc, in_id, in_code) {
  speed = in_speed;
  name = in_name;
  is_at_center = false;
  is_IN_GYM = false;
  health = 20;
  experience = 0;
  PokeDollars = 0;
  battles_to_buy = 0;
  potions_to_buy = 0;
  current_center = 0;
  current_gym = 0;
  destination.x = 0.0;
  destination.y = 0.0;
  cout << "Trainer constructed" << endl;
}

void Trainer::StartMoving(Point2D dest) {
  SetupDestination(dest);

  if (location.x == dest.x && location.y == dest.y) {
    cout << display_code << id_num << ": I'm already there. See?" << endl;
  } else if (state == FAINTED) {
    cout << display_code << id_num
         << ": My pokemon have fainted. I may move but you cannot see me."
         << endl;
  } else {
    cout << display_code << id_num << ": On my way." << endl;
    state = MOVING;
  }
}

void Trainer::StartMovingToGym(PokemonGym* gym) {
  SetupDestination(gym->GetLocation());

  if (state == FAINTED) {
    cout << display_code << id_num
         << ": My Pokemon have fainted so I can't move to gym..." << endl;
  } else if ((location.x == (gym->GetLocation()).x) &&
             (location.y == (gym->GetLocation()).y)) {
    cout << display_code << id_num << ": I am already at the PokemonGym!"
         << endl;
    state = IN_GYM;
  } else {
    current_gym = gym;
    cout << display_code << id_num << ": on my way to gym " << (gym->GetId())
         << "." << endl;
    state = MOVING_TO_GYM;
  }
}

void Trainer::StartMovingToCenter(PokemonCenter* center) {
  SetupDestination(center->GetLocation());

  if (state == FAINTED) {
    cout << display_code << id_num
         << ": My pokemon have fainted so I should have gone to the center.."
         << endl;

  } else if ((location.x == (center->GetLocation()).x) &&
             (location.y == (center->GetLocation()).y)) {
    cout << display_code << id_num << ": I am already at the Center!" << endl;
    state = AT_CENTER;
  } else {
    current_center = center;
    cout << display_code << id_num << ": On my way to Center "
         << (center->GetId()) << "." << endl;
    state = MOVING_TO_CENTER;
  }
}

void Trainer::StartBattling(unsigned int num_battles) {
  Point2D gym_location = current_gym->GetLocation();
  bool is_able_battle;
  is_able_battle =
      current_gym->IsAbleToBattle(num_battles, PokeDollars, health);
  if (location.x == gym_location.x && location.y == gym_location.y) {
    is_IN_GYM = true;
  } else {
    is_IN_GYM = false;
  }

  if (state == FAINTED) {
    cout << display_code << id_num
         << ": My Pokemon have fainted so no more battles for me..." << endl;
  }

  else if (is_IN_GYM == false) {
    cout << display_code << id_num << ": I can only battle in a PokemonGym!"
         << endl;
  } else if ((current_gym->GetPokeDollarCost(num_battles) > PokeDollars)) {
    cout << display_code << id_num << ": Not enough money for battles" << endl;
  } else if (current_gym == NULL || (current_gym->passed() == true)) {
    cout << display_code << id_num
         << ": Cannot battle! This PokemonGym has no more trainers to battle!"
         << endl;

  }

  else if (is_able_battle == false) {
    cout << display_code << id_num
         << ": Cannot battle! Pokemon do not have enough health!" << endl;
  }

  else {
    cout << display_code << id_num << ": Started to battle at the PokemonGym "
         << (current_gym->GetId()) << " with " << num_battles << " battles"
         << endl;
    state = BATTLING_IN_GYM;
    battles_to_buy = num_battles;
  }
}

void Trainer::StartRecoveringHealth(unsigned int num_potions) {
  Point2D center_location = current_center->GetLocation();
  unsigned int experience;
  if (location.x == center_location.x && location.y == center_location.y) {
    is_at_center = true;
  } else {
    is_at_center = false;
  }

  if (is_at_center == false) {
    cout << display_code << id_num
         << ": I can only recover health at a PokemonCenter!" << endl;
  } else if (current_center->CanAffordPotion(num_potions, PokeDollars) ==
             false) {
    cout << display_code << id_num << ": Not enough money to recover health."
         << endl;
  } else if (current_center->HasPotions() == false) {
    cout << display_code << id_num
         << ": Cannot recover! No potion remaining in this PokemonCenter."
         << endl;
  } else {
    cout << display_code << id_num << ": Started recovering " << num_potions
         << " potions at PokemonCenter " << (current_center->GetId()) << endl;
    state = RECOVERING_HEALTH;
    potions_to_buy = num_potions;
  }
}

void Trainer::Stop() {
  state = STOPPED;
  cout << display_code << id_num << ": Stopping.." << endl;
}

bool Trainer::HasFainted() {
  if (health == 0) {
    return true;
  } else
    return false;
}

bool Trainer::ShouldBeVisible() {
  if (HasFainted() != true) {
    return true;
  } else
    return false;
}

void Trainer::ShowStatus() {
  cout << name << " status:";

  switch (state) {
    case 0: {
      cout << " stopped" << endl;
    } break;
    case 1: {
      cout << " moving at a speed of " << speed << " to destination "
           << destination << " at each step of " << delta << endl;
    } break;
    case 2: {
      cout << " fainted" << endl;
    } break;
    case 6: {
      cout << " heading to PokemonGym " << current_gym->GetId()
           << " at a speed of " << speed << " at each step of " << delta
           << endl;
    } break;
    case 5: {
      cout << " heading to PokemonCenter " << current_center->GetId()
           << " at a speed of " << speed << " at each step of " << delta
           << endl;
    } break;
    case 4: {
      cout << " inside PokemonGym " << current_gym->GetId() << endl;
    } break;
    case 3: {
      cout << " inside PokemonCenter " << current_center->GetId() << endl;
    } break;
    case 7: {
      cout << " battling in PokemonGym " << current_gym->GetId() << endl;
    } break;
    case 8: {
      cout << " recovering health in PokemonCenter " << current_center->GetId()
           << endl;
    } break;
  }
  GameObject::ShowStatus();
}

bool Trainer::Update() {
  switch (state) {
    case 0: {
      cout << "Health: " << health << endl;
      cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
      cout << "Experience: " << experience << endl;
      return false;
    } break;
    case 1: {
      bool arrived;
      arrived = UpdateLocation();

      if (arrived == true) {
        if (health == 0) {
          cout << name << " is out of health and can't move" << endl;
          state = FAINTED;
          return true;
        } else {
          state = STOPPED;
          cout << "Health: " << health << endl;
          cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
          cout << "Experience: " << experience << endl;
          return true;
        }
      } else {
        if (health == 0) {
          cout << name << " is out of health and can't move" << endl;
          state = FAINTED;
          return true;
        } else {
          cout << "Health: " << health << endl;
          cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
          cout << "Experience: " << experience << endl;
          state = MOVING;
          return false;
        }
      }

    } break;
    case 6: {
      bool arrived = UpdateLocation();
      if (arrived == true) {
        if (health == 0) {
          cout << name << " is out of health and can't move" << endl;
          state = FAINTED;
          return true;
        } else {
          if (state == MOVING_TO_GYM) {
            current_gym->AddOneTrainer();
          }
          state = IN_GYM;
          cout << "Health: " << health << endl;
          cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
          cout << "Experience: " << experience << endl;
          return true;
        }
      } else {
        if (health == 0) {
          cout << name << " is out of health and can't move" << endl;
          state = FAINTED;
          return true;
        } else {
          if (state == IN_GYM) {
            current_gym->RemoveOneTrainer();
          } else if (state == AT_CENTER) {
            current_center->RemoveOneTrainer();
          }

          state = MOVING_TO_GYM;
          cout << "Health: " << health << endl;
          cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
          cout << "Experience: " << experience << endl;
          return false;
        }
      }

    } break;
    case 5: {
      bool arrived = UpdateLocation();
      if (arrived == true) {
        if (health == 0) {
          cout << name << " is out of health and can't move" << endl;
          state = FAINTED;
          return true;
        } else {
          if (state == MOVING_TO_CENTER) {
            current_center->AddOneTrainer();
          }
          state = AT_CENTER;

          cout << "Health: " << health << endl;
          cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
          cout << "Experience: " << experience << endl;
          return true;
        }
      } else {
        if (health == 0) {
          cout << name << " is out of health and can't move" << endl;
          state = FAINTED;
          return true;
        } else {
          if (state == IN_GYM) {
            current_gym->RemoveOneTrainer();
          } else if (state == AT_CENTER) {
            current_center->RemoveOneTrainer();
          }
          state = MOVING_TO_CENTER;
          cout << "Health: " << health << endl;
          cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
          cout << "Experience: " << experience << endl;
          return false;
        }
      }

    } break;
    case 4: {
      cout << "Health: " << health << endl;
      cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
      cout << "Experience: " << experience << endl;
      return false;
    } break;
    case 3: {
      cout << "Health: " << health << endl;
      cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
      cout << "Experience: " << experience << endl;
      return false;
    } break;
    case 7: {
      unsigned int experience_gained =
          current_gym->TrainPokemon(battles_to_buy);
      health = health - current_gym->GetHealthCost(battles_to_buy);
      PokeDollars =
          PokeDollars - current_gym->GetPokeDollarCost(battles_to_buy);
      experience = experience + experience_gained;
      cout << "** " << name << " completed " << battles_to_buy << " battle(s)!"
           << endl;
      cout << "** " << name << " gained " << experience_gained << " experience!"
           << endl;
      cout << "Health: " << health << endl;
      cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
      cout << "Experience: " << experience << endl;
      if (health == 0) {
        state = FAINTED;
      } else {
        state = IN_GYM;
      }
      return true;
    } break;
    case 8: {
      unsigned int potions_received =
          current_center->DistributePotion(potions_to_buy);
      unsigned int health_recovered = potions_received * 5;
      health = health + health_recovered;
      PokeDollars =
          PokeDollars - current_center->GetPokeDollarCost(potions_to_buy);
      cout << "** " << name << " recovered " << health_recovered
           << " health! **" << endl;
      cout << "** " << name << " bought " << potions_received << " potions! **"
           << endl;
      cout << "Health: " << health << endl;
      cout << "PokeDollars: " << setprecision(2) << PokeDollars << endl;
      cout << "Experience: " << experience << endl;
      state = AT_CENTER;
      return true;
    } break;
  }
}

bool Trainer::UpdateLocation() {
  if (fabs(destination.x - location.x) <= fabs(delta.x) &&
      fabs(destination.y - location.y) <= fabs(delta.y)) {
    cout << display_code << id_num << ": I'm there!" << endl;
    location.x = destination.x;
    location.y = destination.y;
    return true;

  } else {
    if (health == 0) {
      cout << name << " is out of health and can't move" << endl;
      state = FAINTED;
      return false;
    } else {
      double random_dollars;
      cout << display_code << id_num << ": step..." << endl;
      location.x += delta.x;
      location.y += delta.y;
      health--;
      random_dollars = GetRandomAmountOfPokeDollars();
      PokeDollars = PokeDollars + random_dollars;

      return false;
    }
  }
}

void Trainer::SetupDestination(Point2D dest) {
  destination = dest;
  delta.x = (destination.x - location.x) *
            (speed / GetDistanceBetween(destination, location));
  delta.y = (destination.y - location.y) *
            (speed / GetDistanceBetween(destination, location));
}

double GetRandomAmountOfPokeDollars() {
  double random_dollar;
  random_dollar = ((double)rand()) * 2.0 / RAND_MAX;
  return random_dollar;
}

string Trainer::GetName() { return name; }

Trainer::~Trainer() { cout << "Trainer destructed." << endl; }

int Trainer::GetState() { return state; }

PokemonGym* Trainer::GetCurrentGym() { return current_gym; }

PokemonCenter* Trainer::GetCurrentCenter() { return current_center; }
