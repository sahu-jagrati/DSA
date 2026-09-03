// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

// a, b are from arr
// a < b
// b - a equals to the minimum absolute difference of any two elements in arr

// Example 1:

// Input: arr = [4,2,1,3]
// Output: [[1,2],[2,3],[3,4]]
// Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
// Example 2:

// Input: arr = [1,3,6,10,15]
// Output: [[1,3]]
// Example 3:

// Input: arr = [3,8,-10,23,19,-4,-14,27]
// Output: [[-14,-10],[19,23],[23,27]]

// Constraints:

// 2 <= arr.length <= 10^5
// -106 <= arr[i] <= 10^6

#include <bits/stdc++.h>
using namespace std;

// our code has two bugs-
// i) in ans we pushed even if temp is empty
// ii) Suppose:
// Earlier miniDiff = 5
// Later you find difference = 2
// You must clear previous answers, because they are no longer minimum

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int miniDiff = INT_MAX;
  int i = 0, j = 1;
  vector<vector<int>> ans;
  while (j < n)
  {
    int difference = abs(arr[i] - arr[j]);
    miniDiff = min(miniDiff, difference);
    vector<int> temp;
    if (difference == miniDiff)
    {
      temp.push_back(arr[i]);
      temp.push_back(arr[j]);
    }
    ans.push_back(temp);
    i++;
    j++;
  }
  return ans;
}

// correct code of your
vector<vector<int>> minAbsDifference(vector<int> &nums)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int mindiff = INT_MAX;
  vector<vector<int>> ans;
  for (int i = 0; i < n - 1; i++)
  {
    int diff = nums[i + 1] - nums[i]; // we sort array so no need of abs
    if (diff < mindiff)
    {
      mindiff = diff;
      ans.clear(); // remove old pairs
      ans.push_back({nums[i], nums[i + 1]});
    }
    else if (diff == mindiff)
    {
      ans.push_back({nums[i], nums[i + 1]});
    }
  }
  return ans;
}
int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt in an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  vector<vector<int>> answer = minAbsDifference(nums);
  cout << "Minimize Maximum pair sum is: ";
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