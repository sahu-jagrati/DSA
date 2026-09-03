// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].

// Input: digits = [9]
// Output: [1,0]
// Explanation: The array represents the integer 9.
// Incrementing by one gives 9 + 1 = 10.
// Thus, the result should be [1,0].

// digits doesn't contain leading 0's

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// this will overflow for large n
// t.c=O(n)+O(n)=O(n)
// s.c=O(ans.size())
vector<int> plusOne(vector<int> &arr, int n)
{
  long long sum = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int value = arr[i];
    sum = sum * 10 + value;
  }
  int increment = sum + 1;
  while (increment > 0)
  {
    int mod = increment % 10;
    ans.push_back(mod);
    increment /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

// correct and efficient way
// t.c=O(n)
// s.c=O(1) because we change in arr itself
vector<int> One(vector<int> &arr, int n)
{
  int carry = 1; // we need to add1
  for (int i = n - 1; i >= 0; i--)
  {
    int sum = arr[i] + carry;
    arr[i] = sum % 10;
    carry = sum / 10;
  }
  if (carry > 0)
  {
    arr.insert(arr.begin(), carry);
  }
  return arr;
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
  // vector<int> answer = plusOne(arr, n);
  vector<int> answer = One(arr, n);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}