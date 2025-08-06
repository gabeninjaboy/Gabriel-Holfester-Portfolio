/*
 * Name: Gabriel Holfester
 * Date Submitted: 2/13/2025
 * Lab Section: 003
 * Assignment Name: Lab 3: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below






//Simple main function to test Grouping
//Be sure to comment out main() before submitting

/*
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}
*/

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}

Grouping::Grouping(string fileName)
{

  // Creates a file called in file and makes a int called row to track the rows //
  ifstream infile(fileName);
  int row = 0;

  // If the file is open do the neccessary requirements //
  
  if(infile.is_open())
    {
      string line;

      // Until you get to the end of the file, fill up the grid //
      
      while(getline(infile,line))
	{
	  // Until you get to the end of the line in the file, test to see if its a "." or "X" //
	  
	  for(int i = 0; i < line.length(); i++)
	    {
	      // If it's a "." set the grid at the position to 0, else set it to 1 //
	      
	      if(line[i] == '.')
		{
		  grid[row][i] = 0;
		}else if(line[i] == 'X')
		{
		  grid[row][i] = 1;
		}
	      
	    }
	  row++;
	}
      infile.close();
    }else
    {
      cout<<"Unable to open file"<<endl;
    }

  // Make groups for each part of the grid //
  
  for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < 10; j++)
	{

	  // If there's an "X' and the position in the grid, call find groups and make a group and add it to a vector //
     	  if(grid[i][j] == 1)
	    {
	      vector<GridSquare> group;
	      findGroup(i, j, group);
	      groups.push_back(group);
	    }
	  
	}
    }
}


void Grouping::findGroup(int r, int c, vector<GridSquare>& group)
{

  // If it's out of bounds or zero, return //

  if((r > 9 || r < 0 || c > 9 || c < 0) || grid[r][c] == 0)
    {
      return;
    }
  
  GridSquare currentSquare(r, c);
  group.push_back(currentSquare);
  
  // Set the grid to zero so it's not counted again //
  
  grid[r][c] = 0;

  // Find a group for each area around the current grid //
  
      findGroup(r + 1, c, group);
      findGroup(r - 1, c, group);      
      findGroup(r, c + 1, group);
      findGroup(r, c - 1, group);
    
}
