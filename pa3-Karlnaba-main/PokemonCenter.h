#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H

#include <iostream>

#include "Building.h"
#include "Point2D.h"

using namespace std;

enum PokemonCenterStates { POTIONS_AVAILABLE = 0, NO_POTIONS_AVAILABLE = 1 };

class PokemonCenter : public Building {
 public:
  PokemonCenter();
  PokemonCenter(int in_id, double potion_cout, unsigned int potion_cap,
                Point2D in_loc);

  bool HasPotions();
  unsigned int GetNumPotionRemaining();
  bool CanAffordPotion(unsigned int potion, double budget);
  double GetPokeDollarCost(unsigned int potion);
  unsigned int DistributePotion(unsigned int potion_needed);
  bool Update();
  void ShowStatus();
  virtual ~PokemonCenter();

 private:
  unsigned int potion_capacity;
  unsigned int num_potions_remaining;
  double pokedollar_cost_per_potion;
};

#endif
