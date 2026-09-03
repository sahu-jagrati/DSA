#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// t.c=O(n^2)
// s.c=O(1)
void sum(vector<int> &arr, int n, int x)
{

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] + arr[j] == x)
      {
        cout << arr[i] << " " << arr[j] << endl;
      }
    }
  }
}
// by hashmap
// t.c-in ordered map - O(nlogn) or in unnordered map-O(n*1) in best and average and O(n*n) in worst case
// space complexity-O(n) if we dump all elt. in map
bool Sum(vector<int> &arr, int n, int x)
{
  map<int, int> hashmap;
  for (int i = 0; i < n; i++)
  {
    int a = arr[i];
    int b = x - a;
    if (hashmap.find(b) != hashmap.end())
    {
      return true;
    }
    hashmap[a];
  }
  return false;
}
// t.c=O(n) if we don't consider sort time otherwise t.c=O(nlogn)+O(n)=O(nlogn)
// s.c=O(1)
vector<int> twoSum(vector<int> &arr, int n, int x)
{
  sort(arr.begin(), arr.end());
  int i = 0, j = n - 1;
  while (i < j)
  {
    if (arr[i] + arr[j] == x)
      return {arr[i], arr[j]};
    else if (arr[i] + arr[j] > x)
      j--;
    else
      i++;
  }
  return {-1, -1};
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
  int x;
  cin >> x;

  vector<int> result = twoSum(arr, n, x);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  sum(arr, n, x);
  bool answer = Sum(arr, n, x);
  cout << answer << endl;
  return 0;
}