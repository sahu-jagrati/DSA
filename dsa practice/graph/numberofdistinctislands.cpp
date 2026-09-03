// given a boolean 2D matrix of size n*m.
// we have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island.

// Two islands are considered to be identical iff one island is equal to another (not rotated or reflected)

// if we get two identical island then we count them 1 distinct island because both are same to each

// our intution is that
// we store shape in set because set store unique element so set size is number of distinct islands
// how we get shape - by take base row and base column and for identical islands list of indexing should be same
// how we get same list for two islands that's why we take base row and base column - (row-baserow) and (col-basecol) we get same list for identical islands
// but you have to follow pattern of traversal so you travel in same manner and get same list for two identical island

#include <bits/stdc++.h>
using namespace std;

// t.c - N*M(for for loops)*log(N*M)(insert in set in worst case all element)+(N*M*4)(for dfs run for eanch node in 4 direction in worst case)
// s.c-(N*M)(for visited)+(N*M)(for set in worst case)-O(N*M)

class Solution
{
private:
  void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int baserow, int basecol)
  {
    int n = grid.size();
    int m = grid[0].size();

    visited[row][col] = 1;
    vec.push_back({row - baserow, col - basecol});
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
      // neighbour row and column
      int nrow = row + delrow[i];
      int ncol = col + delcol[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          grid[nrow][ncol] == 1 && !visited[nrow][ncol])
      {
        dfs(nrow, ncol, visited, grid, vec, baserow, basecol);
      }
    }
  }

public:
  int numberOfDistinctIsland(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    // create visited because we don;t do any process on i/p data
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!visited[i][j] && grid[i][j] == 1)
        {
          vector<pair<int, int>> vec;
          dfs(i, j, visited, grid, vec, i, j);
          st.insert(vec);
        }
      }
    }
    return st.size();
  }
};

// input type- {{1,1,0,1,1},{1,0,0,0,0},{0,0,0,1,1},{1,1,0,1,0}}
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
  int answer = result.numberOfDistinctIsland(mat);
  cout << answer << endl;

  return 0;
}