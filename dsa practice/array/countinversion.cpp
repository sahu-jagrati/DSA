// count inversion like - find no. of pairs from the array in which i<j &&  arr[i]>arr[j]

// distorted array-refers to an array that has been altered or changed from its expected or original form.Any array that is not in its correct or expected form — either structurally, numerically, or logically
#include <iostream>
#include <vector>
using namespace std;

// brute solution-time complexity- approx.O(n^2) and space complexity-O(1)
int countInversion(vector<int> &arr)
{
  int n = arr.size();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] > arr[j])
      {
        count++;
      }
    }
  }
  return count;
}
// optimal solution-time complexity-O(n logn) and space complexity-O(n) for temporary array see in question clearly because here we change the original array because it is distorted array if you didn't want to change the array you can make the copy the array so mention in interviews, that we do problem with altering the distorted array or by not altering the array
// int cnt=0; // in interviews this is not good
int merge(vector<int> &arr, int low, int mid, int high)
{
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  int cnt = 0;
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      cnt += (mid - left + 1); // because all remaining in the left are inversions
      right++;
    }
  }
  while (left <= mid)
  {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high)
  {
    temp.push_back(arr[right]);
    right++;
  }
  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
  return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
  int cnt = 0;
  if (low >= high)
    return cnt;
  int mid = (low + high) / 2;
  cnt += mergeSort(arr, low, mid);
  cnt += mergeSort(arr, mid + 1, high);
  cnt += merge(arr, low, mid, high);
  return cnt;
}
int countinversion(vector<int> &arr)
{
  int n = arr.size();
  int res = mergeSort(arr, 0, n - 1);

  return res;
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
  // int result = countInversion(arr);
  int result = countinversion(arr);
  cout << result << endl;
  return 0;
}