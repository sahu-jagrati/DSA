//  count number of subarray with XOR as k
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute- time complexity - approx.O(n^3) and space complexity -O(1)
int subarray(vector<int> &arr, int target)
{
  int n = arr.size();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int XOR = 0;
      for (int k = i; k <= j; k++)
      {
        XOR ^= arr[k];
      }
      if (XOR == target)
      {
        count++;
      }
    }
  }
  return count;
}

// better-time complexity-approx.O(n^2) and space complexity-O(1)
int countsubarray(vector<int> &arr, int target)
{
  int n = arr.size();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int XOR = 0;
    for (int j = i; j < n; j++)
    {
      XOR = XOR ^ arr[j];
      if (XOR == target)
      {
        count++;
      }
    }
  }
  return count;
}

// optimal- preXOR-
// time complexity-we use ordered map so O(nlog n) and in case of unorederd map O(n) in average
// space complexity-O(n) in worst case when all xr is unique

int countSubarray(vector<int> &arr, int target)
{
  int n = arr.size();
  int xr = 0;
  map<int, int> mpp;
  mpp[xr]++; //(0,1) have to initially store always
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    xr = xr ^ arr[i];
    int previousoccurence = xr ^ target;
    count += mpp[previousoccurence];
    mpp[xr]++;
  }
  return count;
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
  // int result = subarray(arr, target);
  // int result = countsubarray(arr, target);
  int result = countSubarray(arr, target);
  cout << result << endl;
  return 0;
}
