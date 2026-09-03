// return the minimum integer k such that koko can eat all bananas wihthin given h hours. k= banana/hr i.e no. of bananas koko can eat per hour so in h hour she can eat all bananas. array elements are bananas

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

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
int calculateTotalHour(vector<int> &arr, int mid)
{
  int n = arr.size();
  int totalHour = 0;
  for (int i = 0; i < n; i++)
  {
    totalHour += ceil((double)arr[i] / (double)mid); // we convert it in double because we have to find ceil if it give int then we don't find correct ceil
  }
  return totalHour;
}

// brute- time complexity-O(max(arr)*n)+n(for finding maximum)
int minimumRateToEat(vector<int> &arr, int h)
{
  int n = arr.size();
  int maxi = maximum(arr);
  for (int i = 1; i <= maxi; i++)
  { // i denotes k banana/hr
    int totalHour = calculateTotalHour(arr, i);
    if (totalHour <= h)
      return i;
  }
}

// optimize- by using binary search-first find always range
// time complexity-O((log (max(arr)(base 2)))*n)+n(for finding maximum)
int minimumRateToEatBananas(vector<int> &arr, int h)
{
  int maxi = maximum(arr);
  int low = 1, high = maxi;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int totalHour = calculateTotalHour(arr, mid);
    if (totalHour <= h)
    {
      high = mid - 1;
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
  int hour;
  cin >> hour;
  // int result = minimumRateToEatBananas(arr, hour);
  int result = minimumRateToEat(arr, hour);
  cout << result << endl;
  return 0;
}