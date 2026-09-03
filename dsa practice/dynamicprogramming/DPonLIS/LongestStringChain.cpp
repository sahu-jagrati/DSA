// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// to solve this problem first see LIS problem solution

// now for an example:
// Input: words = ["a","b","ba","bca","bda","bdca"]
// here what is string chain ?
// if we take ["a","ba","bda"] this is a chain
// ["a","ba","bca"] this is a chain
// ["b","ba","bca"] this is a chain

// what do you mean by a chain?
// in chain the first guy can be anything it is not compulsion that it has to be a single character it can be any word after that if you insert one character in that word you get the next word so if we take - ["a","ba","bca"] here the first guy is "a" and in this if we insert 'b' then we get next word "ba" now in that if we insert 'c' then we get next word "bca" . Similarly, if we take - ["a","ba","bda"] here the first guy is "a" and in this if we insert 'b' then we get next word "ba" now in that if we insert 'd' then we get next word "bda" . So that is string chain . if we are talking about previous word in a chain then the previous word should be one deletion qi.e by deleting one character from current word we get previous word. So that is string chain, in the chain if we have just added one character in that word at any given place then we can call this a chain.

// now we have to find the longest chain among all the possible chains
// so in our above example which will be the longest chain?
// if we take chain like this - ["a","ba","bca","bdca"] because in "a" if we insert 'b' we get "ba" then in this if we insert 'c' we get "bca" then in this if we insert 'd' we get "bdca" so can I say the longest string chain here is - ["a","ba","bca","bdca"] and the length is 4 .

// so the question states we have to print the length of longest string chain, even we can print the sequence.

// now how do we solve this particular problem?
// Can we relate this problem to somewhere related to longest increasing subsequence? let's relate so what was a longest increasing subsequence this was saying it is subsequence now does it match longest string chain or we can say longest string subsequence so if we match both then subsequence and subsequence does match, longest and longest does match only problem is string and increasing.

// In LIS if we remember it was like {1,4,3,7,10} then I was like {1,4,7,10} is LIS because 4>1, 7>4 , 10>7 so we were saying greater over here and in this problem we say strings over here are part of it because instead of greater can I say the difference is one character i.e the difference between them is one character so can I say instead of increasing if I can check the difference to be one character then the question is much similar to LIS so if we remember the LIS code :

// LIS code

// for(i=0;i<n;i++){
// for(j=0j<i;j++){
// if(arr[j]<arr[i]&&1+dp[j]>dp[i]){
// dp[i]=1+dp[j]
//}
//}
//}

// so above code is for LIS now I'm looking for a similar structue of subsequence but the problem is when I have two strings, in LIS we had two integers like 4 and 7 and we compared if 7>4 but over here we have two strings assumes that if arr[i] in LIS code is string1 and arr[j] in LIS code is string2 can I say I just need to compare if they are differentiating by one character can I say I need to compare them if they are differentiating by one character if they are can I say it's going to be the same problem instead of increasing I just need to make sure if I'm taking "bca" and the previous guy "ba" then it should be just an addition of character which makes "bca" that is what I need to compare so if I can write the compare I think that my problen will be solved and I can get the maximum like maxi=max(maxi,dp[i]) and I can say that's maxi is my answer so there is a shuttle changes in LIS code  if we can compare(arr[i],arr[j]) and see that they are differentiating by one character like we can form arr[i] which is the word by inserting one characterr on arr[j] that's what we need to check.

// Assuming that I take arr[i]="bdca" and arr[j]="bda" this is definitely possible because if we insert a 'c' in arr[j] then we get "bdca" but how do we write that function to check it's .

// What we do is we write "bdca" okay we keep a pointer p1 over 'b' in this and we write "bda" and keep a pointer p2 over 'b' in "bda" now they are matching so they are just move the pointer now  next p1 points 'd' in "bdca" and pointer p2 points 'd' in "bda" they are matching so just move the pointers now  next p1 points 'c' in "bdca" and pointer p2 points 'a' in "bda" Are they matching? no just move the pointer and remember this 'c' did not match with 'a' so we just moved pointer p1 to 'a'  so now p1 points 'a' in "bdca" now Are they matching? yes move p1 and p2  it ends so at the end we see both pointers reached the end,  both of them reach the end simultaneously it's very important simultaneously then we can say they're matching

