/*
 * Gabriel Holfester
 * CPSC 1070 Section 001
 * 10/24/24
 * This code runs the simulation for a race between Sisko and Janeway with their grading, it will play until someone 
 * wins by passing the goal
*/



#include "WorkPay.h"
#include "Simulation.h"
#include <iostream>

using namespace std;

int main()
{
  bool stopSimulation = false;

  // Runs a while loop until quit is hit to end the "game" //
  
  while(stopSimulation != true)
    {
      char userInput = '\0';
      cout<<"S for Simulation and W for WorkPay: ";
      cin>>userInput; // Asks the user for input // 

      if(userInput == 's' || userInput == 'S')
	{
	  Simulation run; // Creates an instance of Simulation and runs the game //
	  run.runOneGame();

	}else if(userInput == 'W' || userInput == 'w')
	{

	  // Tests all the overloaded operators and functions // 
	  
	  WorkPay workpay1(9);
	  
	  workpay1--;
	  cout<<"Post decrement: "<<workpay1.retrieveDays()<<endl;
	  
	  workpay1++;
	  cout<<"Post increment: "<<workpay1.retrieveDays()<<endl;

	  --workpay1;
	  cout<<"Pre decrement: "<<workpay1.retrieveDays()<<endl;
	  
	  ++workpay1;
	  cout<<"pre increment: "<<workpay1.retrieveDays()<<endl;

	  workpay1 = workpay1 + 5;

	  cout<<"Adding 5: "<<workpay1.retrieveHours()<<endl;

	  workpay1 = workpay1 - 2;

	  cout<<"Subtracting 2: "<<workpay1.retrieveHours()<<endl;
	  


	  
	  
	}else if(userInput == 'Q' || userInput == 'q')
	{
	  stopSimulation = true; // Ends the game if q is pressed //
	}else
	{
	  cout<<"Invalid input, please choose again"<<endl; // simple input validation //
	}
      



    }
  


}
