/*
 * Name: Gabriel Holfester 
 * Date Submitted: 2/20/2025
 * Lab Section: 003
 * Assignment Name: Lab 4: Searching and Sorting
  */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target)
{
  for(int i = 0; i < data.size(); i++)
    {
      if(data[i] == target)
	{
	  return i;
	}
    }

  return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target)
{
  int lowIndex = 0;
  int highIndex = data.size();
  int midIndex;

  while(highIndex >= lowIndex)
    {
      midIndex = (highIndex + lowIndex) / 2;
      
      if(data[midIndex] < target)
	{
	  lowIndex = midIndex + 1;
	}else if(data[midIndex] > target)
	{
	  highIndex = midIndex - 1;
	}else if(data[midIndex] == target)
	{
	  return midIndex;
	}
    }
  return -1;
}
