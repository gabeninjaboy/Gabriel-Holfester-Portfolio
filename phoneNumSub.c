#include "phoneNumSub.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void getAllSubs(char * inPhoneNum, FILE * output)
{
  // Creates a mapping in an array for each number, for example 2 contain "abc" // 
  char * phoneMapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  FILE * dictionary = fopen("/usr/share/dict/words","r");
  char line[256];

  if(dictionary != NULL)
    {
      while(fgets(line, sizeof(line), dictionary))
    {
      // remove the newline chracter to get rid of problems //
      int notLetter = 1;
      line[strcspn(line, "\n")] = '\0';
      int i = 0;
      int numLoop;

      // Tests to see if its a letter and not a special character and if not end the testing //
      
      while(notLetter && i < strlen(line))
        {
          if(isalpha(line[i]))
        {
          line[i] = tolower(line[i]);
          i++;
        }else
            {
              notLetter = 0;
	    }
        }

      

      for(numLoop = 0; numLoop < strlen(inPhoneNum); numLoop++)
        {

	  // create a new array to store each number being tested //
	  
          char newPhone[15];
	  strcpy(newPhone, &inPhoneNum[numLoop]);
	  if(wordMatchNumber(newPhone, line, phoneMapping) && notLetter == 1)
	    {
	      if(strlen(line) >= 3 && strlen(line) <= 10)
		{
		  fprintf(output, "%s\n", line); // Write to output console //
		  break;
		}
	     } 
         }
    }  
      fclose(dictionary);
    }
}

void removeDashes(char * inPhoneNum)
{
  int phoneLocation = 0;
  int newLocation = 0;

  if(inPhoneNum[0] == '+' && inPhoneNum[1] == '1')
    {
      phoneLocation = 2; 
    }

  // While it doesn't reach the end of the character number array //
  while(inPhoneNum[phoneLocation] != '\0')
    {
      // If the value at inPhoneNum[phoneLocation] is a dash set the newLocation to the phoneLocation //
      if(inPhoneNum[phoneLocation] != '-' &&
	 inPhoneNum[phoneLocation] != '(' &&
	 inPhoneNum[phoneLocation] != ')' &&
	 inPhoneNum[phoneLocation] != '.')
    {
      inPhoneNum[newLocation] = inPhoneNum[phoneLocation];
      newLocation++;
    }
      phoneLocation++;
    }
  inPhoneNum[newLocation] = '\0';
}

// Checks to see if the word matches the number //
int wordMatchNumber(char *phoneNum, char *word, char*phoneMapping[])
{
  // Runs until it hits the null terminator of the string, as thats the end of the word in the dictionary //
  int i; 
  for(i = 0; word[i] != '\0' && phoneNum[i] != '\0'; i++)
    {
      char digit = phoneNum[i];

      // Checks to see if it's a valid digit // 
      if(digit < '2' || digit > '9')
    {
      return 0;
    }

      /*
       * This segemnt checks to see if the letter from the current word in the dictionary is found 
       * in the string in the phone mapping array, it subtracts digit from '0' to get it to its actual 
       * number based on the ascii table   
       */
      if(strchr(phoneMapping[digit - '0'], word[i]) == NULL)
    {
      return 0;
    }
    }

  // Tests to see if the word reaches its end, and if not continue testing //
  
  if(word[i] == '\0')
    {
      return 1;
    }
  return 0; 
}
