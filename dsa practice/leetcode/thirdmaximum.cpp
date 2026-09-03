#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// time complexity-O(n)
// space complexity-O(1)
int thirdMax(vector<int> &nums)
{
  int n = nums.size();
  long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == first || nums[i] == second || nums[i] == third)
      continue; // for duplicates
    else if (nums[i] > first)
    {
      third = second;
      second = first;
      first = nums[i];
    }
    else if (nums[i] > second)
    {
      third = second;
      second = nums[i];
    }
    else if (nums[i] > third)
    {
      third = nums[i];
    }
  }
  if (third == LONG_MIN)
    return first;
  return third;
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
  int result = thirdMax(arr);
  cout << result << endl;
  return 0;
}