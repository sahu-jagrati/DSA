// Given a matrix of n*m where every entity either 'O' or'X'.
// replace all 'O' with'X' that are surrounded by 'X'
// A 'O' or {a set of 'O'} is considered to be surrounded by 'X' if there are 'X' at locations just below,just above,just left,just right, diagonals are not considered

// observation-
// If someone or a set of 'O' connected to a boundary, cannot be converted in 'X'

// which algo we use- here we use dfs, we can use bfs also

// we start from boundary 'O' and mark them that they will not be converted and also those are connected with them also not converted  and the rest 'O' are convert in 'X'

// as always we don't do any process in input data, we create another visited matrix

#include <bits/stdc++.h>
using namespace std;

// worst case when all are 'O'
// t.c- O(N)(for boundary col)+O(M)(for boundary row)+O(N*M*4)(in worst case dfs run in total for all nodes in 4 direction)= O(N*M)
// s.c-O(N*M)(for visited)+recursion stack space=O(N*M)
class Solution
{
private:
  void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &mat, vector<int> &delrow, vector<int> &delCOl)
  {
    int n = mat.size();
    int m = mat[0].size();
    visited[row][col] = 1;
    // we move only in four direction
    for (int i = 0; i < 4; i++)
    {
      // neighbour row and col
      int nrow = row + delrow[i];
      int ncol = col + delCOl[i];

      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && mat[nrow][ncol] == 'O')
      {
        dfs(nrow, ncol, visited, mat, delrow, delCOl);
      }
    }
  }

public:
  vector<vector<char>> fill(vector<vector<char>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();

    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    // create visited because we don;t do any process on i/p data
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // go to boundary and call dfs for them
    for (int j = 0; j < m; j++)
    {
      if (!visited[0][j] && mat[0][j] == 'O')
      {
        dfs(0, j, visited, mat, delRow, delCol);
      }
      if (!visited[n - 1][j] && mat[n - 1][j] == 'O')
      {
        dfs(n - 1, j, visited, mat, delRow, delCol);
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (!visited[i][0] && mat[i][0] == 'O')
      {
        dfs(i, 0, visited, mat, delRow, delCol);
      }
      if (!visited[i][m - 1] && mat[i][m - 1] == 'O')
      {
        dfs(i, m - 1, visited, mat, delRow, delCol);
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!visited[i][j] && mat[i][j] == 'O')
        {
          mat[i][j] = 'X';
        }
      }
    }
    return mat;
  }
};

// input type-{{X,X,O},{X,O,X},{O,X,X}}
int main()
{
  int n, m;
  cout << "Enter the row and column size: ";
  cin >> n >> m;
  vector<vector<char>> mat(n, vector<char>(m));
  cout << "Enter the row and column value with either 'O' or 'X': ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }

  Solution result;
  vector<vector<char>> answer = result.fill(mat);
  for (auto row : answer)
  {
    for (auto it : row)
    {
      cout << it << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}