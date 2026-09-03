// You are given a string word containing distinct lowercase English letters.

// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

// Return the minimum number of pushes needed to type word after remapping the keys.

// An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

// Example 1:

// Input: word = "abcde"
// Output: 5
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// Total cost is 1 + 1 + 1 + 1 + 1 = 5.
// It can be shown that no other mapping can provide a lower cost.
// Example 2:

// Input: word = "xycdefghij"
// Output: 12
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "x" -> one push on key 2
// "y" -> two pushes on key 2
// "c" -> one push on key 3
// "d" -> two pushes on key 3
// "e" -> one push on key 4
// "f" -> one push on key 5
// "g" -> one push on key 6
// "h" -> one push on key 7
// "i" -> one push on key 8
// "j" -> one push on key 9
// Total cost is 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12.
// It can be shown that no other mapping can provide a lower cost.

// Constraints:

// 1 <= word.length <= 26
// word consists of lowercase English letters.
// All letters in word are distinct.

#include <bits/stdc++.h>
using namespace std;

// this problem is done by me fully without seeing hint

// here we want minimum number of push
// so what we do is that we ahve a string word and we have 8 keys from 2 to 9 that can have lower case letters so what I am doing here is that first I map each key with char from string word by starting from index 0 with push =1 for each char and after 7 iterations still word string has char then we again start to map char from 2 to 8 key with push = 2 for each char adt again after 7 iteration still string word has char then again we start map char from 2 to 8 key with now push = 3 for each char  and so on so that's how we get minimum push
// and also given a string word containing distinct lowercase English letters so there is no contradiction that the same char can come again and we want to store key for each char that which key is assign to which char  if in future it come then we return same key push so in this problem we don't have this case string word has distinct lowercase English letters

// for an example we have word="xycdefghij"
// i) 'x' 1 push on key 2
// ii) 'y' 1 push on key 3
// iii) 'c' 1 push on key 4
// iv) 'd' 1 push on key 5
// v) 'e' 1 push on key 6
// vi) 'f' 1 push on key 7
// vii) 'g' 1 push on key 8
// now word still has some char but we are done with 1 push now so now againg we start from key 2 with push =2
// viii) 'h' 2 push on key 2
// ix) 'i' 2 push on key 3
// x) 'j' 2 push on key 4
// so that's we get minimum number of pushese=12, if still word has some char and we are done with push =2 upto key 8 then we againg start from key 2 with push =3 and so on

// t.c-O(n) we traverse the word string
// s.c- O(1)
int minimumPushes(string word)
{
  int n = word.size();
  int minPush = 0;
  // initially we push key with push =1
  int push = 1;
  int i = 0; // for travelling string word
  while (i < n)
  {
    // we have 2 to 8 key which are total 7 keys so after 7 the iteration we have to increase the push value because for an example  when we push the same key for second char on that we have to push it two times and for third char we have to push it for three times so after each 7 iterations we increase push by 1
    // after 7 iteration means we have 8th iteration and multiple of 8 and we cannot increase push when i=0 because we already start push with 1

    // also given a string word containing distinct lowercase English letters so we easily increase push because we don't have to store key->char means which char is assign to which key because in future we don't get same char so we don't need to store it

    // we say i!=0 because 0%8==0 always so it increase push but we start push with 1 so in starting we can't increase push if we start push with 0 then we don't have to write i!=0 because in that case 0%8==0 increase the push by 1 and make push=1
    if (i != 0 && i % 8 == 0)
    {
      push++;
    }
    minPush += push;
    i++;
  }
  return minPush;
}
int main()
{
  // given a string word containing distinct lowercase English letters.
  string word;
  cin >> word;
  cout << minimumPushes(word);
  return 0;
}