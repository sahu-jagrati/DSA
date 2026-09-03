#include <bits/stdc++.h>
using namespace std;

// my solution which has 3 bugs-
// Problems in your code
// 1️⃣ p and q might remain -1

// If the array never switches direction, p or q stay -1, but you still use them in loops → invalid logic.

// for(int i=p;i<n-1;i++) // ❌ p can be -1

// You must check if p and q were found.

// 2️⃣ Direction checks are wrong at boundaries

// You use:

// else if(nums[i] <= nums[i-1])

// But equal values are not allowed at all in trionic arrays.

// So if two adjacent elements are equal → immediately return false.

// 3️⃣ Missing validation that all 3 phases exist

// You never check:

// increasing part exists

// decreasing part exists

// final increasing part exists

// Without this, arrays like [1,2,3] will wrongly return true
bool isTrionic(vector<int> &nums)
{
  int n = nums.size();
  if (n < 3)
    return false;
  int p = -1, q = -1;
  // for increasing part
  for (int i = 1; i < n; i++)
  {
    if (nums[i] > nums[i - 1])
    {
    }
    else if (nums[i] <= nums[i - 1])
    {
      p = i - 1;
      break;
    }
  }
  for (int i = p; i < n - 1; i++)
  {
    if (nums[i] > nums[i + 1])
    {
    }
    else if (nums[i] <= nums[i + 1])
    {
      q = i;
      break;
    }
  }
  for (int i = q + 1; i < n; i++)
  {
    if (nums[i] > nums[i - 1])
    {
    }
    else if (nums[i] <= nums[i - 1])
      return false;
  }
  return true;
}

// my code after solving bugs

bool isTonic(vector<int> &nums)
{
  int n = nums.size();
  if (n < 3)
    return false;
  int p = -1, q = -1;

  for (int i = 1; i < n; i++)
  {
    if (nums[i] == nums[i - 1])
      return false; // no equal consider
    if (nums[i] < nums[i - 1])
    {
      p = i - 1;
      break;
    }
  }
  // we want exactly 3 parts- first part=[0,...,p]
  if (p < 1)
    return false; // must have increasing first
  // 2. decreasing part- [p,...,q]
  for (int i = p + 1; i < n; i++)
  {
    if (nums[i] == nums[i - 1])
      return false;
    if (nums[i] > nums[i - 1])
    {
      q = i - 1;
      break;
    }
  }
  if (q == -1)
    return false; // no final increasing part
  // 3. increasing part-[q,...,n-1]
  for (int i = q + 1; i < n; i++)
  {
    if (nums[i] <= nums[i - 1])
      return false;
  }
  return true; // when we get all three parts
}

// for debugging my code i see chatgpt solution so
bool isTonicArray(vector<int> &nums)
{
  int n = nums.size();
  if (n < 3)
    return false;
  int i = 1;
  // 1. strictly increasing
  while (i < n && nums[i] > nums[i - 1])
    i++;
  if (i == 1 || i == n)
    return false; // because if i=1 no first increasing part or if i=n means no second and third part

  // 2. strictly decreaing
  while (i < n && nums[i] < nums[i - 1])
    i++;
  if (i == n)
    return false; // because we have no third part if i=n

  // 3. final strictly increasing part
  while (i < n && nums[i] > nums[i - 1])
    i++;

  return i == n; // means when we travel whole array means get all 3 parts so true
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
  // bool answer = isTonic(nums);
  bool answer = isTonicArray(nums);
  cout << answer << endl;
  return 0;
}
