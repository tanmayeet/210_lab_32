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
  cout << "\n";

  int time = 1;
  while (!tollLane.empty()) {
    int i = (rand() % 100);

    cout << "Time: " << time << " Operation: ";
    if (i < 55) {
      Car paidCar = tollLane.front();
      tollLane.pop_front();
      cout << "Car paid: ";
      tollLane.front().print();

    } else {
      Car joinedLine = tollLane.back();
      tollLane.push_back(Car());
      cout << "Joined lane: ";
      tollLane.back().print();
    }

    cout << "Queue: \n";
    if (!tollLane.empty()) {
      for (auto& car : tollLane) {
        cout << "   ";
        car.print();
      }
    } else {
      cout << " Empty";
    }
    cout << "\n";
    time++;
  }

  return 0;
}
