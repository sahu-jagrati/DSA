// Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

// The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

// Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

// Example 1:

// Input: candyType = [1,1,2,2,3,3]
// Output: 3
// Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
// Example 2:

// Input: candyType = [1,1,2,3]
// Output: 2
// Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.
// Example 3:

// Input: candyType = [6,6,6,6]
// Output: 1
// Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type

#include <bits/stdc++.h>
using namespace std;

// as we use unordered map so insertion and finding take O(1) in average or O(n)in worst case
// or if we use map then it take O(log(n))
// t.c-O(n*1) for insertion in mpp+O(n/2)for finding
// s.c-O(hashmap size)
int distributeCandies(vector<int> &candyType)
{
  int n = candyType.size(); // given n is always even
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[candyType[i]]++;
  }
  int cnt = 0;
  int maxEat = n / 2;
  for (auto it : mpp)
  {
    if (cnt < maxEat)
    {
      if (it.second >= 1)
      {
        cnt++;
      }
    }
  }
  return cnt;
}

int main()
{
  int n;
  cout << "Enter the size of candyType array(size should be even): ";
  cin >> n;
  vector<int> candyType(n);
  cout << "Enter the elt in array that can be repeat: ";
  for (int i = 0; i < n; i++)
  {
    cin >> candyType[i];
  }
  int result = distributeCandies(candyType);
  cout << "Maximum number of different types of candies she can eat if she only eats n / 2 of them: " << result << endl;
  return 0;
}