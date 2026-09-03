// opposite to selection sort
// push the maximum to the last by adjacent swaps
// time complexity is O(n^2) in worst and average case
// in best case it is O(n) when array is already sorted, we don't have to go through all the i's

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
  for (int i = n - 1; i >= 1; i--)
  {
    int didswap = 0; // to check if any swap is done or not for best case
    // if no swap is done then array is already sorted and we can break the loop
    for (int j = 0; j < i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        didswap = 1; // swap is done
      }
    }
    if (didswap == 0)
      break;

    cout << "runs!" << endl;  // it decide how many times the outer loop runs if we put same element twice or more than once then it will runs  for n-1 times for example we have 5 elements and i put 1 two times then it will run 4 times because it will not swap the 1 with itself
  }
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << endl;
  }
  return 0;
}