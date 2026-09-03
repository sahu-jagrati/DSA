// we have d days within these days we have to ship all the weights like wt[]={1,2,3,4,5,6,7,8,9,10} these are weights, ship leave once a day with limited capacity, so we have to found that least capacity which the ship leaves per day and carry all the weights in d days
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// brute- capacity range-[max(arr) to sum of arr[i]]
// time complexity-O((sum-max(arr)+1)*n)+2n(for max(arr) and sum loop))
int maximum(vector<int> &arr)
{
  int n = arr.size();
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, arr[i]);
  }
  return maxi;
}
int numberOfDaysTake(vector<int> &arr, int capacity)
{
  int n = arr.size();
  int day = 1, load = 0;
  for (int i = 0; i < n; i++)
  {
    if (load + arr[i] > capacity)
    {
      day = day + 1;
      load = arr[i];
    }
    // if load is smaller than capacity than
    else
    {
      load += arr[i];
    }
  }
  return day;
}
int leastCapacity(vector<int> &arr, int days)
{
  int n = arr.size();
  int maxi = maximum(arr);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  for (int capacity = maxi; capacity <= sum; capacity++)
  {
    int daysRequired = numberOfDaysTake(arr, capacity);
    if (daysRequired <= days)
      return capacity;
  }
  return -1;
}

// optimize-we have capacity range- max(arr) to sum of arr[i]] and we can do elimination
// time complexity-O((log (sum-max(arr)+1) (base 2))*n)+ 2n(for max(arr) function and sum loop)
int LeastCapacity(vector<int> &arr, int days)
{
  int n = arr.size();
  int low = maximum(arr);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  int high = sum;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int daysRequired = numberOfDaysTake(arr, mid);
    if (daysRequired <= days)
    {
      high = mid - 1; // we wnat least capacity
    }
    else
    {
      low = mid + 1;
    }
  }
  return low;
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
  int days;
  cin >> days;
  // int result = leastCapacity(arr, days);
  int result = LeastCapacity(arr, days);
  cout << result << endl;
  return 0;
}