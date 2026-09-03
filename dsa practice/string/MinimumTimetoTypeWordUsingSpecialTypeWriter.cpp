// There is a special typewriter with lowercase English letters 'a' to 'z' arranged in a circle with a pointer. A character can only be typed if the pointer is pointing to that character. The pointer is initially pointing to the character 'a'.

// Each second, you may perform one of the following operations:

// Move the pointer one character counterclockwise or clockwise.
// Type the character the pointer is currently on.
// Given a string word, return the minimum number of seconds to type out the characters in word.

// Example 1:

// Input: word = "abc"
// Output: 5
// Explanation:
// The characters are printed as follows:
// - Type the character 'a' in 1 second since the pointer is initially on 'a'.
// - Move the pointer clockwise to 'b' in 1 second.
// - Type the character 'b' in 1 second.
// - Move the pointer clockwise to 'c' in 1 second.
// - Type the character 'c' in 1 second.
// Example 2:

// Input: word = "bza"
// Output: 7
// Explanation:
// The characters are printed as follows:
// - Move the pointer clockwise to 'b' in 1 second.
// - Type the character 'b' in 1 second.
// - Move the pointer counterclockwise to 'z' in 2 seconds.
// - Type the character 'z' in 1 second.
// - Move the pointer clockwise to 'a' in 1 second.
// - Type the character 'a' in 1 second.
// Example 3:

// Input: word = "zjpc"
// Output: 34
// Explanation:
// The characters are printed as follows:
// - Move the pointer counterclockwise to 'z' in 1 second.
// - Type the character 'z' in 1 second.
// - Move the pointer clockwise to 'j' in 10 seconds.
// - Type the character 'j' in 1 second.
// - Move the pointer clockwise to 'p' in 6 seconds.
// - Type the character 'p' in 1 second.
// - Move the pointer counterclockwise to 'c' in 13 seconds.
// - Type the character 'c' in 1 second.

// Constraints:

// 1 <= word.length <= 100
// word consists of lowercase English letters.

// lowercase english letters are arranged in circle and initially pointer is at 'a' char

#include <bits/stdc++.h>
using namespace std;

// done by me fully
int minTimeToType(string word)
{
  int minSecond = 0;
  for (int i = 0; i < word.size(); i++)
  {
    // initially pointer is at char 'a' and for i=0 we don't have have i-1 so for word[0] we have to calculate the time from char 'a'
    // time=min(clockwise,counterclockwise)
    if (i == 0)
    {
      minSecond += (min(abs('a' - word[0]), (26 - abs('a' - word[0]))));
    }
    else
    {
      int clockWise = abs(word[i - 1] - word[i]);             // means jaha par pointer hai waha se clockwise next char par
      int counterClockWise = 26 - abs(word[i - 1] - word[i]); // jaha pointer hai baha se next char par counterclockwise
      minSecond += (min(clockWise, counterClockWise));
    }
    // we have to type each character so
    minSecond += 1;
  }
  return minSecond;
}
int main()
{
  string word;
  cin >> word;
  cout << minTimeToType(word);
  return 0;
}