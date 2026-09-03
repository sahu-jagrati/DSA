// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

// Example 1:

// Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
// Output: 1
// Example 2:

// Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
// Output: 3

// Constraints:

// 1 <= dominoes.length <= 4 * 104
// dominoes[i].length == 2
// 1 <= dominoes[i][j] <= 9

#include <bits/stdc++.h>
using namespace std;

// brute solution-

// t.c-O(n^2)
// s.c-O(1)
int numEquivDominoPairs(vector<vector<int>> &dominoes)
{
  int n = dominoes.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int a = dominoes[i][0];
    int b = dominoes[i][1];
    for (int j = i + 1; j < n; j++)
    {
      int c = dominoes[j][0];
      int d = dominoes[j][1];
      if ((a == c && b == d) || (a == d && b == c))
        cnt++;
    }
  }
  return cnt;
}

// optimize solution-
// We can optimize it to O(n) using a hash map.
// Key Idea 💡

// Two dominoes are equivalent if:

// (a,b) == (c,d)  OR  (a,b) == (d,c)

// So we normalize every domino so that:

// smaller number first
// larger number second

// Example

// [2,1] → [1,2]

// Now equivalent dominoes will always look the same.

// Then we count using a frequency map.

// t.c-O(n)
// s.c-O(n) if all pairs are different
int equivalentDominoPairs(vector<vector<int>> &dominoes)
{
  int n = dominoes.size();
  unordered_map<int, int> freq;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int a = min(dominoes[i][0], dominoes[i][1]);
    int b = max(dominoes[i][0], dominoes[i][1]);

    int key = a * 10 + b; // unique key - convert pair into one integer and cnt the frequency of that integer

    cnt += freq[key]; // add previous matches
    freq[key]++;
  }
  return cnt;
}

// we can more optimize it more
// Since numbers are 1–9 only, we can use an array instead of hashmap.

// t.c-O(n)
// s.c-O(100)=O(1) fixed array
int equivDominoPairs(vector<vector<int>> &dominoes)
{
  int n = dominoes.size();
  int freq[100] = {0}; // because numbers are from 1-9 and multiply with 10 and add b go max upto 100
  int cnt = 0;

  for (int i = 0; i < n; i++)
  {
    int a = min(dominoes[i][0], dominoes[i][1]);
    int b = max(dominoes[i][0], dominoes[i][1]);

    int key = a * 10 + b;
    cnt += freq[key];
    freq[key]++;
  }
  return cnt;
}

// pair-counting trick using the combination formula that appears in many coding problems.

// The idea comes from combinatorics in Combination.
// Key Idea 💡

// If a value appears k times, the number of unique pairs we can form is:
//  kC2=k*(k-1)/2

// So instead of adding pairs while traversing, we:

// Count frequency of each domino type.

// Apply kC2 to each frequency

// t.c-O(n)=counting(O(n))+pair calcultionO(100)= total=O(n)
// s.c-O(1) fixed array
int cntEquivPairs(vector<vector<int>> &dominoes)
{
  int freq[100] = {0};
  int n = dominoes.size();

  for (int i = 0; i < n; i++)
  {
    int a = min(dominoes[i][0], dominoes[i][1]);
    int b = max(dominoes[i][0], dominoes[i][1]);

    int key = a * 10 + b;
    freq[key]++;
  }

  int cnt = 0;
  for (int i = 0; i < 100; i++)
  {
    int k = freq[i];
    cnt += k * (k - 1) / 2;
  }
  return cnt;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> dominoes(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    cin >> dominoes[i][0] >> dominoes[i][1];
  }
  cout << numEquivDominoPairs(dominoes) << endl;
  cout << equivalentDominoPairs(dominoes) << endl;
  cout << equivDominoPairs(dominoes) << endl;
  cout << cntEquivPairs(dominoes) << endl;
  return 0;
}

// Why this trick is important 🚀

// This kC2 pattern appears in many problems like:

// Pairs with same remainder

// Good pairs

// Equivalent domino pairs

// Pairs of songs divisible by 60

// Equal row-column pairs

// ✅ Interview tip:
// Whenever the question says “count number of pairs with same property”, think of frequency + kC2.