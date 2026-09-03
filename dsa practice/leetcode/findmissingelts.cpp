// You are given an integer array nums consisting of unique integers.

// Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.

// The smallest and largest integers of the original range are still present in nums.

// Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

// Example 1:

// Input: nums = [1,4,2,5]

// Output: [3]

// Explanation:

// The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.

// Example 2:

// Input: nums = [7,8,6,9]

// Output: []

// Explanation:

// The smallest integer is 6 and the largest is 9, so the full range is [6,7,8,9]. All integers are already present, so no integer is missing.

// Example 3:

// Input: nums = [5,1]

// Output: [2,3,4]

// Explanation:

// The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.

// Constraints:

// 2 <= nums.length <= 100
// 1 <= nums[i] <= 100

#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingElts(vector<int> &nums)
{
  int n = nums.size();
  // sort(nums.begin(), nums.end());
  // int smallest = nums[0];
  // int largest = nums[n - 1];

  // also like
  int smallest = INT_MAX;
  int largest = INT_MIN;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
  {
    st.insert(nums[i]);
    if (nums[i] < smallest)
      smallest = nums[i];
    if (nums[i] > largest)
      largest = nums[i];
  }
  vector<int> answer;
  // range is [smallest,largest] and both smallest and largest are present in the array so search btw them
  for (int i = smallest + 1; i < largest; i++)
  {
    if (!st.count(i))
      answer.push_back(i);
  }
  return answer;
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
  vector<int> answer = findMissingElts(nums);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  return 0;
}