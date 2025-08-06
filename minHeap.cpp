#include "minHeap.h"
#include <iostream>

using namespace std;


minHeap::minHeap() {} //Default constructor, heap is initiallay an empty vector
vector<int> minHeap::getHeap() {return heap;} 

minHeap::minHeap(vector<int> data)
{
  heap = data;
  
  for(int i = data.size() - 1; i >= 0; i--)
    {
      siftDown(i);
    }  
}


void minHeap::insert(int value)
{
  heap.push_back(value);
  siftUp(heap.size() - 1);
}


int minHeap::removeMin()
{
  int temp = heap[0];
  heap[0] = heap[heap.size() - 1];
  heap[heap.size() - 1] = temp;

  heap.pop_back();
  
  siftDown(0);

  return temp;
}

void minHeap::siftUp(int pos)
{
  if(pos <= 0 || pos > heap.size() - 1)
    {
      return;
    }
  
  if((pos - 1) / 2 >= 0)
    {
      if(heap[(pos - 1) / 2] > heap[pos])
	{
	  int temp = heap[(pos - 1) / 2];
	  heap[(pos - 1) / 2] = heap[pos];
	  heap[pos] = temp;
	  
	  siftUp((pos - 1) / 2);
	}
    }
}


void minHeap::siftDown(int pos)
{
  if(pos >= heap.size() || pos < 0)
    {
      return; 
    }
  
  if((2 * pos) + 1 <= heap.size() - 1 && (2 * pos) + 2 <= heap.size() - 1)
    {
      if(heap[(2 * pos) + 1] < heap[pos] && heap[(2 * pos) + 1] < heap[(2 * pos) + 2])
	{
	  int temp = heap[(2 * pos) + 1];
	  heap[(2 * pos) + 1] = heap[pos];
	  heap[pos] = temp;
	  
	  siftDown((2 * pos) + 1);
	}else if(heap[(2 * pos) + 2] < heap[pos] && heap[(2 * pos) + 2] < heap[(2 * pos) + 1])
	{
	  int temp = heap[(2 * pos) + 2];
	  heap[(2 * pos) + 2] = heap[pos];
	  heap[pos] = temp;
	  
	  siftDown((2 * pos) + 2);
	}	
    }else if((2 * pos) + 1 <= heap.size() - 1)
    {
      if(heap[(2 * pos) + 1] < heap[pos])
	{
	  int temp = heap[pos];
	  heap[pos] = heap[(2 * pos) + 1];
	  heap[(2 * pos) + 1] = temp;

	  siftDown((2 * pos) + 1);
	}

      
    }
}
