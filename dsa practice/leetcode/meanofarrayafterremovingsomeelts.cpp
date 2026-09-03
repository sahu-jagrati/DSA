// Given an integer array arr, return the mean of the remaining integers after removing the smallest 5% and the largest 5% of the elements.

// Answers within 10-5 of the actual answer will be considered accepted.

// Example 1:

// Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
// Output: 2.00000
// Explanation: After erasing the minimum and the maximum values of this array, all elements are equal to 2, so the mean is 2.
// Example 2:

// Input: arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
// Output: 4.00000
// Example 3:

// Input: arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
// Output: 4.77778

// Constraints:

// 20 <= arr.length <= 1000
// arr.length is a multiple of 20.
// 0 <= arr[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

// done by me fully
// t.c-O(n-2*remove)+O(nlogn)(sorting)
// s.c-O(1)
double trimMean(vector<int> &arr)
{
  int n = arr.size();
  sort(arr.begin(), arr.end()); // we sort the array because we have to remove 5% of smallest and 5% of largest elt in an array so after sorting first 5% are smallest and last 5% are largest elt in an array
  int remove = (n * 5) / 100;   // 5% of n that we have to remove

  int sum = 0;
  for (int i = remove; i <= (n - 1 - remove); i++)
  {
    sum += arr[i];
  }
  double answer = (double)sum / (n - (2 * remove));
  return answer;
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
  cout << trimMean(arr) << endl;
  return 0;
}