// but do we have any other cases let's see for a case where it's not an insertion at the end assum arr[j]="bcd" and arr[i]="bcda" this is possible because inserting 'a' in arr[j] we get arr[i] so this is possible so instead of checking this we are checking is it possible or not. now what we do is we say let's keep pointer p1 to 'b' in "bcda" and keep pointer p2 to 'b' in "bcd" so they are matching let's move next 'c' matches let's move next 'd' they are matching let's move here so now pointer p1 is at 'a' and pointer p2  finish so 'a' does  not matches so lets' move pointer p1 to next so if at the end of the day again we have simultaneous like we have reached the end for both the strings it is indeed possible so if it is possible that's how we can do it we just need to match it so and one more thing is if  arr[j] is of length 3 then arr[i] has to be length 4 that's for susre otherwise it's definitely not possible because there are only one differnece character so first check for length then we can check for character matching because the character has to be same so we just need to write the compare function in code of LIS

// so running this we will see that we are getting wrong answers on some cases why does that happen because we solve this question thinking of subsequence but if I give you an example like ["xbc","pcxbcf","xb","cxbc","pcxbc"] so here first guy is "xb" then we take "xbc" the "cxbc" the "pcxbc" then "pcxbcf" so we were saying that the longest length will be 5 right but over here we see that we don't care about subsequence i.e we don't care about the order of string given in the question we can pick up from anywhere because question says sequence not subsequence so we can  pick up from anywhere so it is a subset instead of subsequence and if it's a subset we have done this in previous problem Large Divisible Subset what we do we can just sort them because for an example somewhere we have after sort ["xb","xbc","cxbc","pcxbc","pcxbcf"] so if we have sorted them then it would have automatically taken care of the length so we sort the given array of string on the basis of length
bool checkPossible(string &str1, string &str2)
{
  // first we check that there is only difference of 1 in their length
  // so prev string size is 1 less than that the current string
  if (str1.size() != str2.size() + 1)
    return false;

  // like if we take an example that str1="bdca" and str2="bda"
  // so first pointer move in str1 and second pointer move in str2
  int first = 0;
  int second = 0;
  // now keep on comparing till both of them are exhaust because str1 is greater by 1 than str2 so we have checked for str1 to exahust
  while (first < str1.size())
  {
    // if match
    if (str1[first] == str2[second])
    {
      first++;
      second++;
    }
    // if they don't match then we move only pointer of str1
    else
    {
      first++;
    }
  }

  // if both strings are exhaust the true else false
  if (first == str1.size() && second == str2.size())
  {
    return true;
  }
  return false;
}

// custom comparator function to sort strings according to length
// if we use class i.e we declare these function inside the class  then inside it declare this function with (static) keyword
bool comp(string &s, string &t)
{
  return s.size() < t.size(); // because we want shorter string first
}

// t.c:
// O(n^2) for two for loop
// next we are doing checkpossible function for that we are traversing strings as str1 is greater size so let it have length = l
// so total t.c-O((n^2)*l)+O(nlogn)(for sorting given array )
// s.c-O(n)(for dp 1D array for storing maximum length upto ith index)

int longestStringChain(vector<string> &words)
{
  int n = words.size();
  // it is very importtant that first we have to sort the given array of string according to the length of string because if we directly apply LIS code then it is for subsequence but question says we can pick up from anywhere i.e order does not matter so we want subset so for this we sort it according to the length of string
  sort(words.begin(), words.end(), comp); // comp is a custom comparator function that compare length of string and then sort it according to length
  // copy the code of LIS we just want length only
  // first we get length of LIS
  vector<int> dp(n, 1); // store the length of longest increasing subsequence that ends at index i and initially assigned to 1 because itself can also
  int maxi = 1;         // becuase itself
  // I will go from 0 to n-1
  for (int index = 0; index < n; index++)
  {
    // check for previous so go from 0 to index-1
    for (int prev = 0; prev < index; prev++)
    {
      // slight change of code of LIS, here we compare the strings that they have one differnce character or not
      if (checkPossible(words[index], words[prev]) && 1 + dp[prev] > dp[index])
      {
        // then check current dp value with new one if it is greater then we will store it
        dp[index] = 1 + dp[prev];
      }
    }
    // for longest increasing subsequence we check each index dp value
    if (dp[index] > maxi)
    {
      maxi = dp[index]; // length of longest increasing subsequence
    }
  }
  return maxi;
}

int main()
{
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
    cin >> words[i];
  cout << longestStringChain(words);
  return 0;
}