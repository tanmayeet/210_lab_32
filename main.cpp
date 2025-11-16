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
const int probShiftLanes = 100;
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

  for (int i = 0; i < sims; i++) {
    for (int j = 0; j < numLanes; j++) {
      while (!tollPlaza[j].empty()) {
        // i is for deciding the probability of whether the car in the front
        // paid or another car joined the queue
        int prob = (rand() % randMax);

        cout << "Time: " << i << " Operation: ";
        if (prob < probPaidCar) {
          // When testing my code, I realized that for this function, because I
          // want it to print out the car that paid even if the queue is empty,
          // I need to initialize a new Car object and set it to the front car
          // so I can print this value later instead of printing the tollLane at
          // that time, which is empty
          Car paidCar = tollPlaza[j].front();
          // Changed this so after I set the object to the front car, then I pop
          // the front car so it's not in the list anymore
          tollPlaza[j].pop_front();
          // print the car that paid
          cout << "Car paid: ";
          paidCar.print();
        }

        else if (prob > probPaidCar && prob < probJoinsQueue) {
          // Because this function is not getting rid of any cars, we don't need
          // to technically set a new Car object to the back car that just
          // joined the line, but we technicallly could have the same format as
          // the initial loop if we wanted to
          tollPlaza[j].push_back(Car());
          // Generates random car object from class in Car.h
          cout << "Joined lane: ";
          tollPlaza[j].back().print();
        }

        else {
          // shift lanes
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
        cout << "   ";
        car.print();
      }
      cout << "\n";
    }
  }

  return 0;
}
