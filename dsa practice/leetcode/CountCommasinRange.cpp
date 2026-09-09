// You are given an integer n.

// Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

// In standard formatting:

// A comma is inserted after every three digits from the right.
// Numbers with fewer than 4 digits contain no commas.

// Example 1:

// Input: n = 1002

// Output: 3

// Explanation:

// The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.

// Example 2:

// Input: n = 998

// Output: 0

// Explanation:

// ​​​​​​​All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.

// Constraints:

// 1 <= n <= 10^15

#include <bits/stdc++.h>
using namespace std;

// here our approach is that how many number of commas in that range means when comma=0 what is the range of numbers, when comma =1 what is the range of numbers like
// 1 to 999 - comma=0
// 1000 to 999,999- comma=1
// 1,000,000 to 999,999,999 - comma=2 and so on so we count commas by range
// as if n<1000 then comma=0
// comma start from 1000 so start=1000 now we want the end point of the range which is end=start*1000-1
// for start=1000 , end=1000*1000-1=999,999
// for start = 1,000,000  , end=1,000,000*1000-1=999,999,999 here in this range for all number we have comma =2
// now questions is that how we go to next range
// if we see the pattern here then for group1: start=1
// then for group2: start= start*1000=1*1000=1000
// for group3: start=start*1000 = 1000*1000=1,000,000 and so on for next group

// now we want total number of commas in that range so for that first we have to check that if end>n then we don't take all numbers in that range we want only total number of commas in that range but if n<end in that range we don't count commas for remaining number so
// so totalCountofNumber in that range that we want is = min(n,end)-start +1
// totalCommas in the current range = totalCount*comma where initially we start comma=1 and increase it by 1 for every group i.e for group1 : comma=0 , for group1: comma=1 , for group2: comma=2 and so on
// and we add toatl commas of current range in totalNumber of commas upto n

// t.c-
// here we don't iterate for each number from [1 to n] instead of this
// we run loop after every start*1000 interval
// t.c-log(n) base 1000  - sayad ye wrong ho
// s.c-O(1)
long long countCommas(long long n)
{
  // means when n is from 1 to 999 then there is no commas
  if (n < 1000)
    return 0;
  // from 1000 we have 1 comma like 1000=1,000
  // so start with comma=1
  int comma = 1;
  long long totalComma = 0;
  // as comma start from 1000 i.e 1,000
  long long start = 1000;
  // and comma=1 is for n = 1,000 to 999,999
  // so for comma =1 is end for start*1000-1 i.e end=1000-*1000-1=999,999
  // so for any group  start from start we end at start*1000-1 for that comma
  long long end = start * 1000 - 1;
  // we use while loop to get comma in that range
  while (start <= n)
  {
    // update end for that range
    end = start * end - 1;
    // total count of numbers that we want in that rnage [start,end]
    long long count = min(n, end) - start + 1;
    // now we add total commas of current range in the totalComma
    totalComma += (count * comma);
    // update start for next group
    start *= 1000;
    // and also update comma for next group
    comma++;
  }
  return totalComma;
}

int main()
{
  long long n;
  cin >> n;
  cout << countCommas(n);
  return 0;
}