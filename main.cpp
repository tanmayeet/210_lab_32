// COMSC210 | Lab 32-33 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <deque>
#include <iostream>

#include "Car.h"
using namespace std;

// The # of cars in the beginning of the simulation
const int initialSize = 2;
const int probPaidCar = 46;
const int probJoinsQueue = 85;
const int probEmptyEnter = 50;
const int randMax = 100;
const int numLanes = 4;
const int sims = 20;

int main() {
  // deque<Car> tollLane;
  deque<Car> tollPlaza[numLanes];
  // Used to randomize i for a probability
  srand(time(0));

  // Creates initial deque using a traditional for loop
  for (int i = 0; i < numLanes; i++) {
    for (int j = 0; j < initialSize; j++) {
      tollPlaza[i].push_back(Car());
    }
  }

  // Prints initial queue using a range-based for loop
  cout << "Initial queue:\n";
  for (int i = 0; i < numLanes; i++) {
    cout << "Lane " << i + 1 << ": \n";
    for (auto& car : tollPlaza[i]) {
      cout << "   ";
      car.print();
    }
    cout << "\n";
  }

  for (int i = 1; i <= sims; i++) {
    cout << "Time: " << i;
    for (int j = 0; j < numLanes; j++) {
      if (!tollPlaza[j].empty()) {
        // i is for deciding the probability of whether the car in the front
        // paid or another car joined the queue
        int prob = (rand() % randMax);

        if (prob < probPaidCar) {
          Car paidCar = tollPlaza[j].front();
          // Changed this so after I set the object to the front car, then I pop
          // the front car so it's not in the list anymore
          tollPlaza[j].pop_front();
          // print the car that paid
          cout << "Car paid: ";
          paidCar.print();
        }

        else if (prob < probJoinsQueue) {
          tollPlaza[j].push_back(Car());
          // Generates random car object from class in Car.h
          cout << "Joined lane: ";
          tollPlaza[j].back().print();
        }

        else {
          // shift lanes
        }
      } else {
        int probTwo = (rand() % randMax);
        if (probTwo < probEmptyEnter) {
          tollPlaza[j].push_back(Car());
        }
      }
    }
  }

  // Printing out the queue at a given time interval
  cout << "Queue: \n";
  for (int i = 0; i < numLanes; i++) {
    if (tollPlaza[i].empty()) {
      cout << "    Empty";

    } else {
      for (auto& car : tollPlaza[i]) {
        // cout << "Lane: " << j+1;
        cout << "   ";
        car.print();
      }
      cout << "\n";
    }
  }

  return 0;
}
