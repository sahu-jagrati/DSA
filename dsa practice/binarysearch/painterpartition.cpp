// we have wall of some area and we have array that have area of wall in some part like [10,20 ,30,40] , there were k number of partner they  paint 10 unit area of wall in 10 unit time same 20 unit of area in 20 unit of time and so on
// condition-
// each painter must do work, can't be empty
// area divide in consecutive manner
// same as book allocation question

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numberPainters(vector<int> &arr, int area)
{
  int n = arr.size();
  int countPainter = 1;
  long long areaPaint = 0;
  for (int i = 0; i < n; i++)
  {
    if (areaPaint + arr[i] <= area)
      areaPaint += arr[i];
    else
    {
      countPainter += 1;
      areaPaint = arr[i];
    }
  }
  return countPainter;
}
// brute -linear search-we use answer range-[max(arr) to sum(arr)] they take minimum area=max(arr) and maximum area -sum(arr), we discuss in term of area,it can be also in terms of time
// time coplexity-O(sum-maxi+1)*O(n)+O(n)(for sum loop)
int findLargestMinDistance(vector<int> &arr, int painter)
{
  int n = arr.size();
  if (painter > n)
    return -1;
  int maxi = *max_element(arr.begin(), arr.end());
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }

  for (int i = maxi; i <= sum; i++)
  {
    int numberOfPainter = numberPainters(arr, i);
    if (numberOfPainter == painter)
      return i;
  }
}
// optimize-binary search-why?
// we have to find maximum-minimum
// we have range of answer
// we can do elimination
// time complexity-O(log (sum-maxi+1)(base 2))*O(n)+O(n)(for sum loop)
int findlargestMinDistance(vector<int> &arr, int painter)
{
  int n = arr.size();
  if (painter > n)
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
    if (numberPainters(arr, mid) > painter)
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
  int painter;
  cin >> painter;
  // int result = findLargestMinDistance(arr, painter);
  int result = findlargestMinDistance(arr, painter);
  cout << result << endl;
  return 0;
}