// optimal approach
#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end)
{
  while (start < end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
void rightRotateByDplace(int arr[], int n, int d)
{
  d = d % n; // ensure that d is with in the range-[0 to n] like if arr=[-1] and k=2 then (n<k) so we do this
  reverse(arr, 0, n - d - 1);
  reverse(arr, n - d, n - 1);
  reverse(arr, 0, n - 1);
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int d;
  cin >> d;
  rightRotateByDplace(arr, n, d);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}