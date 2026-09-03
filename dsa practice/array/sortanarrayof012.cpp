#include <iostream>
#include <vector>
using namespace std;

// better approach-by using any sorting technique- like merge sort - time complexity-O(nlogn) and space complexity -O(n) because of temporary array

// better approach- time complexity-O(n)+O(n) and space complexity -O(1)
void sortAnArray(vector<int> &arr)
{
  int n = arr.size();
  int count0 = 0, count1 = 0, count2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      count0++;
    }
    else if (arr[i] == 1)
    {
      count1++;
    }
    else
    {
      count2++;
    }
  }
  for (int i = 0; i < count0; i++)
  {
    arr[i] = 0;
  }
  for (int i = count0; i < count0 + count1; i++)
  {
    arr[i] = 1;
  }
  for (int i = count0 + count1; i < n; i++)
  {
    arr[i] = 2;
  }
}

// optimal approach- DNF (Dutch National Flag ) Algorithm- 3's rules- low,mid,high
// [0,---,low-1]=0 - extreme left
// [low,---,mid-1]=1
// [high+1,---,n-1]=2 - extreme right
// [mid,----,high]=0/1/2 in unsorted way
// time complexity-O(n)
// space complexity-O(1)
void sortanarray(vector<int> &arr)
{
  int n = arr.size();
  int low = 0;
  int mid = 0;
  int high = n - 1;
  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[mid], arr[low]);
      low++;
      mid++;
    }
    if (arr[mid] == 1)
    {
      mid++;
    }
    if (arr[mid] == 2)
    {
      swap(arr[mid], arr[high]);
      high--;
    }
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
  // sortAnArray(arr);
  sortanarray(arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}