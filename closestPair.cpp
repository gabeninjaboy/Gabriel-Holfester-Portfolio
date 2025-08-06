/*
 * Name: Gabriel Holfester 
 * Date Submitted: 3/6/2025
 * Lab Section: 003 
 * Assignment Name: Lab 6: Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/

double distance(point &current, point &compare);
double closestPair(string filename);

/*
int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}
*/
double closestPair(string filename)
{
  // Number of points //
  int n = 0;
  
  // Opens in file //
  
  ifstream infile(filename);

  // Reads in the value of n, the number of points //
  infile>>n;

  /* I used the sqaure root because by sqaure rooting something, you get a sqaure, because for example square root of 16 gets you 4 and if 4 is your 
   * b it is a 4x4 grid which is a sqaure, which can hold all your cell values, just like for 250,000 the b is 500 so it's a 500 x 500 grid 
   */
  
  int b = sqrt(n);
  double interval = 1.0/b;

  // Make a vector called plane that the first and second vectors have a size of "b" //
  vector<vector<vector<point>>> plane(b, vector<vector<point>>(b));
  double x,y;

  // Go and read in points from the file into x and y, then place the points in the reqiured part in the plane //

  while(infile>>x>>y)
    {
      int xpos = x/interval;
      int ypos = y/interval;
      plane[xpos][ypos].push_back({x,y});
    }

  double smallest_distance = 10;

  // First two for loops go through the row and colums of the plane //
  
  for(int xIndex = 0; xIndex < b; xIndex++)
    {
      for(int yIndex = 0; yIndex < b; yIndex++)
	{

	  // Is a forloop for the starting index //
	  
	  for(int start = 0; start < plane[xIndex][yIndex].size(); start++)
	    {

	      point currentPoint = plane[xIndex][yIndex][start];

	      // Compares the inside of the cell first, and finds the distance between each points //
	      
	      for(int compareIndex = 0; compareIndex < plane[xIndex][yIndex].size(); compareIndex++)
		{
		  point comparePoint = plane[xIndex][yIndex][compareIndex];

		  // If the distance is less than the smallest distance, and it isn't the same point, set the smallest distance to that distance //
		  
		  if(distance(currentPoint, comparePoint) < smallest_distance && distance(currentPoint, comparePoint) != 0)
		    {
		      smallest_distance = distance(currentPoint, comparePoint);
		    }
		}

	      // Tests the box to the right of the cell you're in //
	      
	      if(xIndex + 1 < b)
		{
		  for(int compareIndex = 0; compareIndex < plane[xIndex + 1][yIndex].size(); compareIndex++)
		    {
		      point comparePoint = plane[xIndex + 1][yIndex][compareIndex];
		      
		      if(distance(currentPoint, comparePoint) < smallest_distance && distance(currentPoint, comparePoint) != 0)
			{
			  smallest_distance = distance(currentPoint, comparePoint);
			}
		    } 
		}

	      // Tests the cell below of the cell you're in // 

	      if(yIndex + 1 < b)
		{
		  for(int compareIndex = 0; compareIndex < plane[xIndex][yIndex + 1].size(); compareIndex++)
                    {
                      point comparePoint = plane[xIndex][yIndex + 1][compareIndex];
		      
                      if(distance(currentPoint, comparePoint) < smallest_distance && distance(currentPoint, comparePoint) != 0)
                        {
                          smallest_distance = distance(currentPoint, comparePoint);
                        }
                    } 
		}

	      // Tests the cell to the bottom right of the cell you're in //
	      
	      if(yIndex + 1 < b && xIndex + 1 < b)
		{
		  for(int compareIndex = 0; compareIndex < plane[xIndex + 1][yIndex + 1].size(); compareIndex++)
                    {
                      point comparePoint = plane[xIndex + 1][yIndex + 1][compareIndex];

                      if(distance(currentPoint, comparePoint) < smallest_distance && distance(currentPoint, comparePoint) != 0)
                        {
                          smallest_distance = distance(currentPoint, comparePoint);
                        }
                    }
		}

	      // Tests the cell to the bottom left of the cell you're in // 
	      
	      if(yIndex + 1 < b && xIndex - 1 >= 0)
                {
                  for(int compareIndex = 0; compareIndex < plane[xIndex - 1][yIndex + 1].size(); compareIndex++)
                    {
                      point comparePoint = plane[xIndex - 1][yIndex + 1][compareIndex];

                      if(distance(currentPoint, comparePoint) < smallest_distance && distance(currentPoint, comparePoint) != 0)
                        {
                          smallest_distance = distance(currentPoint, comparePoint);
                        }
                    }
                }
	      
	    }	  
	}
    }

  return smallest_distance;
}


// Helper function to find the distance between two points //

double distance(point &current, point &compare)
{
  double distance = sqrt(pow(compare.x - current.x, 2) + pow(compare.y - current.y, 2));
  return distance;
  
}
