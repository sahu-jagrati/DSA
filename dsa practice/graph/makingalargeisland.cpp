// given n*n binary grid. A grid is said to be binary if every value in grid is either 0 or 1.
// You can change atmost one cell in grid from 0 to 1.
// you need to find the largest gropu of connected 1s.
// two cells are said to be connected if both are adjacent to each other horizontally or vertically, not diagonally and both have same value.

// we want after converting that one cell in grid from 0 to 1 largest group of connected 1s.
// we convert 0 to 1 any one cell only  and connect two or more than 2 component by this we get large group of connected 1s or not necessary that always that you connect components by convert cell 0 to 1 is large while sometime you convert that one cell which is not connected with more than one component and get large group of connected 1s.

// whenever we talk about components this is from graph and we see we have to convert only one cell that give large group of connected 1s so we have to go with each cell and by traverse this we see there is change in configuration at each step, dynamically changes in graph so, we use disjoint set data structure
// in disjoint set initial each node is parent of itself so we have to convert each cell to cellId by formaula (row,col)=row*n(col length in grid)+col give cellId

// step-1  making components that connect each cell to their ultimate parent
// step-2 try converting 0 to 1by moving in four direction but when we move in 4 direction for a cell and by using size we count same component more than one while moving left or right or top or bottom give wrong answer because you add same component more than one

// so instead of storing size we store ultimate parent of that cell in set(because it store unique)data structure so we take one component only 1 time

// edge case also- when in grid all value are 1 then we take ultimate parent and return their size

// also size after conversion is size of component + 1(this for that cell we convert it from 0 to 1 )

// for more details of solution see notes

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
  // vector<int> parent, rank, size;

public:
  vector<int> parent, rank, size; // declare inside public beacuse we used outside of class Disjoint set
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  // find ultimate parent
  int findUPar(int node)
  {
    if (node == parent[node])
    {
      return node;
    }
    return parent[node] = findUPar(parent[node]);
  }

  // union by rank
  void unionByRank(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (rank[ulp_u] < rank[ulp_v])
    {
      parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u])
    {
      parent[ulp_v] = ulp_u;
    }
    // when rank are same
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  // union by size
  void unionBySize(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    // when size  are same or size[ulp_v]<size[ulp_u]
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

// s.c-O(n*n)(for parent,rank,size array) and set size not consider because it is constant
// t.c-
// step -1
// Total cells = n²

// For each cell, you check 4 neighbors → constant work

// Each unionBySize and findUPar operation in DSU takes
// α(n²) (inverse Ackermann function, almost constant)
// t.c - O(n^2×(4×α(n^2)))=O(n^2)

// step-2
// Again n² cells
// For each zero cell:

// Check 4 neighbors

// Insert at most 4 elements into a set and findUpar is take constant time α(n^2)
// Iterate over at most 4 components
// Important:
// set size ≤ 4 → operations are O(log 4) = O(1)
// t.c-O(n^2)

// for step if grid all cell have valu=1
// for that loop-O(n^2)

// total time complexity -O(n^2)
class Solution
{
private:
  bool isValid(int nrow, int ncol, int n)
  {
    return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
  }

public:
  int maxConnection(vector<vector<int>> &grid)
  {
    int n = grid.size();
    DisjointSet ds(n * n);

    // step-1 make components
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < n; col++)
      {
        if (grid[row][col] == 0)
          continue; // there is no land so don't need to connect

        // for each cell we move in 4 direction horizontally or vertically, not diagonally
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        // we go to neighbour when grid[row][col]=1

        for (int i = 0; i < 4; i++)
        {
          // neighbour row and col
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1)
          {
            // so connect them, for connecting we want cell ID for that particular cell
            int nodeNo = row * n + col;
            int adjNodeNo = nrow * n + ncol;
            ds.unionBySize(nodeNo, adjNodeNo);
          }
        }
      }
    }
    // step-2 convert 0 to 1 of atmost one cell of grid and by the components ultimate parent not by size of component
    int maxi = 0; // beacuse we want largest island after converting atmost one cell from 0 to 1 of the grid
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < n; col++)
      {
        if (grid[row][col] == 1)
          continue; // because we have to convert 0 to 1 not 1 to 1
        // we move in 4 direction
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        // make set to store unique ultimate parent of that cell of the component to avoid add one component size more than one
        set<int> components;

        // we go to neighbour when grid[row][col]=0
        for (int i = 0; i < 4; i++)
        {
          // neighbour row and col
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          if (isValid(nrow, ncol, n))
          {
            // grid[row][col]=0 so we want neighbour who have land i.e grid[nrow][ncol]=1 then we increase the island
            if (grid[nrow][ncol] == 1)
            {
              int adjNodeNo = nrow * n + ncol;
              // we insert in set ultimate parent of neighbour cell
              components.insert(ds.findUPar(adjNodeNo));
            }
          }
        }
        // after moving to neighbour we calculate totalsize from the that we insert in set

        int totalSize = 0;
        for (auto it : components)
        {
          totalSize += ds.size[it];
        }
        maxi = max(maxi, totalSize + 1); // +1 for the cell that we convert
      }
    }

    // but there is case also if all cell in grid has value =1 already then we have to check that the all cell ultimate parent is one cell and that cell size is our answer
    for (int cellNo = 0; cellNo < n * n; cellNo++)
    {
      maxi = max(maxi, ds.size[ds.findUPar(cellNo)]); // size array of disjoint set we use directly because we declare size array public
    }
    return maxi;
  }
};

// input type -n=2
// grid={[1,1][0,1]}

int main()
{
  int n;
  cout << "Enter the size of grid: ";
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  cout << "Enter the value of grid matrix i either 0 or 1 that represent sea or land: ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }
  Solution result;
  cout << "Largest island having 1s is: " << result.maxConnection(grid) << endl;
  return 0;
}