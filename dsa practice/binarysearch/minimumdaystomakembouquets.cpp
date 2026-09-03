// array element denote the day when the flower bloom, m is the no. of bouquets, k deonotes the adjacent flower required

// 1      // type: int
// 1L     // type: long
// 1LL    // type: long long
// int n = 100000;
// long long ans = 1LL * n * n;   // avoids overflow of int*n

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// ypu can also use these to find minimum and maximum

// int mini = *min_element(arr.begin(), arr.end());
// int maxi = *max_element(arr.begin(), arr.end());

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
int minimum(vector<int> &arr)
{
  int n = arr.size();
  int mini = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    mini = min(mini, arr[i]);
  }
  return mini;
}

bool possible(vector<int> &arr, int day, int m, int k)
{
  int n = arr.size();
  int count = 0, numberOfBouquetsCanForm = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] <= day)
    {
      count++;
    }
    else
    {
      numberOfBouquetsCanForm += (count / k);
      count = 0;
    }
  }
  numberOfBouquetsCanForm += (count / k);
  if (numberOfBouquetsCanForm >= m)
    return true;
  return false;
}

// brute- time complexity-O((maxi-mini+1)*n)
int minimumDays(vector<int> &arr, int m, int k)
{
  int n = arr.size();
  int mini = minimum(arr);
  int maxi = maximum(arr);

  long long val = m * 1LL * k * 1LL;
  if (n < val)
    return -1;
  for (int i = mini; i <= maxi; i++)
  {
    if (possible(arr, i, m, k) == true)
      return i;
  }
  return -1;
}

// optimal-using binary search - first find always range
// time complexity-O((log (maxi-mini+1) (base 2))*n) +2n(for maximum and minimum)(you can also find maximum and minimum there also)
int minimumDaysToMakeMBouquets(vector<int> &arr, int m, int k)
{
  int n = arr.size();
  // long long val = m * 1LL * k * 1LL;
  long long val = 1LL * m * k;
  if (n < val)
    return -1;
  int ans = -1;
  int low = minimum(arr);
  int high = maximum(arr);
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (possible(arr, mid, m, k) == true)
      ans = mid;
    high = mid - 1;
    else low = mid + 1;
  }
  return ans; // we can also return low 
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
  int m, k;
  cin >> m >> k;
  // int result = minimumDays(arr, m, k);
  int result = minimumDaysToMakeMBouquets(arr, m, k);
  cout << result << endl;
  return 0;
}