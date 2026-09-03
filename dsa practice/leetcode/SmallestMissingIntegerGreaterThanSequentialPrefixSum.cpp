// You are given a 0-indexed array of integers nums.

// A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.

// Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

// Example 1:

// Input: nums = [1,2,3,2,5]
// Output: 6
// Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
// Example 2:

// Input: nums = [3,4,5,1,12,14,13]
// Output: 15
// Explanation: The longest sequential prefix of nums is [3,4,5] with a sum of 12. 12, 13, and 14 belong to the array while 15 does not. Therefore 15 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.

// Constraints:

// 1 <= nums.length <= 50
// 1 <= nums[i] <= 50

#include <bits/stdc++.h>
using namespace std;

// we want the prefis sequential  so it is fix that we have to start from index 0 if for next index it fulfill the given condition : A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1 then good otherwise only of nums[0] is  prefix sequential
// now we want only sum of longest sequential prefix so we run a loop from index 1 to n because for index =0 we know it is sequential prefix now we have to check from index 1 it can be a part of or not when we get the condition is not fulfill then we stop and we have the sum now we have to check that for that sum there exist the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix. so for that we use set because in given array the number are not unique so we store all value in set so we store them uniquely after that we know answer can be sum if it is not in nums or if sum is present in nums then answer can be sum+=1 or increasing it by 1 until it does not present in given array, we increase by 1 because we want smallest integer x which is missing from nums and it is greater than or equal to sum of longest sequential prefix.

// t.c-O(n)(for sum in worst case)+O(n*1)(for insert in set, we use unordered set so in average it takes O(1) to insert each elt)+O(st.size)(for getting ans in worst case)
// s.c-O(st.size)
int missingInteger(vector<int> &nums)
{
  int n = nums.size();
  int sum = nums[0];
  for (int i = 1; i < n; i++)
  {
    if (nums[i] != nums[i - 1] + 1)
      break;
    sum += nums[i];
  }
  int ans = sum;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
  {
    st.insert(nums[i]);
  }
  while (st.count(sum))
  {
    ans = sum;
    // increase by 1 because we want smallest integer x which is missing from nums and it is greater than or equal to sum of longest sequential prefix. so jaise hi aesa sum ka value mila jo nums me present nhi hai so we return
    sum += 1;
  }
  // we check for last sum+=1 because we know for last above loop cannot run because it may be not fulfill the condition of loop so
  if (st.count(ans))
    ans = ans + 1;
  return ans;
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
  cout << missingInteger(nums);
  return 0;
}