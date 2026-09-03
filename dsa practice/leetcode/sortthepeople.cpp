// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

// For each index i, names[i] and heights[i] denote the name and height of the ith person.

// Return names sorted in descending order by the people's heights.

// Example 1:

// Input: names = ["Mary","John","Emma"], heights = [180,165,170]
// Output: ["Mary","Emma","John"]
// Explanation: Mary is the tallest, followed by Emma and John.
// Example 2:

// Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
// Output: ["Bob","Alice","Bob"]
// Explanation: The first Bob is the tallest, followed by Alice and the second Bob.

// Constraints:

// n == names.length == heights.length
// 1 <= n <= 10^3
// 1 <= names[i].length <= 20
// 1 <= heights[i] <= 10^5
// names[i] consists of lower and upper case English letters.
// All the values of heights are distinct.

#include <bits/stdc++.h>
using namespace std;

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
  int n = names.size();
  unordered_map<int, string> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[heights[i]] = names[i];
  }
  sort(heights.begin(), heights.end());
  vector<string> ans;
  for (int i = 0; i < n; i++)
  {
    ans.push_back(mpp[heights[i]]);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int n;
  cout << "Enter the size of an array: ";
  cin >> n;
  vector<string> names(n);
  cout << "Enter the names array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> names[i];
  }
  vector<int> heights(n);
  cout << "Enter the heights array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> heights[i];
  }
  vector<string> result = sortPeople(names, heights);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}