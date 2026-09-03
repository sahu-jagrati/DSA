// we have to find max.(min. distance between any two consecutive cows) means how we arrange cow so we get this and cows>=2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canBePlace(vector<int> &arr, int distance, int cows)
{
  int n = arr.size();
  int cntcow = 1;          // cow that have to be place
  int coordinate = arr[0]; // that is first cow ideally always place at 0th index
  for (int i = 0; i < n; i++)
  {
    if (arr[i] - coordinate >= distance)
    {
      cntcow++;
      coordinate = arr[i];
    }
  }
  if (cntcow >= cows)
    return true;
  return false;
}
// brute-range-[1 to (max-min)], we use linear search, we take maxi-mini because we have to find distance between two coordinate so, how we take range, please think about it, start with small and then think it can be or should I take to larger than this or not 
// time complexiyt-O(maxi-min)*O(n)+O(nlogn)(for sorting)
int aggressive(vector<int> &arr, int cows)
{
  sort(arr.begin(), arr.end());
  int n = arr.size();
  int maxi = *max_element(arr.begin(), arr.end());
  int mini = *min_element(arr.begin(), arr.end());
  for (int i = 1; i <= (maxi - mini); i++)
  {
    if (canBePlace(arr, i, cows) == true)
      continue;
    else
      return i - 1;
  }
}

// optimize-can we use binary search?
// yes- first we want max
// we have sorted array
// we have range of answer - [1 to (maxi-mini)] we take maxi-mini because we have to dind distance between two coordinate so
// time complexiyt-O(nlogn)(for sorting)+O(log (maxi-mini) (base 2))*O(n)
int aggressiveCows(vector<int> &arr, int cows)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int maxi = *max_element(arr.begin(), arr.end());
  int mini = *min_element(arr.begin(), arr.end());
  int low = 1, high = (maxi - mini); // we already sort the array so we take high=arr[n-1]-arr[0] and low can also we take min of all consecutive distance
  int ans = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (canBePlace(arr, mid, cows) == true)
    {
      ans = mid;
      low = mid + 1; // because we want max
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans; // return high also beacaue high comes from impossible to possible polarity
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
  int cows;
  cin >> cows;
  // int result = aggressive(arr, cows);
  int result = aggressiveCows(arr, cows);
  cout << result << endl;
  return 0;
}