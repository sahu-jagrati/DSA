// A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

// s[i] == 'I' if perm[i] < perm[i + 1], and
// s[i] == 'D' if perm[i] > perm[i + 1].
// Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

// Example 1:

// Input: s = "IDID"
// Output: [0,4,1,3,2]
// Example 2:

// Input: s = "III"
// Output: [0,1,2,3]
// Example 3:

// Input: s = "DDI"
// Output: [3,2,0,1]

// Constraints:

// 1 <= s.length <= 10^5
// s[i] is either 'I' or 'D'.

#include <bits/stdc++.h>
using namespace std;

vector<int> diStringMatch(string s)
{
  int n = s.size();
  vector<int> ans(n + 1);
  // we use two pointer - i for I and j for D so we think that we start with small number(i.e 0) for I and n for (D) and increase i and decrease j manually so we satisfy the given condition without any tension
  int i = 0, j = n;
  int k = 0; // for traversing string
  while (i < j && k < n)
  {
    if (s[k] == 'I')
    {
      ans[k] = i;
      i++;
    }
    else
    {
      ans[k] = j;
      j--;
    }
    k++;
  }
  // ans is of size n+1 so for ans[n] - i and j are became equal so take any one of them
  ans[k] = i;
  return ans;
}
int main()
{
  string s;
  cin >> s;
  vector<int> ans = diStringMatch(s);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}