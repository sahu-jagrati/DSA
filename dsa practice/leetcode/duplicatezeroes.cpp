// Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

// Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

// Example 1:

// Input: arr = [1,0,2,3,0,4,5,0]
// Output: [1,0,0,2,3,0,0,4]
// Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
// Example 2:

// Input: arr = [1,2,3]
// Output: [1,2,3]
// Explanation: After calling your function, the input array is modified to: [1,2,3]

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 9

#include <bits/stdc++.h>
using namespace std;

void duplicateZeros(vector<int> &nums)
{
  int n = nums.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == 0)
      cnt++;
  }
  int size = n + cnt;
  vector<int> temp(size);
  int i = 0, j = 0;
  while (i < size && j < n)
  {
    if (nums[j] == 0)
    {
      temp[i] = 0;
      temp[i + 1] = 0;
      i += 2;
      j++;
    }
    else
    {
      temp[i] = nums[j];
      i++;
      j++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    nums[i] = temp[i];
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  duplicateZeros(nums);
  for (int i = 0; i < n; i++)
  {
    cout << nums[i] << " ";
  }
  return 0;
}