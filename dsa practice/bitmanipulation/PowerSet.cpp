// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

#include <bits/stdc++.h>
using namespace std;

// example: nums=[1,2,3]
// for this nums array the first subset will be an empty subset [ ] which doesn't have anything , the second subset will have [1] after that we will have [2] after that we will have [3] so these are the subsets with one element and then we will subsets with two elts which is [1,2], [1,3],[2,3] and after that there is one subset with three elts [1,2,3]
// so power set is [[],[1],[2],[3],[1,2],[2,3],[1,2,3]] so if we count the number of subsets it is 8 so in total there are 8 subsets and our task is to return all of them

// how do we return it?
// so [],[1],[2] ... these are list so what we need to do is we will have to create a list and then include all the lists inside it and this is what we will be returning

// how do we solve it?
// we know the recursive approach but how can we use the bitwise operators

// first we have to know that if let n=nums.size()
// if n=3 then number of subsets are 2^3=8

// so for size n, the number of subsets are 2^n which we can write 1<<n means 1 left shift of n which is equivalent to 2^n so this is we can write in bitwise

// example: nums=[1,2,3]

// so in bitwise we know that there are three numbers or three we can convert it into bitwise as three bit indexes

// we know in bitwise indexes are start from right with 0

// so I'll write 2 1 0  these are bit indexes and what I will do is I'll just use simple boolean logic and it be like we know for n=3 there are 8 subsets so we like in probability we write first 4 head then 4 tail then for other coin 2 head 2 tail 2 head 2 tail then 1 head 1 tail repeated

// here we also do that
// we have 8 subsets so

// indexes are : 2  1  0 <-these are bit indexes start from right
// 0  0  0
// 0  0  1
// 0  1  0
// 0  1  1
// 1  0  0
// 1  0  1
// 1  1  0
// 1  1  1

// if we have 16 subsets then start with 8-8 then 4-4 then 2-2 then 1-1

// so this is how we will start, now what 0 signifies is do not take and 1 signifies take and if I have to write down the indexes
// then in array nums=[1,2,3]
// indexes   ->        0 1 2 in the array

// i) 0 0 0 -> so for the first time it has 0 0 0 so on the 0th bit index it has 0 so we will not take the zero index in the nums array, it is again 0 on 1st bit index so we will not take index 1 in the nums array, again it has 0 bit on the 2nd bit index so we will not take the index 2 in the nums so eventually we will have an empty subset so this is how we will get an empty subset - []

// next we have ii) 0  0  1 -> so here for 0th bit index we have 1 so we will take the 0th index in the array which is [1] so we take it, next at 1 bit index we have 0 so we don't take index 1 in the nums array and next we again have 0 at 2nd bit index so again we don't take so now we have [1]

// next we have iii) 0 1 0 ->so here for 0th bit index we have 0 so we will not take the 0th index in the array , next at 1 bit index we have 1 so we  take index 1 in the nums array which is [2] and next we again have 0 at 2nd bit index so again we don't take so now we have [2]

// next we have iv) 0 1 1-> so here for 0th bit index we have 1 so we will take the 0th index in the array which is [1] so we take it, next at 1 bit index we have 1 so we  take index 1 in the nums array so we have [1,2] and next we again have 0 at 2nd bit index so again we don't take so now we have [1,2]

// next we have v) 1 0 0-> so here for 0th bit index we have 0 so we will not take the 0th index in the array , next at 1 bit index we have 0 so we don't take index 1 in the nums array and next we  have 1 at 2nd bit index so we take so now we have [3]

// next we have vi) 1 0 1-> so here for 0th bit index we have 1 so we will take the 0th index in the array which is [1] so we take it, next at 1 bit index we have 0 so we don't take index 1 in the nums array and next we have 1 at 2nd bit index so we take index 2 in the array so now we have [1,3]

// next we have vii) 1 1 0-> so here for 0th bit index we have 0 so we will not take the 0th index in the array , next at 1 bit index we have 1 so we take index 1 in the nums array and next we have 1 at 2nd bit index so we take index 2 in the array so now we have [2,3]

