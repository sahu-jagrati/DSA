// DSU ka full form hai:

// 👉 Disjoint Set Union

// Isse Union-Find bhi kaha jata hai.

// Short meaning

// DSU ek data structure hai jo:

// Alag-alag sets ko manage karta hai

// Batata hai do elements same set me hain ya nahi

// Sets ko efficiently merge (union) karta hai

// Core operations

// Find → kisi element ka ultimate parent

// Union → do sets ko merge karna

// Use cases

// Number of Provinces

// Cycle detection in graph

// Kruskal’s Algorithm (MST)

// Connected components

#include <bits/stdc++.h>
using namespace std;

// t.c-O(4*(alpha)) = constant don't need to proof
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
  // rank[i] is the rank of the element i.  Rank is same as height if path compression is not used. With path compression, rank can be more than the actual height.
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
  // size[i] is the number of the elements in the tree representing the set.
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