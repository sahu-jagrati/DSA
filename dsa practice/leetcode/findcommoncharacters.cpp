// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

// Example 1:
// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]

// Example 2:
// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]

#include <bits/stdc++.h>
using namespace std;



int main()
{
  int n;
  cout << "Enter the size of string array: ";
  cin >> n;
  vector<string> words(n);
  cout << "Enter the strings in the words array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }
  vector<string> answer = commonChars(words);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}