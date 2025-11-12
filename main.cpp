// COMSC210 | Lab 32 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <deque>
#include <iostream>

#include "Car.h"

const int initialSize = 2;

int main() {
  deque<Car> tollLane;
  srand(time(0));

  for (int i = 0; i < initialSize; i++) {
    tollLane.push_back(Car());
  }

  cout << "Initial queue:\n";
  for (auto& car : tollLane) {
    car.print();
  }

  while (!tollLane.empty()) {
  }

  return 0;
}
