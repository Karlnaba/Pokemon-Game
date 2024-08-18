#include <iostream>

#include "View.h"

using namespace std;

View::View() {
  size = 11;
  scale = 2;
  origin = Point2D();
}

bool View::GetSubscripts(int& out_x, int& out_y, Point2D location) {
  out_x = (location.x - origin.x) / scale;
  out_y = (location.y - origin.y) / scale;
  if (location.x > 20 || location.x < 0 || location.y > 20 || location.y < 0) {
    cout << "An object is outside the display" << endl;
    return false;
  } else {
    return true;
  }
}

void View::Clear() {
  for (int i = 0; i < view_maxsize; i++) {
    for (int j = 0; j < view_maxsize; j++) {
      grid[i][j][0] = '.';
      grid[i][j][1] = ' ';
    }
  }
}

void View::Plot(GameObject* ptr) {
  int out_x;
  int out_y;
  bool subscript;
  subscript = GetSubscripts(out_x, out_y, ptr->GetLocation());
  if (subscript == true) {
    if (ptr->GetState() == 2) {
      grid[out_x][out_y][0] = '.';
      grid[out_x][out_y][1] = ' ';
    } else {
      if (grid[out_x][out_y][0] == '.') {
        ptr->DrawSelf(grid[out_x][out_y]);
      } else {
        //*(grid[out_x][out_y]) = '*';
        //*(grid[out_x][out_y] + 1) = ' ';
        grid[out_x][out_y][0] = '*';
        grid[out_x][out_y][1] = ' ';
      }
    }
  }
}

void View::Draw() {
  for (int j = size - 1; j >= -1; j--) {
    for (int i = -1; i <= size - 1; i++) {
      if (i == -1 && j % 2 == 0) {
        cout << j * 2;
        if (j / 5 == 0) {
          cout << " ";
        }
      } else if (i == -1 && j % 2 != 0) {
        cout << "  ";
      } else if (j == -1 && i % 2 == 0) {
        cout << i * 2;
        if (i / 5 == 0) {
          cout << " ";
        }
        cout << "  ";
      }
      if (i >= 0 && j >= 0) {
        cout << grid[i][j][0] << grid[i][j][1];
      }
    }
    cout << endl;
  }
}