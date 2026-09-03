// this is the solution of longest increasing subsequence using Binary Search which does not give time limit exceed when given array is so large
// in previous solution we solve this problem using recursion, memoization, tabulation, space optimization, and also an algorithmic approach (tabulation in different way ) but these give  time limit exceed  when given array is so large because t.c-O(n^2) and s.c was O(n) this was the best that we had done till now

// here we are using Binary Search to find length of LIS, by using this we can only find the length of LIS, we cannot use this approach to print LIS

// now how do we actually solve this particular problem

// let's take an example:
// nums[]=[1,7,8,4,5,6,-1,9]
// what I'll say is let's try to go across every elt and try to form subsequences so initially when I'm at 1 let's form a subsequence with 1 so {1} next go to 7 so here Do I need to form a new subsequence or Can I just attach it with {1}? answer is attach it with {1} why? because if we form a new subsequence as {7} it will be of length 1 but if I attach it with {1,7} it is still increasing and having a length 2 so we attach it so now we have {1,7} let's move to 8 now again Can we attach it with {1,7} or Will you prefer this ? we can because 8 is still greater than 7 so we have now {1,7,8} now move to next 4 but if we attach 4 in {1,7,8} it will not be increasing because 4 is less than 8 so it will not be increasing so I can either start with 4 only i.e {4} but there is 1 which we can take with 4 so  we have one more new subsequence {1,4} next we go to 5 now 5 cannot attach with {1,7,8} because 8 is greater than 5 but we can attach 5 in our new subsequence {1.4} so we get {1,4,5} next we move to 6 again 6 cannot attach with {1,7,8} because 8 is greater than 6 but we can attach 6 in our new subsequence {1.4,5 so we get {1,4,5,6} next we move to -1 now we cannot attach -1 with {1,7,8} and also cannot attach with {1,4,5,6} so we again make a new subsequence with {-1} next we move to 9 now can I attach 9 with {1,7,8} yes we can so we get {1,7,8,9} or can we attach 9 with {1,4,5,6}? yes we can so we get {1,4,5,6,9} or can we attach 9 with {-1}? yes we can so we get {-1,9} we end with given array and we get three subsequence:
// i) {1,7,8,9} with length=4
// ii) {1,4,5,6,9} with length=5
// iii) {-1,9} with length=2
// so length=5 is the longest and that is the length of the LIS

// but Will we actually go across and generate all these subsequences because it's going to be very hectic and  it's going to be taking a lot of time because if you make new subsequences at every junction it's going to take up a lot of space because if you're aiming to uh make a new subsequence at every step it's gonna take up a lot of space so we will definitely not move this way but this is an intuition which help us to think of binary search

// as I don't need to print LIS we just need length of LIS
// so can I do something like this when I was carrying {1,7,8} and this was done when 4 came in Can I say {1,7,8} let's rewrite 4 over 7 Can I do something like this {1,4,8} i.e rewrite the same subsequence can I do something like this? the answer is yes we can do it because we are just concerned about the length of LIS so when we are at 1 let's have 1 so {1} and when we are at 7 let's have 7 so {1,7} and when we are at 8 let's have 8 so {1,7,8} now when we are at 4 instead of making {1,4} new subsequence we fit 4 in the existing subsequence since we are actually not concerned about printing LIS and we are concerned about just the length of LIS so we fit 4 in the existing subsequence I say 4 can fit here in place of 7 so what we do is we take the 7 out and say 4 can fit here so now we have  {1,4,8} it does not means {1,4,8} is a subsequence you can see in given array also {1,4,8} is not a subsequence because order not match  so  I'm just making sure instead of storing {1,4} separately I stored {1,4}  right over there to save space even if someone like 9 comes in and because I know if 8 is there why 8 is here because previously 7 was there that's the reason 8 is here after 7 that is something which we definitely know so we are sure that before 8 there is something smaller which is 7 and we have overwritten here so we are not concerned about the subsequence that's why what I did is instead of creating a new I overwrote the 7 to 4 because it's okay to overwrite because we are not concerned about LIS, we are concerned about the length so now move to next which is 5 okay where can 5 be either go and create like {1,4,5} or either say let's not create and instead of that let's omit 8 and overwrite 5 here because either you are carrying {1,7,8} or either you are carrying {1,4,5} it still makes the same sense because we are not concerned about LIS, we are concerned about the length now move to next which is 6 where can I have 6 right after 5 in {1,4,5}so we have now {1,4,5,6} now move to next which is -1 where can I have it I can definitely have it over 1 by replacing 1 with -1 i.e overwrite 1 with -1 so we get {-1,4,5,6} next we move to 9 where can I have 9 pright after 6 so we have {-1,4,5,6,9} but remember this is not a subsequence, this gives you a length of the final answer array because you replicate it by putting those values you replicated the same space by putting thos values , you can see in given array also these are not in given order so this method give you only length of LIS not LIS

