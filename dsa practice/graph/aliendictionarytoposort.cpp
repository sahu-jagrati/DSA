// given a sorted dictionary of an alien language having N words and K starting alphabets of standard dictionary. Find the order of character in the alien language.

// Many orders may be possible for a particular test case, you may return any valid order.and o/p will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string

// order in alien language means like there is an order in standard dictionary 'a b c d .....x y z' so similar there is an order in alien language we have to find this according to given words in dictionary.

// how we find this order- we pick two pair from dictionary and compare them if the character does not match than it means the character from first string appears before character from second string and we have no need to check for next character if character match than check next character of same strings otherwise not and process so on take next two pair

// by this we create directed acyclic graph
// character appears before some character similar to topo sort so we apply topo sort and also we create DAG from given alien dictionary

// also note if K=5 but in given alien sorted dictionary array there is only four letter mention then fifth letter considered as another component of directed graph and it can be in any place in order

// Order is NOT possible in two cases:
//
// 1) Prefix case:
//    Example: {"abcd","abc"}
//    If all characters match but the longer word comes before
//    the shorter prefix word, dictionary order is invalid.
//
// 2) Cycle dependency case:
//    Example: {"aba","bat","ade"}
//    Here character dependencies form a cycle (a -> b -> a).
//    In this case, topological sort is not possible.

#include <bits/stdc++.h>
using namespace std;

// time complexity-O(V+E)(bfs for directed graph)+O(V)(for push nodes with 0 indegree)+O(V)(for indegree)+O(N)(for comparing words)
//  space complexity-O(V)(queue)+O(V)(topsort)+O(V)(indegree array)
class Solution
{
private:
  vector<int> topoSort(int V, vector<vector<int>> &adj)
  {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i])
      {
        indegree[it]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }
    vector<int> topo;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      topo.push_back(node);

      for (auto it : adj[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
        {
          q.push(it);
        }
      }
    }
    return topo;
  }

public:
  // N is the number of words in dictionary array and K is the starting alphabet of standard dictionary
  string findOrder(vector<string> &dictionary, int N, int K)
  {
    // making adjlist for build directed acyclic graph
    vector<vector<int>> adj(K);

    // picking pairs and create edge
    for (int i = 0; i <= N - 2; i++)
    {
      string st1 = dictionary[i];
      string st2 = dictionary[i + 1];

      // comparing string
      int len = min(st1.size(), st2.size());

      // when order is not possible
      bool mismatchFound = false;
      for (int ptr = 0; ptr < len; ptr++)
      {
        if (st1[ptr] != st2[ptr])
        {
          // -'a' because we want to store in form of
          // in standard dictionary we have
          // a b c d ...
          // 0 1 2 3 ...
          // 0 for a , 1 for b and so on

          adj[st1[ptr] - 'a'].push_back(st2[ptr] - 'a');
          mismatchFound = true;
          break;
        }
      }
      // case 1 ordrer not possible-
      if (!mismatchFound && st1.size() > st2.size())
      {
        return "";
      }
    }

    vector<int> topo = topoSort(K, adj);
    // case 2 - order not possible
    if (topo.size() < K)
    {
      return "";
    }
    // we have to return string so convert vector in string
    string ans = "";
    for (auto it : topo)
    {
      ans = ans + char(it + 'a');
    }
    return ans;
  }
};

// input type-{"baa","abcd","abca","cab","cad"}

int main()
{
  int N;
  cout << "Enter number of words in alien dictionary: ";
  cin >> N;
  int K;
  cout << "Enter the number of starting alphabet of standard dictionary: ";
  cin >> K;

  vector<string> alienDictionary(N);
  cout << "Enter words for dictionary: ";
  for (int i = 0; i < N; i++)
  {
    cin >> alienDictionary[i];
  }
  Solution result;
  string answer = result.findOrder(alienDictionary, N, K);
  cout << answer << endl;

  return 0;
}