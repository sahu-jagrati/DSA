// You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

// You are also given an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff.

// An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

// You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between nodes ui and vi.

// Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith query and false otherwise.

// Example 1:

// Input: n = 2, nums = [1,3], maxDiff = 1, queries = [[0,0],[0,1]]

// Output: [true,false]

// Explanation:

// Query [0,0]: Node 0 has a trivial path to itself.
// Query [0,1]: There is no edge between Node 0 and Node 1 because |nums[0] - nums[1]| = |1 - 3| = 2, which is greater than maxDiff.
// Thus, the final answer after processing all the queries is [true, false].
// Example 2:

// Input: n = 4, nums = [2,5,6,8], maxDiff = 2, queries = [[0,1],[0,2],[1,3],[2,3]]

// Output: [false,false,true,true]

// Explanation:

// The resulting graph is:

// Query [0,1]: There is no edge between Node 0 and Node 1 because |nums[0] - nums[1]| = |2 - 5| = 3, which is greater than maxDiff.
// Query [0,2]: There is no edge between Node 0 and Node 2 because |nums[0] - nums[2]| = |2 - 6| = 4, which is greater than maxDiff.
// Query [1,3]: There is a path between Node 1 and Node 3 through Node 2 since |nums[1] - nums[2]| = |5 - 6| = 1 and |nums[2] - nums[3]| = |6 - 8| = 2, both of which are within maxDiff.
// Query [2,3]: There is an edge between Node 2 and Node 3 because |nums[2] - nums[3]| = |6 - 8| = 2, which is equal to maxDiff.
// Thus, the final answer after processing all the queries is [false, false, true, true].

// Constraints:

// 1 <= n == nums.length <= 10^5
// 0 <= nums[i] <= 10^5
// nums is sorted in non-decreasing order.
// 0 <= maxDiff <= 10^5
// 1 <= queries.length <= 10^5
// queries[i] == [ui, vi]
// 0 <= ui, vi < n

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
  vector<int> rank, parent;

public:
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }
  int findUPar(int node)
  {
    if (node == parent[node])
      return node;

    return parent[node] = findUPar(parent[node]);
  }

  void unionByRank(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
    {
      return;
    }
    if (rank[ulp_u] < rank[ulp_v])
    {
      parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u])
    {
      parent[ulp_v] = ulp_u;
    }
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};

// there is an edge between two nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).
// here we also have an sorted nums array
// since the nums array is already sorted, we don't need to check every single pair of nodes to see it an edge exists. If two distant node are connected because their difference is within maxDiff, all the adjacent nodes between them in the sorted array must also be within maxDiff of each other. THis means we only need to check adjacent elts to build our graph's connected components.
// Since the nums array is already sorted, we don't need to check every single pair of nodes to see if an edge exists.
// suppose- nums[]=[1,3,5,8,9]
// maxdiff=2
// If we didn't know the array was sorted, we would have to check every pair:
// 1-3
// 1-5
// 1-8
// 1-9
// 3-5
// 3-8 and so on there are O(n^2) pairs
// but because the array is sorted, we only check:
// 1-3, 3-5, 5-8, 8-9
// Why is that enough?
// example- nums[]=[1,3,5]
// adjacent differences:
// 3-1=2
// 5-3=2
// graph:  1----3----5
// Can 1 reach 5? Yes
// even though we never checked (1,5), there is already a path: 1->3->5 so checking pair (1,5) is unnecessary.
// example 2- nums[]=[1,3,5,10] and maxdiff=2
// adjacent differences:
// 3-1=2
// 5-3=2
// 10-5=5
// graph: 1--3--5    but 10 is another connected
// Can 1 connect to 10? difference: 10-1=9 No
// Can 3 connect to 10? 10-3=7 No
// Can 5 connect to 10? 10-5=5 NO.
// once the adjacent gap is too large,nothing can cross it. means if adjacent nodes gap is large then if we take distant node then the gap is so large so then there is no chance to connect them so that's why we check for adjacent nodes if there is an edge between adjacent nodes then there is a path to reach from distant nodes
// Why does sorting make this true?
// look at this sorted array: 1 3 5 10
// suppose the adjacent gap : 5---10 is larger than maxDiff
// every number on the left is <=5 and Every number on the right is >=10. so for any left elt a and right elt b: b-a>=10-5
// Since 10-5>maxDiff every other cross-gap difference is also greater than maxDiff
// so no edge can exist across this gap.

