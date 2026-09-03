// You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

// For each queries[i], extract the substring s[li..ri]. Then, perform the following:

// Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
// Let sum be the sum of digits in x. The answer is x * sum.
// Return an array of integers answer where answer[i] is the answer to the ith query.

// Since the answers may be very large, return them modulo 109 + 7.

// Example 1:

// Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]

// Output: [12340, 4, 9]

// Explanation:

// s[0..7] = "10203004"
// x = 1234
// sum = 1 + 2 + 3 + 4 = 10
// Therefore, answer is 1234 * 10 = 12340.
// s[1..3] = "020"
// x = 2
// sum = 2
// Therefore, the answer is 2 * 2 = 4.
// s[4..6] = "300"
// x = 3
// sum = 3
// Therefore, the answer is 3 * 3 = 9.
// Example 2:

// Input: s = "1000", queries = [[0,3],[1,1]]

// Output: [1, 0]

// Explanation:

// s[0..3] = "1000"
// x = 1
// sum = 1
// Therefore, the answer is 1 * 1 = 1.
// s[1..1] = "0"
// x = 0
// sum = 0
// Therefore, the answer is 0 * 0 = 0.
// Example 3:

// Input: s = "9876543210", queries = [[0,9]]

// Output: [444444137]

// Explanation:

// s[0..9] = "9876543210"
// x = 987654321
// sum = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
// Therefore, the answer is 987654321 * 45 = 44444444445.
// We return 44444444445 modulo (109 + 7) = 444444137.

// Constraints:

// 1 <= m == s.length <= 10^5
// s consists of digits only.
// 1 <= queries.length <= 10^5
// queries[i] = [li, ri]
// 0 <= li <= ri < m

#include <bits/stdc++.h>
using namespace std;

int Mod = 1e9 + 7;

// if we use its I version then it give out of range exception because string size is so large so when we extraxt x and multiply it with sum it become more large so we cannot do it manually

// this solution done by me
vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
{
  int n = s.size();
  vector<int> digitArray(n, 0);
  vector<int> prefixSum(n, 0);
  vector<int> prefixStr(n, 0);
  int P = 0;
  if (s[0] - '0' != 0)
  {
    digitArray[0] = s[0] - '0';
    prefixStr[0] = P * 10 + s[0] - '0';
    prefixSum[0] = s[0] - '0';
  }
  for (int i = 1; i < n; i++)
  {
    int digit = s[i] - '0';
    if (digit != 0)
    {
      digitArray[i] = digit;
      prefixStr[i] = prefixStr[i - 1] * 10 + digit;
    }
    else
    {
      prefixStr[i] = prefixStr[i - 1]; // when we have 0 at that index then our value is previous value
    }
    prefixSum[i] = prefixSum[i - 1] + digit; // because adding 0 does not affect
  }
  int m = queries.size();
  vector<int> ans(m);
  for (int i = 0; i < m; i++)
  {
    int l = queries[i][0];
    int r = queries[i][1];
    long long x = 0;
    for (int j = l; j <= r; j++)
    {
      if (digitArray[j] != 0)
      {
        x = (x * 10 + digitArray[j]) % Mod;
      }
    }
    long long sum = 0;
    if (l == 0)
      sum = prefixSum[r];
    else
      sum = prefixSum[r] - prefixSum[l - 1];
    ans[i] = (x * sum) % Mod;
  }
  return ans;
}
// our above code is correct but there is so much unnecessary thing like there is no nedd of digitarray , prefixStr array, and for index=0 no need of check s[0]-'0' !=0

// t.c-
// 1st loop runs n times so O(n)
// second loop run m times and in worst case l can be 0 and r can be n-1 so second loop total runs O(m*n) where m is queries size and n is string size
// total t.c-O(n)+O(m*n)
// s.c-O(n)(for prefixsum array) and ans size is required

// but this code also give time limit exceed because s.size() can be maximum 10^5 and number of queries can also be so much

// this solution done by me
vector<int> sumandmultiply(string s, vector<vector<int>> &queries)
{
  int n = s.size();
  vector<int> prefixSum(n, 0);
  prefixSum[0] = s[0] - '0';

  // loop for prefixSUm
  for (int i = 1; i < n; i++)
  {
    if (s[i] - '0' != 0)
    {
      prefixSum[i] = prefixSum[i - 1] + (s[i] - '0');
    }
    else
    {
      prefixSum[i] = prefixSum[i - 1];
    }
    // no need to check 0 because adding 0 does not affect
  }
  int m = queries.size();
  vector<int> ans(m);
  for (int i = 0; i < m; i++)
  {
    int l = queries[i][0];
    int r = queries[i][1];
    long long x = 0;
    for (int j = l; j <= r; j++)
    {
      if (s[j] - '0' != 0)
      {
        x = (x * 10 + (s[j] - '0')) % Mod; // take Mod here also because this can be also a large number
      }
    }
    long long sum = 0;
    if (l == 0)
      sum = prefixSum[r];
    else
      sum = prefixSum[r] - prefixSum[l - 1];
    ans[i] = (x * sum) % Mod; // again take Mod because after multiply it become so large
  }
  return ans;
}

