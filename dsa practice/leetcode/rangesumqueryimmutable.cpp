// Given an integer array nums, handle multiple queries of the following type:

// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

// Example 1:

// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]

// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

// Constraints:

// 1 <= nums.length <= 10^4
// -105 <= nums[i] <= 10^5
// 0 <= left <= right < nums.length
// At most 10^4 calls will be made to sumRange.

#include <bits/stdc++.h>
using namespace std;

// brute force done by me fully
// s.c-O(n) for arr
class NumArray
{
  vector<int> arr;

public:
  // constructor
  NumArray(vector<int> &nums)
  {
    arr = nums;
  }
  // function
  // t.c-O(n) in worst case for one query when left=0 and right=n-1
  //   For every query, you loop from left to right
  // Time per query = O(n) (worst case)
  // If there are many queries → TLE risk
  int sumRange(int left, int right)
  {
    int sum = 0;
    for (int i = left; i <= right; i++)
    {
      sum += arr[i];
    }
    return sum;
  }
};

// optimal solution- prefix sum
// Since the array is immutable, we precompute prefix sums once” means:
// 👉 The array will never change after it is given.
// No updates like:
// nums[i] = x
// insert / delete elements

// When to use this approach?

// ✔ Array does not change
// ✔ Many range sum queries
// ❌ If updates are required → use Fenwick Tree / Segment Tree

// s.c-O(n) for prefix array
class NumsArray
{
  vector<int> prefix; // store the sum of elts upto that index in each index
public:
  // t.c-O(n)
  NumsArray(vector<int> &nums)
  {
    prefix.resize(nums.size() + 1, 0); // initially store 0 for each index, +1 because we make array from 0 to n+1 in which prefix[0]=0 always because for 0 elt sum=0
    // prefix[1]=sum of 1 elt of nums i.e nums[0]+prefix[0]
    //prefix[2]=prefix[1]+nums[1] means sum of 2 elts and we already store sum of 1 elt in prefix[1] and for 1 elt nums[1]
    // and so on 
    for (int i = 0; i < nums.size(); i++)
    {
      prefix[i + 1] = prefix[i] + nums[i];
    }
  }
  // t.c-O(1)
  int sumRanges(int left, int right)
  {
    return prefix[right + 1] - prefix[left]; // we do right+1 because prefix array is 0-based indexing and we store sum in prefix array according to 1-based and we want to include nums[right] also in sum and we don't do left+1 because we also want include nums[left] into sum which is store in prefix[left+1] if we write - prefix[right+1]-prefix[left+1] this exclude nums[left] so we write prefix[right+1]-prefix[left] where prefix[right+1]=prefix[right]+nums[right] and prefix[left]=prefix[left-1]+nums[left-1]
    
  }
};

int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt in an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  // NumArray *numarray = new NumArray(nums);
  // int left, right;
  // cout << "Enter the range: ";
  // cin >> left >> right;
  // int sum1 = numarray->sumRange(left, right);
  // cout << sum1 << endl;
  NumsArray *numarray = new NumsArray(nums);
  int left, right;
  cout << "Enter the range: ";
  cin >> left >> right;
  int sum1 = numarray->sumRanges(left, right);
  cout << sum1 << endl;
  return 0;
}
