// You are given two strings s and target, both having length n, consisting of lowercase English letters.

// Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

// A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

// Example 1:

// Input: s = "abc", target = "bba"

// Output: "bca"

// Explanation:

// The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
// The lexicographically smallest permutation that is strictly greater than target is "bca".
// Example 2:

// Input: s = "leet", target = "code"

// Output: "eelt"

// Explanation:

// The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
// The lexicographically smallest permutation that is strictly greater than target is "eelt".
// Example 3:

// Input: s = "baba", target = "bbaa"

// Output: ""

// Explanation:

// The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
// None of them is lexicographically strictly greater than target. Therefore, the answer is "".

// Constraints:

// 1 <= s.length == target.length <= 300
// s and target consist of only lowercase English letters.

// Hint 1
// Maintain frequency counts of s.
// Hint 2
// Walk left-to-right; if equal to target[i] is possible, take it and continue.
// Hint 3
// If not, try the smallest letter strictly greater than target[i].
// Hint 4
// If neither, backtrack left to the most recent index where you matched target and try to bump there.

#include <bits/stdc++.h>
using namespace std;

// I do this problem by using chatgpt

// solution: frequency count + left-to-right matching + backtracking

// The important part is: when we cannot continue matching target, we go backward to the most recent position where we matched an equal character and try to make that character slightly larger.

// Frequency count
//       ↓
// Match target left → right
//       ↓
// Can't match?
//       ↓
// Try smallest character > target[i]
//       ↓
// If impossible → backtrack
//       ↓
// At each backtracked position:
// try smallest character > target[j]
//       ↓
// Fill rest in sorted order

// There are two reasons we need to backtrack:

// 1. Matching target fails
//    ↓
//    Try to make current/previous position greater

// 2. Matching target succeeds completely means s==target
//    ↓
//    We have exactly target
//    ↓
//    Still need STRICTLY greater
//    ↓
//    Backtrack and increase something

// both string s and target are of same length

// t.c-O(n*26) = approx. O(n)
// s.c-O(26)(for freq array)+O(n)(for used array)
string lexGreaterPermutation(string s, string target)
{
  int n = s.size();
  vector<int> freq(26, 0); // because we have only lowercase english letters
  // frequency of charaacters in s
  for (char ch : s)
  {
    freq[ch - 'a']++;
  }

  // we will store the characters used to match target
  vector<int> used(n, -1); // we store the index of that

  // left-to-right on target string
  for (int i = 0; i < n; i++)
  {
    int t = target[i] - 'a'; // get character value in form of 0 to 25

    // Case 1: We can match target[i]
    if (freq[t] > 0)
    {
      freq[t]--;
      used[i] = t; // we store index of character that is match
      continue;    // skip the below process
    }

    // Case 2: Cannot match target[i]
    // First try to make answer greater at position i (i.e current position)
    // for that we want character slightly greater that current one so if current character is t then we go from t+1 to 25 for getting slightly greater character than current one so we do this by checking frequency
    for (int c = t + 1; c < 26; c++)
    {

      if (freq[c] > 0)
      {                                   // means we get slightly greater character present in string s
        string ans = target.substr(0, i); // so first we add the matching character of target into answer so that start from index 0 and go to length i
        ans += char('a' + c);             // then we add character that is slightly greater than character at position i
        freq[c]--;
        // fill remaining positions with smallest chars because we already add one slightly greater character in ans so now it is lexicographically greater than target and we want smallest permutation so remaining characters add in sorted order
        for (int x = 0; x < 26; x++)
        {
          // in append(): freq[x] denotes that add character char('a'+x) freq[x] times
          ans.append(freq[x], char('a' + x));
        }
        return ans;
      }
    }

    // Case 3: Cannot match target[i] and cannot make position i greater (i.e we cannot get slightly greater character)
    // backtrack to the most recent position where we matched an equal character and try to make that character slightly larger.
    // as character at index i not match so we backtrack from i-1 to 0 where we get
    for (int j = i - 1; j >= 0; j--)
    {
      // return the character used at position j
      freq[used[j]]++;

      int original = target[j] - 'a'; // now for j

      // try a character strictly greater than target[j] so if current character is original then we go from original+1 to 25 for getting slightly greater character than current one so we do this by checking frequency
      for (int c = original + 1; c < 26; c++)
      {
        if (freq[c] > 0)
        {                                   // means we get slightly greater character present in string s
          string ans = target.substr(0, j); // so first we add the matching character of target into answer so that start from index 0 and go to length j
          ans += char('a' + c);             // then we add character that is slightly greater than character at position j
          freq[c]--;
          // smallest possible suffix
          // fill remaining positions with smallest chars because we already add one slightly greater character in ans so now it is lexicographically greater than target and we want smallest permutation so remaining characters add in sorted order
          for (int x = 0; x < 26; x++)
          {
            // in append(): freq[x] denotes that add character char('a'+x) freq[x] times
            ans.append(freq[x], char('a' + x));
          }
          return ans;
        }
      }
    }
    return "";
  }

  // we matched target completely means s == target
  // but we need strictly greater, not equal.
  // Therefore backtrack and try to increase
  // the rightmost possible generation means try to increase one rightmost character slightly
  // so we go from n-1 to 0
  // this is when s == target
  // I explain this part by example below
  for (int j = n - 1; j >= 0; j--)
  {
    freq[used[j]]++;
    int original = target[j] - 'a';
    for (int c = original + 1; c < 26; c++)
    {
      if (freq[c] > 0)
      {
        string ans = target.substr(0, j);
        ans += char('a' + c);
        freq[c]--;
        for (int x = 0; x < 26; x++)
        {
          ans.append(freq[x], char('a' + x));
        }
        return ans;
      }
    }
  }
  return "";
}

