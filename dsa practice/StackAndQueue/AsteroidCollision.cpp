// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// Example 1:

// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
// Example 2:

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.
// Example 3:

// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
// Example 4:

// Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
// Output: [-6,2,4]
// Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 destroys -1. Since 2 and 4 are both moving right, they never collide.

// Constraints:

// 2 <= asteroids.length <= 10^4
// -1000 <= asteroids[i] <= 1000
// asteroids[i] != 0

#include <bits/stdc++.h>
using namespace std;

// how do we think of the approach

// question says we have an array of asteroids where positive sign shows it move in right direction and negative sign shows it move in left direction
// and its absolute value show the size of asteroid
// and all asteroids move at the smae speed.

// suppose we have two asteroids: a1 and a2
//
// i) if they are move in the same direction they will never meet so there is no collision, either both move in right direction or move in left direction

// ii) but suppose a1 moves in right direction and a2 moves in left direction means both move in opposite direction so there is collision and smaller one in (comparison to size i. after taking absolute)  is explode. if both are of same size, both will explode.

// now for this we use an stack to solve this because here when we traverse if they are of same sign no explosion but when we get opposite sign then there is explosion so just before current one is compare in size with current who will explode  suppose if previous one explode then its previous check with current one so we want last in first out system so that's why we use stack

// suppose arr=[4,7,1,1,2,-3,-7,17,15,-16]

// initially stack is empty and we start traverse from index i=0

// index       sign       absolute value       stack
// stack is empty and we have at i=0 asteroid moving right so push
//  0           +            4                   4
//  1           +            7                   4,7
//  2           +            1                   4,7,1
//  3           +            1                   4,7,1,1
//  4           +            2                   4,7,1,1
// now here at i=5 we have opposite sign from the top of the stack so collision happen here if we check size then current=3 and at top we have 1 so top will explode so remove it from stack then in top we get 1 which is also smaller than 3 so will also explode so pop then we have 7 in top which is greater than 3 now 3 will explode so and we move to next index and in stack we have now 4,7
//  5           -            3                   4,7
// now at i=6 we have opposite sign from top of stack so collison happen here both have same size =7 so both explode and we move to next index and in stack we have 4 only
// 6            -            7                  4
// at i=7 we have sign = +ve same sign as top so push
// 7            +            17                 4,17
// 8            +            15                 4,17,15
// now at index =9 we have opposite sign from top of the stack so collision happen here so current size=16 and top size=15 so top will explode so pop then at top we have 17 >current size so  now 16 will explode and array is finish so all collisions are done so now answer is stack elt and in stack we have 4,17
// 9            -            16                 4,17
// but when we take out elt from stack we get like this [17,4] but answer is [4,17] so we have to reverse the elt after stack

// here in above example you notice one thing that I store only asteroids that move in right direction in stack means having positive sign not store -ve sign asteroid in stack now for this I explain this with one more example

// suppose we have an arr like this =[4,7,1,1,2,-3,-7,17,15,-18,-19]
// we start from index 8 here from 0 to 8 same form above example
// when we are at index =8 we have in stack 4,17,15

// index    sign        absolute value     stack
//  8        +             15               4,17,15
// now at index =9 we have oppsotie sign value from top of the stack so collision happens here now current size=18 and top size = 15 so 15 will explode and pop then at top we have 17<18 so 17 will explode and pop then at top we have 4 < 18 so 4 will explode and pop now stack is empty remember stack is empty now I'll end up inserting the negative element now we insert 18 with its sign so now in stack we have -18 and this is the first time that we insert negative elt in stack so it will happen if the stack is empty
//  9       -               18              -18
// next we have same sign elt with the top so push it in stack no collision happens here  so if stack is empty or if stack's top elt is negative and current elt also -ve then they can never collide
//  10      -               19              -18,-19
// finish array so we have [-19,-18] in satck reverse it [-18,-19] is our answer after all collisions

// these are the cases that we will have to take care of when we have to push +ve sign elt in stack and when we have to push -ve sign elt and when collision happens

// algorithm:

