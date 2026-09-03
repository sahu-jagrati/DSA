// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

// Given the current state of the board, update the board to reflect its next state.

// Note that you do not need to return anything.

// Example 1:

// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
// Example 2:

// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 25
// board[i][j] is 0 or 1.

// Follow up:

// Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

#include <bits/stdc++.h>
using namespace std;

// this is fully done by me
bool isValid(int nrow, int ncol, int m, int n)
{
  return nrow >= 0 && nrow < m && ncol >= 0 && ncol < n;
}
void gameOfLife(vector<vector<int>> &board)
{
  int m = board.size();
  int n = board[0].size();
  // we use temp so that we can change value in board and for next cell we don't use update value so we use temp
  vector<vector<int>> temp = board;
  // we travel each cell individually
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int cnt0 = 0, cnt1 = 0; // for neighbour counting
      int value = temp[i][j];
      // move in 8 directions
      for (int k = -1; k <= 1; k++)
      {
        for (int l = -1; l <= 1; l++)
        {
          if (k == 0 && l == 0)
            continue; // for skip the cell where we stand itself
          int nrow = i + k;
          int ncol = j + l;
          if (isValid(nrow, ncol, m, n))
          {
            if (temp[nrow][ncol] == 0)
              cnt0++;
            else
              cnt1++;
          }
        }
      }
      // after checking each neighbour
      // we change cell in board grid so we use temp
      if (value == 0 && cnt1 == 3)
        board[i][j] = 1;
      else if (value == 1 && cnt1 > 3)
        board[i][j] = 0;
      else if (value == 1 && cnt1 < 2)
        board[i][j] = 0;
      else if ((value == 1 && cnt1 == 2) || (value == 1 && cnt1 == 3))
        board[i][j] = 1;
    }
  }
}

// improve my above code -
// we don't need cnt0 at all, only live neighbours matter
void gameofLife(vector<vector<int>> &board)
{
  int m = board.size();
  int n = board[0].size();

  vector<vector<int>> temp = board;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int cnt1 = 0;
      for (int k = -1; k <= 1; k++)
      {
        for (int l = -1; l <= 1; l++)
        {
          if (k == 0 && l == 0)
            continue;
          int nrow = i + k;
          int ncol = j + l;
          if (isValid(nrow, ncol, m, n) && temp[nrow][ncol] == 1)
          {
            cnt1++;
          }
        }
      }
      if (temp[i][j] == 0 && cnt1 == 3)
        board[i][j] = 1;
      else if (temp[i][j] == 1 && (cnt1 < 2 || cnt1 > 3))
        board[i][j] = 0;
      else
        board[i][j] = temp[i][j];
    }
  }
}

// optimize solution-
// Instead of using a separate temp matrix, we encode both old and new states in the same board.
// we use 4 states-
// current      next         value
// 0->0       dead->dead     0
// 1->1       live->live     1
// 1->0       live->dead     -1
// 0->1       dead->live      2
// Important:

// abs(board[i][j]) == 1 → means it was originally alive
void gameOflife(vector<vector<int>> &board)
{
  int m = board.size();
  int n = board[0].size();

  // mark transitions
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int live = 0;
      for (int k = -1; k <= 1; k++)
      {
        for (int l = -1; l <= 1; l++)
        {
          if (k == 0 && l == 0)
            continue;
          int nrow = i + k;
          int ncol = j + l;
          if (isValid(nrow, ncol, m, n) && abs(board[nrow][ncol]) == 1)
            live++;
        }
      }
      // apply rules with encodeing
      if (board[i][j] == 1 && (live < 2 || live > 3))
        board[i][j] = -1; // live->dead
      if (board[i][j] == 0 && live == 3)
        board[i][j] = 2; // dead->live
    }
  }
  // finalize values
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] > 0)
        board[i][j] = 1;
      else
        board[i][j] = 0;
    }
  }
}
int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> board(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }
  cout << endl;
  // gameOfLife(board);
  // gameofLife(board);
  gameOflife(board);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}