// COMSC210 | Lab 32 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <deque>
#include <iostream>

#include "Car.h"

// The # of cars in the beginning of the simulation
const int initialSize = 2;

int main() {
  deque<Car> tollLane;
  // Used to randomize i for a probability
  srand(time(0));

  // Creates initial deque using a traditional for loop
  for (int i = 0; i < initialSize; i++) {
    tollLane.push_back(Car());
  }

  // Prints initial queue using a range-based for loop
  cout << "Initial queue:\n";
  for (auto& car : tollLane) {
    cout << "   ";
    car.print();
  }
  cout << "\n";

  int time = 1;
  while (!tollLane.empty()) {
    // i is for deciding the probability of whether the car in the front paid or
    // another car joined the queue
    int i = (rand() % 100);

    cout << "Time: " << time << " Operation: ";
    if (i < 55) {
      // When testing my code, I realized that for this function, because I want
      // it to print out the car that paid even if the queue is empty, I need to
      // initialize a new Car object and set it to the front car so I can print
      // this value later instead of printing the tollLane at that time, which
      // is empty
      Car paidCar = tollLane.front();
      // Changed this so after I set the object to the front car, then I pop the
      // front car so it's not in the list anymore
      tollLane.pop_front();
      // print the car that paid
      cout << "Car paid: ";
      paidCar.print();

    } else {
      // Because this function is not getting rid of any cars, we don't need to
      // technically set a new Car object to the back car that just joined the
      // line, but we technicallly could have the same format as the initial
      // loop if we wanted to
      tollLane.push_back(Car());
      // Generates random car object from class in Car.h
      cout << "Joined lane: ";
      tollLane.back().print();
    }

    // Printing out the queue at a given time interval
    cout << "Queue: \n";
    if (tollLane.empty()) {
      cout << "    Empty";

    } else {
      for (auto& car : tollLane) {
        cout << "   ";
        car.print();
      }
      cout << "\n";
    }
    time++;
  }
  return 0;
}