// next we have viii) 1 1 1-> so here for 0th bit index we have 1 so we will take the 0th index in the array which is [1] so we take it, next at 1 bit index we have 1 so we  take index 1 in the nums array and next we have 1 at 2nd bit index so we take index 2 in the array so now we have [1,2,3]

// so if we do this, it actually works and if I have to write down the numbers in decimal then 0 0 0 is actually 0 then 0 0 1 is 1 in decimal , 0 1 0 is actually 2 in decimal, 0 1 1 is actually 3 in decimal, 1 0 0 is actually 4 in decimal, 1 0 1 is actually 5 in decimal , 1 1 0 is actually 6 in decimal, 1 1 1 is actually 7 in decimal

// so basically what we need to do is need to iterate from 0 to (2^n)-1 where n is size of nums array or number of elts in the set so 0 to till (2^n)-1 this is what we need to iterate and for every binary we have to check the bit indexes like here we have 0 , 1, 2 bit indexes and depending on that we will create our list and eventually when the list is created we store it in list of list so the order doesn't matter and eventually we have to return a list which is containing all the list which are basically subsets so once all the subsets are generated  we have to take the individual list and put it into the bigger list and this is what we will be returning so now we write the psuedo code

// what is our first task? the first task is if n is given as three figure out the number of subsets so we can write it :

// if n is 3 then we have 8 subsets
// no.OfSubsets=1<<n;  // i.e 2^n
// and maybe declare a list answer which is going to store all the list so : ans=[];

// the first step is We know that we have to iterate from 0 to (2^n)-1 so run a loop so we go from 0 to 7 for n=3
// for(num=0 to no.Subset-1){
// first time the num=0 so what do I need to do? I need to check for 0th bit index, 1st bit index, 2nd bit index, three bits or rather 0 1 2 so if n is 3 we will go for 0  1  2 so we will be basically going from maybe we can take it as (0 to n-1) these are bit indexes so
// at evry step we have to create a particular list so we take a list
// vector<int>temp; // for the subset now we have to check whether we take nums array elt or not so for that we have to check the bit indexes value like for n=3 we check the 0th bit, 1st bit, 2nd bit so we have to check the ith bit is set or not, set means 1 or not
// so how do we check that ith bit is  set bit or not for that we do : (num & (1<<i)) if this turns out to be a non-zero number means it is set otherwise it is not so
// for(i=0 to n-1){
// if(num&(1<<i)){ // means this is a set bit and this will be part of subset i.e ith bit is 1 so we take nums[i] value in our subset so
// temp.push_back(nums[i]);
//}
// and for loop is completed, once the for loop is completed it means I have checked from 0 till the last bit(n-1) which is the 2nd if n=3 so we add subset in our ans list
// ans.push_back(temp);
//}
// return ans;
//}

// t.c-
// outer for loop will be taken : O(2^n) because we iterate it from 0 to (2^n)-1 and inner loop taken : O(n)
// so total t.c-O(n*(2^n)) in order to generate all the subsets

// s.c-
// I know there will be 2^n subsets , can I analyze what is the size of each of them? I cannot say that so I can say that s.c is near about (n*(2^n)) because it's not sure that each subset will be of size n

// so we can also use a recursive method which also have similar t.c but there is extra s.c which is auxiliary stack space

vector<vector<int>> powerSet(vector<int> &nums)
{
  int n = nums.size();
  vector<vector<int>> ans;
  int subsets = 1 << n; // which is 2^n
  for (int num = 0; num <= subsets - 1; num++)
  {
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
      // if it is a set bit i.e 1 then take nums value
      if (num & (1 << i))
      {
        temp.push_back(nums[i]);
      }
    }
    ans.push_back(temp);
  }
  return ans;
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
  vector<vector<int>> ans = powerSet(nums);
  for (auto arr : ans)
  {
    for (auto it : arr)
    {
      cout << it << " ";
    }
    cout << endl;
  }
  return 0;
}