/*
 * Gabriel Holfester
 * CPSC 1070:001
 * Sprout Squad
 * 11/13/2024
 */


#include "Cipher.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{

  // declares a string object "key" to be used as user input // 
  
  string key;
  bool continueDriver = false; 
  cout<<"Type in the word to use as the key: ";
  cin>>key;
  
  
  
  Cipher cipher(key.size(), &key[0]);

  // the while loop here is used to continue asking to decode or encode with a key until the user wants to quit // 

  while(continueDriver != true)
    {
      char userInput;
      
      cout<<"\nKey: "<<key<<endl;
      cout<<"[e] encode with that key"<<endl;
      cout<<"[d] decode with that key"<<endl;
      cout<<"[q] quit"<<endl;
      cin>>userInput;

      if(userInput == 'e' || userInput == 'E')
	{
	  
	  // encodes if the user wants to encode their input, and also prints the result //
	  
	  string encodeUserInput;
	  cout<<"Enter what to encode: ";
	  cin>>encodeUserInput;
	  cout<<"result: "<<cipher.encodeMessage(encodeUserInput)<<endl;
	}else if(userInput == 'd' || userInput == 'D')
	{

	  // decodes if the user wants to decode their input, and also prints the result // 
	  
	  string decodeUserInput;
	  cout<<"Enter what to decode: ";
	  cin>>decodeUserInput;
	  cout<<"result: "<<cipher.decodeMessage(decodeUserInput)<<endl;
	}else if(userInput == 'q' || userInput == 'Q')
	{

	  // quits if the user wants to quit //
	  
	  continueDriver = true;
	}
    }
}

