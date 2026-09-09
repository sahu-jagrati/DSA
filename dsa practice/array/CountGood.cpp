#include <bits/stdc++.h>
using namespace std;

int countGoodRotations(vector<int> &nums)
{
  int n = nums.size();
  int firstHalf = 0, secondHalf = 0;
  int i = 0, j = n - 1;
  while (i < j)
  {
    firstHalf += nums[i];
    secondHalf += nums[j];
    i++;
    j--;
  }
  cout << firstHalf << " " << secondHalf << endl;
  int ans = 0;
  vector<int> prefix(n);
  vector<int> suffix(n);
  prefix[0] = firstHalf;
  suffix[0] = secondHalf;
  if (firstHalf > secondHalf)
    ans += 1;

  i = 1, j = ((i - 1) + n / 2) % n;
  while (i < n)
  {
    prefix[i] = prefix[i - 1] - nums[i - 1] + nums[j];
    suffix[i] = suffix[i - 1] - nums[j] + nums[i - 1];
    if (prefix[i] > suffix[i])
      ans += 1;
    i++;
    j = ((i - 1) + n / 2) % n;
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
  cout << countGoodRotations(nums);
  return 0;
}