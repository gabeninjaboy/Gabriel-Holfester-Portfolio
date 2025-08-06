/*
 * Gabriel Holfester
 * CPSC 1070:001
 * Sprout Squad
 * 11/13/2024
 */

#ifndef CIPHER_H
#define CIPHER_H
#include "Queue.h"
#include <string>
using namespace std;

class Cipher
{

 private:
  
  // Declares necessary private varibles to be accessed through the Cipher class // 
  string key;
  Queue queue;
  int size;


 public:

  // declares necessary function prototypes to be implemented inside the Cipher class //
  
  Cipher();
  Cipher(int, char *);
  void setCipher(int, char *);
  char * getCipher();
  string encodeMessage(string in);
  string decodeMessage(string in);
  static char letterShift(char l1, char l2, bool reverse);
};



#endif
