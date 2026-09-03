// You are given a string word containing lowercase English letters.

// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

// Return the minimum number of pushes needed to type word after remapping the keys.

// An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

// Example 1:

// Input: word = "abcde"
// Output: 5
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// Total cost is 1 + 1 + 1 + 1 + 1 = 5.
// It can be shown that no other mapping can provide a lower cost.
// Example 2:

// Input: word = "xyzxyzxyzxyz"
// Output: 12
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "x" -> one push on key 2
// "y" -> one push on key 3
// "z" -> one push on key 4
// Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
// It can be shown that no other mapping can provide a lower cost.
// Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.
// Example 3:

// Input: word = "aabbccddeeffgghhiiiiii"
// Output: 24
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// "f" -> one push on key 7
// "g" -> one push on key 8
// "h" -> two pushes on key 9
// "i" -> one push on key 9
// Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
// It can be shown that no other mapping can provide a lower cost.

// Constraints:

// 1 <= word.length <= 105
// word consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// it's first version problem we have string word with distinct lowercase English letter so in that we don't require to store the key with its char

// but here we can have repeatative char so we have to store the char with its key means we have to store which key is assign to which char

// t.c-
// for making mpp O(n) // as we use unordered_map so in average it take O(1) for insertion and search
// let m=mpp.size
// for sorting v O(mlogm)
// for minPush loop O(m)
// total t.c-O(n)+O(mlogm)+O(m)
// s.c-O(m)(for mpp)+O(m)(for v)=O(2m)

int minimumPushes(string word)
{
  int n = word.size();
  // here we can have repeatative char in string word so we have to store which char is assign to which key so for that we compute frequency here
  unordered_map<char, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[word[i]]++;
  }
  // now we want to sort mpp A.T its frequency value because for the char having highest frequency I want to give push=1 so we can minimize the number of push because frequency*push = total push for that char  so for that we store the map entries in a vector and sort it according to its freqeuency value
  vector<pair<char, int>> v(mpp.begin(), mpp.end());
  sort(v.begin(), v.end(), [](auto &a, auto &b)
       { return a.second > b.second; });
  int m = v.size();
  int i = 0;
  int minPush = 0;
  int push = 1;
  while (i < m)
  {
    // we have 2 to 8 key which are total 7 keys so after 7 the iteration we have to increase the push value because for an example  when we push the same key for second char on that we have to push it two times and for third char we have to push it for three times so after each 7 iterations we increase push by 1
    // after 7 iteration means we have 8th iteration and multiple of 8 and we cannot increase push when i=0 because we already start push with 1
    // we say i!=0 because 0%8==0 always so it increase push but we start push with 1 so in starting we can't increase push if we start push with 0 then we don't have to write i!=0 because in that case 0%8==0 increase the push by 1 and make push=1
    if (i != 0 && i % 8 == 0)
      push++;
    minPush += (push * v[i].second);
    i++;
  }
  return minPush;
}

int main()
{
  string word;
  cin >> word;
  cout << minimumPushes(word);
  return 0;
}