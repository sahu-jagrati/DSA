// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 10^9

#include <bits/stdc++.h>
using namespace std;

// in this problem we want a largest number by concatenating the integers of nums
// so as a intgere it is difficult to concatenate because  like we have nums=[10,2] we don't want addition means 10+2=12 no we don't want this, we want concatenation means by arranging these intgers of nums we want largest numbers that we can form here I can form two number by concatenation first="102" or second="210" here 210>102 so we return 210 here concatenation can done by string easily

// as we want largest number that we can form by given integer array so
// i) we convert the given array of integers into the array of string because concatenation in string is very easy and can compare easily which is larger so
// ii) we want largest number:
// if we try to sort the array in descending order but not normally means we want sort the array like first we get all numbers starting with 9 and in that case they also sort in apne aap mean suppose we have 90 and 9 we take 9 first then 90 because concatenate 990>909 so then we go for 8 then 7 and so on  , we first go with 9 because number starting with 9 si larger than number starting with 8 to 1

// iii) To sort the array like [3,30,34,5,9] of strings in descending order to form the largest possible number, the correctly sorted order is ['9','5','34','3','30']
// here you can see we takes 3 before 30 because

// WHy standary sorting fails?
// Standard Alphabetical(Lexicographical) Sorting: Results in ['9','5','34','30','3'] because "34">"30">"3". However, concatenating this gives 9534303.

// The better concatenation: If we put 3 before 30, we get 330, which is greater than 303.

// To fix this, we must use a custom operator that compares combinations of elements : a+b vs b+a and here a+b and b+a is not addition, it is concatenation of two string and then check whick one is greater, suppose we have a="3" and b="30" so a+b="330" and b+a="303" so "330" > "303"

// there is an edge case if we have an array full of zeroes like ["0","0"] then in that case answer is "0" only not "00"

// we must add a check after sorting , if the largest number at the beginning of your sorted array is "0", the entire result must be simplified to just a single "0" instead of "000" because if number has 1/2/3... then it start with either one of them but it begins with 0 means there is no other digit so simply we return single digit "0"

// t.c-O(n)(for construct temp array)+O(nlogn)(for sorting)+O(n)(for construct ans string)=O(nlogn) where n is size of nums array given
// s.c-O(n)(for temp array)+O(n)(for ans string)
string largestNumber(vector<int> &nums)
{
  // first we convert our integer array into string array so we easily sort them by applying custom operator
  vector<string> temp;
  for (int x : nums)
  {
    temp.push_back(to_string(x));
  }
  // now we sort the string array using a custom operator that compares combinations of elements : a+b vs b+a because  here if we sort according to lexicographically it fails and here a+b and b+a is not addition, it is concatenation of two string and then check whick one is greater, suppose we have a="3" and b="30" so a+b="330" and b+a="303" so "330" > "303"
  sort(temp.begin(), temp.end(), [](const string &a, const string &b)
       { return (a + b) > (b + a); });
  // edge case when the largest number at the beginning of your sorted array is "0", the entire result must be simplified to just a single "0" instead of "000"
  if (temp[0] == "0")
    return "0";
  string ans = "";
  for (auto st : temp)
  {
    ans += st;
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
  cout << largestNumber(nums);
  return 0;
}