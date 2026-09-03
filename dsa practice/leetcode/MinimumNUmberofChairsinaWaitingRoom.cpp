// You are given a string s. Simulate events at each second i:

// If s[i] == 'E', a person enters the waiting room and takes one of the chairs in it.
// If s[i] == 'L', a person leaves the waiting room, freeing up a chair.
// Return the minimum number of chairs needed so that a chair is available for every person who enters the waiting room given that it is initially empty.

// Example 1:

// Input: s = "EEEEEEE"

// Output: 7

// Explanation:

// After each second, a person enters the waiting room and no person leaves it. Therefore, a minimum of 7 chairs is needed.

// Example 2:

// Input: s = "ELELEEL"

// Output: 2

// Explanation:

// Let's consider that there are 2 chairs in the waiting room. The table below shows the state of the waiting room at each second.

// Second	Event	People in the Waiting Room	Available Chairs
// 0	Enter	1	1
// 1	Leave	0	2
// 2	Enter	1	1
// 3	Leave	0	2
// 4	Enter	1	1
// 5	Enter	2	0
// 6	Leave	1	1
// Example 3:

// Input: s = "ELEELEELLL"

// Output: 3

// Explanation:

// Let's consider that there are 3 chairs in the waiting room. The table below shows the state of the waiting room at each second.

// Second	Event	People in the Waiting Room	Available Chairs
// 0	Enter	1	2
// 1	Leave	0	3
// 2	Enter	1	2
// 3	Enter	2	1
// 4	Leave	1	2
// 5	Enter	2	1
// 6	Enter	3	0
// 7	Leave	2	1
// 8	Leave	1	2
// 9	Leave	0	3

// Constraints:

// 1 <= s.length <= 50
// s consists only of the letters 'E' and 'L'.
// s represents a valid sequence of entries and exits.

// Hint 1
// Iterate from left to right over the string and keep track of the number of people in the waiting room using a variable that you will increment on every occurrence of ‘E’ and decrement on every occurrence of ‘L’.
// Hint 2
// The answer is the maximum number of people in the waiting room at any instance.

#include <bits/stdc++.h>
using namespace std;

// by using hint
// i make a variable ans=0 initially because no. of chairs required can't be -ve so start with 0

// then we make another variable chairs=0 and traverse string if we get'E' we increase chairs by 1 or if we get 'L' we decrease chairs by 1 and each time during traverse we take max(ans,chairs) so we get the maximum number of people in the waiting room at any instance.

// so at any instance minimum chairs requires=maximum number of people in waiting room at that instance

// t.c-O(n)
// s.c-O(1)
int minimumChairs(string s)
{
  int n = s.size();
  int ans = 0;
  int chairs = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'E')
      chairs += 1;
    else
      chairs -= 1;
    ans = max(ans, chairs);
  }
  return ans;
}
int main()
{
  string s;
  cin >> s;
  cout << minimumChairs(s);
  return 0;
}