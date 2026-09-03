// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct

#include <bits/stdc++.h>
using namespace std;

// as we use unordered map so insertion and finding take O(1) in average or O(n)in worst case
// or if we use map then it take O(log(n))
// t.c-O(n*1) for insertion in mpp+O(hashmap size*1)for finding
// s.c-O(hashmap size)
bool containDuplicate(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]]++;
  }
  for (auto it : mpp)
  {
    if (it.second > 1)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt in an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  bool result = containDuplicate(nums);
  cout << "Array contains duplicate or not: " << result << endl;
  return 0;
}