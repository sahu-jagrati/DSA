#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute solution- time complexity-O(n log n) for sorting and if we think for for loop it is O(n^2) then it is not because there is continue and break also so if we seee proper then for each we have run two times  for example- {(1,3) (8,9) (2,4) (2,6) (8,10) (9,11) (15,18) (16,17)} -like (1,3)- (2,4)&(2,6) and (8,9)-(8,10)&(8,11) and so on
// so time complexity is O(nlog n + 2n)
// space complexity-O(n) in worst case if none of them are overlapping
vector<vector<int>> mergeoverlapping(vector<vector<int>> &arr)
{
  int n = arr.size(); // gives row size
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++)
  {
    int start = arr[i][0];
    int end = arr[i][1];
    if (!ans.empty() && end <= ans.back()[1])
    {
      continue;
    }
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j][0] <= end)
      {
        end = max(end, arr[j][1]);
      }
      else
      {
        break;
      }
    }
    ans.push_back({start, end});
  }
  return ans;
}

// optimal- time complexity-O(n log n + n)
// space complexity-O(n) in worst case
vector<vector<int>> mergeOverlapping(vector<vector<int>> &arr)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++)
  {
    if (ans.empty() || arr[i][0] > ans.back()[1])
    {
      ans.push_back(arr[i]);
    }
    else
    {
      ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr(n, (vector<int>(2)));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> arr[i][j];
    }
  }
  // vector<vector<int>> result = mergeoverlapping(arr);
  vector<vector<int>> result = mergeOverlapping(arr);
  for (const auto it1 : result)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << " ";
  }
  cout << endl;
  return 0;
}