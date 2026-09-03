// You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

//                                                                                               You are also given an integer success.A spell and potion pair is considered successful if the product of their strengths is at least success.

//                                                                                               Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

//                                                                                               Example 1 :

// Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
// Output: [4,0,3]
// Explanation:
// - 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
// - 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
// - 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
// Thus, [4,0,3] is returned.
// Example 2:

// Input: spells = [3,1,2], potions = [8,5,8], success = 16
// Output: [2,0,2]
// Explanation:
// - 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
// - 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful.
// - 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful.
// Thus, [2,0,2] is returned.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// it is correct but it time limit exceed for large array
// time complexity-O(n*m)
// space complexity-O(ans.size())
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
  int n = spells.size();
  int m = potions.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; j < m; j++)
    {
      long long number = (long long)spells[i] * potions[j];
      if (number >= success)
        count++;
    }
    ans.push_back(count);
  }
  return ans;
}

// in this also time limit exceeds for large array
// time complexity-O(n*m)+O(mlogm)(for sorting potions)
// space complexity-O(ans.size())
vector<int> SuccessfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
  int n = spells.size();
  int m = potions.size();
  vector<int> ans;
  sort(potions.begin(), potions.end());
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; j < m; j++)
    {
      long long number = (long long)spells[i] * potions[j];
      if (number >= success)
      {
        count = count + (m - j);
        break;
      }
    }
    ans.push_back(count);
  }
  return ans;
}

// give index such that-arr[index]>=target
int lowerBound(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int ans = n; // if the arr[index] which is >= target not find in array then in that case we return hypothetical arr.size()
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] >= target)
    {
      ans = mid;
      high = mid - 1; // we have to find smallest index so
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

// for optimizing we use lowerbound of binary search because our goal is to find minimum potion strength needed so
// first we sort the potions array
// spell*potion>=success
// potion>=success/spell where potion is integer
// now we have to find smallest integer>=success/spell  that's exactly the ceiling value

// if we use floats-double required=ceil((double)success/spell) it is unsafe because it cause precision error for largde integer

// so we use integer math-ceil(a/b)=(a+b-1)/b
// so required=(success+spell-1)/spell

// time complexity-O(nlogm)+O(mlogm)(for sorting potions)
// space complexity-O(ans.size())
vector<int> Successfulpairs(vector<int> &spells, vector<int> &potions, long long success)
{
  int n = spells.size();
  int m = potions.size();
  vector<int> ans;
  sort(potions.begin(), potions.end());
  for (int i = 0; i < n; i++)
  {
    double required = (success + spells[i] - 1) / spells[i];
    // int index = lowerBound(potions, required);

    auto it = lower_bound(potions.begin(), potions.end(), required);
    int count = potions.end() - it;
    ans.push_back(count);
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> spells(n);
  vector<int> potions(m);
  for (int i = 0; i < n; i++)
  {
    cin >> spells[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> potions[i];
  }
  long long success;
  cin >> success;

  vector<int> result = Successfulpairs(spells, potions, success);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}