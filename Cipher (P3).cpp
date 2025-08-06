/*
 * Gabriel Holfester
 * CPSC 1070:001
 * Sprout Squad
 * 11/13/2024
 */

#include "Cipher.h"
#include "Queue.h"
#include <cctype>
using namespace std;

// Declares the default constructor, making the char array "cpsc" and setting the size to the length of that array // 

Cipher::Cipher()
{
  char arr[4] = {'c', 'p', 's', 'c'};
  key = &arr[0];
  size = 4;
}

/* 
 * Declares the Cipher classs constructor, tests to see if the put in parameters have any numbers or 
 * upper case letters, and if so removes them so the key can be used to shift 
 * and encode and decode each strig the user puts in 
 */

Cipher::Cipher(int sizeOfArr, char * pointKey)
{
  size = sizeOfArr;
  key = "";
  for(int i = 0; i <sizeOfArr; i++)
    {
      if(isalpha(pointKey[i]))
	{
	  key+=tolower(pointKey[i]);
	}
    }  
}

// Sets the Cipher, exactly the same concept as the Cipher class constructor // 

void Cipher::setCipher(int sizeOfArr, char * pointKey)
{
  size = sizeOfArr;
  key = "";

  for(int i = 0; i < sizeOfArr; i++)
    {
      if(isalpha(pointKey[i]))
	{
	  key+=tolower(pointKey[i]);
	}

    }

  
}

// Returns the memory address of the key // 

char * Cipher::getCipher()
{
  return &key[0];
}


/*
 * Encodes the message by first building the queue, then using the key it shifts the letters
 * of each part in the string by the key amount, the work for this is done in the letter shift function 
 */

string Cipher::encodeMessage(string in)
{
  string outString = "";

  queue.clear();
  
  for(int i = 0; i < size; i++)
    {
      queue.enqueue(key[i]);
    }
  for(long unsigned int i = 0; i < in.length(); i++)
    {
      int l1 = in[i];

   
      char deValue = ' ';
      queue.dequeue(deValue);
      queue.enqueue(deValue);
      outString+= letterShift(l1, deValue, false);
       
    }
  return outString;
}

// Does everything with the same concept as the encodeMessage function but instead does the opposite by decoding the message // 

string Cipher::decodeMessage(string in)
{
  
  string outString = "";

  queue.clear();

  for(int i = 0; i < size; i++)
    {
      queue.enqueue(key[i]);
    }
  for(long unsigned int i = 0; i < in.length(); i++)
    {
          int l1 = in.at(i);

          char deValue = ' ';
          queue.dequeue(deValue);
          queue.enqueue(deValue);
          outString+= letterShift(l1, deValue, true);
        
    }
  return outString;

  
}





// Shifts a letter "l1" by "l2" and checks to see whether your adding or subtracting //

char Cipher::letterShift(char l1, char l2, bool reverse)
{
  // The character that's being shifted to returned // 
  char returnChar;
  
  if(reverse)
    {
      // gets the "Shifted value" for l1 and l2, (for example a would be 1) //
      char firstIn = l1 - 96;
      char secondIn = l2 - 96;

      // gets the distance between the first and second shifted values // 
      
      int shifted = firstIn - secondIn;
      if(shifted < 1)
	{
	  returnChar = 122 + shifted;
	}else 
	{
	  
	  returnChar = l1 - secondIn;  
	}

      return returnChar;

      // Does the same thing before by encodes in using the concepts above //
      
    }else if (!reverse)
    {
      char firstIn = l1 - 96;
      char secondIn = l2 - 96;
      char shifted = firstIn + secondIn;

      if(shifted > 26)
	{
	  returnChar = 97 + shifted - 27; 

	}else
	{
	  returnChar = l1 + secondIn;
	    
	}
	
      
    }

  return returnChar;

  
}
