#include "phoneNumSub.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{


   
  FILE * inputFile;
  FILE * outputFile;

  if(argc < 3)
    {

      exit(1);
    }
  


  inputFile = fopen(argv[1], "r");
  outputFile = fopen(argv[2], "w");

 

  if(inputFile == NULL)
    {
      printf("Error while creating file!");
      exit(1);

    }

  if(outputFile == NULL)
    {
      printf("Error while creating file!");
      exit(1);
    }


  char numbers[20];

  while(fgets(numbers, 20, inputFile))
    {

      
      numbers[strcspn(numbers, "\n")] = '\0';
      
      removeDashes(numbers);

      
      
      fprintf(outputFile, "%s\n", numbers);

      getAllSubs(numbers, outputFile);
    }

    
  
    fclose(inputFile);
  

  }