// why binary search?
// initially we had {1,7,8} and when we got 4 you wanna insert 4 if there was a 4 already then you inserted at that place or you say there is no 4 so please go across and insert it right at the the first element after 4 since we know that our answer array is sorted so in order to insert 4 here you can simply do a binary search and binary search will say 4 will go at place of 7 next we go to 5 so binary search will say the first elt after 5 is 8 so we'll say I'll go here in place of 8 next we have 6 so first elt after 6 is no one so 6 go after 5 so we have {1,4,5,6} next we have -1 so first elt after -1 is 1 so -1 go in place of 1 so we have {-1,4,5,6} next we have 9 so first elt after 9 is no one so 9 go after 6 so we have {-1,4,5,6,9} that's how we get the length that's how we replicate that's the thought process behind the binary search

// so in C++ there exists a function like lower_bound()
// let's take another example:
// nums[]=[1,4,5,4,2,8]
// so we go across and take {1} next we have 4 so take it {1,4} next we have 5 take it {1,4,5} next we have 4 again and in our answer array if there exists a 4 you just rewrite it over 4 because that's you do you don't put it across anywhere else next we have 2 so for 2 we have first elt after 2 is 4 so we rewrite over it so we have now {1,2,5} next we have 8 for 8 we have no first elt after 8 so put 8 after 5 so we have {1,2,5,8} so this is the length = 4

// Can we regenerate the LIS subseqeunce by binary search? answer is no for that we have to store lot of things but we can easily get the length of LIS by binary search because we optimize the space instead of carrying different subsequences we reuse the space and we created it

// our main intention of binary search is if there is an elt as nums[i] find nums[i] or either find first elt that's greater than  nums[i] in an answer array and in C++ this can easily be done using a function called lower_bound() if we are doing a lower_bound() on any array it gives you the index of arr[i] if it exist or gives you first index which is greater than arr[i].

// lower_bound() is a STL algorithm used to find the first position where a given value can be inserted in a sorted range without violating the order. In simple terms, it returns an iterator pointing to the first element that is greater than or equal to (>=) the given value

#include <bits/stdc++.h>
using namespace std;

// t.c-O(nlogn) where n is size of given array, outer for loop runs n times and for binary search i.e lower bound  logn so in worst case each time can be so we have total t.c-O(nlogn)
// s.c-O(n) for temp array in worst case
// there is no time limit exceed in this solution when n is so large

// always remember the temp array is not the LIS subsequence we are just using it to store elts so that we easily do replicate in this not making separate new for other one new subsequence, we are not generating the LIS, we are just get the length of LIS over here
int longestIncreasingSubsequence(vector<int> &nums, int n)
{
  // answer array but it is not a subsequence
  vector<int> temp;
  // first we push the first elt of an given array
  temp.push_back(nums[0]);
  int length = 1; // for answer length
  // next we move from index 1 to n-1
  for (int i = 1; i < n; i++)
  {
    // if last elt of temp is less than current elt then we directly push it
    if (nums[i] > temp.back())
    {
      temp.push_back(nums[i]);
      length++; // when we push elt in temp in else we only replcae elt so in that case length still same not increase
    }
    // when last elt of temp is greater than current then we use binary search by lower_bound() function
    else
    {
      // index of elt that we replace with current elt
      int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin(); // lower_bound() returns an iterator so we do - temp.begin() so iterator-iterator gives value
      // change the current value with index value
      temp[index] = nums[i];
    }
  }
  return length; // we can directly return temp.size() but it take extra time so we use length variable
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
  return 0;
}