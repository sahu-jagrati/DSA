// first take minimum and swap with 0th index  then take second minimum and swap it with 1st index and so on
// time complextity is O(n^2) in all cases best,average,worst

#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int miniIndex;
  for (int i = 0; i <= n - 2; i++)
  {
    miniIndex = i;
    for (int j = i; j <= n - 1; j++)
    {
      if (arr[miniIndex] > arr[j])
      {
        miniIndex = j;
      }
      swap(arr[miniIndex], arr[i]);
      // int temp=arr[miniIndex];
      // arr[miniIndex]=arr[i];
      // arr[i]=temp;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << endl;
  }
  return 0;
}