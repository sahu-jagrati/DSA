#include <iostream>
#include <vector>
#include <map>
using namespace std;

int duplicate(vector<int> &arr, int n)
{
  map<int, int> hashmap;
  for (int i = 0; i < n; i++)
  {
    hashmap[arr[i]]++;
  }
  for (auto it : hashmap)
  {
    if (it.second > 1)
    {
      return it.first;
    }
  }
  return -1;
}

// t.c-O(n)
vector<int> allDuplicate(vector<int> &arr, int n)
{
  map<int, int> hashmap;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    hashmap[arr[i]]++;
  }
  for (auto it : hashmap)
  {
    if (it.second > 1)
    {
      ans.push_back(it.first);
    }
  }
  return ans;
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
  int result = duplicate(arr, n);
  cout << result << endl;

  vector<int> answer = allDuplicate(arr, n);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}