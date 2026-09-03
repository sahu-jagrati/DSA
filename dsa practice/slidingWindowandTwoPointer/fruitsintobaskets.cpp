// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

// Example 1:

// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.
// Example 2:

// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].
// Example 3:

// Input: fruits = [1,2,3,2,2]
// Output: 4
// Explanation: We can pick from trees [2,3,2,2].
// If we had started at the first tree, we would only pick from trees [1,2].

// Constraints:

// 1 <= fruits.length <= 105
// 0 <= fruits[i] < fruits.length

// given an integer array fruits where fruits[i] is the type of fruit the ith tree produces
// arr=[3,3,3,1,2,1,1,2,3,3,4] represent type of fruit
// more than one tree can produce same type of furit
// we have 2 baskets- each basket can hold only a single type of fruit and there is no limit on the amount of fruit each basket can hold
// example- b1 hold only fruit of type 3 and b2 hold only type 2 of furit
// our task is to pick maximum number of fruits with given that if we start picking fruit then we cannot skip any fruit in btw
// example- b1 pick type 3 so we start from index 0 and pick 3,3,3 then we go to index 7 and pick type 2 for b2 basket and after that we agin put 3,3 to b1 here we skip 1,2,1,1 fruit so we cannot do this

// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

// here max fruits that we can pick is if we start from index 3 then
// b1 store type 1 fruit and b2 store type 2 fruit then maximum we can pick 5 fruits

// also arr=[3,3,3,3,]
// b1=3,3,3,3 and b2 is empty also can be

// if we convert our question to calculate maxlength subarray with 2 types of numbers/fruits
#include <bits/stdc++.h>
using namespace std;

// naive solution- genearte all subarrays with 2 types of fruits
// set maximum have 3 elts so log3 is constant for insertion
// t.c-O(n^2)
// s.c-o(1) and here also st.size is max=3 which is constant
int maxFruitsPick(vector<int> &nums)
{
  int n = nums.size();
  int maxlen = 0;
  for (int i = 0; i < n; i++)
  {
    set<int> st;
    for (int j = i; j < n; j++)
    {
      st.insert(nums[j]);
      if (st.size() <= 2) // we do for 2 beacuse we want to put fruits in 2 baskets
      {
        maxlen = max(maxlen, j - i + 1);
      }
      // when st.size>2
      else
        break;
    }
  }
  return maxlen;
}

// better solution- two pointers/sliding window
// we use map to cnt number of fruits by size of map

// t.c-O(n(outer while loop) + n(inner while loop))*1(for insert in mpp because mpp size is max go to 3 so it is constant) also if we use ordered map it is log3 which is alos constant
// s.c-O(1) because mpp size is max =3 constant
int maximumFruitsPick(vector<int> &nums)
{
  int n = nums.size();
  int l = 0, r = 0, maxlen = 0;
  unordered_map<int, int> mpp; // store fruit type,frequency>
  // run n times
  while (r < n)
  {
    mpp[nums[r]]++;
    if (mpp.size() > 2)
    {
      // this while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
      while (mpp.size() > 2)
      {
        mpp[nums[l]]--;
        if (mpp[nums[l]] == 0)
          mpp.erase(nums[l]);
        l++; // shrink the window
      }
    }
    // we do for 2 beacuse we want to put fruits in 2 baskets
    if (mpp.size() <= 2)
    {
      maxlen = max(maxlen, r - l + 1);
    }
    r++; // expand the window
  }
  return maxlen;
}

// optimal solution- we try to remove inner while loop of better solution
// but this used only for getting maxlen, we cannot use to print subarray of maxlen
// pattern-2 optimal solution of two pointers/sliding window

// here we shrink window/l only by 1 place to match current length with maxlen, not go beyond maxlength

// t.c-O(n)(for outer while loop)*1(for insert in mpp because mpp size is max go to 3 so it is constant) also if we use ordered map it is log3 which is alos constant
//  s.c-O(1) because mpp size is max =3 constant

int maximumFruitsCanPick(vector<int> &nums)
{
  int n = nums.size();
  int l = 0, r = 0, maxlen = 0;
  unordered_map<int, int> mpp; // store fruit type,frequency>
  // run n times
  while (r < n)
  {
    mpp[nums[r]]++;
    // we shrink only by 1 place so take O(1) time now
    if (mpp.size() > 2)
    {
      mpp[nums[l]]--;
      if (mpp[nums[l]] == 0)
        mpp.erase(nums[l]);
      l++; // shrink the window
    }
    if (mpp.size() <= 2)
    {
      maxlen = max(maxlen, r - l + 1);
    }
    r++; // expand the window
  }
  return maxlen;
}

int main()
{
  int n;
  cout << "Enter the size of an array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt of an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  // int answer = maxFruitsPick(nums);
  // int answer = maximumFruitsCanPick(nums);
  int answer = maximumFruitsPick(nums);
  cout << "Maximum fruits we pick are: " << answer << endl;
  return 0;
}