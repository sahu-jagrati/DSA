// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 10^9
// All the integers in nums are unique.

// as we know subsequence is a sequence derived from an array by deleting some or no elements without changing the order of the remaining elements.

// while subset is also derived from an array by deleting some or no elts but here we can change the order of the elts i.e in subset order of elts does not matter
// like for an example:
// nums[]=[1,16,7,8,4]
// if we say about subsequence then subsequence can be {1,16,8} maintain the order
// but if we say about subset then subset can be {1,16,8} or can be {1,8,16} or can be {1,7,16} because in subset order of elts does not matter

// now divisible subset
// A.T.Q in subset every pair of elts satisfies either of these one condition :

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0

// for example
// nums[]=[1,16,7,8,4]
// if we take subset - {16,8,4}
// then the pairs can be (16,8),(16,4),(8,4) here and  16%8==0, 16%4==0, 8%4==0  so every pair is divisible we are not saying that 8 is divisible by 16 it can be either way 8%16==0 or 16%8==0 either one can be so 16%8==0 so satisfy

// so we have to find the largest divisible subset
// here in our above example which is the largest divisible subset? it can be {1,16,8,4} is the largest divisible subset because pairing 1 with anyone it is divisible and other pairs is also satisfy one of the divisible condition. so this can be a possible answer . if we add in 7 in this subset then it does not satisfy because if we take pair (4,7) then either 4%7 !=0 or 7%4 !=0 so subset {1,16,7,8,4} can not be answer so our possible answer is {1,16,8,4}

// now given that also that given array has distinct positive integers i.e all the integers in nums are unique and positive
// and also if there are multiple solutions then we can return any of them
// since we are talking about subset then we can print {1,16,8,4} or can print {8,4,16 ,1} or can print {4,1,16,8} we can print any of the answers

// now since they are saying print any answer and we are looking for divisibility we need to convert this problem into somewhere related to longest increasing subsequence because we know in dynamic programming it's generally the subsequence where we deal with the indexes and then we decide whether to pick or notpick we generally know that so can we relate this to somewhere around longest increasing subsequence but how? I'll tell you that what if I sort the given array because since I can print any answer and the order does not matter so even if I sort the given array and I try to find out an answer it is still okay as long as the divisibility is not compromised

// so let's sort the given array
// so given array is nums[]=[1,16,7,8,4]
// sort it
// after sorting we have nums[]=[1,4,7,8,16]
// because it doesn't matter if we sort it whatever answer I get like even if I get {1,4,8,16} that's still okay because subset can be of any order
// now how do we make sure that each of the pairs are divisible?
// since I have sorted it if I'm picking 1 as my first guy and the next guy I pick up 4  and then I say that 4 is divided by 1 i.e 4/1 so if I'm picking up 8 the next guy because I cannot pick up 7 because 7 cannot be divided by 4 but can I pick up 8? Why? because 8 is divisible by 4 . Can I say if 8 is divisible by 4 which eventually means that 8 is also divisible by 1 because 4 is divisible by 1 so 8 has to be divisible by 1 next we get 16 and now 16 is divisible by 8 which indirectly means 16 16 is divisible by 4 and 16 is divisible by 1 also due to the sorted because I've already checked for the divisibility of 4 by 8 and divisibility of 1 by 4 so I can easily say if 16 is divisible by 8 means 16 are divisible by all the elts in the answer array so I can say I can easily pick up 16.

// so did we find the pattern? we did whenever I'm picking up elt i.e for an example when we pick 16 since the array we sort it I am definitely sure if 16 is divisible by 8  then it will be divided by all the other picked elts that's in our answer

// so can I say that once we sort the given array am I looking out to figure longest divisible subsequence and answer is yes why because 4 divided by 1 is true, 8 divided by 4 is true, 16 divided by 8 is true prior to this we we were solving the problem which was longest increasing subsequence like we were talking 1 <3<5<16 this was longest increasing subsequence can I relate this problem to longest divisible subsequence instead of increasing I'm making sure that the next number that is being picked has to be divisible so if we remmeber the code of longest increasing subsequence if I just rewrite the code it was something like this

// this is code of longest increasing subsequence
// for(i=0;i<n;i++){
// for(j=0;j<i;j++){
// if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
// dp[i]=1+dp[j]
// hash[i]=j
//}
//}
//}

// now question is changing to longest divisible subsequence so once the given array is sorted I've changed the question to divisible  so in code of longest increasing subsequence  we  have slight change
// for(i=0;i<n;i++){
// for(j=0;j<i;j++){
// if(arr[i]%arr[j]==0 && 1+dp[j]>dp[i]){
// dp[i]=1+dp[j]
// hash[i]=j
//}
//}
//}

// once we done this then we can use the hash array to tack back the longest divisible subsequence

// the key point is that here we need to sort the given array because if we don't sort the array the logic does not works

#include <bits/stdc++.h>
using namespace std;

// t.c-O(n^2)(for calculating dp and hash array)+O(temp size i.e answer array to backtrack it)
// s.c-O(2*n)(for dp and hash 1D array)+O(answer array size)
// in worst case largest divisible subset can be given array itself then answer size is O(n)
int longestDivisibleSubset(vector<int> &nums, int n)
{
  // the key point is that here we need to sort the given array because if we don't sort the array then the logic of longest increasing subsequence does not works
  sort(nums.begin(), nums.end());

  // now use the concept of printing longest increasing subsequence
  // first we get length
  vector<int> dp(n, 1); // store the length of longest divisible  subsequence that ends at index i and initially assigned to 1 because itself can also
  vector<int> hash(n);  // for backtracking index of an answer subsequence so store index
  int maxi = 1;         // becuase itself
  // I will go from 0 to n-1
  int lastIndex = 0; // for backtrack to print
  for (int index = 0; index < n; index++)
  {
    // hash initially store itself index so
    hash[index] = index;
    // check for previous so go from 0 to index-1
    for (int prev = 0; prev < index; prev++)
    {
      // check current elt is divisible by prev or not, if it is divisible then all elts in answer array is also divisible because we sort the given array
      if (nums[index] % nums[prev] == 0 && 1 + dp[prev] > dp[index])
      {
        // then check current dp value with new one if it is greater then we will store it for getting length of longest divisible subsequence
        dp[index] = 1 + dp[prev];
        hash[index] = prev;
      }
    }
    // for longest divisible subsequence we check each index dp value
    if (dp[index] > maxi)
    {
      maxi = dp[index]; // length of longest divisible subsequence
      lastIndex = index;
    }
  }
  // for printing longest divisible subsequence
  vector<int> temp;
  // lastIndex elt is the elt that has length of longest divisible subsequence so first we push it in our answer
  temp.push_back(nums[lastIndex]);
  // in above example when we track longest divisible subsequence we stop when hash[0]=0 means itself so  we run the loop until hash[lastIndex]==lastIndex when it equal we stop  and we update lastIndex with hash[lastIndex]
  while (hash[lastIndex] != lastIndex)
  {
    // we start with pushing elt already
    lastIndex = hash[lastIndex];
    temp.push_back(nums[lastIndex]);
  }
  reverse(temp.begin(), temp.end());
  // print longest divisible subsequence
  for (auto it : temp)
    cout << it << " ";
  cout << endl;
  return maxi; // length of longest divisible subsequence
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << longestDivisibleSubset(nums, n);
  return 0;
}