int main()
{
  // both s and target are of same length
  string s, target;
  cin >> s >> target;
  cout << lexGreaterPermutation(s, target);
  return 0;
}

// let understand above solution with example:
// s="abc"
// target="bba"

// Initial:
// freq of s:
// a=1
// b=1
// c=1

// traverse left to right in target

// i=0
// target character=b
// we have b in freq, so take it:
// answer prefix=b
// remaining:
// a=1
// b=0
// c=1

// i=1
// target character=b.
// but freq[b]=0
// So we cannot continue.

// Can we make position 1 greater than b?
// Yes.
// because we have c>b
// So:
// prefix="b"
//        + "c"
//        +   smallest remaining ="a"

// result: "bca"
// Exactly what we want.

// Why do we need backtracking?
// Consider: s="aabc" , target="aacc"

// Initial:
// freq:
// a=2
// b=1
// c=1

// traverse left to right in target

// i=0
// target character=a
// we have a in freq, so take it:
// answer prefix=a
// remaining:
// a=1
// b=1
// c=1

// i=1
// target character=a.
//  we have a in freq, so take it:
// answer prefix=aa
// remaining:
// a=0
// b=1
// c=1

// i=2
// target character=c.
// we have c in freq, so take it:
// answer prefix=aac
// remaining:
// a=0
// b=1
// c=0

// i=3
// target character=c.
// But freq[c]=0
// so we cannot continue.

// Can we make position 3 greater than c?
// No.
// Because we don't have any character greater than c.

// So we backtrack: from i-1 to 0
// here i=3 so i-1=2
// We return the character used at position 2:
// freq[c]++;
// Now:
// remaining:
// a=0
// b=1
// c=1

// At position 2, target was:
// target[2]='c'

// Can we choose something greater than c?
// No.
// So continue backtracking.
// Return the character used at position 1:
// freq[a]++;

// Now remaining:
// a=1
// b=1
// c=1

// At position 1: target[1]='a'

// Can we choose something greater than a?
// Yes
// Smallest available greater character is:
// b
// Therefore:
// prefix=target.substr(0,i) where i=1 means start from index 0 and upto length 1 so we get
// prefix="a"
// biggest character="b"
// remaining="ac"

// So:
// "ab"+"ac"
// ="abac"

// And indeed:
// ans=abac
// target=aacc
// if we compare lexicographically
// at position 1:
// b>a
// Therefore:
// "abac">"aacc"

// this example is for explaining the part of code   when s == target

// We matched target completely. // But we need STRICTLY greater, not equal. //  Therefore backtrack and try to increase // the rightmost possible position.means try to increase one rightmost character slightly
// so we go from n-1 to 0
// this is when s == target
// I explain this part by example below

//     for (int j = n - 1; j >= 0; j--)
// {
//   freq[used[j]]++;
//   int original = target[j] - 'a';
//   for (int c = original + 1; c < 26; c++)
//   {
//     if (freq[c] > 0)
//     {
//       string ans = target.substr(0, j);
//       ans += char('a' + c);
//       freq[c]--;
//       for (int x = 0; x < 26; x++)
//       {
//         ans.append(freq[x], char('a' + x));
//       }
//       return ans;
//     }
//   }
// }
// return "";

// Let's separate the two situations.

// Case 1: We fail while processing the target
// Suppose: s="abc" , target="bba"

// We do:
// i=0  target[0]=b  can take b
// i=1 target[1]=b  cannot take b

// NOw we haven't finished matching target.
// So we try to make the answer greater at tge current position.
// b+c+a="bca" I  explain this in above example
// Done.

// Case 2: We successfully match the entire target

// Consider: s="abc" , target="abc"

// We can do:
// i=0  -> a
// i=1  -> b
// i=2  -> c
// So we get: "abc"

// But the question asks for:
// permutation > target
// and "abc" not > "abc"

// It's equal.
// So now we have to backtrack and make some earlier character bigger.

// That's the above code do.

// s="abc" , target="abc"
// At j=2:
// atrget[2]=c
// There is nothing greater than c.
// So go back:
// j=1
// target[1]=b
// Can we use something greater than b?
// Yes. we have c
// So: a + c + remaining(a? actually remaining b)

// gives: "acb"
// And:
// "acb">"abc"

// Therefore: answer="acb"

// Why isn't this already handled by the earlier loop?
// Because the earlier loop only looks for a greater character when matching fails.

// In this case, matching never fails:
// target="abc" and s="abc"
// So the first loop reaches the end and returns nothing.

// We need to say:

// "I successfully constructed exactly target, but equality isn't allowed. Now let me go backward and find the rightmost position that I can increase."

// That's why the second backtracking section exists.

// There are two reasons we need to backtrack:

// 1. Matching target fails
//    ↓
//    Try to make current/previous position greater

// 2. Matching target succeeds completely
//    ↓
//    We have exactly target
//    ↓
//    Still need STRICTLY greater
//    ↓
//    Backtrack and increase something