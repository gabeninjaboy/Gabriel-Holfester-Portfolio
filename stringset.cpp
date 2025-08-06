/*
 * Name: Gabriel Holfester
 * Date Submitted: 2/27/2025
 * Lab Section: 003
 * Assignment Name: Lab 5: Spell Checker Using a Hash Table
 */

#include "stringset.h"
#include <functional>
#include <iostream>
using namespace std;


Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
  // If the number of elements equals the size, double the size of the list and make a new table to rehash the values to //
  
  if(num_elems == size)
    {
      size = size * 2;
      vector<list<string>> newTable(size);

      // Goes through the whole table vector //
      
      for(int i = 0; i < table.size(); i++)
	{

	  // Then goes through each individual linked list //
	  
	  for(auto it = table[i].begin(); it != table[i].end(); ++it)
	    {
	      // Gets the new hash value for the newly doubled list //
	      
	      int newIndex = stringHash(*it) % size;

	      // Sets the value of the point in that linked list to the front of the new index //
	      
	      newTable[newIndex].push_front(*it);
	    }
	}

      table = newTable;
    }

  // Tests to see if the word is in the array // 
  
  if(find(word))
    {
      return;
    }

  // Gets the index to where you want to insert, then inserts 
  
  int index = stringHash(word) % size;

  table[index].push_front(word);
  num_elems++;
  
}

bool Stringset::find(string word) const
{
  // Get the index where the word will be //
  
  int index = stringHash(word) % size;

  // Go through the linked list and if the value is equal to the word, return true //
  
  for(auto it = table[index].begin(); it != table[index].end(); ++it)
    {
      if(*it == word)
	{
	  return true;
	}
    }
  return false;  
}

void Stringset::remove(string word)
{
  // Find the index of the word you want to remove //
  
  int index = stringHash(word) % size;

  // If you don't find the word simply return as it doesn't exist //
  
  if(!find(word))
    {
      return;
    }

  // Then remove the word at the index and decrement the number of elements // 
  
  table[index].remove(word);

  num_elems--;
}
