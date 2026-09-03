// You are given a 0-indexed string array words.

// Two strings are similar if they consist of the same characters.

// For example, "abca" and "cba" are similar since both consist of characters 'a', 'b', and 'c'.
// However, "abacba" and "bcfd" are not similar since they do not consist of the same characters.
// Return the number of pairs (i, j) such that 0 <= i < j <= word.length - 1 and the two strings words[i] and words[j] are similar.

// Example 1:

// Input: words = ["aba","aabb","abcd","bac","aabc"]
// Output: 2
// Explanation: There are 2 pairs that satisfy the conditions:
// - i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'.
// - i = 3 and j = 4 : both words[3] and words[4] only consist of characters 'a', 'b', and 'c'.
// Example 2:

// Input: words = ["aabb","ab","ba"]
// Output: 3
// Explanation: There are 3 pairs that satisfy the conditions:
// - i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'.
// - i = 0 and j = 2 : both words[0] and words[2] only consist of characters 'a' and 'b'.
// - i = 1 and j = 2 : both words[1] and words[2] only consist of characters 'a' and 'b'.
// Example 3:

// Input: words = ["nba","cba","dba"]
// Output: 0
// Explanation: Since there does not exist any pair that satisfies the conditions, we return 0.

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consist of only lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// we solve by brute force
// this is wrong
// Two strings are similar if they contain exactly the same set of characters.

// Example:

// "abca" -> {a,b,c}
// "cba"  -> {a,b,c}

// Similar ✅

// But:

// "ab"  -> {a,b}
// "abc" -> {a,b,c}

// Not similar ❌

// Issue in your code

// You only check whether every character of str2 exists in str1.

// if(!st.count(str2[l]))

// This verifies:

// characters(str2) ⊆ characters(str)

// but you never verify:
// that every character of str1 also be exists in str2
// characters(str) ⊆ characters(str2)
// Counter Example
// words = {"ab", "a"}

// For:

// str = "ab"   => {a,b}
// str2 = "a"

// Every character of "a" exists in {a,b}, so flag=true.

// Your code counts them as similar.

// But:

// {a,b} != {a}

// So the answer should be 0, not 1.
// int similarPairs(vector<string> &words)
// {
//   int n = words.size();
//   int cnt = 0;
//   // we count for each pair
//   for (int i = 0; i < n; i++)
//   {
//     string str1 = words[i];
//     // store char of str1 in hashset
//     unordered_set<char> st;
//     for (int j = 0; j < str1.size(); j++)
//     {
//       st.insert(str1[j]);
//     }
//     // check
//     for (int k = i + 1; k < n; k++)
//     {
//       string str2 = words[k];
//       bool flag = true;
//       for (int l = 0; l < str2.size(); l++)
//       {
//         if (!st.count(str2[l]))
//         {
//           flag = false;
//           break;
//         }
//       }
//       if (flag == true)
//         cnt += 1;
//     }
//   }
//   return cnt;
// }

// brute force
// correct code is
// n=words.size
// m = maximum length of words[i]
// creating a set-O(m) because we insert each character once.
// comparing sets- Each set can contain at most 26 lowercase letters. so s1==s2 takes atmost O(26)=O(1)
// t.c- number of pairs approx n^2 and cost per pair O(m)
// total t.c-O((n^2)*m)
// s.c-O(26) because atmost set can have 26 lowercase letters
int similarPairs(vector<string> &words)
{
  int n = words.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    unordered_set<char> st1(words[i].begin(), words[i].end());
    for (int j = i + 1; j < n; j++)
    {
      unordered_set<char> st2(words[j].begin(), words[j].end());
      if (st1 == st2)
        cnt++;
    }
  }
  return cnt;
}

// better set solution
// Now:
// Building all sets: O(n·m)
// Comparing all pairs: O(n²·26) ≈ O(n²)
// Total t.c:
// O(n·m + n²)
// s.c-O(n*26) for each string we have unordered set in sets vector so its size is n and for each unordered set we have max of 26 lowercase letters
int similarpairs(vector<string> &words)
{
  // Precompute all sets first: by making an array of unordered set for each string of words array
  vector<unordered_set<char>> sets;
  for (auto &word : words)
  {
    sets.push_back(unordered_set<char>(word.begin(), word.end()));
  }
  int cnt = 0;
  int n = words.size();
  // check for each pair
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (sets[i] == sets[j])
      {
        cnt++;
      }
    }
  }
  return cnt;
}

// optimal approach(Bitmask) I copy this from chatgpt I have no idea what happen here
// Since there are only 26 lowercase letters, represent each word as a bitmask.
// t.c-O(n^2)
// s.c-O(n)
// int similarPairs(vector<string>& words) {
//     int n = words.size();
//     vector<int> mask(n);

//     for(int i = 0; i < n; i++) {
//         int m = 0;
//         for(char ch : words[i]) {
//             m |= (1 << (ch - 'a'));
//         }
//         mask[i] = m;
//     }

//     int cnt = 0;

//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             if(mask[i] == mask[j])
//                 cnt++;
//         }
//     }

//     return cnt;
// }
int main()
{
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
    cin >> words[i];
  cout << similarPairs(words);
  return 0;
}