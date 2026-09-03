// You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

// Example 1:

// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
// Example 2:

// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
// Example 3:

// Input: letters = ["x","x","y","y"], target = "z"
// Output: "x"
// Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].

// Constraints:

// 2 <= letters.length <= 10^4
// letters[i] is a lowercase English letter.
// letters is sorted in non-decreasing order.
// letters contains at least two different characters.
// target is a lowercase English letter.

#include <bits/stdc++.h>
using namespace std;

// we have sorted array letters and we want smallest char greater than target so we use binary search which help to remove half array if not satisfy

// t.c-O(log n)(base 2)
// s.c-O(1)
char nextGreatestLetter(vector<char> &letters, char target)
{
  int n = letters.size();
  int low = 0;
  int high = n - 1;
  char answer = letters[0];
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (letters[mid] > target)
    {
      answer = letters[mid];
      high = mid - 1;
    }
    else if (letters[mid] <= target)
      low = mid + 1;
  }
  return answer;
}

int main()
{
  int n;
  cin >> n;
  vector<char> letters(n);
  for (int i = 0; i < n; i++)
  {
    cin >> letters[i];
  }
  char target;
  cin >> target;

  char answer = nextGreatestLetter(letters, target);
  cout << answer << endl;
  return 0;
}