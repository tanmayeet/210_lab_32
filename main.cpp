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

  int time = 1;
  while (!tollLane.empty()) {
    int i = (rand() % 100);

    cout << time << "Operation: ";
    if (i < 55) {
      tollLane.pop_front();
      cout << "Car paid: ";
      tollLane.front().print();
      cout << "\n";

    } else {
      tollLane.push_back(Car());
      cout << "Joined lane: ";
      tollLane.back().print();
      cout << "\n";
    }

    time++;
    cout << "Queue: \n";
    for (auto& car : tollLane) {
      car.print();
    }
  }

  return 0;
}
