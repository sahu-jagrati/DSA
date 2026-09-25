// Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

// All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

// Note: You are not allowed to use any built-in library method to directly solve this problem.

// Example 1:

// Input: num = 26
// Output: "1a"
// Example 2:

// Input: num = -1
// Output: "ffffffff"

// Constraints:

// -2^31 <= num <= 2^31 - 1

#include <bits/stdc++.h>
using namespace std;

// we use simple method : repeated divison of 16
// Hexadecimal is a base-16 system so when we divide num with 16 we get remainder from 0 to 15 so it uses the digits 0-9 for values zero through nine, and the letters A-F to represent the remainders values 10 through 15.
// A=10, B=11,C=12,D=13,E=14,F=15

// algorithm to convert base-10 integer (given) into base-16 number:

// Step-1: Divide the decimal integer by 16.
// Step-2: Get the integer quotient = num for next step and add the remainder in answer string.
// Step-3: Convert any remainder between 10 and 15 into its corresponding letter(A-F).
// Step-3: Repeat the process with the quotient until our quotient becomes 0
// Step-4: Reverse the answer string of remainders and after reversing it is our answer

// example: Suppose num=26
// 1. 26/16=1 with a remainder of 10 which is 'A' but question say convert it in lower case so 'a'
// 2. 1/16=0 with a remainder of 1
// Now read the remainders from the bottome to the top(or reverse order): 1,a
// answer="1a"