// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// done by me fully
// let strs.size()=n
// let m=strs[i].size()
// t.c-O(n*mlogm)+O(n*1)+st.size()*n, we use unordered set so in average it takes O(1) for insert or access
// s.c-O(result.size)+O(st.size)+O(n)(for temp array), result size  is required
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
  int n = strs.size();
  vector<string> temp = strs;
  for (int i = 0; i < n; i++)
  {
    sort(temp[i].begin(), temp[i].end());
  }
  unordered_set<string> st;
  for (int i = 0; i < n; i++)
    st.insert(temp[i]);
  vector<vector<string>> result;
  for (auto it : st)
  {
    string str = it;
    vector<string> group;
    for (int i = 0; i < n; i++)
    {
      if (str == temp[i])
        group.push_back(strs[i]);
    }
    result.push_back(group);
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; i++)
  {
    cin >> strs[i];
  }
  vector<vector<string>> answer = groupAnagrams(strs);
  for (auto it1 : answer)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  return 0;
}