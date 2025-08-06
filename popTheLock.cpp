/* 
 *Gabriel Holfester
 *9/13/2024
 *Project-1 Pop the Lock
 *CPSC 1070
 *TA helped with - Debugging (grade scope print errors)
 *The purpose of this program is to simulate the arcade game "Pop the Lock" where you enter a mode for the 
 *Difficulty of the lock, and guess for 4 regions North, South, East, and West. If you guess
 *Every region correctly the lock will pop and you will win!, if you don't a "*" will be your guess on the lock 
 *And a "X" will be the computers guess on the lock. 
 */



#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;




char runMenu(void);
int generateRandomNumber(int, int);
void makeGuess(int);
void displayLock(int);
void printLock(int[4], int[4], int, bool);
bool isCharInsideArray(char userInput, char sideArray[], int index, int size);
void runGame(void);



// makes the printing for each lock //

void makeMenuLock();
void makeHardMode(char[15]);
void makePoppedHardMode(char[15]);
void makeHarderMode(char[19]);
void makePoppedHarderMode(char[19]);
void makePoppedHardestMode(char[27]);
void makeHardestMode(char[27]);



int main()
{
  runGame();
  cout<<"\n";
}



// Runs the menu, and repeats the question for selecting a level til a right letter is picked //


char runMenu(void)
{
  // creates a null variable for the userInput until it gets assigned later // 
  char userInput = '\0';
  bool stopStatement = false; 
  // Prints out the whole menu and options // 
  cout<< "\nWelcome to Pop the Lock!\n\n"; 
  makeMenuLock();

  cout<< "\n\n\n\n";

  cout<< "------- Menu -------\n";
  cout<< "        Press A to play Pop the Lock in HARD mode.\n";
  cout<< "        Press B to play Pop the Lock in HARDER mode.\n";
  cout<< "        Press C to play Pop the Lock in HARDEST mode.\n\n";
  cout<< "        Press Q to exit Pop the Lock\n\n";
  

  // Asks the user for Input untik they finally pick a correct answer // 
  while(stopStatement != true)
    {


      cout<< "Enter mode:\n";
       
      cin>>userInput;

      if(userInput == 'A' || userInput == 'a')
	{
	  makeGuess(0);
	  return 'A';
	  

	  
	}else if(userInput == 'B' || userInput == 'b')
	{
	  makeGuess(1);
	  return 'B';
	  
	    
	}else if(userInput == 'C' || userInput == 'c')
	{

	  makeGuess(2);
	  return 'C';
	}else if(userInput == 'Q' || userInput == 'q')
	{
	  return 'Q'; 
	}else
	{
	  cout<<"Invaid input, Please try again";
	} 
      
      
    }  

  return 'Y';
}

// Makes the pickture of the menu lock, just a series of print statements //

void makeMenuLock()
{

  cout<<"     .------------.\n";
  cout<<"    / .----------. \\\n";
  cout<<"   / /            \\ \\\n";
  cout<<"   | |            | |\n";
  cout<<"  _| |____________| |_\n";
  cout<<".' |_|            |_| '.\n";
  cout<<"'.____________________.'\n";
  cout<<"|                      |\n";
  cout<<"|                      |\n";
  cout<<"|                      |\n";
  cout<<"|                      |\n";
  cout<<"|                      |\n";
  cout<<"|                      |\n";
  cout<<"'._____________________|\n";
  cout<<"'.____________________.'\n";
  

   
  
}


// Generates a random number from x and y, and returns that value //

int generateRandomNumber(int x, int y)
{
  int randomNumber = x + (rand() % (y - x + 1));
  return randomNumber;


}


/* this function will display the block for the selcected mode (Hard, Harder, Hardest), ask the user to guess the combination for the lock
 *and preform reasonble input validation, and call print lock to display the lock with the guesses
 */

