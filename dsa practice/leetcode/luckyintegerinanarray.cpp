// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.

// Example 1:

// Input: arr = [2,2,3,4]
// Output: 2
// Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
// Example 2:

// Input: arr = [1,2,2,3,3,3]
// Output: 3
// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
// Example 3:

// Input: arr = [2,2,2,3,3]
// Output: -1
// Explanation: There are no lucky numbers in the array.

#include <bits/stdc++.h>
using namespace std;

int findLucky(vector<int> &arr)
{
  int n = arr.size();
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[arr[i]]++;
  }
  int ans = -1;
  for (auto it : mpp)
  {
    if (it.first == it.second)
    {
      ans = max(ans, it.first);
    }
  }
  return ans;
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the elt in an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int answer = findLucky(arr);
  cout << "Lucky integer in an array: " << answer << endl;
  return 0;
}