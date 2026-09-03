// You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).

// Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.

// The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.

// Example 1:

// Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
// Output: [[0,0],[0,1]]
// Explanation: The distances from (0, 0) to other cells are: [0,1]
// Example 2:

// Input: rows = 2, cols = 2, rCenter = 0, cCenter = 1
// Output: [[0,1],[0,0],[1,1],[1,0]]
// Explanation: The distances from (0, 1) to other cells are: [0,1,1,2]
// The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
// Example 3:

// Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
// Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
// Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
// There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].

// Constraints:

// 1 <= rows, cols <= 100
// 0 <= rCenter < rows
// 0 <= cCenter < cols

#include <bits/stdc++.h>
using namespace std;

// we can  move only four direction from given cells - up/down or left/right and for remaining cells use the neighbour cells
// so four direction frow (r,c) is (r-1,c),(r+1,c),(r,c-1),(r,c+1)

// also we have to check the boundary when we move neighbours
// and when we go from one neighbour to other it visited same neighbour more than one times so we have to mark visited cell

// t.c-O(rows*cols) because we visit each cell once
// s.c-O(2*rows*cols) for result,visited matrix, for result is it required

// it is BFS solution
vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
{
  vector<vector<int>> result;
  vector<vector<int>> visited(rows, vector<int>(cols, 0)); // visited matrix used for avoiding repeating cells
  queue<pair<int, int>> q;                                 // store <row,col> , we don't carry distance because we go in four direction i.e in neighbour and push it directly in queue so it is already sorted no nedd to take distance
  q.push({rCenter, cCenter});
  visited[rCenter][cCenter] = 1;
  vector<int> rowVector = {-1, 0, 1, 0};
  vector<int> colVector = {0, 1, 0, -1}; // corresponding to row

  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    int row = it.first;
    int col = it.second;
    result.push_back({row, col});
    // we can move in four direction so use rowVector and colVector
    for (int k = 0; k < 4; k++)
    {
      int nrow = row + rowVector[k]; // nrow is neighbourrow
      int ncol = col + colVector[k]; // ncol is neighbour column
      // check boundary and also it is not visited cell

      if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && !visited[nrow][ncol])
      {
        visited[nrow][ncol] = 1;
        q.push({nrow, ncol});
      }
    }
  }
  return result;
}

// simpler solution than BFS
// The trick is to use Manhattan Distance and then sort.

// The Manhattan distance from (rCenter, cCenter) to (r, c) is:
// ∣r-rCenter|+|c-cCenter|
// 1️⃣ Idea

// Traverse all cells in the matrix.
// Store their coordinates.
// Sort them based on Manhattan distance from (rCenter, cCenter

// t.c-O(rows*cols)+O(rows*cols*log(rows*cols))(for sorting)
// s.c-O(rows*cols) for result matrix
vector<vector<int>> allcellsDistOrder(int rows, int cols, int rCenter, int cCenter)
{
  vector<vector<int>> result;
  // first we simply insert cells in result
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result.push_back({i, j});
    }
  }
  // sort according to dist
  sort(result.begin(), result.end(), [&](vector<int> &a, vector<int> &b)
       {
    int d1=abs(a[0]-rCenter)+abs(a[1]-cCenter);
    int d2=abs(b[0]-rCenter)+abs(b[1]-cCenter);
    return d1<d2; });
  return result;
}
int main()
{
  int rows, cols, rCenter, cCenter;
  cin >> rows >> cols >> rCenter >> cCenter;
  // vector<vector<int>> answer = allCellsDistOrder(rows, cols, rCenter, cCenter);
  // for (auto it1 : answer)
  // {
  //   for (auto it2 : it1)
  //   {
  //     cout << it2 << " ";
  //   }
  //   cout << endl;
  // }

  vector<vector<int>> result = allcellsDistOrder(rows, cols, rCenter, cCenter);
  for (auto &it : result)
  {
    cout << it[0] << " " << it[1] << endl;
  }
  return 0;
}