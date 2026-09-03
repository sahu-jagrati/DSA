#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// t.c=O(n)
int maximum(vector<int> &arr, int n)
{
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > maxi)
      maxi = arr[i];
  }
  return maxi;
}

// by divide and conquer-t.c-O(n)
int maxim(vector<int> &arr, int left, int right)
{
  if (left == right)
    return arr[left]; // base case only one elt

  // base case two elts
  if (right - left == 1)
    return (arr[left] > arr[right]) ? arr[left] : arr[right];

  // divide array into two halves
  int mid = left + (right - left) / 2;
  int maxLeft = maxim(arr, left, mid);
  int maxRight = maxim(arr, mid + 1, right);

  return (maxLeft > maxRight) ? maxLeft : maxRight;
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
  // int result = maximum(arr, n);
  int result = maxim(arr, 0, n - 1);
  cout << result << endl;
  return 0;
}