#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// brute approach-time complexity-O(n)*O(n) = approx.O(n^2)
// space complexity-O(1)
bool linearSearch(vector<int> &arr, int num)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if (num == arr[i])
    {
      return true;
    }
  }
  return false;
}
int longestconsecutivesequence(vector<int> &arr)
{
  int n = arr.size();
  int longest = 1;
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int x = arr[i];
    count = 1;
    while (linearSearch(arr, x + 1) == true)
    {
      x = x + 1;
      count = count + 1;
    }
    longest = max(longest, count);
  }
  return longest;
}

// better approach- time complexity-O(n)+for sorting O(n^2), here for sorting you can use better merge sort then for sorting time complexity -O(nlogn)
// space complexity-O(1)
int longestconsecutive(vector<int> &arr)
{
  int n = arr.size();
  int longest = 1;
  int lastSmaller = -2147483648;
  int currCount = 0;
  // sort the array - we use here insertion sort-O(n^2)
  for (int i = 0; i < n; i++)
  {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
      int temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (arr[i] - 1 == lastSmaller)
    {
      currCount = currCount + 1;
      lastSmaller = arr[i];
    }
    else if (arr[i] != lastSmaller)
    {
      currCount = 1;
      lastSmaller = arr[i];
    }
    longest = max(longest, currCount);
  }
  return longest;
}

// optimal approach- in unordered set in best and average case for insertion time complexity is O(n*1) for inserting n elements or in worst case O(n*n) for inserting n elements so when we take best case for insertion t.c is O(n) and in second loop we iterate so O(n) and in while loop if we correctly see total iteration we do 7+3+4=14 = 2n when we take array  = [102,4,100,1,101,3,2,1,1] so, set size is 7 so, 7+3+4 iteration in while loop 7 for all , 3 for (100,101,102) and 4 for(1,2,3,4)
// time complexity in best case is O(n)+O(2n)=O(n)
// space complexity-O(n) assuming all elements are unique
int longestConsecutiveSequence(vector<int> &arr)
{
  int n = arr.size();
  int count = 0;
  int longest = 1;
  if (n == 0)
    return 0;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
  {
    st.insert(arr[i]);
  }
  for (auto it : st)
  {
    if (st.find(it - 1) == st.end())
    {
      int count = 1;
      int x = it;
      while (st.find(x + 1) != st.end())
      {
        x = x + 1;
        count = count + 1;
      }
      longest = max(longest, count);
    }
  }
  return longest;
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
  // int result = longestconsecutivesequence(arr);
  // int result = longestconsecutive(arr);
  int result = longestConsecutiveSequence(arr);
  cout << result << endl;
  return 0;
}