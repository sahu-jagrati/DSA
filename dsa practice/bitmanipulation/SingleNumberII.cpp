// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

// Constraints:

// 1 <= nums.length <= 3 * 10^4
// -2^31 <= nums[i] <= 2^31 - 1
// Each element in nums appears exactly three times except for one element which appears once.

#include <bits/stdc++.h>
using namespace std;

// question says in given array every number appears thrice except one elt

// brute force solution:
// by using hashmap but it takes space
// if we are using ordered map then it takes O(logn) for insert/access
// we are using unordered map so it takes O(1) as an average for insert/access
// t.c-O(n*1)+O(mpp size)
// s.c-O(mpp size)
// as almost all elts appear thrice except once so mpp size=(n/3)+1, where n is size of nums

int singlenumber(vector<int> &nums)
{
  unordered_map<int, int> mpp; // stores (valuemfrequency)
  for (int x : nums)
  {
    mpp[x]++;
  }
  int ans;
  for (auto it : mpp)
  {
    if (it.second == 1)
    {
      ans = it.first;
      break;
    }
  }
  return ans;
}

// better solution: using the bitwise operators

// set bit in binary representation refers to a bit whose value is 1
// unset bit(or cleared bit) whose value is 0

// example: nums=[5,5,5,2,4,4,4]

//                                            2nd 1st 0th bit
// if we write 5 in terms of bitwise it's: 5 -> 1 0 1
// again we have  5 ->                          1 0 1
// again we have 5 ->                           1 0 1
// now we have 2 ->                             0 1 0
// now we have 4 ->                             1 0 0
// again 4 ->                                   1 0 0
// again 4 ->                                   1 0 0

// let us observe something in bitIndex
// In 0th bit because of 5 we have 3 - 1's
// in 1st bit we have 1 - 1's because of 2
// in 2nd bit we have 6 - 1's because of 5 and 4 where 6 is multiple of 3 i.e 6%3==0

// assume instead of 2 in nums if we have 6 then : nums=[5,5,5,6,4,4,4]
//                                            2nd 1st 0th bit
// if we write 5 in terms of bitwise it's: 5 -> 1 0 1
// again we have  5 ->                          1 0 1
// again we have 5 ->                           1 0 1
// now we have 6 ->                             1 1 0
// now we have 4 ->                             1 0 0
// again 4 ->                                   1 0 0
// again 4 ->                                   1 0 0

// now if we see :
// In 0th bit because of 5 we have 3 - 1's where 3%3==0 so this bit will not be set in my original number so it will be unset bit in my original number
// in 1st bit we have 1 - 1's because of 6 so we have 1 - 1's which is not a multiple of 3 there by the first bit is set bit in my number
// in 2nd bit we have 7 - 1's because of 5, 6, and 4 where 7  is not a multiple of 3 i.e 7%3==1 so thereby second bit will also be set bit in my number

// so my number is 1 1 0 where 0th bit is unset bit , 1st bit is set bit and 2nd bit is also set bit so we get:
// 1 1 0 which is 6 so our answer is 6

// so We have to count a set bit for every bit position anf if count is not a multiple of 3 means at that bit position in my  binary answer there is a set bit otherwise it is a unset bit

// so How many bit position will be there? If there are integers we know there will be 0 to 31 bit position means total 32 bit positions we have and for each bit position we have to count a set bit for each elt in nums at that bit position

// t.c-O(32*n)
// s.c-O(1)
int singleNumber(vector<int> &nums)
{
  int n = nums.size();
  int ans = 0;
  // we have bitpositions: 0 to 31
  for (int bitIndex = 0; bitIndex < 32; bitIndex++)
  {
    // count set bit for each bit Index/position for each elt in nums
    int countSetBit = 0;
    for (int i = 0; i < n; i++)
    {
      // if it is a set bit then
      if (nums[i] & (1 << bitIndex))
      {
        countSetBit++;
      }
    }
    // then check for that bit index if total number of set bit is not a multiple of 3 then there will be set bit in that bit index in answer number
    if (countSetBit % 3 == 1)
    {
      ans = ans | (1 << bitIndex);
    }
  }
  return ans;
}

