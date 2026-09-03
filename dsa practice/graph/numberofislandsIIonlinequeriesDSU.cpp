// you are given a n,m which means the row and column of the 2D matrix and an array of size k denoting the number of operations(online queries which you have to answer). Matrix elts is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator and each operator has two integer A[i][0],A[i][1] means that you can change the cell matrix [A[i][0],A[i][1]] from sea to island. Retun how many island are there in the matrix after each operator. You need to return an array of size k.

// Note- An island means group of 1s surrounded by water and is formed by connecting adjacent land horizontally or vertically, not diagonally
// if there is no land horizontally or vertically then it is an island in itself also

//  given k online queries(means given question you have to answer it in each step) so we have to answer them after each step so the number of island will be change after each step

// so we see that the configuration is change at each step which is dynamically changes and merge the island also in step. so for that type we use DSU-disjoint set data structure

// initial configuration in disjoint set is each of node is parent of itself
// so we have to give number to each cell that make them parent of itself

// we give each cell number from 0 to (n*m-1)
// but how we know that this number represent which cell

// so formula for finding cellNo(row,col) is (row,col)=(row*m)+col = node ID that represents cell, where m is the number of total column

// our approach is that we go to operator or queries one by one and take cnt=0
// and mark them visited as island and increase cnt by +1
// now traverse the neighbour of cell in four direction(top,right,bottom,left) if the neighbour cell is land and not connected before so connect it and decrease cnt by -1 or if there is land but it is connected by some other node like of ultimate parent so not connecte it and  not decrease cnt, remain it as it is, so do nothing

// or if in operator or queries same cell is asked again- so say it is already visited and not mark it again island

// in last we get list of answer of each queries or operator of size k return this

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
  vector<int> rank, parent, size; // we make this public because we use parent array out of class
  // constructor
  DisjointSet(int n) // n is the number of vertices
  {
    // n+1 takes because of 0 based indexing
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1, 1);
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

// s.c-O(n*m)(for parent,rank,size array)+O(n*m)(for visited matrix)+O(k)(for ans array)=O(n*m)
// t.c-
// for each union/find-O(4*α(n*m)), 4 for move in 4 direction and n*m total nodes
// so per operator t.c-O(4 × α(n*m)) ≈ O(α(n*m))
// total t.c-For k operators:
// O(k × α(n*m))
// Since α(n*m) is almost constant:

// ✅ Final Time Complexity = O(k)

class Solution
{
public:
  vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
  {
    DisjointSet ds(n * m); // total vertices is n*m
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int cnt = 0;
    vector<int> ans;
    // traverse each operator and answer it
    for (auto it : operators)
    {
      int row = it[0];
      int col = it[1];
      // if same cell again then
      if (visited[row][col] == 1)
      {
        ans.push_back(cnt); // nothing do with cnt
        continue;           // don't go further
      }
      // if not visited
      visited[row][col] = 1; // mark visited and increase cnt by +1
      cnt++;
      // travel in 4 direction
      vector<int> delrow = {-1, 0, 1, 0};
      vector<int> delcol = {0, 1, 0, -1};
      for (int i = 0; i < 4; i++)
      {
        int adjrow = row + delrow[i];
        int adjcol = col + delcol[i];
        if (adjrow >= 0 && adjrow < n && adjcol >= 0 && adjcol < m)
        {
          // having land and but not connected before so connect it and decrease cnt by -1
          if (visited[adjrow][adjcol] == 1)
          {
            // for connecting we have to find nodeNo
            int nodeNo = row * m + col;
            int adjNodeNo = adjrow * m + adjcol;
            // not connected before
            if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo))
            {
              // decrease cnt by -1
              cnt--;
              // and connect them
              ds.unionBySize(nodeNo, adjNodeNo);
            }
          }
          // already connect by ultimate parent so do nothing
        }
      }
      ans.push_back(cnt); // for each operator
    }
    return ans;
  }
};

// input type - n=4,m=5
// initial matrix of size n*m Originally, the 2D matrix is all 0 which means there is no land in the matrix, after each operation we place land in that cell if same cell again then it is already visited and not mark it again island
// k=4 size of operator array
// queries or opeator array-A={[1,1],[0,1],[3,3],[3,4]} i.e [row,col]

int main()
{
  int n, m;
  cout << "Enter the row and column size of matrix: ";
  cin >> n >> m;
  int k;
  cout << "Enter the size of operator or queries array: ";
  cin >> k;
  vector<vector<int>> operators(k, vector<int>(2));
  cout << "Enter the value of operator array: ";
  for (int i = 0; i < k; i++)
  {
    cin >> operators[i][0] >> operators[i][1];
  }

  Solution result;
  vector<int> answer = result.numOfIslands(n, m, operators);
  cout << "Number of island for each operator: \n";
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}