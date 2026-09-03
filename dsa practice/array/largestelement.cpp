#include <iostream>
#include <vector>
using namespace std;

// for sorted array, largest=arr[n-1] whose time complexity is depend on which sorting technique you used, generally time complexity is O(nlogN) and space complexity is O(1) for no stacking which is a brute approach

int largestElement(vector<int> &arr, int n)
{
  // for unsorted array, time complexity is O(n) which is better than O(nlogn), it is a optimal approach
  int largest = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (largest < arr[i])
    {
      largest = arr[i];
    }
  }
  return largest;
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
  int result = largestElement(arr, n);
  cout << result << endl;
  return 0;
}