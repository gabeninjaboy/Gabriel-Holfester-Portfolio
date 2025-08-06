#ifndef SIMULATION_H
#define SIMULATION_H


class Simulation
{

  // Defines public functions to be used in Simulation.cpp //
  
 public:

  Simulation();
  void moveJaneway(unsigned int *ptrJaneway);
  void moveSisko(unsigned int *ptrSisko);
  void runOneGame();
  
};

#endif
