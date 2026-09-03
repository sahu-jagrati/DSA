// A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

// You are given an array of strings sentences, where each sentences[i] represents a single sentence.

// Return the maximum number of words that appear in a single sentence.

// Example 1:

// Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
// Output: 6
// Explanation:
// - The first sentence, "alice and bob love leetcode", has 5 words in total.
// - The second sentence, "i think so too", has 4 words in total.
// - The third sentence, "this is great thanks very much", has 6 words in total.
// Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.
// Example 2:

// Input: sentences = ["please wait", "continue to fight", "continue to win"]
// Output: 3
// Explanation: It is possible that multiple sentences contain the same number of words.
// In this example, the second and third sentences (underlined) have the same number of words.

// Constraints:

// 1 <= sentences.length <= 100
// 1 <= sentences[i].length <= 100
// sentences[i] consists only of lowercase English letters and ' ' only.
// sentences[i] does not have leading or trailing spaces.
// All the words in sentences[i] are separated by a single space.

#include <bits/stdc++.h>
using namespace std;

int cntWordInSentence(string sentence)
{
  stringstream ss(sentence);
  string word;
  int cnt = 0;
  while (ss >> word)
    cnt++;
  return cnt;
}
int mostWordsFound(vector<string> &sentences)
{
  int maxWords = INT_MIN;
  for (int i = 0; i < sentences.size(); i++)
  {
    int cnt = cntWordInSentence(sentences[i]);
    if (cnt > maxWords)
      maxWords = cnt;
  }
  return maxWords;
}
int main()
{
  int n;
  cin >> n;
  cin.ignore(); // IMPORTANT: remove leftover newline
  vector<string> sentences(n);
  for (int i = 0; i < n; i++)
  {
    getline(cin, sentences[i]);
  }
  cout << mostWordsFound(sentences);
  return 0;
}
// Why cin.ignore()?

// After:

// cin >> n;

// the buffer looks like:

// 5\n

// So getline() reads that \n immediately → empty string 😵

// 👉 cin.ignore() removes that newline.

// ✅ Alternative (more robust)
// cin.ignore(numeric_limits<streamsize>::max(), '\n');

// This clears the entire buffer safely.

// 🚀 Summary
// Always use cin.ignore() after cin >> n when using getline()
// Store input directly into vector