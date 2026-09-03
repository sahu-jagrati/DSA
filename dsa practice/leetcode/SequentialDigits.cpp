// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]

// Constraints:

// 10 <= low <= high <= 10^9

#include <bits/stdc++.h>
using namespace std;

// first I think that I run loop from low to high and check each number is sequential digit or not But I know the constraints are so big it give Time limit exceed and it is difficult to check sequential digit because for that we have to check each digit from back by taking MOD

// Then I see hint and I solve it in one try completely by own with hint

// Hint 1
// Generate all numbers with sequential digits and check if they are in the given range.
// Hint 2
// Fix the starting digit then do a recursion that tries to append all valid digits.

// According to hint what we do is we start with a digit so we run a loop for each digit from 1 to 9 because number can start from 1 to 9 any digit then I take a varible-d which is 1+digit that we take in loop so d go upto 9 and then we make number like x=x*10+d and if it is in our range then push it in our answer and we increas d by 1 so and add it to one's,tenth,hundreth place and so on so we don't need to check separatley that it is sequentiall digit because we increase it by 1 and from x+1 we add it to the place

void sequentialDigit(int x, vector<int> &ans, int low, int high)
{
  // digit
  int d = x + 1; // we take d=x+1 because A.T.Q each digit in the number is one more that the previous digit so if starting digit is x then it's nect digit is x+1 so we take d=x+1
  // we take d upto 9, why we don't take 0 because 0 is always less than 1 and we know number cannot start with 0 so we cannot take 0 as other place
  while (d <= 9)
  {
    if (x >= low && x <= high)
    {
      ans.push_back(x);
    }
    // also we don't check that digit in the number is one more than the previous digit because we increse d by 1 so no need to check separately
    x = x * 10 + d;
    d++;
  }
  // in last we check for x also
  if (x >= low && x <= high)
  {
    ans.push_back(x);
  }
}

// t.c
// for loop runs from 1 to 9 so O(9)
// now while loop also in worst case run from 2 to 9 if number start from 1 when i=1 dso O(9)
// total t.c-O(9*9)=O(18)
// s.c-O(ans size) which is required
vector<int> sequentialDigits(int low, int high)
{
  vector<int> ans;
  // we run loop from 1 to 9 because number can start from any digit
  for (int i = 1; i <= 9; i++)
  {
    sequentialDigit(i, ans, low, high);
  }
  return ans;
}
int main()
{
  int low, high;
  cin >> low >> high;
  vector<int> ans = sequentialDigits(low, high);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}