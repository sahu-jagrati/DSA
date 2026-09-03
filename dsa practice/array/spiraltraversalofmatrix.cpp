#include <iostream>
#include <vector>
using namespace std;

// time complexity-the outer while loop and all for loops combined visit each elt. exactly once so, total element i s n*m hence, time complexity is O(n*m)
// space complexity -O(n*m) for storing the answer
vector<int> spiralTraversalOfMatrix(vector<vector<int>> &arr)
{
  int n = arr.size();
  int m = arr[0].size();
  int left = 0, right = m - 1;
  int top = 0, bottom = n - 1;
  vector<int> ans;
  while (top <= bottom && left <= right)
  {
    for (int i = left; i <= right; i++)
    {
      ans.push_back(arr[top][i]);
    }
    top++;
    for (int i = top; i <= bottom; i++)
    {
      ans.push_back(arr[i][right]);
    }
    right--;
    if (top <= bottom)
    {
      for (int i = right; i >= left; i--)
      {
        ans.push_back(arr[bottom][i]);
      }
      bottom--;
    }
    if (left <= right)
    {
      for (int i = bottom; i >= top; i--)
      {
        ans.push_back(arr[i][left]);
      }
      left++;
    }
  }
  return ans;
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  vector<int> result = spiralTraversalOfMatrix(arr);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}