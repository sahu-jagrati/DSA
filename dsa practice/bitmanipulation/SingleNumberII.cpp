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

// it's based on bits and the bits will be taking care of everything, technically we just think about one or two numbers and  then the solution is expanded to bigger set of numbers because the bits will be taking care of.
// first of all forget about the array, lets' takes a simple array:
// nums=[2,2,2,1]
// What we need? we need the number that appears once.

// so I'll create three buckets:
// i) ones: here we storing all the numbers which is appearing ones
// ii) twos: here we storing all the numbers which is appearing twice
// iii) threes: here we storing all the numbers which is appearing thrice

// we will do some bitwise to storing them

// nums=[2,2,2,1]

// as of now initially what are the buckets storing?
// ones=0
// twos=0
// threes=0

// What we do next?
// When we'll start traversing:
// index=0,  we have to figure out where will this 2 go, from the naked eye, I know that this 2 will end up at ones right now but programmatically I don't know where it go out of these three buckets , so we have to figure out a way , can I say:

// i) nums[i] will go to ones if it is not in twos, it cannot be in threes for sure because the number at max will appear thrice so if it isn't three it cannot appear four times

// ii) nums[i] will go to twos if it is in ones

// iii) nums[i] will go to threes if it is in twos, Can I say this if it is in twos then only it will go to threes

// These above are three conditions , now we'll have to convert these into bitwise

// What we do is? We take this index[0], nums[0]=2 and we start thinking of an operation that will add and delete because that is what we need to do ? It will go to ones if it is not in twos, go to ones means add, it will go to twos if it is in ones means it will go to twos means we'll be adding to twos and it'll be deleting in ones, after this nums[i] will go to threes if it is in twos means it will go to threes means we'll be adding to threes and it'll be deleting in twos.

// Do we need to go to threes?
// There's no significance of threes if we carefully see we decide if it goes to ones on the basis of twos , we decide if it goes to twos on the basis of ones beyond if we don't need threes, we don't need to store threes for the third variable as of now keep in mind that threes will not be needed anyways

// Let's started we have the first elt, nums[0]=2 , the first elt nums[0]=2 has to go to ones
// What are the operators we know? We know about and(&) operator, or(|) operator, xor(^) operator
// initially we have :

// ones=0
// twos=0
// threes=0
// we are at nums[0]=2
// suppose we have an & operator then (0 & 2)=0 so for adding we cannot use & operator for adding operation
// Can I use a | operator for adding: (0 | 2)=2 , so I can use | operator for adding
// or can I use an ^ operator for adding: (0^2)=2 , so I can also use a ^ operator for adding

// so either of ^ / | operator we will be using to perform the addition operation
// we say it will go to ones if it is not in twos
// So what is the next thing for ones? if it is not in twos

// Let's say we'll be using ^ operator for performing addition operation (for intuition later we discuss) so we have (nums[i]^ones) when we add in ones now what about : if it is not in twos, How do we write if not in twos that's very important? Assume two = 0 and we do kind of a negation like a not operator : ~twos so if twos=0 after ~twos everything will turn out to be 1's if all of them are 0's then they will turn out to be 1's: ~(00000)=11111 by applying not operator and then if we do an & operator between them i.e: ((nums[i]^ones) & (~twos))  what will happen is? it will get into ones if it is not in twos so: (ones^nums[i])(add it in ones) & (~twos)(check it is not in twos, ) then we take & of both , What happend :
// nums[0]=2 and initially ones=0 and twos=0
// and ones= (2^0)&(~0)=(2)&(~0)=2
// so ones=2
// ones= (nums[i]^ones)&(~twos), Why ~twos because it is add in ones if it is not in twos
// Imagine if it was in twos , imagine 2 was in twos  so what is 2 in binary? 10 , and when we try to add in ones so what happens: ~twos=(~2), in binary 2=10 and we do ~(10)=01 and assume ones=0 and nums[i]=2 so what will happens? (0^2)&(~2) What will happen is? if it was in twos it should go to threes? so (0^2)&(~2) so in binary if we see : (10)&(01)=0 so technically we don't push it into ones because we know it's already in twos so it's the third occurence, it's a third occurence

