//
//    elevators.C
//
//    Function stubs for the missing parts of elevators.
//
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include "building.h"
#include "elevators.h"
#include <vector>
#include <queue>
#include <semaphore.h>
using namespace std;

// A vector of Queues to store the passengers that want to go to a given floor

typedef vector < queue<int> > QueueVector;

struct passenger {
  const Person *name;
  int org, dest;
  sem_t wait;
};


//
// Elevator constructor
//   Called once for each elevator before the thread is created.
//
Elevator::Elevator()
{ 
  // This is the place to perform any one-time initializations of
  // per-elevator data.
    
}
//
// Elevator::display_passengers()
//
//  Call display() for each Person on the elevator.
//  Return the number of riders.
//
//  Beware: calling message() from this function will hang the simulation.
//
int Elevator::display_passengers()
{
  return 0;
}

//
// Elevator::run()
//
//   Main thread for an elevator.
//   Will be called at the beginning of the simulation, to put the
//   Elevator into operation.  run() should pick up and deliver Persons,
//   coordinating with other Elevators for efficient service.
//   run should never return.
//   
void Elevator::run()
{ 
  message("running");
  if (door_is_open()){
    close_door();
  }
  for (int m = 0; m<12; m++){
    move_to_floor(m);
    onfloor();
    open_door();
    close_door();
    if (m==12)
      m = 0;
  }
  /* while (origin < destination){
    move_up();
    origin++;
    if (onfloor()){
      open_door();
    }
    }*/
  // Pick up and drop off passengers.
};

//
//  take_elevator
//
//    A Person (who) calls this function to take an elevator from their
//    current floor (origin) to a different floor (destination).
//
void take_elevator(const Person *who, int origin, int destination)
{
  QueueVector vector1[11];
  for (int d = 0;d<12;d++){
    if (destination == d){
      vector1[d].push_back(*who);
    }
  }
  //move_up();
}

  // Should not return until the person has taken an elevator
  // to their destination floor.
;