void makeGuess(int mode)
{


  int guessArray[4];
  int tumbler[4];

  

  int indexOfNorthGuess = -1;
  int indexOfSouthGuess = -1;
  int indexOfEastGuess = -1;
  int indexOfWestGuess = -1;
  
  bool popped;
  bool validGuess = false;

  if(mode == 0)
    {


       // defines user input //

      

      char northUserInput = '\0';
      char southUserInput = '\0';
      char eastUserInput = '\0';
      char westUserInput = '\0';

      // Makes the arrays for what the numbers are in a hard lock // 
      char arr[] = {'1','2','3','4','5','6','7','8','9','0','A','B','C','D'};

      
      makeHardMode(arr);

      // makes the random values for our combination //


      int ranNumN = generateRandomNumber(0, 3);
      int ranNumE = generateRandomNumber(4, 6);
      int ranNumS = generateRandomNumber(7, 10);
      int ranNumW = generateRandomNumber(11, 13);

      // makes the combination to guess //
      
      char northLock = arr[ranNumN];
      char eastLock = arr[ranNumE];
      char southLock = arr[ranNumS];
      char westLock = arr[ranNumW];

      cout<<"Guess one value on each side of the lock, starting from the top moving clockwise to try and unlock the lock!\n";


      // tests to see if the guess is valid, and if it isn't it repeats until it is valid // 
      int numGuesses = 0;
      while(validGuess != true)

	
	{

	  
	  
	  cout<<"Enter north lock value: ";
	  cin>>northUserInput;
	  cout<<"Enter east lock value: ";
	  cin>>eastUserInput;
	  cout<<"Enter south lock value: ";
	 
	  cin>>southUserInput;
	  cout<<"Enter west lock value: ";
	  cin>>westUserInput;

	  
	  bool validNorthLock = isCharInsideArray(northUserInput, arr,0,3);
	  bool validEastLock = isCharInsideArray(eastUserInput, arr, 4,6);
          bool validSouthLock = isCharInsideArray(southUserInput, arr, 7,10);
          bool validWestLock = isCharInsideArray(westUserInput, arr, 11, 13);

 
	  if(validNorthLock == true && validSouthLock == true && validEastLock == true && validWestLock == true)
	    {
	      validGuess = true;
	      
	    }else
	    {
	      
	       cout<< "You have an incorrect value in one of your guesses. Try again.\n";
	 
	    } 
	  

	  numGuesses++;

          if(numGuesses > 10)
            {
              validGuess = true;
            }

	}
      

      // calculates the index at which your guess was //

	  for(int i = 0; i <= 3; i++)
	        {
		  if(arr[i] == northUserInput)

		    {
		      indexOfNorthGuess = i + 1;
		    }
		}

	  for(int i = 4; i <= 6; i++)
	      {
	       if(arr[i] == eastUserInput)
		 {
		  
		       indexOfEastGuess = i + 1;
		 }
	      }
		
	  
     
	  for(int i = 7; i <= 10; i++)
	    {
	      if(arr[i] == southUserInput)
		{
		  indexOfSouthGuess = i + 1;
		}

	    }

      
	   
	    for(int i = 11; i <= 13; i++)
	      {
		if(arr[i] == westUserInput)
		  {
		    indexOfWestGuess = i + 1;
		  }
	      }
	    


	    if(indexOfNorthGuess == ranNumN && indexOfSouthGuess == ranNumS && indexOfEastGuess == ranNumE && indexOfWestGuess == ranNumW)
	      {
		popped = true; 
	      }else
	      {
		popped = false; 
	      } 


	

	guessArray[0] = indexOfNorthGuess;
	guessArray[1] = indexOfEastGuess;
	guessArray[2] = indexOfSouthGuess;
	guessArray[3] = indexOfWestGuess;

	tumbler[0] = ranNumN;
	tumbler[1] = ranNumE;
	tumbler[2] = ranNumS;
	tumbler[3] = ranNumW;

	
	printLock(tumbler, guessArray, 0, popped);

	
    }else if(mode == 1)
    {

      // defines user input //



      char northUserInput = '\0';
      char southUserInput = '\0';
      char eastUserInput = '\0';
      char westUserInput = '\0';

      // Makes the arrays for what the numbers are in a harder lock //
      char arr[] =  {'1','2','3','4','5','6','7','8','9','0','A','B','C','D','\
E','F','G','H'};


      makeHarderMode(arr);

      // makes the random values for our combination //


      int ranNumN = generateRandomNumber(0, 3);
      int ranNumE = generateRandomNumber(4, 8);
      int ranNumS = generateRandomNumber(9, 13);
      int ranNumW = generateRandomNumber(14, 17);

      // makes the combination to guess //

      char northLock = arr[ranNumN];
      char eastLock = arr[ranNumE];
      char southLock = arr[ranNumS];
      char westLock = arr[ranNumW];

      cout<<"Guess one value on each side of the lock, starting from the top moving clockwise to try and unlock the lock!\n";


      // tests to see if the guess is valid, and if it isn't it repeats until it is valid //
      int numGuesses = 0;
      while(validGuess != true)
	{
	 


          cout<<"Enter north lock value: ";
          cin>>northUserInput;
          cout<<"Enter east lock value: ";
          cin>>eastUserInput;
          cout<<"Enter south lock value: ";

          cin>>southUserInput;
          cout<<"Enter west lock value: ";
          cin>>westUserInput;


          bool validNorthLock = isCharInsideArray(northUserInput, arr,0,3);
          bool validEastLock = isCharInsideArray(eastUserInput, arr, 4,8);
          bool validSouthLock = isCharInsideArray(southUserInput, arr, 9,12);
          bool validWestLock = isCharInsideArray(westUserInput, arr, 13, 17);

	  
          if(validNorthLock == true && validSouthLock == true && validEastLock == true && validWestLock == true)
            {
              validGuess = true;

            }else
            {
	      cout<< "You have an incorrect value in one of your guesses. Try again.\n";

            }

	  numGuesses++;

	  if(numGuesses > 10)
	    {
	      validGuess = true;
	    }


        }


      // calculates the index at which your guess was //

          for(int i = 0; i <= 3; i++)
                {
                  if(arr[i] == northUserInput)

                    {
                      indexOfNorthGuess = i + 1;
                    }
                }

          for(int i = 4; i <= 8; i++)
              {
               if(arr[i] == eastUserInput)
                 {

		   indexOfEastGuess = i + 1;
                 }
              }



          for(int i = 9; i <= 12; i++)
            {
              if(arr[i] == southUserInput)
                {
                  indexOfSouthGuess = i + 1;
                }

            }



            for(int i = 13; i <= 17; i++)
              {
                if(arr[i] == westUserInput)
                  {
                    indexOfWestGuess = i + 1;
		  }
              }



            if(indexOfNorthGuess == ranNumN && indexOfSouthGuess == ranNumS && indexOfEastGuess == ranNumE && indexOfWestGuess == ranNumW)
              {
                popped = true;
              }else
              {
                popped = false;
              }




        guessArray[0] = indexOfNorthGuess;
        guessArray[1] = indexOfEastGuess;
        guessArray[2] = indexOfSouthGuess;
        guessArray[3] = indexOfWestGuess;

        tumbler[0] = ranNumN;
        tumbler[1] = ranNumE;
        tumbler[2] = ranNumS;
        tumbler[3] = ranNumW;

	printLock(tumbler, guessArray, 1, popped);

	      
    }else if (mode == 2)
    {

      // defines user input //



      char northUserInput = '\0';
      char southUserInput = '\0';
      char eastUserInput = '\0';
      char westUserInput = '\0';

      // Makes the arrays for what the numbers are in a hardest lock //
      char arr[] = {'1','2','3','4','5','6','7','8','9','0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};


      makeHardestMode(arr);

      // makes the random values for our combination //


      int ranNumN = generateRandomNumber(0, 8);
      int ranNumE = generateRandomNumber(9, 13);
      int ranNumS = generateRandomNumber(14, 21);
      int ranNumW = generateRandomNumber(22, 25);

      // makes the combination to guess //

      char northLock = arr[ranNumN];
      char eastLock = arr[ranNumE];
      char southLock = arr[ranNumS];
      char westLock = arr[ranNumW];

      cout<<"Guess one value on each side of the lock, starting from the top moving clockwise to try and unlock the lock!\n";


      // tests to see if the guess is valid, and if it isn't it repeats until it is valid //

      int numGuesses = 0;
      
      while(validGuess != true)
	{



          cout<<"Enter north lock value: ";
          cin>>northUserInput;
          cout<<"Enter east lock value: ";
          cin>>eastUserInput;
          cout<<"Enter south lock value: ";

          cin>>southUserInput;
          cout<<"Enter west lock value: ";
          cin>>westUserInput;


          bool validNorthLock = isCharInsideArray(northUserInput, arr,0,7);
          bool validEastLock = isCharInsideArray(eastUserInput, arr, 8,12);
          bool validSouthLock = isCharInsideArray(southUserInput, arr, 13,20);
          bool validWestLock = isCharInsideArray(westUserInput, arr, 21, 25);
	  
          if(validNorthLock == true && validSouthLock == true && validEastLock == true && validWestLock == true)
            {
              validGuess = true;

            }else
            {
	      cout<< "You have an incorrect value in one of your guesses. Try again.\n";

            }


	  numGuesses++;

          if(numGuesses > 10)
            {
              validGuess = true;
            }

        }


      // calculates the index at which your guess was //

          for(int i = 0; i <= 7; i++)
                {
                  if(arr[i] == northUserInput)

                    {
                      indexOfNorthGuess = i + 1;
                    }
                }

          for(int i = 8; i <= 12; i++)
              {
               if(arr[i] == eastUserInput)
                 {

		   indexOfEastGuess = i + 1;
                 }
              }



          for(int i = 13; i <= 20; i++)
            {
              if(arr[i] == southUserInput)
                {
                  indexOfSouthGuess = i + 1;
                }

            }



            for(int i = 21; i <= 25; i++)
              {
                if(arr[i] == westUserInput)
                  {
                    indexOfWestGuess = i + 1;
		  }
              }



            if(indexOfNorthGuess == ranNumN && indexOfSouthGuess == ranNumS && indexOfEastGuess == ranNumE && indexOfWestGuess == ranNumW)
              {
                popped = true;
              }else
              {
                popped = false;
              }




        guessArray[0] = indexOfNorthGuess;
        guessArray[1] = indexOfEastGuess;
        guessArray[2] = indexOfSouthGuess;
        guessArray[3] = indexOfWestGuess;

        tumbler[0] = ranNumN;
        tumbler[1] = ranNumE;
        tumbler[2] = ranNumS;
        tumbler[3] = ranNumW;

	printLock(tumbler, guessArray, 2, popped);



    }




  
  

}


// checks to see if a character is inside of an array // 

bool isCharInsideArray(char userInput, char sideArray[], int index, int size)
{
  for(int i = index; i <= size; i++)
    {
      if(sideArray[i] == userInput)
	{
	  return true;
	}
      
    }

  return false;

} 

// Makes the hard mode lock with an array for the charcters on the lcok which will be filled with required values in makeGuess // 
void makeHardMode(char* arr)
{
  cout<<"     .------------.\n";
  cout<<"    / .----------. \\\n";
  cout<<"   / /            \\ \\\n";
  cout<<"   | |            | |\n";
  cout<<"  _| |____________| |_\n";
  cout<<".' |_|            |_| '.\n";
  cout<<"'.____________________.'\n";
  cout<<"|       |"<<arr[0]<<"|"<<arr[1]<<"|"<<arr[2]<<"|"<<arr[3]<<"       |\n";
  cout<<"|       --------       |\n";
  cout<<"|     "<<arr[13]<<"|        |"<<arr[4]<<"     |\n";
  cout<<"|     "<<arr[12]<<"|        |"<<arr[5]<<"     |\n";
  cout<<"|     "<<arr[11]<<"|        |"<<arr[6]<<"     |\n";
  cout<<"|       --------       |\n";
  cout<<"|       |"<<arr[10]<<"|"<<arr[9]<<"|"<<arr[8]<<"|"<<arr[7]<<"       |\n";
  cout<<"'._____________________|\n";
  cout<<"'.____________________.'\n";
  
}

// Makes the harder mode lock with an array for the charcters on the lcok which will be filled with required values in makeGuess //

void makeHarderMode(char* arr)
{
  cout<<"     .------------.\n";
  cout<<"    / .----------. \\\n";
  cout<<"   / /            \\ \\\n";
  cout<<"   | |            | |\n";
  cout<<"  _| |____________| |_\n";
  cout<<".' |_|            |_| '.\n";
  cout<<"'.____________________.'\n";
  cout<<"|       |"<<arr[0]<<"|"<<arr[1]<<"|"<<arr[2]<<"|"<<arr[3]<<\
"       |\n";
  cout<<"|     "<<arr[17]<<" -------- "<<arr[4]<<"     |\n";
  cout<<"|     "<<arr[16]<<"|        |"<<arr[5]<<"     |\n";
  cout<<"|     "<<arr[15]<<"|        |"<<arr[6]<<"     |\n";
  cout<<"|     "<<arr[14]<<"|        |"<<arr[7]<<"     |\n";
  cout<<"|     "<<arr[13]<<" -------- "<<arr[8]<<"     |\n";
  cout<<"|       |"<<arr[12]<<"|"<<arr[11]<<"|"<<arr[10]<<"|"<<arr[9]<<\
"       |\n";
  cout<<"'._____________________|\n";
  cout<<"'.____________________.'\n";

}

// Makes the hardest mode lock with an array for the charcters on the lcok which will be filled with required values in makeGuess //

void makeHardestMode(char* arr)
{
   cout<<"     .------------.\n";
  cout<<"    / .----------. \\\n";
  cout<<"   / /            \\ \\\n";
  cout<<"   | |            | |\n";
  cout<<"  _| |____________| |_\n";
  cout<<".' |_|            |_| '.\n";
  cout<<"'.____________________.'\n";
  cout<<"|       "<<arr[0]<<""<<arr[1]<<""<<arr[2]<<""<<arr[3]<<""<<arr[4]<<""<<arr[5]<<""<<arr[6]<<""<<arr[7]<<"       |\n";
  cout<<"|     "<<arr[25]<<" -------- "<<arr[8]<<"     |\n";
  cout<<"|     "<<arr[24]<<"|        |"<<arr[9]<<"     |\n";
  cout<<"|     "<<arr[23]<<"|        |"<<arr[10]<<"     |\n";
  cout<<"|     "<<arr[22]<<"|        |"<<arr[11]<<"     |\n";
  cout<<"|     "<<arr[21]<<" -------- "<<arr[12]<<"     |\n";
  cout<<"|       "<<arr[20]<<""<<arr[19]<<""<<arr[18]<<""<<arr[17]<<""<<arr[16]<<""<<arr[15]<<""<<arr[14]<<""<<arr[13]<<"       |\n";
  cout<<"'._____________________|\n";
  cout<<"'.____________________.'\n";

}

// Does the same thing as the other "Make lock" functions, but instead displays it as popped if the users guess is right //

void makePoppedHardestMode(char* arr)
{
   cout<<"                    .------------.\n";
  cout<<"                   / .----------. \\\n";
  cout<<"                  / /            \\ \\\n";
  cout<<"                  | |            | |\n";
  cout<<"                  | |            | |\n";
  cout<<"  ________________| |_           |_|\n";
  cout<<".'  ***           |_| '.\n";
  cout<<"'.____________________.'\n";
  cout<<"|       "<<arr[0]<<""<<arr[1]<<""<<arr[2]<<""<<arr[3]<<""<<arr[4]<<""<<arr[5]<<""<<arr[6]<<""<<arr[7]<<"       |\n";
  cout<<"|     "<<arr[25]<<" -------- "<<arr[8]<<"     |\n";
  cout<<"|     "<<arr[24]<<"|        |"<<arr[9]<<"     |\n";
  cout<<"|     "<<arr[23]<<"|        |"<<arr[10]<<"     |\n";
  cout<<"|     "<<arr[22]<<"|        |"<<arr[11]<<"     |\n";
  cout<<"|     "<<arr[21]<<" -------- "<<arr[12]<<"     |\n";
  cout<<"|       "<<arr[20]<<""<<arr[19]<<""<<arr[18]<<""<<arr[17]<<""<<arr[16]<<""<<arr[15]<<""<<arr[14]<<""<<arr[13]<<"       |\n";
  cout<<"'._____________________|\n";
  cout<<"'.____________________.'\n";



}

// Does the same thing as the other "Make lock" functions, but instead displays it as popped if the users guess is right //

void makePoppedHardMode(char* arr)
{
  cout<<"                    .------------.\n";
  cout<<"                   / .----------. \\\n";
  cout<<"                  / /            \\ \\\n";
  cout<<"                  | |            | |\n";
  cout<<"                  | |            | |\n";
  cout<<"  ________________| |_           |_|\n";
  cout<<".'  ***           |_| '.\n";
  cout<<"'.____________________.'\n";
  cout<<"|       |"<<arr[0]<<"|"<<arr[1]<<"|"<<arr[2]<<"|"<<arr[3]<<" \
      |\n";
  cout<<"|       --------       |\n";
  cout<<"|     "<<arr[13]<<"|        |"<<arr[4]<<"     |\n";
  cout<<"|     "<<arr[12]<<"|        |"<<arr[5]<<"     |\n";
  cout<<"|     "<<arr[11]<<"|        |"<<arr[6]<<"     |\n";
  cout<<"|       --------       |\n";
  cout<<"|       |"<<arr[10]<<"|"<<arr[9]<<"|"<<arr[8]<<"|"<<arr[7]<<"       |\n";
  cout<<"'._____________________|\n";
  cout<<"'.____________________.'\n";

}

// Does the same thing as the other "Make lock" functions, but instead displays it as popped if the users guess is right //

void makePoppedHarderMode(char* arr)
{
  cout<<"                    .------------.\n";
  cout<<"                   / .----------. \\\n";
  cout<<"                  / /            \\ \\\n";
  cout<<"                  | |            | |\n";
  cout<<"                  | |            | |\n";
  cout<<"  ________________| |_           |_|\n";
  cout<<".'  ***           |_| '.\n";
  cout<<"'.____________________.'\n";
  cout<<"|       |"<<arr[0]<<"|"<<arr[1]<<"|"<<arr[2]<<"|"<<arr[3]<<\
"       |\n";
  cout<<"|     "<<arr[17]<<" -------- "<<arr[4]<<"     |\n";
  cout<<"|     "<<arr[16]<<"|        |"<<arr[5]<<"     |\n";
  cout<<"|     "<<arr[15]<<"|        |"<<arr[6]<<"     |\n";
  cout<<"|     "<<arr[14]<<"|        |"<<arr[7]<<"     |\n";
  cout<<"|     "<<arr[13]<<" -------- "<<arr[8]<<"     |\n";
  cout<<"|       |"<<arr[12]<<"|"<<arr[11]<<"|"<<arr[10]<<"|"<<arr[9]<<\
"       |\n";
  cout<<"'._____________________|\n";
  cout<<"'.____________________.'\n";

}


/* This function displays the lock based off the user input inside of make guess where Tumbler will be an array of indexs of the computers guess
 * guess will be an array of the indexs at which the users guess is, mode is which level you are, and popped is whether or not the users guess
 * is correct
 */

void printLock(int tumbler[4], int guess[4], int mode, bool popped)
{

  // Makes the arrays for all types of locks to be compared and changed later in this function //
  
  char harderArr[] = {'1','2','3','4','5','6','7','8','9','0','A','B','C','D','E','F','G','H'};
  char hardArr[] = {'1','2','3','4','5','6','7','8','9','0','A','B','C','D'};
  char hardestArr[] = {'1','2','3','4','5','6','7','8','9','0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
  if(mode == 0)
    {
 
      /* changes the values of each location based on what was picked, and
       * checks to see if the locked is popped, and displays accordingly 
       */

  
      
      if(tumbler[0] == guess[0])
	  {
	    hardArr[tumbler[0] - 1] = '#';
	  }else
	  {
	    hardArr[tumbler[0] - 1] = 'X';
	    hardArr[guess[0] - 1] = '*';
	  }

      

	if(tumbler[1] == guess[1])
          {
            hardArr[tumbler[1] - 1] = '#';
          }else
          {
           hardArr[tumbler[1] - 1] = 'X';
            hardArr[guess[1] - 1] = '*';
          }

       
	
       
	if(tumbler[2] == guess[2])
          {
            hardArr[tumbler[2] - 1] = '#';
          }else
          {
            hardArr[tumbler[2] - 1] = 'X';
            hardArr[guess[2] - 1] = '*';
          }

	

	if(tumbler[3] == guess[3])
          {
            hardArr[tumbler[3] - 1] = '#';
          }else
          {
            hardArr[tumbler[3] - 1] = 'X';
            hardArr[guess[3] - 1] = '*';
          }

       

	

     
	  if(popped == true)
	    {
	    
	      makePoppedHardMode(hardArr);
	      cout<<"Congrats! You popped the lock!\n";
	      
	    }else
	    {

	      makeHardMode(hardArr);
	    }
	    
      
    }else if(mode == 1)
    {

      // *Used for debugging* //

      /*
      cout<<"Tumbler \n";
      
      for(int i = 0; i < 4; i++)
	{
	  cout<<tumbler[i];
	  cout<<"\n";
	}

      cout<<"\n guess \n";
      
      for(int i = 0; i < 4; i++)
        {
          cout<<guess[i];
	  cout<<"\n";
        }
      */


      /* changes the values of each location based on what was picked, and
       * checks to see if the locked is popped, and displays accordingly
       */
      
      if(tumbler[0] == guess[0])
          {
            harderArr[tumbler[0] - 1] = '#';
          }else
          {
            harderArr[tumbler[0] - 1] = 'X';
            harderArr[guess[0] - 1] = '*';
          }



        if(tumbler[1] == guess[1])
          {
            harderArr[tumbler[1] - 1] = '#';
          }else
          {
            harderArr[tumbler[1] - 1] = 'X';
            harderArr[guess[1] - 1] = '*';
          }


	if(tumbler[2] == guess[2])
          {
            harderArr[tumbler[2] - 1] = '#';
          }else
          {
            harderArr[tumbler[2] - 1] = 'X';
            harderArr[guess[2] - 1] = '*';
          }



        if(tumbler[3] == guess[3])
          {
            harderArr[tumbler[3] - 1] = '#';
          }else
          {
            harderArr[tumbler[3] - 1] = 'X';
            harderArr[guess[3] - 1] = '*';
          }


	if(popped == true)
            {

              makePoppedHarderMode(harderArr);
              cout<<"Congrats! You popped the lock!\n";

            }else
            {

              makeHarderMode(harderArr);
            }


    }else if(mode == 2)
    {



      /* changes the values of each location based on what was picked, and
       * checks to see if the locked is popped, and displays accordingly
       */

      if(tumbler[0] == guess[0])
          {
            hardestArr[tumbler[0] - 1] = '#';
          }else
          {
            hardestArr[tumbler[0] - 1] = 'X';
            hardestArr[guess[0] - 1] = '*';
          }



        if(tumbler[1] == guess[1])
          {
            hardestArr[tumbler[1] - 1] = '#';
          }else
          {
            hardestArr[tumbler[1] - 1] = 'X';
            hardestArr[guess[1] - 1] = '*';
          }


	if(tumbler[2] == guess[2])
          {
            hardestArr[tumbler[2] - 1] = '#';
          }else
          {
            hardestArr[tumbler[2] - 1] = 'X';
            hardestArr[guess[2] - 1] = '*';
          }



        if(tumbler[3] == guess[3])
          {
            hardestArr[tumbler[3] - 1] = '#';
          }else
          {
            hardestArr[tumbler[3] - 1] = 'X';
            hardestArr[guess[3] - 1] = '*';
          }


	if(popped == true)
            {

              makePoppedHardestMode(hardestArr);
              cout<<"Congrats! You popped the lock!\n";

            }else
            {

              makeHardestMode(hardestArr);
            }


    }

}


// Runs the whole "Pop the Lock" game calls every previous function to make the game work //

void runGame(void)
{
  runMenu();
  
}
