// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

// A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

// For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
// Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

// Example 1:

// Input: s = "is2 sentence4 This1 a3"
// Output: "This is a sentence"
// Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
// Example 2:

// Input: s = "Myself2 Me1 I4 and3"
// Output: "Me Myself and I"
// Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.

// Constraints:

// 2 <= s.length <= 200
// s consists of lowercase and uppercase English letters, spaces, and digits from 1 to 9.
// The number of words in s is between 1 and 9.
// The words in s are separated by a single space.
// s contains no leading or trailing spaces.

// Hint 1
// Divide the string into the words as an array of strings
// Hint 2
// Sort the words by removing the last character from each word and sorting according to it

#include <bits/stdc++.h>
using namespace std;

string sortSentence(string s)
{
  stringstream ss(s);
  string word;
  vector<string> words;
  while (ss >> word)
    words.push_back(word);

  // we make temp because if in words array we access and change together then  for the next word access it give change word which is wrong and we store at j-1 because indexing in array is 0-based
  vector<string> temp = words;
  for (int i = 0; i < temp.size(); i++)
  {
    string str = temp[i];
    int j = str[str.size() - 1] - '0'; // convert the char digit into integer
    str.erase(str.size() - 1, 1);
    words[j - 1] = str;
  }
  string answer = "";
  for (int i = 0; i < words.size(); i++)
  {
    if (!answer.empty())
      answer += ' ';
    answer += words[i];
  }
  return answer;
}
int main()
{
  string s;
  getline(cin, s);
  cout << sortSentence(s);
  return 0;
}