// optimal solution
// We need to answer two things for every query:

// Sum of non-zero digits
// Number formed by non-zero digits

// The first is easy with prefix sums.

// The second is the tricky part.
// t.c-O(n+q) where n is size of string and q is size of queries
// s.c-O(4*n) for arrays
// T take this solution from chatgpt
vector<int> SumAndMultiply(string s, vector<vector<int>> &queries)
{
  int n = s.size();
  vector<long long> digitSum(n + 1, 0); // store the prefix sum of non-zero digits
  vector<int> cnt(n + 1, 0);            // prefix count of non-zero digits, tells us how many digits survive after removing zeros
  vector<long long> hash(n + 1, 0);     // prefix hash over only non-zero digits
  vector<long long> pow10(n + 1, 1);    // power of 10

  // powers of 10
  for (int i = 1; i <= n; i++)
  {
    pow10[i] = (pow10[i - 1] * 10) % Mod;
  }
  int k = 0; // number of non-zero digits processed
  for (int i = 0; i < n; i++)
  {
    int d = s[i] - '0';
    digitSum[i + 1] = digitSum[i] + d;
    cnt[i + 1] = cnt[i];
    if (d != 0)
    {
      cnt[i + 1]++;
      k++;
      hash[k] = (hash[k - 1] * 10 + d) % Mod;
    }
  }
  vector<int> ans;
  for (auto &q : queries)
  {
    int l = q[0];
    int r = q[1];

    long long sum = digitSum[r + 1] - digitSum[l];

    int left = cnt[l];
    int right = cnt[r + 1];

    int len = right - left;

    long long x = 0;
    if (len == 0)
      x = 0;
    else
    {
      x = (hash[right] - hash[left] * pow10[len] % Mod + Mod) % Mod;
    }
    ans.push_back((x * sum) % Mod);
  }
  return ans;
}
int main()
{
  string s;
  cin >> s;
  int m;
  cin >> m;
  vector<vector<int>> queries(m, vector<int>(2));
  for (int i = 0; i < m; i++)
  {
    cin >> queries[i][0] >> queries[i][1];
  }
  vector<int> ans = SumAndMultiply(s, queries);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}

// To get an optimal solution, we need to avoid scanning every substring for each query.

// Current Solution

// For every query:

// Build x by traversing from l to r → O(r-l+1)
// Compute sum using prefix sum → O(1)

// Overall:

// O(n+q×n)

// Worst case:

// O(nq)

// This is too slow if n, q ≤ 10^5.

// Idea for O(n + q)

// We need to answer two things for every query:

// Sum of non-zero digits
// Number formed by non-zero digits

// The first is easy with prefix sums.

// The second is the tricky part.

// Why normal prefix sum is not enough?

// Example:

// s = "102304"

// Query:

// [0,5]

// Non-zero digits:

// 1 2 3 4

// Number:

// 1234

// The zeros disappear.

// Because digits shift left whenever a zero is removed, a normal prefix hash cannot directly answer the query.

// Data Structures Needed

// Precompute:

// 1. Prefix sum of non-zero digits
// digitSum[i]

// Example

// s = 102304

// digitSum

// 1
// 1
// 3
// 3
// 6
// 10

// Now

// sum = digitSum[r]-digitSum[l-1]
// 2. Prefix count of non-zero digits
// cnt[i]

// Example

// 1 0 2 3 0 4

// cnt

// 1
// 1
// 2
// 3
// 3
// 4

// This tells us how many digits survive after removing zeros.

// 3. Powers of 10
// pow10[i]=10^i mod MOD
// 4. Prefix hash over only non-zero digits

// Suppose

// s = 102304

// Extract

// 1234

// Now build

// hash

// 1
// 12
// 123
// 1234

// using

// hash[i] = hash[i-1]*10 + digit;

// Now every non-zero digit has an index

// digit : 1 2 3 4
// index : 1 2 3 4

// Suppose query

// [2,5]

// Substring

// 2304

// Non-zero digits

// 234

// Using the prefix count, we know:

// first non-zero digit in the query corresponds to position 2 in the compressed array
// last corresponds to position 4

// Now use rolling hash:

// answerHash =
// hash[right]
// -
// hash[left-1]*10^(length)

// Exactly like substring hashing for strings.

// This gives

// 234

// in O(1).

// Complexity

// Preprocessing:

// Prefix sum → O(n)
// Prefix count → O(n)
// Prefix hash → O(n)
// Powers of 10 → O(n)

// Each query:

// Sum → O(1)
// Number → O(1)

// Total:

// O(n+q)

// Space:

// O(n)