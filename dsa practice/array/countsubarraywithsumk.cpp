#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute approach- when using three for loops time complexity is approx.O(n^3)
// space complexity is O(1)
int countsubarraywithsumk(vector<int> &arr, int target)
{
  int n = arr.size();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      long long sum = 0;
      for (int k = i; k <= j; k++)
      {
        sum += arr[k];
      }
      if (sum == target)
      {
        count++;
      }
    }
  }
  return count;
}

// better approach- time complexity is approx.O(n^2)
// space complexity is O(1)
int countSubarraywithsumk(vector<int> &arr, int target)
{
  int n = arr.size();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    long long sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += arr[j];

      if (sum == target)
      {
        count++;
      }
    }
  }
  return count;
}

// optimal approach-prefix sum-
// time complexity- if we use ordered map then in insertion / deletion takes O(logn) so, here in each iteration there is insertion or deletion = O(logn) and n iterations total- so time complexity is O(nlogn)
// if we use unordered map then in best/average-insertion/deletion-O(1)so, time complexity is O(n*1) and in worst case O(n*n)
// space complexity - in worst case if each prefix sum is unique then we storing n entries in mpp so, space complexity is -O(n)
int countSubarrayWithSumK(vector<int> &arr, int target)
{
  int n = arr.size();
  map<int, int> mpp;
  int count = 0;
  long preSum = 0;
  mpp[0] = 1; //(0,1) initially store always as sum =0 with cnt=1
  for (int i = 0; i < n; i++)
  {
    preSum += arr[i];
    int remove = preSum - target;
    count += mpp[remove];
    mpp[preSum] += 1;
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
  // int result = countsubarraywithsumk(arr, target);
  // int result = countSubarraywithsumk(arr, target);
  int result = countSubarrayWithSumK(arr, target);
  cout << result << endl;
  return 0;
}