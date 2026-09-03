// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

// Example 1:

// Input: nums = [1,1,1,2,2,3]
// Output: 5, nums = [1,1,2,2,3,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,1,2,3,3]
// Output: 7, nums = [0,0,1,1,2,3,3,_,_]
// Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Constraints:

// 1 <= nums.length <= 3 * 10^4
// -10^4 <= nums[i] <= 10^4
// nums is sorted in non-decreasing order.

// Whenever a problem says: sorted array + in-place + O(1) extra space
// we should immediately think: "Can I solve this with two pointers instead of a map/set?"

#include <bits/stdc++.h>
using namespace std;

// Accoding to question we cannot allocate space for another array , we want to modifying the input array in-place with O(1) memory

// I don't used another array but I take ordered map which take space
// brute force solution that take extra space
// I know given input array is sorted in increasing order but still I write this solution

// this run and give correct output but I think this is not good and also question provided that given array is sorted
// Because the array is sorted, we don't need a map at all.
// because ordered map also store elt in sorted order which we already have

// and question specifically ask for O(1) extra memory
// but in my solution: s.c-O(n) in the worst case for map
// and we use ordered map so it takes O(logn) at an average for each elt and here we have n elts
// so total t.c-O(nlogn)

// t.c-O(nlogn)
// s.c-O(n)
// so this is not best solution , it is correct but in question we required space: O(1)

pair<int, vector<int>> removeDuplicates(vector<int> &nums)
{
  int n = nums.size();
  // I used ordered map to store number in sorted order with their frequency
  map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]]++;
  }
  int k = 0; // k is the first k elts of nums where  each elts appears  atmost twice
  int i = 0; // for in-place/modify nums elt so for traverse
  for (auto it : mpp)
  {
    // if frequency of that elt >=2 means we can take only two elts because each elt can appear atmost twice so we for >=2 we take 2 freuquency of them
    if (it.second >= 2)
    {
      k += 2;
      nums[i++] = it.first;
      nums[i++] = it.first; // we place them in front of array
    }
    // when freq<2 means freq=1 because for 0 not elt exist
    else
    {
      k += it.second;       // i.e k+=1
      nums[i++] = it.first; // that elt appear one time in array in front
    }
  }
  return {k, nums}; // where nums is modify array in which first k elt are appear atmost twice and in sorted order, rest k-n elt remain as it is appear in nums
}

// A.T.Q no extra memory , we have to done in O(1) space
// as given that array is sorted so we have to use that
// example:  nums=[1,1,1,2,2,3,3,3]
// all equal values are next to each other.
// We only need to ask: Should I keep this current elt or discard it?
// We are allowed to keep atmost 2 copies.
// So We can always keep the first two elts.
// Why?
// If the array has: [1,1,1,1,2,2,3]
// we want: [1,1,2,2,3]
// After the first two elements, whenever we see another number, we can check: nums[i]!=nums[k-2]
// If true, it means the current number is different from the number that was placed two positions before.
// Therefore,keeping it will not create three copies.

// so we use two-pointer approach:

// example: nums=[1,1,1,2,2,3]
// initially: k=0

// First 1:  if(k<2||x!=nums[k-2])
// k<2 is true
// so: nums[k]=x so nums[0]=1
// k++; k=1

// second 1:  again k<2 is true
// keep it so nums[k]=x so nums[1]=1
// k++; k=2

// third 1: now k<2 is false so check x!=nums[k-2]
// here x=1 and nums[k-2]=nums[2-2]=nums[0]=1
// therefore: 1!=1 is false
// so don't keep this 1. this is exactly what we want

// Now 2
// current x = 2 and k = 2
// check : x!=nums[k-2] which is 2!=1 true.
// so keep it
// nums[k]=nums[2]=x=2
// k++; k=3

// next 2
// x=2 and nums[k-2]=nums[3-2]=nums[1]=1 which is 2!=1 true
// so keep it
// nums[k]=nums[3]=2
// k++; k=4

// next 3
// now: x=3 and nums[k-2]=nums[4-2]=2 which is 3!=2 true
// so keep it
// nums[k]=nums[4]=3
// k++; k=5

// iteration finsh
// Final first k elts: [1,1,2,2,3] and k=5

// Why k-2?
// Suppose we've already constructed: [1,1,2,2,3] and k=5
// Now suppose the next value is 3.
// We check: nums[k-2] which is nums[3] and that is = 2
// Since 3!=2 means we can safely add another 3: [1,1,2,2,3,3]
// But suppose another 3 comes.
// Now: k=6
// Check: nums[k-2]=nums[4]=3
// and current: x=3
// therefore: 3!=3 is false. so we reject it.
// Thus, we can never have 3,3,3 in our result means never have three copies or more than 2 copies in  our result

// t.c-O(n)
// s.c-O(1)

// what is two pointer here? one is k and other is current elt pointer
int removeDuplicatesFromSortedArray(vector<int> &nums)
{
  int k = 0;
  // If the array has: [1,1,1,1,2,2,3]
  // we want: [1,1,2,2,3]
  // After the first two elements, whenever we see another number, we can check: nums[i]!=nums[k-2]
  // If true, it means the current number is different from the number that was placed two positions before.
  // Therefore,keeping it will not create three copies.
  for (int x : nums)
  {
    // we check k<2 for first two elts of given array because for them there is no nums[k-2] means no k-2 index
    if (k < 2 || x != nums[k - 2])
    {
      nums[k] = x;
      k++;
    }
  }
  return k; // Final first k elts
}
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  // array should be sorted
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int ans = removeDuplicatesFromSortedArray(nums);
  cout << ans; // ans is the first k elts
  return 0;
}