// i) so our first condition in bitwise is clear now: (ones^nums[i])&(~twos)
// Now our question is that Why we don't use | operator instead of ^ operator? let's come to the next index, index=1 and this is 2 i.e nums[1]=2 and ones=2 so if we use the | operator then (ones | nums[1])=(2 | 2)=2 & (~twos)=2 & (~0)= 2 so it never gets deleted means according to ii) condition if it is in ones then it will go in twos but here ones=2 again means it will never deleted that's why we cannot use the | operator so thereby the | operator goes out of the question so we can ^ operator so Can I say I'll again apply the same formula: (ones^nums[i])&(~twos) and here I am saying that nums[i]=2 is not in twos and now twos=0 then we have: (2^2)&(~0)= 0 so eventually get 0 so it is deleted from ones means now ones=0 , remember this it is deleted from ones, so I'm actually deleting it from ones at this point since it is no more than ones means we have ones=0, it has to go into twos

// Now what is the statement for twos? nums[i] will go to twos if it is in ones so for that having it in twos we have to delete it from ones then we add it in twos,it will go to twos if it is in ones means it will go to twos means we'll be adding to twos and it'll be deleting in ones,  if it is not in ones then I put it / I add it to twos  because first it should be deleted from ones then we can add it in twos means : (twos^nums[i])&(~ones) so (two^nums[i])(add it in twos) & (~ones)(delete it from the ones) and we take & of both, I'm checking if it is still there in ones we don't deserve to come to twos because it shouldn't be there in ones now since I'v deleted it that's why this comes in twos , so waht will happen is : twos=0 and nums[i]=2 and ones=0 so: (0^2)&(~0)=2 so now twos=2

// now we move to the next index=2 and nums[2]=2, when we come to this particular 2 What will happen? I will try to make it go over ones which is : (ones^nums[i])&(~twos)=(0^2)&(~2)=0 means it is not in ones then try with twos so we have: (twos^nums[i])&(~ones)=(2^2)&(~0)=0 means it is take it out of twos i.e delete it from twos and we can store it in threes but , Do we need to store in the threes? Why do I need to store it into the threes? I don't need to remember who appears  thrice, I care who is appears once.

// now we move to the next index=3 and nums[3]=1, when we try with ones then we have: (ones^nums[i])&(~twos)=(0^1)&(~0)=1 now in ones we have 1, now if we try to get into the twos what will happen? here twos=0 nums[3]=2 and ones=1 then (twos^nums[i])&(~ones) =(0^2)&(~1)=0 means it will never ever go to twos, it stay in ones and our traversal is finish and we'll find our elt in ones because we want elt that appears ones so it will store in ones so our answer in last is ones.

// You might be thinking that what if we have a lot of numbers and they are not arranged in order because the example we took in that they were arranges so don't worry because everything happens in the bit level it doesnot happens in the number level, it happens at the bit level so when we apply ^ , when we apply & automatically takes care of those bit indexes

// so smaller solution and eventually we can spread it to a bigger one because bit indexes will take care of those bit positions.

// t.c-O(n)
// s.c-O(1)
int single_Number(vector<int> &nums)
{
  int n = nums.size();
  // here we storing all the numbers which is appearing ones
  int ones = 0;
  // here we storing all the numbers which is appearing twos
  int twos = 0;
  // no need to store for thrice because we care only for elt that appears once,  I don't need to remember who appears  thrice, I care who is appears once.
  // traverse the given arrays
  for (int i = 0; i < n; i++)
  {
    // elt appears in ones , if it is not in twos(so we do ~twos)
    // and ^ operator performs addition in ones
    ones = (ones ^ nums[i]) & (~twos);
    // nums[i] will go to twos if it is in ones so for that having it in twos we have to delete it from ones then we add it in twos so for deleting it from ones we do (~ones) then add it in twos so for adding  ^ operator performs addition in twos
    twos = (twos ^ nums[i]) & (~ones);
  }
  return ones; // number that appear once
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
  cout << singlenumber(nums) << endl;
  cout << singleNumber(nums) << endl;
  cout << SingleNumber(nums) << endl;
  return 0;
}