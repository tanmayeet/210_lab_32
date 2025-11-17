// COMSC210 | Lab 32-33 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <deque>
#include <iostream>

#include "Car.h"
using namespace std;

// Constants
const int initialSize = 2;
const int probPaidCar = 46;
const int probJoinsQueue = 85;
const int probEmptyEnter = 50;
const int randMax = 100;
const int numLanes = 4;
const int sims = 20;

int main() {
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
    cout << "Time: " << i << endl;
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
          cout << "Lane " << j + 1 << ": Paid: ";
          paidCar.print();
        }

        else if (prob < probJoinsQueue) {
          tollPlaza[j].push_back(Car());
          // Generates random car object from class in Car.h
          cout << "Lane " << j + 1 << ": Joined: ";
          tollPlaza[j].back().print();
        }

        else {
          Car switched = tollPlaza[j].back();
          tollPlaza[j].pop_back();
          int randLane;
          do {
            randLane = (rand() % numLanes);
          } while (randLane == j);
          tollPlaza[randLane].push_back(switched);
          cout << "Lane " << j + 1 << ": Switched to lane: " << randLane + 1
               << ": ";
          switched.print();
        }

      } else {
        int probTwo = (rand() % randMax);
        if (probTwo < probEmptyEnter) {
          tollPlaza[j].push_back(Car());
          cout << "Lane: " << j + 1 << "Entered: ";
          tollPlaza[j].back().print();
        } else {
          cout << "Lane " << j + 1 << "No action.\n";
        }
      }
    }
    // Printing out the queue at a given time interval
    for (int i = 0; i < numLanes; i++) {
      cout << "Queue: " << i + 1 << endl;
      if (tollPlaza[i].empty()) {
        cout << "    Empty]\n";

      } else {
        for (auto& car : tollPlaza[i]) {
          // cout << "Lane: " << j+1;
          cout << "   ";
          car.print();
        }
        cout << "\n";
      }
    }
  }
  cout << endl;
  return 0;
}
