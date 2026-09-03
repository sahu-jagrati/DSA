#include <bits/stdc++.h>
using namespace std;

// brute force-
vector<int> countNumber(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; j < n; j++)
    {
      if (nums[j] < nums[i])
        count++;
    }
    ans.push_back(count);
  }
  return ans;
}

// solution-2
//  t.c-O(N^2)
//  s.c-O(N)(for map)ans ans we don't take ans space because it only store answer not solve problem

// but using here map is unnecessay, it is done by count also
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> mpp;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]] = 0; // reset key value if there is repeated elt in array like {8,1,2,2,4} so,ans={4,0,1,1,3}
    for (int j = 0; j < n; j++)
    {
      // if (j != i && nums[i] > nums[j]) // j!=i not required because we already check nums[i]>nums[j] so not take equal value
      if (nums[j] < nums[i])
      {
        mpp[nums[i]]++;
      }
    }
    ans.push_back(mpp[nums[i]]);
  }
  return ans;
}

// optimized solution- by hashmap
// we use temp because we don't modify input array
// t.c-O(nlog(n))
// s.c-O(n)(temp array) ans ans we don't take ans space because it only store answer not solve problem
vector<int> countSmallerNumber(vector<int> &nums)
{
  int n = nums.size();
  vector<int> temp = nums;
  sort(temp.begin(), temp.end());
  unordered_map<int, int> mpp;

  for (int i = 0; i < temp.size(); i++)
  {
    // we do this because we want smaller for each elt so when  they repeated they already find so not take again
    if (mpp.find(temp[i]) == mpp.end())
    {
      mpp[temp[i]] = i; // because we have sorted so by index we count smaller numbers
    }
  }
  vector<int> ans;
  for (auto it : nums)
  {
    ans.push_back(mpp[it]);
  }
  return ans;
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
  // vector<int> result = smallerNumbersThanCurrent(nums);
  // vector<int> result = countNumber(nums);
  vector<int> result = countSmallerNumber(nums);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}