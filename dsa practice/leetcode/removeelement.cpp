#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
  int j = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != val)
    {
      nums[j] = nums[i];
      j++;
    }
  }
  return j;
}

int main()
{
  int n;
  cin >> n;
  int value;
  cin >> value;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int result = removeElement(arr, value);
  cout << result << endl;
  return 0;
}