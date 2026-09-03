// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

// now the houses are arranged in circular way means now house[0] and house[n-1] are also adjacent not rob together at a night.

// Since House[0] and House[n-1] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[0]-House[n-2] or House[1]-House[n-1], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.

// like this is the problem like of start at index 0 to (n-2) or start at index 1 to (n-1) which gives more money

// so we do already do House Robber problem so there is no need to change logic only change here is the house array means which part i have to take so we use same logic here also and
// answer is max(for index 0 include,for index last include )

// we use space optimization solution here, for rest memoization or tabulation solution see in House Robber problem and you can use them also

// t.c-O(n)
// s.c-O(1)

int maximumMoney(vector<int> &nums)
{
  int n = nums.size();
  int prev = nums[0];
  int prev2 = 0;
  for (int i = 0; i < n; i++)
  {
    int pick = nums[i];
    if (i > 1)
      pick += prev2;

    int notpick = 0 + prev;

    int curr = max(pick, notpick);
    prev2 = prev;
    prev = curr;
  }
  return prev;
}

int rob(vector<int> &house)
{
  int m = house.size();
  // there is an edge case if house array has only 1 elt then it is the only
  if (m == 1)
    return house[0];
  // we make two temp arrays
  // temp1-index 0 to m-2
  // temp2- index 1 to n-1
  vector<int> temp1, temp2;
  for (int i = 0; i < m; i++)
  {
    if (i != m - 1)
      temp1.push_back(house[i]);
    if (i != 0)
      temp2.push_back(house[i]);
  }
  return max(maximumMoney(temp1), maximumMoney(temp2));
}

int main()
{
  int m;
  cin >> m;
  vector<int> house(m);
  for (int i = 0; i < m; i++)
  {
    cin >> house[i];
  }
  cout << rob(house);
  return 0;
}