// better solution II : in order to optimize above solution: we will be sorting the given array nums

// suppose nums=[2,2,1,2,1,1,4,3,4,4]
// after sorting, nums=[1,1,1,2,2,2,3,4,4,4]

// I know one thing that our answer is 3, we can see that with the naked eye but how can we compute it? So after sorting We'll take the advantage of one thing that is all the groups with 3 elts are together till a point where the single elt breaks in and then again it is together so there will be a point till which the groups are together and then someone comes in between so we'll take that advantage

// So what we'll do is we'll start with 1st index elt not the 0th index
// after sorting, nums=[1,1,1,2,2,2,3,4,4,4]
// start with 1st index
// so I'm standing at index=1 if this particular group is having all the three elts together though Can I say nums[0] and nums[1] will be same? It will be so I'll check for index = 1 that nums[0]=nums[1]=1 both of them are same fine I still haven't got my number and then I'll move 3 places ahead so now I am at index=1 move 3 places so we go at index=5 again check nums[i-1] and nums[i] so nums[5-1] and nums[5] is same or not? nums[4]=nums[5]=2 same so still haven;t got my number then again move 3 places ahead so now I am at index=5 move 3 places so we go at index=8 now I am satnding at index=8 i.e nums[8]=4 someone got in between the cluster or the group is no more there like it is there but you are not traversing the middle elt anymore of the group and that is only possible if the previous elt and the current elt is not the same , WHy? because the single elt came in between thereby nums[7] and nums[8] are nit same in that scenario the nums[i-1] will be our answer .

// Edge case : corner cases
// i) suppose single elt is at the 0th index then
// example: nums=[2,3,3,3] after sorting
// we always start with index=1 and we check nums[i-1] and nums[i] so here also we check nums[0] and nums[1] they will not match so the answer = nums[i-1]=nums[0], algorithm still works

// ii) suppose single elt is in between we solved that above
// iii) suppose single elt is at the last index like
// nums=[3,3,3,4,4,4,5] we start with index=1 same move 3 place ahead so index=4 same move 3 places ahead so index=7 out of range so in this case we don't find a mismatch then the last elt will always be our answer because it is given that there is always one elt that occurs once .

// So very simple WHat we do is?
// i) sort the given array
// then start from index=1 and go on till size of nums and shifting index by 3 places because we have to go to every middle elt of group and we know if nums[i-1]!=nums[i] means nums[i-1] is our answer and in case when last elt is single means we travel entire numbs and not return then return nums[n-1] is our answer

// t.c-O(nlogn)(for sorting)+O(n/3)
// s.c-O(1)
// but only disadvantage is that we are distorting the given input i.e we change the given input order by sorting it

// and also you might be thinking that how is this solution is better than previous bitwise solution? in previous bitwise solution t.c-O(32*n) and in this solution t.c-O(nlogn) so 32 in logn = log(2^32) which means array size has to be 2^32 near about that's not going to happen that's why this solution is better than previous bitwise solution and also for smaller arrays (logn) will be extremely small while bitwise solution always taking (32*n) no matter what was the size of the array that's why this solution is better than previous bitwise solution
int SingleNumber(vector<int> &nums)
{
  int n = nums.size();
  // sort the array
  sort(nums.begin(), nums.end());
  // start from index=1 and move index 3 places ahead
  // because we have to go to middle elt of group
  for (int i = 1; i < n; i += 3)
  {
    // if previous elt is not = to current the previous elt is our answer
    if (nums[i - 1] != nums[i])
    {
      return nums[i - 1];
    }
  }
  // case when last elt is single , we know question says there is always one elt that occurs once.
  return nums[n - 1];
}

// Optimized solution: using the concepts of buckets
// it's based on bits and the bits will be taking care of everything technically
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << singlenumber(nums) << endl;
  cout << singleNumber(nums) << endl;
  cout << SingleNumber(nums) << endl;
  return 0;
}