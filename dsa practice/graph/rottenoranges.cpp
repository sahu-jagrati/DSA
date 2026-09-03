// given a grid of n*m where each cell in the grid can have values 0,1 or 2 which has the following meaning-
// 0-empty cell
// 1-cells have fresh oranges
// 2-cells have rooten oranges

// we have to determine the minimum time required to rotten all fresh oranges. If any of fresh orange is not rotten by already rotten orange then return -1.
// a rotten orange at index[i,j] can rot other oranges at indexes [i-1,j],[i+1,j],[i,j-1],[i,j+1] i.e we can move only in 4 direction

// if there are many already rotten oranges in grid then all move simultaneously together to rot there neighbour oranges and process move so on like flood fill question neighbour to neighbour
// which algo we use
// if we use dfs then it does not take all already rotten oranges  simultaneously together, it move one by one that take time
// so we use bfs algo-level order-go level by, in this we move simultaneously to all rotten oranges together - zwhich is done by queue data structure

#include <bits/stdc++.h>
using namespace std;

// s.c-O(N*M)(for queue in worst case)+O(N*M)(for visited)=O(N*M)
// t.c-O(N*M)(for marking visited matrix)+O(N*M)(pushing all fresh orange in queue in worst case )+O(N*M*4)(move in 4 direction for each node)-O(N*M)
class Solution
{
public:
  int minimumTimeToRotOranges(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    // we use this for record rotten orange and as also a good engineer we don't interrupt with input data
    vector<vector<int>> visited(n, vector<int>(m));
    // {{row,col},time}
    queue<pair<pair<int, int>, int>> q;
    // mark visited matrix
    int cntFresh = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 2)
        {
          // initially we push all oranges index that is already rotten
          q.push({{i, j}, 0});
          visited[i][j] == 2;
        }
        else
        {
          visited[i][j] = 0;
        }
        if (grid[i][j] == 1)
          cntFresh++;
      }
    }
    int tm = 0;
    // we have to move in only four direction so
    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    int cnt = 0; // for checking in last we visit all fresh orange or not otherwise return -1
    while (!q.empty())
    {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int t = q.front().second;
      tm = max(tm, t);
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        // neighbour row and column
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
        {
          q.push({{nrow, ncol}, t + 1});
          visited[nrow][ncol] = 2;
          cnt++;
        }
      }
    }
    // for checking  we visit all fresh orange or not otherwise return -1
    if (cntFresh != cnt)
      return -1;

    // this can also be done

    // for(int i=0;i<n;i++){
    //   for(int j=0;j<m;j++){
    //     if(visited[i][j]!=2&&grid[i][j]==1)return -1;
    //   }
    // }
    return tm;
  }
};

// input type-{{0,1,2},{0,1,1},{2,1,1}}
int main()
{
  int n, m;
  cout << "Enter the row and column size: ";
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  cout << "Enter the row and column value (it can be 0,1 and 2): ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  Solution result;
  int answer = result.minimumTimeToRotOranges(grid);
  cout << answer << endl;

  return 0;
}