/*
 * Name: Gabriel Holfester 
 * Date Submitted: 4/10/25
 * Lab Section: 003
 * Assignment Name: Lab 9: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

//bool isSafe(vector<vector<int>>, int, int, int);
int placeQueens(vector<vector<int>> &board, int size, int row);

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
  vector<vector<int>> board(n, vector<int> (n, 0));

  return placeQueens(board, n, 0);
  
  
}

int placeQueens(vector<vector<int>> &board, int size, int row)
{

  if(row >= size)
  {
      if(size % 2 == 1 && board[0][size / 2] == 1)
	    {
	      return 1;
	    }
      else
	    {
	      return 2;
	    }
  }
  int rowSolutions = 0;
  int totalSolutions = 0;
  // If it's the first row, only need to check half cols

  
  int m;
  if (row == 0) m = (size+1)/2;
  else m = size;


  
  for(int col = 0; col < m; col++)
    {

      bool checkSafe = true;
      // only check rows above the current row // 
      for(int r = row - 1; r >= 0; r--)
	    {
        
	      if(board[r][col] == 1)
	      {
	        checkSafe = false;
	      }

	      // Check diagonals and other diagonals // 
	      
	      int Cl=col-(row-r);
	      int Cr=col+(row-r);
	      if(Cl>=0)
		{
		  if(board[r][Cl]) checkSafe = false;
		}
	      if(Cr < size)
		{
		  if(board[r][Cr]) checkSafe = false;
		}
	    }


      // If your spot is safe, place the queen and go onto the next row adding the correct solution, and reseting the board //
      
      if(checkSafe == true)
	{
	  board[row][col] = 1;
	  rowSolutions = placeQueens(board, size, row + 1);
	  if(rowSolutions != 0)
	    {
	      totalSolutions += rowSolutions;
	    }
	  board[row][col] = 0;
	  
	}
      
    }
  
  return totalSolutions;        
}

/*
int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}
    */

