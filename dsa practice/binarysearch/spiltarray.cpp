// spilt array into k subarray  such that the max subarray sum is minimum
// same as book allocation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numberSpilt(vector<int> &arr, int sum)
{
  int n = arr.size();
  int countSpilt = 1;
  long long totalsum = 0;
  for (int i = 0; i < n; i++)
  {
    if (totalsum + arr[i] <= sum)
      totalsum += arr[i];
    else
    {
      countSpilt += 1;
      totalsum = arr[i];
    }
  }
  return countSpilt;
}
// brute -linear search-we use answer range-[max(arr) to sum(arr)] they take minimum sum=max(arr) and maximum sum -sum(arr), we discuss in term of area,it can be also in terms of time
// time coplexity-O(sum-maxi+1)*O(n)+O(n)(for sum loop)
int findLargestMinsum(vector<int> &arr, int spilt)
{
  int n = arr.size();
  if (spilt > n)
    return -1;
  int maxi = *max_element(arr.begin(), arr.end());
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }

  for (int i = maxi; i <= sum; i++)
  {
    int numberOfspilt = numberSpilt(arr, i);
    if (numberOfspilt == spilt)
      return i;
  }
}
// optimize-binary search-why?
// we have to find maximum-minimum
// we have range of answer
// we can do elimination
// time complexity-O(log (sum-maxi+1)(base 2))*O(n)+O(n)(for sum loop)
int findlargestMinSum(vector<int> &arr, int spilt)
{
  int n = arr.size();
  if (spilt > n)
    return -1;
  int low = *max_element(arr.begin(), arr.end());
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  int high = sum;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (numberSpilt(arr, mid) > spilt)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low; // because low go from non-possible to possible polarity
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
  int spilt;
  cin >> spilt;
  // int result = findLargestMinsum(arr, spilt);
  int result = findlargestMinSum(arr, spilt);
  cout << result << endl;
  return 0;
}