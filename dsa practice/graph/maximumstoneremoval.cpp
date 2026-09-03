// There are n stones at some integer coordinate points on a 2D plane. Each coordinate point may have atmost one stone.
// You neet to remove some stones.
// A stone can be removed if it shares either the same row or same col as another stone that has not been removed.
// Given an array stones of length n where stones[i]=[xi,yi] represents the location of ith stone, return the maximum possible number of stones that you can remove.

// we can remove stone if there is another stone in same row or col that has not been removed till now and also we can removed this stone also when we get other stone in same row or same col that has not been removed till now
// if we connect all those stone that are in  same row or same col i.e if we connect stone that depned on other stone when we connect all these stone we get one component for this component we can remove all stone except 1 because for last stone there is no other stone that is in same row or same col that has not been removed till now similarly for other component we do  same process
// so if we get components and its size then answer is sum of all components.size()-1

// if we have total n stones and say three components then
// like c1 component has size x1
// c2 component has size x2
// c3 component has size x3

// answer=(x1-1)+(x2-1)+(x3-1) and n=x1+x2+x3
// answer=n-3 where n is total no. of stone and 3 is total no.of component
// so answer is total no.of stone-no.of component
// we have to figure out no.of components either by traversal bfs/dfs or by disjoint set data structure for this initial we have configuration in which each node is parent of itseld here we have matrix of row and column
// in many previous question we give cellId to each cell that represent them as a node
// here we treat row and col as node in disjoint set
// and connect the row and col that having stone
// after getting components there is some component that have no stone so we have to discard them and we want valid disjoint set having stones
// for all the stones we want unique ultimate parents

// see more details of solution in notes

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
  vector<int> rank, parent, size;

public:
  // vector<int> rank, parent, size; // we make this public because if we use parent array out of class
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

// s.c-O(maxrow+maxcol+1)for parent,rank,size array + O(n)(for map storing unique row and col that have stone, At most 2n entries)=O(maxrow+maxcol+n)

// t.c-
// O(n) for finding maxRow and maxCol
// n*α(maxRow+maxCol) for making connecting components
// n⋅α(maxRow+maxCol) for counting components from map
// total t.c-n⋅α(maxRow+maxCol)
class Solution
{
public:
  // given stones array having coordinate where we have stone and n denotes stone array size
  int maxStoneRemove(vector<vector<int>> &stones, int n)
  {
    // first we determine total number of row and col
    int maxRow = 0;
    int maxCol = 0;
    // by itertaing on stones array the maxRow index in coordinate given is total number of row and maxCol index in coordinate given is total number of col of matrix
    for (auto it : stones)
    {
      maxRow = max(maxRow, it[0]); // it[0] represents row in that coordinate
      maxCol = max(maxCol, it[1]); // it[0] represents column in that coordinate
    }

    // in disjoint set initial each nodes is parent of itself
    // for matrix we initial take single number to represnt cell but here we treat row and col as nodes in disjoint set
    DisjointSet ds(maxRow + maxCol + 1);

    unordered_map<int, int> stoneNodes; // store row and col that have stone and store unique
    for (auto it : stones)
    {
      // coordinate of row and col where we have stone
      int nodeRow = it[0];
      int nodeCol = it[1] + maxRow + 1; // because col start after row nodes in disjoint set
      ds.unionBySize(nodeRow, nodeCol);
      // map store unique so store row and col that have stone
      stoneNodes[nodeRow] = 1;
      stoneNodes[nodeCol] = 1;
    }
    int cnt = 0;               // we cnt number of components having stones
    for (auto it : stoneNodes) // travel map
    {
      if (ds.findUPar(it.first) == it.first)
      {
        cnt++;
      }
    }
    return n - cnt; // answer is total stones - no. of components
  }
};

// inut type - n=6
// stone array-[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]] coordinate having stone
// matrix size we determine by maxrow index and maxcol index from stone array

int main()
{
  int n;
  cout << "Enter the size of stone array: ";
  cin >> n;
  vector<vector<int>> stones(n, vector<int>(2));
  cout << "Enter the value of stone array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> stones[i][0] >> stones[i][1];
  }
  Solution result;
  cout << "Maximum stone remove is: " << result.maxStoneRemove(stones, n) << endl;

  return 0;
}