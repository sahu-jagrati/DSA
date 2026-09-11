// You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

// Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.

// Example 1:

// Input: digits = [1,2,3,4]

// Output: 12

// Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.

// Example 2:

// Input: digits = [0,2,2]

// Output: 2

// Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.

// Example 3:

// Input: digits = [6,6,6]

// Output: 1

// Explanation: Only 666 can be formed.

// Example 4:

// Input: digits = [1,3,5]

// Output: 0

// Explanation: No even 3-digit numbers can be formed.

// Constraints:

// 3 <= digits.length <= 10
// 0 <= digits[i] <= 9

#include <bits/stdc++.h>
using namespace std;

// I solve this problem by own

// here we want 3-digit unique even number formed by the digit available in digits array

// and for one number we can use each digit only once
// means like we have to make 100 then we can make 100 only if we have frequency of 0 in given array =2 if it is either 1 or 0 then we cann't make this number

// Each copy of a digit can only be used once per number, and there may not be leading zeros

// What I think is that?
// we want 3-digit number and we know 3-digit number start from 100 and end at 999 and in this we want even 3-digit number so we have to check also it should be even and for unique we use set to store so set.size is our answer so we run a loop from 100 to 999 and check each number can I form from a given digits array so for that we make a frequency array that we have this digit this number of times and we have only 0...9 digit to make a number so we make freq array of 10 size so we use according to that and if I can form 3-digit number then I check it is even or not

// first we check can I form 3-digit number  or not by using given given digit in digits array
// t.c-O(3) because each number have 3 digits
// s.c-O(1)
bool canForm(int num, vector<int> &freq)
{
  // freq array store the no.of times each digit given in question and we know
  // for checking we can form number or not we check each digit of num we have in freq array or not if freq[digit]==0 we means we don't have that digit so we cannot form that number so we return false
  while (num > 0)
  {
    int digit = num % 10;
    if (freq[digit] == 0)
    {
      // means  we cannot form the number so we return false
      return false;
    }
    // otherwise we decrease the freq[digit] by 1 because we can use each copy of digit once per number
    freq[digit]--;
    num /= 10;
  }
  return true; // means we can form the number using given digits
}

// if digits.size=n
// and we use unordered set so it take O(1) in average case to insert and getting size
// t.c-O(n)(for freq array construction)+O(999*3)(for check each number from 100 to 999 and each number has 3 digits )
// s.c-O(10)(for freq array)+O(500)(in worst case when we make all 3-digit even number from 100 to 999)=O(1)
int totalNumbers(vector<int> &digits)
{
  // we use set to store unique 3-digit number
  unordered_set<int> st;
  // freq array to store frequency of each digit
  vector<int> freq(10); // we have total 10 digit - 0...9
  for (int x : digits)
  {
    freq[x]++;
  }
  // now we check each 3-digit number from 100 to 999 can I form or not and it is even or not
  for (int i = 100; i < 1000; i++)
  {
    vector<int> temp = freq; // I use temp because when I check can I form number or not I reduce freq. of digit for that number so for checking next number we want all given frequency
    if (canForm(i, temp))
    {
      // check even or not
      if (i % 2 == 0)
      {
        // then push in set
        st.insert(i);
      }
    }
  }
  // total number of unique 3-digit even numbers are = st.size
  return st.size();
}

int main()
{
  int n;
  cin >> n;
  vector<int> digits(n); // having 0...9 any number of times
  for (int i = 0; i < n; i++)
  {
    cin >> digits[i];
  }
  cout << totalNumbers(digits);
  return 0;
}