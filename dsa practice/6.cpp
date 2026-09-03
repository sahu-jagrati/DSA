#include <bits/stdc++.h>
using namespace std;

// array always pass by reference not value
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << endl;
  }
  arr[0] += 100;
  cout << "Value inside function:" << arr[0] << endl;
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
  printArray(arr, n);
  cout << "Value inside main function:" << arr[0] << endl;
  return 0;
}