// So If two distant nodes are connected because their difference is within maxDiff, all the adjacent nodes between them in the sorted array must also be within maxDiff of each other that is if difference of two distant nodes is within maxdiff then the difference of nodes between them is also within maxDiff

// Suppose:
// nums[]=[2,4,6,7] and maxdiff=5
// the distant nodes are: 2 and 7 and difference is 7-2=5 so they satisfy the condition
// now check every adjacent pair between them :
// 4-2=2
// 6-4=2
// 7-6=1
// every adjacent difference is also <=5
// therefore, there is alradey a chain: 2-4-6-7
// So there is no need to create a direct edge between 2 and 7
// one more example: nums[]=[1,2,4,6] and maxdiff=5
// differnece btw 1 and 6=6-1=5
// adjacent differences:
// 2-1=1
// 4-2=2
// 6-4=2
// again: 1-2-4-6
// so connecting only adjacent elts is enough.
// the key mathematical reason is:
// for a sorted array: nums[i]<=nums[i+1]<=....<=nums[j]
// If nums[j]-nums[i]<=maxDiff then every adjacent difference inside that interval is also atmost maxDiff
// only adjacent differnce in that interval also within maxDiff
// Why?
// Each adjacent difference is only a part of the total difference:
// nums[j]-nums[i]=(nums[i+1]-nums[i]+(nums[i+2]-nums[i+1])+...+(nums[j]-nums[j-1]))

// All these adjacent differences are non-negative (because the array is sorted). If even one adjacent difference were greater than maxDiff, then the total difference would be even larger than maxDiff, which is impossible.

// The main idea to remember

// The sorted order turns the array into a chain.

// If every adjacent pair in a segment satisfies difference ≤ maxDiff, then the entire segment is one connected component.
// If any adjacent pair has difference > maxDiff, that gap acts like a wall. No element on the left can connect to any element on the right.

// That's why the algorithm only needs to check adjacent elements, reducing the work from O(n²) to O(n) when building the DSU.

// t.c- O(n)(for checking every adjacent pair and making edge)+O(m)(for checking each query) since DisjointSet taking constant t.c so no extra t.c
// total t.c-O(n+m) where n is the number of nodes and m is size of queries array
// s.c-O(2*n)(for rank,parent array)+O(m)(for ans array )
vector<bool> pathExistence(int n, int maxDiff, vector<int> &nums, vector<vector<int>> &queries)
{
  DisjointSet ds(n);
  for (int i = 1; i < n; i++)
  {
    if (abs(nums[i] - nums[i - 1]) <= maxDiff)
      ds.unionByRank(i, i - 1);
  }
  int m = queries.size();
  vector<bool> ans(m);
  for (int i = 0; i < m; i++)
  {
    int u = queries[i][0];
    int v = queries[i][1];
    if (ds.findUPar(u) == ds.findUPar(v))
      ans[i] = true;
    else
      ans[i] = false;
  }
  return ans;
}

int main()
{
  int n;
  cout << "Enter the number of nodes:" << endl;
  cin >> n;
  int maxDiff;
  cout << "Enter the maxDiff value: " << endl;
  cin >> maxDiff;
  vector<int> nums(n);
  cout << "Enter the nums array value: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int m;
  cout << "Enter the query size: " << endl;
  cin >> m;

  vector<vector<int>> queries(m, vector<int>(2));
  cout << "Enter the query array: " << endl;
  for (int i = 0; i < m; i++)
  {
    cin >> queries[i][0] >> queries[i][1];
  }
  vector<bool> ans = pathExistence(n, maxDiff, nums, queries);
  for (int i = 0; i < m; i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}
