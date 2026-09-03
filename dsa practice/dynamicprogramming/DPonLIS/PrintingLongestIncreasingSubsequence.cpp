// here first we learn best method to get length of longest increasing subsequence by learning tabulation method in different way

// let's take an example
// nums[]=[5,4,11,1,16,8]
// now I'll declare a dp of size n i.e dp[n] 1D array
// where dp[i] signifies the longest increasing subsequence that ends at index i
// so here we decalre dp[6] size
// for an example if I ask you what is the longest increasing subsequence that ends with 5(i.e at index=0) we will be like the length is 1 definitely because before 5 I cannot have anyone so dp[0]=1. Similarly, if I ask you what is the  longest increasing subsequence that ends at 4 again length is 1 because 5 cannot be a part of it so 4 only the part of subsequence so dp[1]=1. Similarly, if I ask you what is the  longest increasing subsequence that ends at 11 we can say 5 can be a part of it or we can say 4 can be a part of it so either {5,11} or {4,11} so it can have a length of 2 so dp[2]=2 , next we go to 1 can we have a longest increasing subsequence anyone before 1? answer is no because we  cannot take 5 before 1 or we cannot take 4 before 1 or we cannot take 11 before 1 because we want increasing subsequence so there will be length is 1 for 1 so subsequence is {1} so dp[3]=1, next we go to 16, can we have a longest increasing subsequence anyone before 16? answer is yes I can have 4 before 16 or I can have 5 before 16 or I can have 11 before 16 or I can have 1 before 16 that's one of the ways I can definitely say I can have {5,11} before 16 also or {4,11} before 16 also like there can be a lot of other ways as well like {4,16} so if we figure out  the longest increasing subsequence that ends at index 4 is length=3 that can be either {5,11,16} or {4,11,16} so dp[4]=3 , next we go to 8,can we have a longest increasing subsequence anyone before 8? yes there can be {5,8} or {4,8} or {1,8}. Can I have {11,8}? no. so  the longest increasing subsequence that ends at index 5 is length=2 so dp[5]=2

// so now we get all the  longest increasing subsequence that ends at index i now we have dp[]=[1,1,2,1,3,2]  so know for every index these are the length of longest increasing subsequence that ends at index i

// and the longest increasing subsequence  will be the max(dp[i]) where i ranges from 0 to n-1 so max(dp[i])=3 so answer is 3

// now What's the thought process behind this algorithm?
// we understand this with above example
// let's try to figure out one thing is for sure even if there does not exist any elt before that index   I know the length will always be 1,  max length will be 1 because he itself so initially dp will have all the values assigned to 1 because he itself will be the maximum length for that index  like for index=0 it have no previous elts so this will still stay as one, let's move to the next index for index=1 Does it have any previous elt ? yes it has previous elt which is 5 but 5 is greater than 4 so for index=1 5 cannot be a part of subsequence so for index=1 it will still stay as 1 so dp[1]=1 still and I don't have any other previous elts apart from 5, let's move next to 11 index=2 so does this has previous elt ? yes 5 and 4 are previous elts for 11 . Can 5  become the previous of 11? yes so if there is a subsequence that ends at 5 of length 1 i.e dp[0]=1 so Can I say if I involve 11 in the subsequence of{5} the length will be +1 so dp[3]=1+1 i.e 1+ dp[0], now next previous is 4 again this is of a subsequence length 1 so {4,11} dp[3]=2  but dp[2] is already 2 so no need to update it because I already have a length =2 because of {5,11}, let's move to 1 i.e index=3, now Can 5 be a part with 1? no. Can4 be a part of 1? No. Can 11 be apart of 1 ? No becuase we want increasing subsequence so 1 will be only having a length=1 so dp[3]=1,  next move to 16 i.e index=4 , so Can take 5 and 16? yes so length=1 adds with length=1 makes it length=2. Can 4 be a part of 16? yes so length=1 adds with length=1 makes it length=2 which is already length=2. Can 11 be a part of 16? yes i say {11,16} and 11 in itself is a length=2 i.e dp[2]=2 which is {5,11} or {4,11} so this length=2 can be a part of 16 makes it length=3 so dp[4]=3, next move to 8 i.e index=5 , Can 5 be a part of 8? yes so length =1 adds with length=1 makes it length=2.Can 4 be a part of 8? yes again length=2 which is already . Can 11 ?no . can 1 with 8? yes again length =2 which is already.

// this is how we fill up the entire dp array once we have filled up the entire dp array we figur out the maximumm and here maximum =3 and that is going to be our length of longest increasing subsequence

// so What I'm doing is? I'm starting from index =0 and going on till index=n-1 and whenever we are standing at any index we check for previous indexes from 0 to index-1 and what we are checking? we are saying can the previous be a part of mine or not if it is then the answer will be 1+dp[previous] and I will store that in my current dp i.e dp[current] but I need to compare that nums[prev]<nums[current] if it is then we add 1 + dp[prev] and then compare with myself if it is greater then I'll store it i.e dp[current]=max(dp[current],1+dp[prev]) and at the end of the day the max(dp[i]) will be my answer.

