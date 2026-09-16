#include <bits/stdc++.h>
using namespace std;

// brute force - generate all subarrays
// it run for 992 case from 999 after that it show time limit exceed
long long distantSubarrays(vector<int> &nums, int goal, int k)
{
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    long long sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += nums[j];
      if (abs(sum - goal) >= k)
        ans++;
    }
  }
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
  int goal, k;
  cin >> goal >> k;
  cout << distantSubarrays(nums, goal, k);
  return 0;
}