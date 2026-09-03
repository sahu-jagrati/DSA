// in this we use divide and merge technique
// we divide array into half and then further divide and so on, so this is like recursion backtracking by recursion we don't have to make another array again and again

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
  // [low...mid] and [mid+1...high]
  int left = low;
  int right = mid + 1;
  // temporary array
  vector<int> temp;
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
  // copy temp to arr
  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}
void mergeSort(vector<int> &arr, int low, int high)
{
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}
void printArray(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
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
  mergeSort(arr, 0, n - 1);
  printArray(arr);
  return 0;
}

// time complexity is O(nlogn)with base 2 in all cases(best,average,worst) because we divide array in two equal halves
// space complexity is O(n) because of temporary array