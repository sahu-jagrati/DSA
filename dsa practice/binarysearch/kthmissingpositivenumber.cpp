// array is sorted and of positive number
// and max(arr) define upto where the number is take i.e 1 to max(arr)
// we have to find kth missing number like we have array [2,3,4,7,11] so what is 1 to max(arr)
// 1 2 3 4 5 6 7 8 9 10 11
// by seeing in array which numbers are missing
// 1 5 6 8 9
// if k=5 then 5th missing number is 9

// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

// Example 1:

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// Example 2:

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

// Constraints:

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// 1 <= k <= 1000
// arr[i] < arr[j] for 1 <= i < j <= arr.length

// Follow up:

// Could you solve this problem in less than O(n) complexity?
#include <iostream>
#include <vector>
using namespace std;

// brute- do dry run and see how it runs
// time complexity-O(n)
// space complexity-O(1)
int missingNumber(vector<int> &arr, int k)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if (arr[i] <= k)
      k++;
    else
      break;
  }
  return k;
}

// it is typically binary search-
// time complexity-O(n)
// space complexity-O(1)

// optimize-array is sorted so you think of binary search but we can't directly use it and also we can't use binary search in answer range also because we don't find maximum or minimum so we can eliminate some part
// so, how apply binary search
// first we try to find two nearby index of ans- for this we find upto that index how many number are missing like we have arr=[2,3,4,7,11] so in index 0 we have 1 missing number, in index 1 we have 1 missing number, same in index 2, in index 3 we have 3 missing number, in index 4 we have 6 missing number
// find the ans- let k=5 and we discuss arr above so 5th missing number lie btw 3rd and 4th index, at 3rd index we have  3 missing number but we want 5th so more=k-missing=5-3=2 so, 7+1=8+1=9 so, ans=9
// ans=arr[high]+more=arr[high]+k-missing and missing = arr[high]-(high+1) when (low<=high), so overall ans = k+high+1=k+low
// by dry run you can understand clearly
int KthMissingNumber(vector<int> &arr, int k)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int missing = arr[mid] - (mid + 1);
    if (missing < k) // we have less than here
      low = mid + 1;
    else
      high = mid - 1;
  }
  return (k + high + 1);
  // return k+low;
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
  // int result = missingNumber(arr, k);
  int result = KthMissingNumber(arr, k);
  cout << result << endl;
  return 0;
}