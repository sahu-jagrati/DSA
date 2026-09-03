// You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

// We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

// If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
// For example, the word "apple" becomes "applema".
// If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
// For example, the word "goat" becomes "oatgma".
// Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
// For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
// Return the final sentence representing the conversion from sentence to Goat Latin.

// Example 1:

// Input: sentence = "I speak Goat Latin"
// Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
// Example 2:

// Input: sentence = "The quick brown fox jumped over the lazy dog"
// Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

// Constraints:

// 1 <= sentence.length <= 150
// sentence consists of English letters and spaces.
// sentence has no leading or trailing spaces.
// All the words in sentence are separated by a single space.

#include <bits/stdc++.h>
using namespace std;

// write by me fully
// n = total characters in sentence
// t.c-O(n)
// s.c-O(n) for answer string
string toGoatLatin(string sentence)
{
  string answer;
  set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  stringstream ss(sentence);
  string word;
  int cnt = 0;
  while (ss >> word)
  {
    cnt++;
    if (st.count(word[0]))
    {
      word.append("ma");
    }
    else if (!st.count(word[0]))
    {
      word = word.substr(1) + word[0];
      word.append("ma");
    }
    for (int i = 0; i < cnt; i++)
    {
      word.append("a");
    }
    if (!answer.empty())
      answer += " ";
    answer += word;
    // answer += " "; // this gives space also after last word
  }
  return answer;
}

// short version of above
// n = total characters in sentence
// t.c-O(n)
// s.c-O(n) for answer string
string togoatLatin(string sentence)
{
  string answer;
  set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  stringstream ss(sentence);
  string word;
  int cnt = 0;
  while (ss >> word)
  {
    cnt++;
    if (st.count(word[0]))
    {
      word.append("ma");
    }
    else
    {
      word = word.substr(1) + word[0] + "ma";
    }
    word += string(cnt, 'a'); // better way to add a's
    if (!answer.empty())
      answer += " ";
    answer += word;
    // answer += " "; // this gives space also after last word
  }
  return answer;
}

// optimized version(best for interviews)-

// n=length of sentence
// t.c-O(n) each character visited once
// s.c-O(n)
string togoatlatin(string sentence)
{
  string answer;
  int n = sentence.size();
  int wordIndex = 1;
  int i = 0;

  while (i < n)
  {
    string word = "";

    // extract one word from sentence manually
    while (i < n && sentence[i] != ' ')
    {
      word += sentence[i];
      i++;
    }

    // check vowel
    char ch = word[0];
    bool isVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');

    if (isVowel)
      word.append("ma");
    else
    {
      word = word.substr(1) + word[0] + "ma";
    }
    // add required 'a'
    word += string(wordIndex, 'a');

    if (!answer.empty())
      answer += " ";
    answer += word;

    wordIndex++;
    i++; // skip space
  }
  return answer;
}
int main()
{
  string sentence;
  getline(cin, sentence);

  // string result = toGoatLatin(sentence);
  // string result = togoatLatin(sentence);
  string result = togoatlatin(sentence);
  cout << result << endl;
  return 0;
}