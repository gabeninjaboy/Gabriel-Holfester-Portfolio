#include "Simulation.h"
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

// declares the constructor //

Simulation::Simulation()
{



}

// Moves Janeway up or down depeneding on the random chance there is based on the table //

void Simulation::moveJaneway(unsigned int *ptrJaneway)
{

  // creates a random number between 1 and 100 //
  
  int randomNum = rand() % 100 + 1;

  // Moves janeway based on random percentage //
  
  if(randomNum <= 50)
    {
      *ptrJaneway += 3;

    }else if(randomNum <= 65)
    {
      *ptrJaneway -= 6;
      if(*ptrJaneway > 100)
	{
	  *ptrJaneway = 0;
	}

    }else
    {
      *ptrJaneway += 1;

    }

  if(*ptrJaneway < 0)
    {
      *ptrJaneway = 0;
    }
}

// exactly the same as move JaneWay with different percentages and movements based off the table //

void Simulation::moveSisko(unsigned int *ptrSisko)
{
  int randomNum = rand() % 100 + 1;

  if(randomNum <= 35)
    {
      *ptrSisko = *ptrSisko;
      
    }else if(randomNum <= 65)
    {
      *ptrSisko += 9;

    }else if(randomNum <= 70)
    {
      *ptrSisko -= 12;
      if(*ptrSisko > 100)
	{
	  *ptrSisko = 0;
	}

    }else
    {
      *ptrSisko += 1;
      
    }

}

void Simulation::runOneGame()
{

  // creates a boolean to end the game if someone wins // 
  
  bool endGame = false; 
  
  // declares unsigned ints for parameter pointers to point to //
  
  unsigned int janewayPosition = 0;
  unsigned int siskoPosition = 0;
  
  // declares the pointers to be used in the move functions // 
  
  unsigned int* ptrJaneway = &janewayPosition;
  unsigned int* ptrSisko = &siskoPosition;

  // constructs an array of size 80 for that track // 
  
  int arrSize = 80;
  char trackArr[arrSize];

  // uses a for loop to fill the array with the 80 dashes before anybody moves //

 

  
  for(int i = 0; i < arrSize; i++)
    {
      trackArr[i] = '-';

    }

  // prints out the necessary intro for running the simulator //
  
  cout<<"                        Running O.W.E.N. Simulation...\n";
  cout<<"                        Janeway: J              Sisko: S\n";
  cout<<"         <<< Online Work Evaluation and Notification System Simulation >>>\n";


  while(endGame != true)
    {

      // prints out the track // 
      
      cout<<"[ ";
      for(int i = 0; i < arrSize; i++)
	{
	  cout<<trackArr[i];
	}
      cout<<" ]\n";


      // resets the positions of J and S back to "-" before they move again //
      
      trackArr[*ptrSisko] = '-';
      trackArr[*ptrJaneway] = '-';


      // moves the positions of Sisko and Janeway //
      
      moveSisko(ptrSisko);
      moveJaneway(ptrJaneway);
      
      // checks to see if someone one and checks if theres a tie // 
      
      if(*ptrSisko > 80 && *ptrJaneway >= 80)
	{
	  cout<<"WOW!!! A TIE!!!";
	  endGame = true;

	}else if(*ptrJaneway >= 80)
	{
	  cout<<"JANEWAY WINS!!!!";
	  endGame = true;

	}else if(*ptrSisko >= 80)
	{
	  cout<<"SISKO WINS!!!";
	  endGame = true;
	}
      
      // tests to see if Sisko and Janeway are in the same spot and if they are it prints a "!" and if not it just prints S and J // 
      
      if(*ptrSisko == *ptrJaneway)
	{
	  trackArr[*ptrSisko] = '!';
	}else
	{
	  trackArr[*ptrSisko] = 'S';
	  trackArr[*ptrJaneway] = 'J';
	}

      // delays everything by 1 second //

      usleep(1000000);


    }


}
