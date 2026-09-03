// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"
// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"
// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"

// Constraints:

// 1 <= num1.length, num2.length <= 10^4
// num1 and num2 consist of only digits.
// num1 and num2 don't have any leading zeros except for the zero itself.

#include <bits/stdc++.h>
using namespace std;

// I solve this problem fully by own
// we know addition of number start from back
// so here we also start from back
// and we take one variable 'carry' to store carry so we can add it in next

// example: num1="456" and num2="77"
// n=3 and m=2
// start with i=2 and j=1 and ans=""
// and carry =0 initially
// sum=carry=0
// sum+=6=6
// sum+=7 =6+7=13
// ans+=(13%10)= 3 as a character
// carry=13/10=1
// again sum=carry=1
// sum+=1=5+1=6
// sum+=7=6+7=13
// ans+=(13%10)=3 so we get ans=33 as a string
// carry=13/10=1
// now num2 finish so we go with num1 only
// again sum=carry=1
// sum+=4=1+4=5
// ans+=(5%10)=5 so we get ans=335 as a string
// carry=5/10=0
// now num1 is also finish
// and we have carry=0 so if condition also not exist
// so now we reverse the ans so we get ans=533 as a string
// now our answer is "533"

// t.c-O(n+m) because we traverse each char of both string once
// s.c-O(1) because answer string is required so here I don't mention it
string addStrings(string num1, string num2)
{
  int n = num1.size();
  int m = num2.size();
  int i = n - 1, j = m - 1;
  string ans = ""; // empty answer string
  int carry = 0;
  // we traverse from back and check both iteration should be >=0
  while (i >= 0 && j >= 0)
  {
    int sum = carry;      // initially sum=carry because we add carry of previous in next
    sum += num1[i] - '0'; // here first we convert character into digit and then add it in sum
    sum += num2[j] - '0'; // similary here also
    // str += to_string(sum % 10); // the digit that we add in final string is sum%10 because if sum>9 then means there is carry for next so sum%10 and we convert digit into string for add in answer string or we can convert sum%10 in character by +'0'
    ans += (sum % 10) + '0';
    carry = sum / 10; // carry for next
    i--;
    j--;
  }
  // this is when we have only num1 character means num2 is finish
  while (i >= 0)
  {
    int sum = carry;
    sum += num1[i] - '0';
    // str += to_string(sum % 10); // we can do +'0' also instead of to_string
    ans += (sum % 10) + '0';
    carry = sum / 10;
    i--;
  }
  // this is when we have only num2 character means num1 is finish
  while (j >= 0)
  {
    int sum = carry;
    sum += num2[j] - '0';
    // str += to_string(sum % 10); // we can do +'0' also instead of to_string
    ans += (sum % 10) + '0';
    carry = sum / 10;
    j--;
  }
  // this is when carry only left so we simply add it in ans string
  if (carry)
  {
    // str += to_string(carry); // we can do +'0' also instead of to_string
    ans += carry + '0';
  }
  // we reverse the ans string because we do addition from back so in ans string we add the number from back so
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  string num1, num2;
  cin >> num1 >> num2;

  cout << addStrings(num1, num2);

  return 0;
}