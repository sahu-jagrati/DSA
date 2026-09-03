// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// // Find the number that occurs twice and the number that is missing and return them in the form of an array.

// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]

// Example 2:
// Input: nums = [1,1]
// Output: [1,2]

#include <bits/stdc++.h>
using namespace std;

// we have to store
// duplicate first
// missing second

// Time & Space Complexity

// Time Complexity: O(N)

// Space Complexity: O(N) (because of hashmap)
vector<int> findErrorNums(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]]++;
  }
  // vector<int> ans;
  // here we use two loops,

  // for (auto it : mpp)
  // {
  //   if (it.second > 1)
  //   {
  //     ans.push_back(it.first);
  //   }
  // }
  // for (int i = 1; i <= n; i++)
  // {
  //   if (mpp[i] == 0)
  //     ans.push_back(i);
  // }

  // we done in single loop but it is not in order(duplicate,missing)
  // for(int i=1;i<=n;i++){
  //   if(mpp[i]==2){
  //     ans.push_back(i);
  //   }
  //   else if(mpp[i]==0){
  //     ans.push_back(i);
  //   }
  // }

  // this give in order-{duplicate,missing}
  int duplicate = -1, missing = -1;
  for (int i = 1; i <= n; i++)
  {
    if (mpp[i] == 2)
    {
      duplicate = i;
    }
    else if (mpp[i] == 0)
    {
      missing = i;
    }
  }
  return {duplicate, missing};
}

// solution that done in space O(1)
// math approach-
// sum of n natural number-S=n(n+1)/2
// sum of square of n natural number-S2=n(n+1)(2n+1)/6
// but according to our array we have one duplicate(D) and one missing(M) so S'=S+D-M and S2'=S2+D^2-M^2
// D-M=S'-S=A(say)
// D+M=(S2'-S2)/S'-S=B(say)
// after solving these equation
// D=((D-M)+(D+M))/2=(A+B)/2
// M=D-(D-M)=(D-A)

// t.c-O(n) n is length of array
// s.c-O(1)
vector<int> find(vector<int> &nums)
{
  long long n = nums.size();
  long long S = n * (n + 1) / 2;
  long long S2 = n * (n + 1) * (2 * n + 1) / 6;

  long long S_actual = 0;
  long long S2_actual = 0;

  for (int i = 0; i < n; i++)
  {
    S_actual += nums[i];
    S2_actual += 1LL * nums[i] * nums[i];
  }
  // D-M
  long long diff = S_actual - S;
  // D^2 - M^2
  long long diff2 = S2_actual - S2;

  // D+M
  long long sum = diff2 / diff;

  int duplicate = (diff + sum) / 2;
  int missing = duplicate - diff;

  return {duplicate, missing};
}
int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt in an array(in which one number is repeated twice and one is missing from 1 to n): ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  // vector<int> result = findErrorNums(nums);
  vector<int> result = find(nums);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}