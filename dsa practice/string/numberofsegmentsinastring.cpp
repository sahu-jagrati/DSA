// Given a string s, return the number of segments in the string.

// A segment is defined to be a contiguous sequence of non-space characters.

// Example 1:

// Input: s = "Hello, my name is John"
// Output: 5
// Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
// Example 2:

// Input: s = "Hello"
// Output: 1

// Constraints:

// 0 <= s.length <= 300
// s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
// The only space character in s is ' '.

#include <bits/stdc++.h>
using namespace std;

// s is a sentence
int countSegments(string s)
{
  int n = s.size();
  int cntSegment = 0;
  // stringstream break the sentence into string
  stringstream ss(s);
  string word;
  while (ss >> word)
  {
    cntSegment++;
  }
  return cntSegment;
}

int main()
{
  string sentence;
  getline(cin, sentence);

  int answer = countSegments(sentence);
  cout << answer << endl;
  return 0;
}