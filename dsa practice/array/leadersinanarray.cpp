#include <iostream>
#include <vector>
using namespace std;

// brute approach- time complexity- approx.O(n^2)
// space complexity- is O(1) in solving the problem but in returning answer in worst case space complexity is o(n)
vector<int> leadersinanarray(vector<int> &arr)
{
  vector<int> ans;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    bool leader = true;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] > arr[i])
      {
        leader = false;
        break;
      }
    }
    if (leader == true)
    {
      ans.push_back(arr[i]);
    }
  }
  return ans;
}

// optimal approach- time complexity-O(n) if in question say return in sorted way then in this case time complexity is O(n)+O(nlogn)
// space complexity is O(1) in solving the problem but in returning answer in worst case space complexity is o(n) when all are leaders
vector<int> leadersInAnArray(vector<int> &arr)
{
  int maxi = -2147483648;
  vector<int> ans;
  int n = arr.size();
  for (int i = n - 1; i >= 0; i--)
  {
    if (arr[i] > maxi)
    {
      ans.push_back(arr[i]);
    }
    maxi = max(arr[i], maxi);
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
  // vector<int> result = leadersinanarray(arr);
  vector<int> result = leadersInAnArray(arr);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}