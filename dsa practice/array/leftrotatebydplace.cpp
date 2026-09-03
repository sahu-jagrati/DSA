#include <iostream>
#include <vector>
using namespace std;

// brute approach - // time complexity over all is O(n+d) and space complexity is O(d) because we use temporary array of size d
void leftRotateByDplace(int arr[], int n, int d)
{
  d = d % n; // because if we have d greater than size of array then in that case we rotate by their remainder so we don't have to rotate so many times so, we reduce it lesser than 7
  int temp[d];
  for (int i = 0; i < d; i++)
  {
    temp[i] = arr[i]; // here time complexity is O(d)
  }
  for (int i = d; i < n; i++)
  {
    arr[i - d] = arr[i]; // here time complexity is O(n-d)
  }
  for (int i = n - d; i < n; i++)
  {
    arr[i] = temp[i - (n - d)]; // here time complexity is O(d)
  }
}

// optimal approach- time complexity is O(2n) and space complexity is O(1) because there is no extra space use
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
void leftRotate(int arr[], int n, int d)
{
  // there is also predefined reverse function which takes from begining to end-1 but in my it is not define like - reverse(arr,arr+d) i.e from 0 to d-1
  reverse(arr, 0, d - 1); // here time complexity is O(d)

  reverse(arr, d, n - 1); // here time complexity is O(n-d)
  reverse(arr, 0, n - 1); // here time complexity is O(n)
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
  int d; // place from which we rotate
  cin >> d;
  // leftRotateByDplace(arr, n, d);
  leftRotate(arr, n, d);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}