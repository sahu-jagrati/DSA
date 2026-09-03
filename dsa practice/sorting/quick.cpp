// time complexity is O(nlogn) when pivot is first element, logn because we divide array in to two halves but not in equal and n because of pivotcorrectposition function we go n times
// space complexity is O(1) because we does not have any temporary array
// it is divide and conquer

// time complexity is O(n^2) if we choose largest or smallest element as the pivot

#include <iostream>
#include <vector>
using namespace std;

int pivotCorrectPosition(vector<int> &arr, int low, int high)
{
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (i < j)
  {
    while ((arr[i] <= pivot) && (i <= high - 1))
    {
      i++;
    }
    while ((arr[j] > pivot) && (j >= low + 1))
    {
      j--;
    }
    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[low], arr[j]); // when j crosses i then immediate swap pivot with i
  return j;
}
void quickSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int partionIndex = pivotCorrectPosition(arr, low, high);
    quickSort(arr, low, partionIndex - 1);
    quickSort(arr, partionIndex + 1, high);
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
  quickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}
