// array is sorted

#include <iostream>
#include <vector>
using namespace std;

// time complexity-O(n)
// space complexity-O(ans.size())
vector<int> searchRange(vector<int> &nums, int target)
{
  int n = nums.size();
  if (n == 0)
    return {-1, -1};
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == target)
    {
      ans.push_back(i);
    }
  }
  // If the target is not found, then ans will be empty, meaning ans.size() == 0.
  // Then, in this line:
  // When ans.size() == 0,
  // ans.size() - 1 == -1.
  // and If ans is empty, ans.size() - 1 = -1,
  // so you are doing ans[-1], which is undefined behavior
  // That’s what triggers the runtime error message:

  // reference binding to null pointer of type 'int'
  // for (int i = 0; i < ans.size() - 1; i++)
  // {
  //   first = ans[i];
  //   last = ans[ans.size() - 1];
  // }

  if (ans.empty())
    return {-1, -1};
  int first = ans.front();
  int last = ans.back();
  return {first, last};
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
  int target;
  cin >> target;

  vector<int> result = searchRange(arr, target);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}