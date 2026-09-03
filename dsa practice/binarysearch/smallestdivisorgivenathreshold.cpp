// we want a smallest divisor that on dividing the array element and taking ceil of all quotient and add should be less than equal to threshold
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
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

// brute- range-[1 to max(arr)]
// time complexity-O(max(arr)*n)+n(for maximum)
int smallestDivisor(vector<int> &arr, int threshold)
{
  int n = arr.size();
  if (n > threshold)
    return -1;
  int maxi = maximum(arr);
  for (int divisor = 1; divisor <= maxi; divisor++)
  {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += ceil((double)arr[i] / double(divisor));
    }
    if (sum <= threshold)
      return divisor;
  }
  return -1;
}

// optimize- we have range and we want smallest divisor so we can do elimination
// time complexity-O((log (max(arr))(base 2))*n)+ n(for maximum)
int sum(vector<int> &arr, int divisor)
{
  int n = arr.size();
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += ceil((double)arr[i] / (double)divisor);
  }
  return sum;
}

int SmallestDivisor(vector<int> &arr, int threshold)
{
  int n = arr.size();
  if (n > threshold)
    return -1;
  int low = 1, high = maximum(arr);
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (sum(arr, mid) <= threshold)
      high = mid - 1; // we are looking for smallest so reduce high
    else
      low = mid + 1;
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
  int threshold;
  cin >> threshold;
  // int result = smallestDivisor(arr, threshold);
  int result = SmallestDivisor(arr, threshold);
  cout << result << endl;
  return 0;
}