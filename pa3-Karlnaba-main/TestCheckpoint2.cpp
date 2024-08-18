#include <iostream>

#include "Building.h"
#include "GameObject.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Vector2D.h"

using namespace std;

int main() {
  Building newbuild;
  newbuild.ShowStatus();
  Point2D point;
  point.x = 1;
  point.y = 2;

  Building build2('B', 2, point);
  build2.ShowStatus();
  build2.AddOneTrainer();
  build2.ShowStatus();

  PokemonCenter pokecenter1;
  pokecenter1.ShowStatus();

  PokemonCenter pokecenter2(2, 3, 50, point);
  pokecenter2.AddOneTrainer();
  bool haspotions;
  haspotions = pokecenter2.HasPotions();
  cout << "Does PokemonCenter have potions: " << haspotions << endl;

  unsigned int getnumpot;
  getnumpot = pokecenter2.GetNumPotionRemaining();
  cout << "PokemonCenter has " << getnumpot << " potions" << endl;

  bool afford;
  afford = pokecenter2.CanAffordPotion(2, 30);
  cout << "Can they afford to buy potions: " << afford << endl;

  double cost;
  cost = pokecenter2.GetPokeDollarCost(3);
  cout << "The cost of this many potions is: " << cost << endl;

  unsigned int lessremain;
  lessremain = pokecenter2.DistributePotion(4);
  cout << "Potions needed: " << lessremain << endl;

  unsigned int moreremain;
  moreremain = pokecenter2.DistributePotion(47);
  cout << "Current amount: " << moreremain << endl;

  bool depleted;
  depleted = pokecenter2.Update();
  depleted = pokecenter2.Update();

  pokecenter2.ShowStatus();

  PokemonGym gym1;
  PokemonGym gym2(100, 2, 3.0, 5, 2, point);

  double cost_battle = gym2.GetPokeDollarCost(3);
  cout << "Cost of 3 battles: " << cost_battle << endl;

  unsigned int health_cost = gym2.GetHealthCost(4);
  cout << "Health cost of 4 battles: " << health_cost << endl;

  unsigned int remaining_battles = gym2.GetNumBattlesRemaining();
  cout << "Battles remaining: " << remaining_battles << endl;

  bool able_to_battle = gym2.IsAbleToBattle(2, 30, 30);
  cout << "Are they able to battle: " << able_to_battle << endl;

  unsigned int poke_train = gym2.TrainPokemon(4);
  cout << "The amount of experience gained: " << poke_train << endl;

  unsigned int poke_train_max = gym2.TrainPokemon(97);
  cout << "The amount of experience gained: " << poke_train_max << endl;

  gym2.AddOneTrainer();

  unsigned int experience = gym2.GetExperiencePerBattle();
  cout << "Experience per battle: " << experience << endl;

  bool update = gym2.Update();
  cout << "Can you battle more: " << update << endl;

  bool passed = gym2.passed();
  cout << "Passed: " << passed << endl;

  gym2.ShowStatus();
}