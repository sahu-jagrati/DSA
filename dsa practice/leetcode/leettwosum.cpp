#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (nums[i] + nums[j] == target)
      {
        return {i, j}; // return the indices of the two numbers imediately
      }
    }
  }
  return {}; // return empty vector if no such pair found
}

int main()
{
  int n;
  cin >> n;
  int target;
  cin >> target;
  vector<int> arr(n);
  vector<int> arr1(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = i + 1; j < arr.size(); j++)
    {
      if (arr[i] + arr[j] == target)
      {
        cout << arr[i] << " " << arr[j] << endl;
        // arr1[i] = arr[i];
        // arr1[j] = arr[j];

        // arr1.push_back(arr[i]);
        // arr1.push_back(arr[j]);
        arr1[i] = i;
        arr1[j] = j;
      }
    }
  }
  for (int i = 0; i < arr1.size(); i++)
  {
    cout << arr1[i] << " "; // this return an array of index of the elements which sum to target
    // cout << endl;
    // if (arr1[i] != 0)
    // {
    //   cout << arr1[i] << " ";
    // }
  }
  cout << endl;
  
  vector<int> store = twoSum(arr, target);
  for (int i : store)
  {
    cout << i << " ";
  }
  return 0;
}