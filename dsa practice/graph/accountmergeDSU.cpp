// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order

// we have to merge the similar accounts

// two or more than two accounts are similar if some email account are same in them, if name are same only then we cann't say the account sre similar because two person can have same name

// so merge similar account and after merging sort the email ID of each account and delete the similar account
// answer can be in any order

// so you want to merge the set which dynamically changes at every step of configuration so we use DSU(disjoint set union) to merge the set

//
// we do this problem in three step-
// step -1 we initially do configuration for disjoint set that is each of the node is parent of itself so union them and take map data structure also to store email who belong to which index

// step-2 we get connected component, now we have to merge the email by travel one by one map and go with ulp of each index to merge mail

// step 3- after merging mail sort them then we store them in answer

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
// n is accounts size
// m is number of unique emails
// s.c-O(n*3)(for parent,rank,size array) +O(m)(for unordered map)+O(m)(for mergedMail) =O(n+m) we don't take ans size because it doesn;t use for solving problem

// t.c-
// for each union/find-O(α(n))
// traverse for (n*account[i].size)=m  wheere m is number of unique emails
// t.c for make connected components-O(m*α(n))
// for step 2 t.c-O(m*α(n)) for finUpar for each unique mail
// for sorting mails -O(mlogm)

// total - O(O(m*α(n))+mlogm)=O(mlogm)
class Solution
{
public:
  // accounts is array of string array- string array has name followed with many email accounts
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
  {
    int n = accounts.size();
    DisjointSet ds(n);
    unordered_map<string, int> mapMailNode; // store{mail,node(i.e index of string array)}

    // step-1
    for (int i = 0; i < n; i++)
    {
      // start after name
      // because want to merge mail so start after the name
      // and each string array size is different so accounts[i].size()
      for (int j = 1; j < accounts[i].size(); j++)
      {
        string mail = accounts[i][j];
        // if in map email is not exists
        if (mapMailNode.find(mail) == mapMailNode.end())
        {
          mapMailNode[mail] = i; // i is index of string array that mail belong to that string
        }
        // if it in mapMailNode already  email is exists
        // then connect the current index of string to already mail exist string node
        else
        {
          ds.unionBySize(i, mapMailNode[mail]);
        }
      }
    }

    // step-2 we get connected component now we merge mail by travel map and merge mail to their ultimate parent node
    vector<vector<string>> mergedMail(n);
    for (auto it : mapMailNode)
    {
      string mail = it.first;
      int node = ds.findUPar(it.second); // in map email is with their current string node we want to merge it with ultimate parent node so find ultimate parent
      mergedMail[node].push_back(mail);
    }

    // step-3 after merging sort each individual mergedmail and push in ans
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
      if (mergedMail[i].size() == 0) // because some of string array become empty due to merging
        continue;
      sort(mergedMail[i].begin(), mergedMail[i].end());
      vector<string> temp;
      temp.push_back(accounts[i][0]); // first we push name
      for (auto it : mergedMail[i])
      {
        temp.push_back(it);
      }
      ans.push_back(temp);
    }
    return ans;
  }
};

// input type- given array of string array followed by name and many email account
//  accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]

int main()
{
  int n;
  cout << "Enter the account size: ";
  cin >> n;
  vector<vector<string>> accounts(n);
  cout << "Enter the account array: ";
  for (int i = 0; i < n; i++)
  {
    int m;
    cout << "Enter the size of string array in account array: " << i << ": ";
    cin >> m;
    for (int j = 0; j < m; j++)
    {
      string s;
      cin >> s;
      accounts[i].push_back(s);
    }
  }

  Solution result;
  vector<vector<string>> answer = result.accountsMerge(accounts);
  for (auto it1 : answer)
  {
    for (auto it : it1)
    {
      cout << it << " ";
    }
    cout << endl;
  }

  return 0;
}