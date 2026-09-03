// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
// Example 2:

// Input: arr = [1,2]
// Output: false
// Example 3:

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true

// Constraints:

// 1 <= arr.length <= 1000
// -1000 <= arr[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

// done by me fully
// t.c-O(n*1)+O(mpp.size^2)*1 - we use unordered map so for insert and fetch it take O(1) in average case
// s.c-O(n) if all number has one occurence in worst case =O(mpp.size)
bool uniqueOccurences(vector<int> &arr)
{
  unordered_map<int, int> mpp;
  for (int i = 0; i < arr.size(); i++)
  {
    mpp[arr[i]]++;
  }
  for (auto it1 : mpp)
  {
    int value = it1.first;
    int freq = it1.second;
    for (auto it2 : mpp)
    {
      if (value != it2.first && freq == it2.second)
        return false;
    }
  }
  return true;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << uniqueOccurences(arr) << endl;
  return 0;
}