#include <iostream>
#include <vector>
using namespace std;

// t.c=O(n)
// s.c=O(1)
bool linearSearch(vector<int> &arr, int target)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
      return true;
  }
  return false;
}

int recursive(vector<int> &arr, int target, int n, int index = 0)
{
  if (n == index)
    return -1;
  if (arr[index] == target)
    return index;
  return recursive(arr, target, n, index + 1);
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
  int target;
  cin >> target;

  bool result = linearSearch(arr, target);
  cout << result << endl;

  int answer = recursive(arr, target, n);
  cout << answer << endl;
  return 0;
}