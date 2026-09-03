// There are n magicians standing in a line, each having an energy value (positive or negative).
// → This is given as an array energy[].

// You can choose any magician as the starting point.

// After absorbing energy from magician i, you are teleported to magician (i + k) automatically (you cannot choose).

// You keep teleporting by steps of k until you go beyond the last magician.

// The total energy gained is the sum of all energies of magicians you visited.

// Your goal:
// 👉 Find the maximum total energy you can get by choosing the best starting magician.

// example-energy = [2, -3, 1, 4, -1]
// k = 2
// Possible paths:

// Start at i = 0: take magicians 0, 2, 4 → sum = 2 + 1 + (-1) = 2

// Start at i = 1: take magicians 1, 3 → sum = -3 + 4 = 1

// Start at i = 2: take magicians 2, 4 → sum = 1 + (-1) = 0

// Start at i = 3: take magician 3 → sum = 4

// Start at i = 4: take magician 4 → sum = -1

// ✅ Maximum = 4 (starting at index 3

#include <bits/stdc++.h>
using namespace std;

// generate all subarray with adding k to i
// t.c = O(n*k) approx.
// s.c=O(1)
// it is correct but it give time limit exceed for large size array
int maximumEnergy(vector<int> &arr, int k)
{
  int n = arr.size();
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    long long sum = 0;
    int j = i;
    while (j < n)
    {
      sum += arr[j];
      j = j + k;
    }
    maxi = max((long long)maxi, sum);
  }
  return maxi;
}

// same as above code and also give time limit exceed
int MaximumEnergy(vector<int> &arr, int k)
{
  int n = arr.size();
  long long maxi = LLONG_MIN;

  for (int i = 0; i < n; i++)
  {
    vector<long long> preSum;
    long long sum = 0;
    for (int j = i; j < n; j = j + k)
    {
      sum += arr[j];
      preSum.push_back(sum);
    }
    if (!preSum.empty())
    {
      maxi = max(maxi, preSum.back());
    }
  }
  return maxi;
}

// by dp
// t.c=O(n)
// s.c=O(n)
int maxiEnergy(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<long long> dp(n, 0);
  long long maxi = LLONG_MIN;
  for (int i = n - 1; i >= 0; i--)
  {
    // dp[i]=arr[i]+(i+k<n?dp[i+k]:0);
    if (i + k < n)
      dp[i] = arr[i] + dp[i + k];
    else
      dp[i] = arr[i];

    maxi = max(maxi, dp[i]);
  }
  return maxi;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int k;
  cin >> k;
  // int result = maximumEnergy(arr, k);
  // int result = MaximumEnergy(arr, k);
  int result = maxiEnergy(arr, k);
  cout << result << endl;
  return 0;
}