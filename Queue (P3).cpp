/*
 * Gabriel Holfester
 * CPSC 1070:001
 * Sprout Squad
 * 11/13/2024
 */


#include <iostream>
#include "Queue.h"
#include <cstdlib>
using namespace std;

// declares both the front and rear to be "nullptr" as there is nothing inside it yet, also declares the count to zero to be incremented // 

Queue::Queue()
{
  front = nullptr;
  rear = nullptr;
  count = 0;
}

// declares the destructor for the queue to stop memory leaks and hanging pointers // 

Queue::~Queue()
{
  QueueNode * garbage = front;
  while(garbage != nullptr)
    {
      front = front->next;
      garbage->next = nullptr;
      delete garbage;
      garbage = front;
    }
  count = 0;
}

// The function that adds on the queue, follows implementation based on the text book // 

void Queue::enqueue(char value)
{
  if(isEmpty())
    {
      front = new QueueNode(value);
      rear = front;
    }else
    {
      rear->next = new QueueNode(value);
      rear = rear->next;
    }

  // increments the count by one to later be tested if the queue is full //
  count++;
}

// removes an item from the queue as based on by the textbook //

void Queue::dequeue(char &letter)
{
  QueueNode *temp = nullptr;

  // If the queue is empty, makes sure not to dequeue to stop errors from occuring //
  
  if(isEmpty())
    {
      cout<<"The queue is empty.\n";
      exit(1);
    }else
    {
      letter = front->key;
      temp = front;
      front = front->next;
      delete temp;

      // decrements the count to later be tested if the queue is full // 
      
      count--;
    }
}

// Tests to see if theres anything inside the queue, if not it returns true // 

bool Queue::isEmpty() const
{
  if(front == nullptr)
    {
      return true;
    }else
    {
      return false; 
    }
}

// Tests to see if the queue is full based off project requirements // 

bool Queue::isFull() const
{
  return count >= 100;
}

// Clears the queue // 

void Queue::clear()
{
  char key;

  while(!isEmpty())
    {
      dequeue(key);

    }
  count = 0;

  
}

