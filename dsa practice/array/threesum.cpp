// arr[i]+arr[j]+arr[k]=0 but i!=j!=k i.e index not equal value can be equal but triplets should be unique like[-1,-1,2] only not[2,-1,-1]
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// brute solution-time complexity-O(n3*(1)(for sorting we have three elts each time)*log(no.of triplets)(insertion in ordered set))
// space complexity-
// set<vector<int>>- stores unique triplets-each triplets has 3 integers-in th worst case, all o(n^3) triplets may sum to zero and be unique
// vector<int>temp-constant space each time
// final ans vector-created form the set has the same number of triplets-so uses samp space as st.
// final space complexity-O(n^3)(in worst case, due to storing all valid triplets)

vector<vector<int>> three(vector<int> &arr)
{
  int n = arr.size();
  set<vector<int>> st; // we use set because we can store unique triplets
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        if (arr[i] + arr[j] + arr[k] == 0)
        {
          vector<int> temp = {arr[i], arr[j], arr[k]};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// better solu- we use ordered set for hashset
// n = size of the input array.

// Outer loop runs n times.

// Inner loop runs up to n - i - 1 times ⇒ Total ≈ O(n^2) pairs.

// For each pair:

// hashset.find(...) → O(log n)

// hashset.insert(...) → O(log n)

// Sorting triplet → O(1)

// st.insert(...) → O(log m) (where m is number of unique triplets, at most O(n^2))
// inside the inner loop-O(logn+logn+logm)=O(logn+logm)
// so total time complexity-O(n ^2)⋅O(logn+logm)=O(n ^2 (logn+logm))=O(n^2 log(n.m))=approx.O(n^2 log n)

// space complexity=O(n)+2*O(n^2)=O(n^2) same explanation as in brute only o(n) add beacuse of hashset
vector<vector<int>> threesum(vector<int> &arr)
{
  int n = arr.size();
  set<vector<int>> st;
  for (int i = 0; i < n; i++)
  {
    set<int> hashset;
    for (int j = i + 1; j < n; j++)
    {
      int third = -(arr[i] + arr[j]);
      if (hashset.find(third) != hashset.end())
      {
        vector<int> temp = {arr[i], arr[j], third};
        sort(temp.begin(), temp.end());
        st.insert(temp);
      }
      hashset.insert(arr[j]);
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// optimal approach- time complexity-O(n log n)(for sorting)+O(n*n(for while loop))=O(n log n + n^2)
// space complexity-O(no. of triplets) for returning the answer not solving
vector<vector<int>> threeSum(vector<int> &arr)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++)
  {
    if (i > 0 && arr[i] == arr[i - 1])
      continue; // continue means don't go down, go to for loop and i++
    int j = i + 1;
    int k = n - 1;
    while (j < k)
    {
      int sum = arr[i] + arr[j] + arr[k];
      if (sum < 0)
      {
        j++;
      }
      else if (sum > 0)
      {
        k--;
      }
      else
      {
        vector<int> temp = {arr[i], arr[j], arr[k]};
        ans.push_back(temp); //  Its time complexity is O(1) because pushback add new elt at the end of the list
        j++;
        k--;
        // increase j upto that arr[j] not equla to previous one and same for k
        while (j < k && arr[j] == arr[j - 1])
          j++;
        while (j < k && arr[k] == arr[k + 1])
          k--;
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
  // vector<vector<int>> result = three(arr);
  // vector<vector<int>> result = threesum(arr);
  vector<vector<int>> result = threeSum(arr);
  for (const auto it1 : result)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}