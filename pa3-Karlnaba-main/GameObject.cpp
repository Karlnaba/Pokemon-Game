#include <iostream>

#include "GameObject.h"
#include "Point2D.h"

using namespace std;

GameObject::GameObject(char in_code) {
  display_code = in_code;
  location.x = 0;
  location.y = 0;
  id_num = 1;
  state = 0;
  std::cout << "GameObject constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code) {
  location.x = in_loc.x;
  location.y = in_loc.y;
  id_num = in_id;
  display_code = in_code;
  state = 0;
  std::cout << "GameObject constructed" << endl;
}

Point2D GameObject::GetLocation() { return location; }

int GameObject::GetId() { return id_num; }

char GameObject::GetState() { return state; }

void GameObject::ShowStatus() {
  std::cout << display_code << id_num << " at " << location << endl;
}

void GameObject::DrawSelf(char* ptr) {
  *ptr = display_code;
  *(ptr + 1) = id_num + 48;
}
GameObject::~GameObject() { cout << "GameObject destructed." << endl; }
