// you are given an n*m binary matrix where 0 represent a sea cell and 1 represent a land cell
// A move consistes of walking fram one land cell to anothe adjacent(4-directionally) land cell or walking off the boundary of the grid.

// find the number of land cell in grid for which we cannot walk off the boundary of the grid in any number of moves.

// similar to surrouded region replace 'O' with 'X' question

// same observation-
// 1 that are connected to the boundary,never be our answer and the 1's that are connected to them are also not our answer

// in surrouded region replace 'O' with 'X' question  we use dfs so here we use bfs algo

#include <bits/stdc++.h>
using namespace std;

// worst case when all are 1
// t.c-O(N**4)(in worst case when queue has to go for all element) +O(N)+O(M)(for boundary elt)=O(N*M)
// s.c-O(N*M)(for visited)+O(N*M)(for queue in worst case)=O(N*M)
class Solution
{
public:
  int numberOfEnclaves(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();

    // create visited because we don;t do any process on i/p data
    vector<vector<int>> visited(n, vector<int>(m, 0));
    //{row,col}
    queue<pair<int, int>> q;
    // move on boundary

    for (int i = 0; i < n; i++)
    {
      if (!visited[i][0] && mat[i][0] == 1)
      {
        q.push({i, 0});
        visited[i][0] = 1;
      }
      if (!visited[i][m - 1] && mat[i][m - 1])
      {
        q.push({i, m - 1});
        visited[i][m - 1] = 1;
      }
    }
    for (int j = 0; j < m; j++)
    {
      if (!visited[0][j] && mat[0][j] == 1)
      {
        q.push({0, j});
        visited[0][j] = 1;
      }
      if (!visited[n - 1][j] && mat[n - 1][j] == 1)
      {
        q.push({n - 1, j});
        visited[n - 1][j] = 1;
      }
    }

    // move only in 4 direction
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        // neighbour row and col
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] != 1 && mat[nrow][ncol] == 1)
        {
          q.push({nrow, ncol});
          visited[nrow][ncol] = 1;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!visited[i][j] && mat[i][j] == 1)
        {
          cnt++;
        }
      }
    }
    return cnt;
  }
};

// input type-{{0,0,0,1},{0,1,1,0},{0,1,1,0},{0,0,0,1}}
int main()
{
  int n, m;
  cout << "Enter the row and column size: ";
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  cout << "Enter the row and column value with either 0 or 1: ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }

  Solution result;
  int answer = result.numberOfEnclaves(mat);
  cout << answer << endl;

  return 0;
}