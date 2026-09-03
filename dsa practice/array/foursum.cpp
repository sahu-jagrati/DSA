// arr[i]+arr[j]+arr[k]+arr[l]=target and i!=j!=k!=l
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// brute solution-time complexity-O(n^4 * (1+O(log (no.of quads)))) where 1 for sort temp and log(no.of quad) is for insert in set
// space complexity-O(no.of quads.)*2 because of set and ans(for returning the answer)
vector<vector<int>> four(vector<int> &arr, int target)
{
  int n = arr.size();
  set<vector<int>> st; // we want unique so we use set
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        for (int l = k + 1; l < n; l++)
        {
          // if (arr[i] + arr[j] + arr[k] + arr[l] == tartget)
          long long sum = arr[i] + arr[j];
          sum = sum + arr[k];
          sum = sum + arr[l];
          if (sum == target)
          {
            vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
            sort(temp.begin(), temp.end());
            st.insert(temp);
          }
        }
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// better solution- we use ordered set-time complexity-O(n^3 * O(log n + log m + log n))=O(n^3 * O(log n + log m)) where m is no. of quads.
// space complexity-O(n)(for hashset)+O(m)*2
// if we use unorederd set for hashset-time complexity-O(n^3 * log m) becasue for hashset it becomes o(1) in average case
vector<vector<int>> foursum(vector<int> &arr, int target)
{
  int n = arr.size();
  set<vector<int>> st;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      set<long long> hashset;
      for (int k = j + 1; k < n; k++)
      {
        long long sum = arr[i] + arr[j];
        sum += arr[k];
        // long long fourth = target - (arr[i] + arr[j] + arr[k]);
        long long fourth = target - sum;
        if (hashset.find(fourth) != hashset.end())
        {
          vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
        hashset.insert(arr[k]);
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// optimal solution- time complexity-O(n^2 * (n for while loop))+ O(n log n)(for sorting)=O(n^3) + O(n log n)
// space complexity-O(no.of quads) for returning the answer not solving the problem
vector<vector<int>> fourSum(vector<int> &arr, int target)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  set<vector<int>> st;
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++)
  {
    if (i > 0 && arr[i] == arr[i - 1])
      continue; // continue means doesn't go down, go to for loop and increase i
    for (int j = i + 1; j < n; j++)
    {
      if (j > i + 1 && arr[j] == arr[j - 1])
        continue;
      int k = j + 1;
      int l = n - 1;
      while (k < l)
      {
        long long sum = arr[i] + arr[j];
        sum += arr[k];
        sum += arr[l];
        if (sum < target)
        {
          k++;
        }
        else if (sum > target)
        {
          l--;
        }
        else
        {
          vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
          ans.push_back(temp); // Its time complexity is O(1) because pushback add new elt at the end of the list
          k++;
          l--;
          while (k < l && arr[k] == arr[k - 1])
            k++;
          while (k < l && arr[l] == arr[l + 1])
            l--;
        }
      }
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
  int target;
  cin >> target;
  // vector<vector<int>> result = four(arr, target);
  // vector<vector<int>> result = foursum(arr, target);
  vector<vector<int>> result = fourSum(arr, target);
  for (const auto it1 : result)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  return 0;
}