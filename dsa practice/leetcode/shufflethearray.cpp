// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

// Return the array in the form [x1,y1,x2,y2,...,xn,yn].

// Example 1:

// Input: nums = [2,5,1,3,4,7], n = 3
// Output: [2,3,5,4,1,7]
// Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
// Example 2:

// Input: nums = [1,2,3,4,4,3,2,1], n = 4
// Output: [1,4,2,3,3,2,4,1]
// Example 3:

// Input: nums = [1,1,2,2], n = 2
// Output: [1,2,1,2]

// Constraints:

// 1 <= n <= 500
// nums.length == 2n
// 1 <= nums[i] <= 10^3

#include <bits/stdc++.h>
using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
  vector<int> answer(2 * n);
  int i = 0, j = n; // we use two pointer approach
  int k = 0;        // for answer array
  while (j < 2 * n)
  {
    answer[k++] = nums[i];
    answer[k++] = nums[j];
    i++;
    j++;
  }
  return answer;
}
int main()
{
  int n;
  cin >> n;
  int size = 2 * n;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
  {
    cin >> nums[i];
  }
  vector<int> answer = shuffle(nums, n);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  return 0;
}