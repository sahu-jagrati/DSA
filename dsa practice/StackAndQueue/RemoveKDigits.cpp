// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// Constraints:

// 1 <= k <= num.length <= 10^5
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

#include <bits/stdc++.h>
using namespace std;

// here we want a smallest possible integer after removing k digits from given num.

// so for getting smallest integer, initial digits should be smaller means a number start from 9 and a number start from 1 in this a number start from 1 is smaller than a number start from 9

// so our main intuition is that : keep smaller digits at the start and get rid(remove) of the larger digit and we have condition that we can only remove k digits

// so here we use stack to store the digits
// and we want smaller digit in start so we start traversing from left to right i.e index 0 to n-1 in given nums

// example- num="1432219" , k=3

// initially stack is empty
// index                   stack         k

// we are at index 0 and having digit=1 , in stack there is nothing so no larger digit we simply push 1 in stack

//  0                         1           3
// now we are at index=1 , num[1]=4 which is greater than st.top() so there is no need to remove 1 from stack because 1 is smaller than 4 so integer starting from 1 is smaller than 4 so we simply push 4 in stack

//  1                        1,4           3

// now at index=2, num[2]=3 which is smaller than st.top() so we have to remove the 4 from the stack because integer 14 > 13 so we pop 4 from stack then at top we have 1 and integer start from 1 is smaller than 3 so we simply push 3 in stack and reduce k-- and we get k=2>0 because we remove 4

//  2                        1,3           2

// now at  index=3, num[3]=2 which is smaller than st.top() so we have to remove the 3 from the stack because integer 13 > 12 so we pop 3 from stack then at top we have 1 and integer start from 1 is smaller than 2 so we simply push 2 in stack and reduce k-- and we get k=1>0 because we remove 3

//  3                        1,2            1

// now at index = 4, num[4]=2 which is equal to st.top() so there is no meaning to remove 2  because we have now 12 and by removing 2 and again adding 2 give same so we don't remove 2, we simply push next 2 in stack

//  4                        1,2,2          1
// now at index=5. num[5]=1 which is smaller than st.top() so we have to remove the 2 from the stack because integer 122 > 121 so we pop 2 from stack then at top we have 2  but we cannot remove because after removing first 2 from stack we get k=0 means we cannot remove any digits now   so we simply push 21 in stack and reduce k--  and we get k=0 means now we cannot remove any digits and because we remove one 2

// 5                       1,2,1           0

// now k==0 so we cannot remove any digits so remaining digits of num we simply push in stack
//  6                     1,2,1,9           0

// so in stack whatever we have is our inetger after removing k larger digits

// so we get "9121" from the stack but it is not in the correct order so reverse it

// ans="1219"

// edge cases:
// we know k<=n , where n is the size of the given string num

// i) if k==n  remove all digits so in that case return "0"

// ii) after removing k digits we get something like "00100". Is this a valid number? no, valid number is "100" so we have to remove the larding zeroes from the answer, there is also a case when we get "0000" means all are leading zeores so in that case we return "0"

// iii) suppose num="123456" and k=3
// here  we traverse the given num from left to right and stack will always contain smaller elt then in stack we have something like this : 1,2,3,4,5,6 so after the complete traversal we have not removed anything , k is still 3 so in that case we take off the last k digits from the stack so here we remove last 3 digits from the stack and we get "321" after reverse ans="123"

// iv) we remove digits from the stack and traversal on given num is complete but still we have k>0 means left over to remove something in that case we also take off the last remaining k digits from the end of the stack

// Algorithm:
// Use a stack to store digits of the resulting number
// Iterate through each digit of the input string from left to right i.e 0 to n-1
// While the stack is not empty, the current digit is smaller than the top of the stack, and k is greater than 0, pop from the stack and decrement k by 1
// Push the current digit onto the stack
// If k is still greater than 0 after the complete iteration(i.e traversal), remove remaining k digits from the end of the stack
// Collect the remaining digits from the stack to form the result
// and we reverse the result to get answer in the given order
// Remove any leading zeroes from the result
// If the result is empty after removing zeroes, return "0"

// function to find the smallest possible integer after removing k digits

// t.c-
// O(n)(for traversing)+O(k)(for inner while loop to remove k digits)+O(k)(in worst case if inner while loop of for loop no run)+O(n)(in worst case)+(O(n)(if in answer all are zeroes then popping them)+O(n)(for reverse)=O(n) overall for trimming zerores and reverse(because popping zeores and reverse remaining elts) example: )"131000")

// toatl t.c-O(3n)+O(2k) as k<=n
// so t.c=O(n) approx
// s.c-O(n)(for stack in worst case)+O(n)(for  storing answer)
string removeKdigits(string &nums, int k)
{
  stack<char> st; // to store digits of the resulting number as a char
  // traverse on the given string from left to right
  for (int i = 0; i < nums.size(); i++)
  {
    // current digit
    char digit = nums[i];
    // While the stack is not empty, the current digit is smaller than the top of the stack, and k is greater than 0, pop from the stack and decrement k by 1
    // pop last digits(when possible) if a smaller digit is found
    while (!st.empty() && k > 0 && (st.top() > digit))
    {
      st.pop(); // pop the last digit
      k--;      // decrement k by 1
    }
    // push the current digit
    st.push(digit);
  }
  // iii) and iv) edge case when after complete traversal on give string we have not removed anything or still left over to remove something means we still have k>0 in that case take off last k digits from the end of the stack
  while (!st.empty() && k > 0)
  {
    st.pop(); // pop the last added digits
    k--;      // decrement k by 1
  }
  // i) edge case when k==nums.size
  if (st.empty())
    return "0";
  // to store the result
  string ans = "";
  // adding digits in stack to ans
  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }
  // trimming the zeroes at the back , now here first we remove the zeores from the back so after reversing we don't get leading zeroes
  while (ans.size() > 0 && ans.back() == '0')
  {
    ans.pop_back();
  }
  // reverse to get the answer in actual order
  reverse(ans.begin(), ans.end());
  // edge case after trimming zeores we get empty answer means answer="0000" so we trim all zeroes
  if (ans.empty())
    return "0";
  // return the stored answer in actual order
  return ans;
}

int main()
{
  string nums;
  cin >> nums;
  int k;
  cin >> k;
  cout << removeKdigits(nums, k);
  return 0;
}