/*
 * Gabriel Holfester
 * CPSC 1070:001
 * Sprout Squad
 * 11/13/2024
 */

#ifndef QUEUE_H
#define QUEUE_H


class Queue
{

 private:

  // declares a count for testing if the queue is full or not // 
  
  int count;

  // creates a struct for a Queue node to be made by linked lists //
  
  struct QueueNode
  {
    char key;
    QueueNode* next;
    

    QueueNode(char key1, QueueNode* next1 = nullptr)
    {
      key = key1;
      next = next1; 

    }

  };

  // declares the front and end of the queue "values" //

  QueueNode* front;
  QueueNode* rear; 

 public:

  // declares prototypes for constructors and other necessary functions inside the .cpp file // 
  Queue();
  ~Queue();

  void enqueue(char);
  void dequeue(char &);
  bool isEmpty() const;
  bool isFull() const;
  void clear();
  

};



#endif
