// Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

// Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

// Notice that you can return the vertices in any order.

// Example 1:

// Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
// Output: [0,3]
// Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
// Example 2:

// Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
// Output: [0,2,3]
// Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.

// Constraints:

// 2 <= n <= 10^5
// 1 <= edges.length <= min(10^5, n * (n - 1) / 2)
// edges[i].length == 2
// 0 <= fromi, toi < n
// All pairs (fromi, toi) are distinct.

// Hint 1
// A node that does not have any incoming edge can only be reached by itself.
// Hint 2
// Any other node with incoming edges can be reached from some other node.
// Hint 3
// We only have to count the number of nodes with zero incoming edges.

#include <bits/stdc++.h>
using namespace std;

// by using hint
// if there is no incoming edges in a vertex then we can't reach that vertex from other vertex, we reach only by itself so it's in our set
// the vertices that are having incoming edges we can reach them from other vertex easily so we don't have to mention them in our set because they are reachable from other nodes and we want smallest set of vertices from which all nodes in the graph are reachable.

// so we make array of size n(which is no of vertices) initially all having value -1 then we travle edges array in that for each edge array[toi] =1 we set up means there is an incoming edge in that vertex
// so in next loop we check those value of array still have -1 value is the vertex with no incoming edge so we push it in our result
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
  vector<int> mpp(n, -1);
  for (int i = 0; i < edges.size(); i++)
  {
    // incoming edges come in toi in [fromi,toi]
    mpp[edges[i][1]] = 1;
  }
  vector<int> res;
  for (int i = 0; i < n; i++)
  {
    if (mpp[i] == -1)
      res.push_back(i);
  }
  return res;
}
int main()
{
  int n;
  cout << "Enter no. of vertices: ";
  cin >> n;
  int m;
  cout << "Enter the size of edges array: ";
  cin >> m;
  vector<vector<int>> edges(m, vector<int>(2));
  for (int i = 0; i < m; i++)
  {
    cin >> edges[i][0] >> edges[i][1];
  }
  vector<int> result = findSmallestSetOfVertices(n, edges);
  for (auto x : result)
  {
    cout << x << " ";
  }
  return 0;
}