#include <bits/stdc++.h>
using namespace std;

// that's how this algo. works
// why dp? because we are storing the previous states
// t.c still O(n*n) // it give time limit exceed if n goes to 10^5 because it still n*n become 10^5 * 10^5 = 10^10
// but s.c now boiled down to O(n) for only 1D dp array
int longestIncreasingSubsequence(vector<int> &nums, int n)
{
  // declare dp of size n 1D array
  vector<int> dp(n, 1); // initially assigned to 1 because for itself length is 1

  // for answer
  int maxi = 1; // becuase itself
  // I will go from 0 to n-1
  for (int index = 0; index < n; index++)
  {
    // check for previous so go from 0 to index-1
    for (int prev = 0; prev < index; prev++)
    {
      // check prev elt is smaller or not
      if (nums[prev] < nums[index])
      {
        // then check current dp value with new one if it is greater then we will store it
        dp[index] = max(dp[index], 1 + dp[prev]);
      }
    }
    // for longest increasing subsequence we check each index dp value
    maxi = max(maxi, dp[index]);
  }
  return maxi;
}

// now above solution still give time limit exceed when n increasing so much because of n*n t.c
// we required this solution if we want to print the longest increasing subsequence

// what we will do is as of now we were creating a dp array and we were initially saying everyone to be 1 in dp now let's create one backtrack array that backtrack previous index  lets' assume just name as hash and initially  assigned the index himself so hash[]=[0,1,2,3,4,5] we initially assign index itself to it we do this for above example

// so we have now nums[]=[5,4,11,1,16,8]
// initially, dp[]=[1,1,1,1,1,1]
// and hash[]=[0,1,2,3,4,5]
// now start from index=0
// over here 5 it does not have any previous so it will have dp[0]=1 and hash[0]=0 still because we have no previous now move to next so for 4, 5 cannot be so dp[1]=1 and hash[1]=1 now move to next so for 11 Can we say before 11 there was this index 0 so store hash[2]=0 because before 11 there was an index 0 which has 5 and dp[2]=1+1=2 , now we had 4 before 11 again dp[2]=2 no need to update, next move to 1 and for 1 no prev cannot be part so dp[3] still 1 and hash[3]=3,next move to 16 it says that 5 can be part of 16 so dp[4]=1+1=2 and hash[4]=0 and 4 again give dp[4]=2 so no need to update next we have 11 can be a part so dp[4]=1+2=3 sp now dp[4] update from2 to 3 and it coming from 11 which is index=2 so hash[4] now store index =2 so hash[4]=2, next move to 8 for 8 we can have 5 so dp[5]=1+1=2 amd hash[5]=0 and 4 can also but still same so no need to update, now the longest increasing subsequence we get at index=4 because dp[4]=3 so answer sunseqeunce has {16} and hash[4]=2  so we get backtrack to index=2 so nums[2] is also in answer so {16,11} and hash[2]=0 so backtrack to index=0 so nums[0] is also in answer so {16,11,5} and hash[0]=0 itself so stop so we get answer={16,11,5} reverse it so {5,11,16} is our answer with length=3

// t.c-O(n*n)(for length)+O(length of LIS)(for while loop)
// s.c-O(n)*2 for dp and hash 1D array + O(temp size) whihc is length of LIS
int printLongestIncreasingSubsequence(vector<int> &nums, int n)
{
  // first we get length of LIS
  vector<int> dp(n, 1); // store the length of longest increasing subsequence that ends at index i and initially assigned to 1 because itself can also
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
      // check prev elt is smaller or not
      if (nums[prev] < nums[index] && 1 + dp[prev] > dp[index])
      {
        // then check current dp value with new one if it is greater then we will store it
        dp[index] = 1 + dp[prev];
        hash[index] = prev;
      }
    }
    // for longest increasing subsequence we check each index dp value
    if (dp[index] > maxi)
    {
      maxi = dp[index]; // length of longest increasing subsequence
      lastIndex = index;
    }
  }
  // for print LIS
  vector<int> temp;
  // lastIndex elt is the elt that has length of longest increasing subsequence so first we push it in our answer
  temp.push_back(nums[lastIndex]);
  // in above example when we track longest increasing subsequence we stop when hash[0]=0 means itself so  we run the loop until hash[lastIndex]==lastIndex when it equal we stop  and we update lastIndex with hash[lastIndex]
  while (hash[lastIndex] != lastIndex)
  {
    // we start with pushing elt already
    lastIndex = hash[lastIndex];
    temp.push_back(nums[lastIndex]);
  }
  reverse(temp.begin(), temp.end());
  // print LIS
  for (auto it : temp)
    cout << it << " ";
  cout << endl;
  return maxi; // length of LIS
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
  cout << longestIncreasingSubsequence(nums, n) << endl;
  cout << printLongestIncreasingSubsequence(nums, n);
  return 0;
}