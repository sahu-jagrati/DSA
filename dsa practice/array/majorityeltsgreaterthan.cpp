// n/3 times
// in case of >n/2 there is only 1 majority elt may be found maximum but in >n/3 2 majority elt may be found maximum
// if question ask return ans in sorted order then use sort method
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute solution-time complexity-O(n^2) and space complexity-in worst case -O(n/3) which is O(2)=O(1) because 2 elts maximum may be found  and in best case O(1)
vector<int> majority(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (ans.size() == 0 || ans[0] != arr[i])
    {
      int count = 0;
      for (int j = 0; j < n; j++)
      {
        if (arr[i] == arr[j])
        {
          count++;
        }
      }
      if (count > (n / 3))
      {
        ans.push_back(arr[i]);
      }
    }
    if (ans.size() == n / 3)
    {
      break;
    }
  }
  return ans;
}
// better solution-
vector<int> Majority(vector<int> &arr)
{
  int n = arr.size();
  map<int, int> mpp;
  vector<int> ans;
  // for (int i = 0; i < n; i++)
  // {
  //   mpp[arr[i]]++;
  // }
  // for (auto it : mpp)
  // {
  //   if (it.second > (n / 3))
  //   {
  //     ans.push_back(it.first);
  //   }
  // }

  // ii) way - time complexity-O(n)+O(logn (in case of ordered map)) or O(n*1(in case of best case of unordered map)) or O(n*n(in worst case of unordered map)) + sorting complexity O(NlogN where N is ans size)(which doesn't effect because for sorting n=2 )
  // space complexity - in worst case if all elements exist one time than O(n)
  // we add +1 because we want greater than n/3 and in check we compare with == sign not > than sign
  int mini = (int)(n / 3) + 1;
  for (int i = 0; i < n; i++)
  {
    mpp[arr[i]]++;
    if (mpp[arr[i]] == mini)
    {
      ans.push_back(arr[i]);
    }
    // ans size can never be greater than 2 you can see it by taking example
    if (ans.size() == 2)
    {
      break;
    }
  }
  sort(ans.begin(), ans.end());

  return ans;
}

// optimal solution- Moore's voting algorithm but in some differnet approach because here 2 maximum elt may be found so we use same for 2 elts
// time complexity-O(n)+O(n)+O(sorting complexity)
// space complexity-O(n/3)=O(2)=O(1) 2 because 2 elts maximum may be found
vector<int> majorityElement(vector<int> &arr)
{
  int n = arr.size();
  int elt1, elt2;
  int count1 = 0, count2 = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (count1 == 0 && arr[i] != elt2) // because if this is not then both cann't count in proper way
    {
      count1 = 1;
      elt1 = arr[i];
    }
    else if (count2 == 0 && arr[i] != elt2)
    {
      count2 = 1;
      elt2 = arr[i];
    }
    else if (elt1 == arr[i])
    {
      count1++;
    }
    else if (elt2 == arr[i])
    {
      count2++;
    }
    else
    {
      count1--;
      count2--;
    }
  }
  // now check that  the value of elt1 and elt2 we get  is present  greater than n/3 times or not
  int count3 = 0, count4 = 0;
  for (int i = 0; i < n; i++)
  {
    if (elt1 == arr[i])
    {
      count3++;
    }
    if (elt2 == arr[i])
    {
      count4++;
    }
  }
  if (count3 > (n / 3))
  {
    ans.push_back(elt1);
  }
  if (count4 > (n / 3))
  {
    ans.push_back(elt2);
  }
  sort(ans.begin(), ans.end());
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
  // vector<int> result = majority(arr);
  // vector<int> result = Majority(arr);
  vector<int> result = majorityElement(arr);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}