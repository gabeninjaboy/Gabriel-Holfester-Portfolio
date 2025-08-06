/*
 * Name: Gabriel Holfester
 * Date Submitted: 2/20/2025
 * Lab Section: 003
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>
#include <cstdlib>
using namespace std;


template <class T>
vector<T> quickSort(vector<T> &lst, int low, int high);

template <class T>

vector<T> combineArray(vector<T> lst1, vector<T> lst2);

template <class T>


vector<T> mergeSort(vector<T> lst)
{

  // Creates two lists to break the array up into and makes a list index to track whats in your array //
  
  vector<T> list1;
  vector<T> list2;
  int listIndex = 0;

  // If your list only has one element return your list //
  
  if(lst.size() == 1)
    {
      return lst;
    }

  // Adds the halfs of the array into each new list //
  
  for(int i = listIndex; listIndex < lst.size() / 2; listIndex++)
    {
      list1.push_back(lst[listIndex]);
    }

  for(int i = listIndex; listIndex < lst.size(); listIndex++)
    {
      list2.push_back(lst[listIndex]);
    }

  // Calls merge sort on both lists //
  vector<T> newList1 = mergeSort(list1);
  vector<T> newList2 = mergeSort(list2);

  for(int i = 0; i < list1.size(); i++)
    {
      cout<<"List 1: "<<list1[i]<<endl;
    }
  for(int i = 0; i < list2.size(); i++)
    {
      cout<<"List 2: "<<list2[i]<<endl;
    }

  cout<<""<<endl;

  // Combines the two arrays //
  
  vector<T> vec = combineArray(newList1, newList2);
  return vec;  
}

template <class T>
vector<T> quickSort(vector<T> lst)
{
  int low = 0;
  int high = lst.size() - 1;
  return quickSort(lst, low, high);
}

// Combines arrays for merge sort //

template <class T>
vector<T> quickSort(vector<T> &lst, int low, int high)
{

  // Base case to end //

  if(low >= high)
    {
      return lst;
    }
  
  // Pivot index is what is requried //
  
  int pivotIndex = low + rand() % (high - low + 1);

  // Swap the pivot index with the back of the array //
  
  T pivotValue = lst[pivotIndex];
  T temp = lst[low];
  lst[low] = pivotValue;
  lst[pivotIndex] = temp;
  pivotIndex = low;


  // For the full size of the array //
  
  for(int i = low; i < lst.size(); i++)
    {
      // If the value is less than the pivot value increase the pivot index and swap the pivot index with the other value //
      
      if(lst[i] < pivotValue)
	{

	  pivotIndex++;
	  T current = lst[i];
	  T tempLoop = lst[pivotIndex];
	  lst[pivotIndex] = current;
	  lst[i] = tempLoop;
	}
    }


  // Swap again with the pivot index //
  
  temp = lst[pivotIndex];
  lst[pivotIndex] = pivotValue;
  lst[low] = temp;
  
  // Recurse by making the array smaller //
  
  quickSort(lst, low, pivotIndex - 1);
  quickSort(lst, pivotIndex + 1 , lst.size() - 1);

  return lst;
}


template <class T>
vector<T> combineArray(vector<T> lst1, vector<T> lst2)
{

  // Creates a new list for things to be pushed into, and a index for both sub arrays //
  
  vector<T> newList;
  int list1Index = 0;
  int list2Index = 0;

  // Go until you reach the end of one of the lists //
  
  while(list1Index < lst1.size() && list2Index < lst2.size())
    {

      // Checks to see if the value at each index is less than another, if so add it to the new list //

  
      
      if(lst1[list1Index] < lst2[list2Index])
	{
	  newList.push_back(lst1[list1Index]);
	  list1Index++;
	}else if(lst2[list2Index] < lst1[list1Index])
	{
	  newList.push_back(lst2[list2Index]);
	  list2Index++;
	}else if(lst2[list2Index] == lst2[list2Index])
	{
	  newList.push_back(lst2[list2Index]);
	  list2Index++;
	  newList.push_back(lst1[list1Index]);
          list1Index++;
	}
   
      
    }

  // When you reach the end of one of the lists, add the rest of the other list to the new list // 
  
  if(list1Index >= lst1.size())
    {
      for(int i = list2Index; i < lst2.size(); i++)
	{
	  newList.push_back(lst2[i]);
	}
    }else if(list2Index >= lst2.size())
    {
      for(int i = list1Index; i < lst1.size(); i++)
        {
          newList.push_back(lst1[i]);
        }
    }

  return newList;
}





