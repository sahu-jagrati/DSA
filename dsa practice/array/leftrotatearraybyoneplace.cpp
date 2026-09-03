#include <iostream>
#include <vector>
using namespace std;

// time complexity is O(n) and space complexity is O(1) because we don't use extra space but
// if someone ask what is space that given in algorithm is O(n) becuase of array 
// but if someone ask what is extra space used then it is O(1) so clear it during interview which space they want
void leftRotateByOnePlace(vector<int> &arr, int n)
{
  int temp = arr[0];
  for (int i = 0; i < n; i++)
  {
    arr[i] = arr[i + 1];
  }
  arr[n - 1] = temp;
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
  leftRotateByOnePlace(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}