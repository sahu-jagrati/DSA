// You are given two 0-indexed integer permutations A and B of length n.

// A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

// Return the prefix common array of A and B.

// A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

// Example 1:

// Input: A = [1,3,2,4], B = [3,1,2,4]
// Output: [0,2,3,4]
// Explanation: At i = 0: no number is common, so C[0] = 0.
// At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
// At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
// Example 2:

// Input: A = [2,3,1], B = [3,1,2]
// Output: [0,1,3]
// Explanation: At i = 0: no number is common, so C[0] = 0.
// At i = 1: only 3 is common in A and B, so C[1] = 1.
// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.

// Constraints:

// 1 <= A.length == B.length == n <= 50
// 1 <= A[i], B[i] <= n
// It is guaranteed that A and B are both a permutation of n integers.

// Hint 1
// Consider keeping a frequency array that stores the count of occurrences of each number till index i.
// Hint 2
// If a number occurred two times, it means it occurred in both A and B since they’re both permutations so add one to the answer.

#include <bits/stdc++.h>
using namespace std;

// done by me fully
// t.c-
// outer loop - runs n times
// inner loop - runs i+1 times for each i so total work: 1 + 2+ ....+n=O(n^2)
// map traversal-
// map can have up to n elts
// this loop runs O(n) for each i
// so overall-
// for each i, work=O(i)+O(n)= approx.O(n)
// total: n*O(n)=O(n^2)

// final t.c-O(n^2)

// s.c-
// answer vector-O(n)
// mpp - up to O(n)
// final s.c-O(n)
vector<int> findThePrefixArray(vector<int> &A, vector<int> &B)
{
  int n = A.size();
  vector<int> answer(n);
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    // check upto i
    for (int j = 0; j <= i; j++)
    {
      mpp[A[j]]++;
      mpp[B[j]]++;
    }
    int cnt = 0;
    // we check for 2 because A and B are permutation so it contains all integers from 1 to n exactly once so if it in both array then it is 2
    for (auto it : mpp)
    {
      if (it.second == 2)
        cnt++;
    }
    answer[i] = cnt;
    mpp.clear();
  }
  return answer;
}

// but my solution recomputes prefix from scratch every time → inefficient.
// optimal solution
// Since both arrays are permutations (1 to n):
// Each number appears exactly once in A and B
// We just need to track:
// 👉 “How many elements are common in prefix [0..i] of both arrays”
// ✅ Optimized Approach (O(n))

// Instead of recalculating every time:

// Use a frequency array freq
// Traverse once
// When a number appears in both prefixes → count it
// 💡 Logic

// At each index i:

// Add A[i] → increase freq
// Add B[i] → increase freq
// If any number reaches freq == 2, it means:
// 👉 It appeared in both A and B prefix → increment count

// we make frequency array of size n+1 that count freq of each elt and we check every time

// t.c-O(n) single loop
// s.c-O(n)+O(n)=O(n)- for freq array and for answer array
vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
  int n = A.size();
  vector<int> answer(n);

  vector<int> freq(n + 1, 0); // since values are 1 to n so n+1
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    freq[A[i]]++;
    if (freq[A[i]] == 2)
      cnt++; // because each elt is exactly once in each of both array
    freq[B[i]]++;
    if (freq[B[i]] == 2)
      cnt++;

    answer[i] = cnt; // this is satisfied because we don't recompute for index 0 when we calculate for answer[1] and so on we increase cnt
  }
  return answer;
}
// Key Interview Insight
// Avoid recomputing prefix → use incremental tracking
// Use frequency / hashing smartly
// This pattern appears in:
// Prefix problems
// Set intersection problems
// Sliding window problems

// solution- using set
// idea:
// Maintain two sets:
// setA → elements seen in A so far
// setB → elements seen in B so far
// At each index:
// Insert elements
// Check if newly added element exists in the other set

// t.c-O(n) // we use unordered set so O(1) for insert and access
// s.c-O(n)
vector<int> findPrefixArray(vector<int> &A, vector<int> &B)
{
  int n = A.size();
  vector<int> answer(n);
  unordered_set<int> setA, setB;
  int cnt = 0;

  for (int i = 0; i < n; i++)
  {
    setA.insert(A[i]);
    if (setB.count(A[i]))
      cnt++; // we use this technique because each elt in both array is exactly once time exist
    setB.insert(B[i]);
    if (setA.count(B[i]))
      cnt++; // This works because:
             // Each element appears only once (permutation)
             // So no double counting issue
    answer[i] = cnt;
  }
  return answer;
}
int main()
{
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  vector<int> B(n);
  for (int i = 0; i < n; i++)
  {
    cin >> B[i];
  }
  // vector<int> answer = findThePrefixArray(A, B);
  // vector<int> answer = findThePrefixCommonArray(A, B);
  vector<int> answer = findPrefixArray(A, B);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  return 0;
}

// Frequency array	Fastest, interview preferred
// ✅ Set approach	Cleaner, easier to think
// 🚀 Pro Tip (Important)

// In interviews:

// First explain brute force (your original)
// Then optimize → frequency method (best answer)
// Mention set approach as alternative