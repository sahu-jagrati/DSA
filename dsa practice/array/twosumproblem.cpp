#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute approach- time complexity- O(n^2) and space complexity-O(1)
void twosum(vector<int> &arr, int target)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    // for (int j = 0; j < n; j++)
    // {
    //   if (i == j)
    //   {
    //     continue;
    //   }
    for (int j = i + 1; j < n; j++) // by using this time complexity also approx. O(n^2) in this case
    {
      if (arr[i] + arr[j] == target)
      {
        cout << arr[i] << " " << arr[j] << endl;

        break;
      }
    }
  }
}
// better approach- hashmap - time complexity-in ordered map - O(nlogn) or in unnordered map-O(n*1) in best and average and O(n*n) in worst case
// space complexity-O(n) if we dump all elt. in map
string twoSum(vector<int> &arr, int target)
{
  map<int, int> mpp;
  for (int i = 0; i < arr.size(); i++)
  {
    int a = arr[i];
    int b = target - a;
    if (mpp.find(b) != mpp.end())
    {
      return "Yes"; // return {mpp[b],i};
    }
    mpp[a] = i;
  }
  return "No";
}

// optimal approach- no map use, two pointer approach it is done in sorted array
// i) variety-1 when we return Yes or No- time complexity - O(n)+O(for sorting) here we use insertion sort so, +O(n^2) in worst case and in average case or in best case +O(n) when arrsy is already sorted
// space complexity-O(1) but if interviewer ask you change array by sorted it then s.c is O(n)

// ii) variety-2 when we want to return index for it this is not optimal approach- we have to use another data strut=cture that store value with index, for this better approach is the optimal one i.e. hashmap
string twoSumProblem(vector<int> &arr, int target)
{
  int n = arr.size();
  int left = 0;
  int right = n - 1;
  for (int i = 0; i < n - 1; i++)
  {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
      int temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
  while (left < right)
  {
    int sum = arr[left] + arr[right];
    if (sum == target)
    {
      return "Yes";
    }
    else if (sum > target)
    {
      right--;
    }
    else
    {
      left++;
    }
  }
  return "No";
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
  twosum(arr, target);
  // string result = twoSum(arr, target);
  string result = twoSumProblem(arr, target);
  cout << result << endl;
  return 0;
}