// Initialize an empty stack to track asteroids after collisions.
// loop through each asteroid in the input array means traverse each elt of given asteroids array
// If the asteroid is moving right(i.e +ve sign), push it onto the stack
// If the asteroid is moving left(i.e -ve sign), check for collisions with top elts of the stack
// While the top of the stack is a smaller right-moving asteroid,pop it from the stack
// If the top of the stack is a right-moving asteroid of equal size,pop it and do not push the current asteroid because both explode
// If the stack is empty or the top is a left-moving asteroid(i.e -ve sign), push the current asteroid
// after the loop ends, return the stack as the final result after reverse

// t.c-O(n)(for traverse each asteroids once)+O(n)(while pop out when collision happens for while loop but it is throughout the whole journey we pop out n elts not for each so O(n) not O(n^2))= O(2n)
// s.c-O(n)(in worst case for stack)+O(n)(for ans array in worst case)=O(2n)
vector<int> asteroidCollision(vector<int> &asteroids)
{
  // we use stack to track asteroids after collisions.
  stack<int> st;
  // Traverse all the asteroids
  for (int i = 0; i < asteroids.size(); i++)
  {
    // Push the asteroid in stack if a right moving asteroid is seen
    if (asteroids[i] > 0)
    {
      st.push(asteroids[i]);
    }
    // Else if the current asteroid is moving left, perform the collisions
    else
    {
      // Until the right moving asteroids at top of the stack  are smaller in size, keep on destroying them
      while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
      {
        // Destroy the asteroid
        st.pop();
      }
      // if right moving asteroids at top of the stack  are of same size to current left moving asteroids then both destroy
      if (!st.empty() && st.top() == abs(asteroids[i]))
      {
        // Destroy both the asteroids
        st.pop();
      }
      // Otherwise, if there is no right moving asteroid in stack, the left moving asteroid will not be destroyed means either stack is empty or in stack we have left moving asteroid so we push current left moving asteroid
      else if (st.empty() || st.top() < 0)
      {
        st.push(asteroids[i]);
      }
    }
  }
  // now we pop out remaining elts from the stack that are left after all collisions
  vector<int> ans;
  while (!st.empty())
  {
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  // Return the final state of asteroids
  return ans;
}

// here in above solution we use stack so after all collisions when we pop out elts in our ans array then later we need to reverse it for getting answer in given order of elt

// so instead of using stack we use vector then we don't need to reverse later and in vector we also pop_back() function and back() function to get last elt that we insert
// for in stack we have top() in vector we have back() to get last inserted elt
// in stack we have pop() in vector we have pop_back() to pop last elt that we insert
// in stack we have push() in vector we have push_back() to  insert elt in last

// t.c-O(n)(for traverse each asteroids once)+O(n)(while pop out when collision happens for while loop but it is throughout the whole journey we pop out n elts not for each so O(n) not O(n^2))= O(2n)
// s.c-O(n)(in worst case for st array)
vector<int> asteroidCollisions(vector<int> &asteroids)
{
  // we use list to track asteroids after collisions.
  // List implementation of stack
  vector<int> st;
  // Traverse all the asteroids
  for (int i = 0; i < asteroids.size(); i++)
  {
    // Push the asteroid in stack if a right moving asteroid is seen
    if (asteroids[i] > 0)
    {
      st.push_back(asteroids[i]);
    }
    // Else if the current asteroid is moving left, perform the collisions
    else
    {
      // Until the right moving asteroids at top of the stack  are smaller in size, keep on destroying them
      while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i]))
      {
        // Destroy the asteroid
        st.pop_back();
      }
      // if right moving asteroids at top of the stack  are of same size to current left moving asteroids then both destroy
      if (!st.empty() && st.back() == abs(asteroids[i]))
      {
        // Destroy both the asteroids
        st.pop_back();
      }
      // Otherwise, if there is no right moving asteroid in stack, the left moving asteroid will not be destroyed means either stack is empty or in stack we have left moving asteroid so we push current left moving asteroid
      else if (st.empty() || st.back() < 0)
      {
        st.push_back(asteroids[i]);
      }
    }
  }
  // now no need to reverse we directly return st
  // Return the final state of asteroids
  return st;
}

int main()
{
  int n;
  cin >> n;
  vector<int> asteroids(n);
  for (int i = 0; i < n; i++)
  {
    cin >> asteroids[i];
  }

  // vector<int> ans = asteroidCollision(asteroids);
  vector<int> ans = asteroidCollisions(asteroids);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}