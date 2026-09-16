// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

// For example, if the prices of the stock in the last four days are [7,2,1,2] and the price of the stock today is 2, then the span of today is 3 because starting from today, the price of the stock was less than or equal to 2 for 3 consecutive days.
// Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
// Implement the StockSpanner class:

// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.

// Example 1:

// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]

// Explanation
// StockSpanner stockSpanner = new StockSpanner();
// stockSpanner.next(100); // return 1
// stockSpanner.next(80);  // return 1
// stockSpanner.next(60);  // return 1
// stockSpanner.next(70);  // return 2
// stockSpanner.next(60);  // return 1
// stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
// stockSpanner.next(85);  // return 6

// Constraints:

// 1 <= price <= 10^5
// At most 104 calls will be made to next.

#include <bits/stdc++.h>
using namespace std;

// What does the problem say?

// So initially we will be starting with the call StockSpanner() so this call make the obejct of StockSpanner class and we can say that this is when the stock market starts means whenever we call this our stock market start after that we'll be having next function calls, so next() function call basically taking a integer value as a parameter and return possible integer value

// our task is to return a possible integer that defines maximum consecutive days for which the stock price was less than or equal to the current day in past means we want number of consecutive days in past whose stock price was less than or equal to current day price including the current day price also and it is called the span

// example-
// StockSpanner()
// next->7
// next->2
// next->1
// next->3
// next->3
// next->1
// next->8

// initially StockSpanner call then we call the first next function
// and we initialize an empty list for storing answer of each next call

// Let's understand so if I check the first one, we know the stock market starts so we are coming across 7 so can I say that this is day1 and before this there are no days so I can surely say that for this next(7) we return 1 for itself because in past there are no days which are less than or equal to current day price so for next(7) we return 1 that is it itself so ans=1

// let's go to the next call, next(2) so this time when we look to the past and the previous day had a 7 which is not lesser than or equal to the current day price so that day cannot be computed so again we can say that for next(2) we return 1 for itself  now ans=1

// let's go the next call, next(1) again we look to the past and the previous day had a 2 which is not lesser than or equal to the current day price so that day cannot be computed so again we can say that for next(1) we return 1 for itself   now ans=1

// let's go the next call, next(3) this time when we look to the stock price in past  means in previous days  we have [7,2,1] and current also 3 so we have [7,2,1,3] rememeber we want consecutive days so What I can say is we can take today and the day with price 1 and a day with price 2 , we cannot take day with price 7 because 7 is greater than 3 so we get 3 consecutive days including today which has price lesser than or equal to current day price so next(3) returns 3 so now we have ans=3

// let's go the next call, next(3) this time when we look to the stock price in past means in previous days we have [7,2,1,3] and current also 3 so we have [7,2,1,3,3] rememeber we want consecutive days so What I can say is we can take today and the day with price 3 and a day with price 1 , and the day with price 2, we cannot take day with price 7 because 7 is greater than 3 so we get 4 consecutive days including today which has price lesser than or equal to current day price so next(3) returns 4 so now we have ans=4

// let's go the next call, next(1) this time when we look in past  means in previous days we have 3 which is larger than currnet day price 1 so we cannot take them so next(1) returns 1 for itself so now ans=1

// let's go the next call, next(8) this time when we look to the stock price in past means in previous days we have [7,2,1,3,3,1] and current also 8 so we have [7,2,1,3,3,1,8] rememeber we want consecutive days so What I can say is we can take today and the day with price 1 and a day with price 3 ,  the day with price 3, the day with price 1 , the day with price 2, the day with price 7, so we get 7 consecutive days including today which has price lesser than or equal to current day price so next(8) returns 7 so now we have ans=7

// finish all next calls

// brute force:
// we have a array or a list which is dynamic in nature so I can store all days in them when we call next() function so let's have a list globally under the StockSpanner class

// ALgorithm
// Initialize an array to store the stock span for each day means we store the stock price of each day
// Start traversing the given stock prices array
// For each elt(i.e next call), traverse backward to find the previous day with a stock price less than or equal to the current day's price
// Calculate the span by counting the number of consecutive days with stock prices less than or equal to the current day's price
// Store the calculated stock span for each day in the array
// Once the traversal is complete, return the array containing the stock spans means return the answer array that contains answer of each next() function call

class StockSpanner
{
  vector<int> price; // store price of each day  so we can check  previous price for current day price
  // constructor initialize the price array for each object from starting means with empty
public:
  StockSpanner()
  {
    price.clear();
  }
  // function that return span which is the maximum consecutive days for which the stock price was less than or equal to the current day price in past means we want number of consecutive days in past whose stock price was less than or equal to current day price including the current day price also

  // t.c- O(number of days)(for for loop) for each next call
  // s.c-O(total number of next calls)(for array price) because we store each next call val into the array price
  int next(int val)
  {
    // we add a current day price in price arrar
    price.push_back(val);
    // here count represent the span of the stock's price given that today's price is val
    int count = 1; // for current price itself is also count
    // we traverse backwars to find stock span
    // we alread count ofr current day itself so we start from price.size()-2 because price.size()-1 store the current day price which we already count
    for (int i = price.size() - 2; i >= 0; i--)
    {
      // when we get previous day price lesser than or equal to current day price
      if (price[i] <= val)
        count++;
      // if it is not then we break because we want consecutive days
      else
        break;
    }
    return count; // span of the current day stock's price
  }
};

// optimal solution:
// in above solution every time we are taking number of days so every time when we are doing a next call we are typically checking through the entire data
// so now we optimize it

// we have
// example-
// StockSpanner()
// next->7
// next->2
// next->1
// next->3
// next->3
// next->1
// next->8
// array of next call - [7,2,1,3,3,1,8]
// let's understand what was taking time and if I can optimize from there so for this particluar next call next(3)(second 3 I was telling) What I did was I stood at the current elt and I went back, back and I said this 7 is not possible for 3 because 7 was greater than 3 that violates the condition less than or equal so 7 cannot be counted in the consecutive days so eventually I figured out the length for the second 3 we get length=4 and in order to do that I had to traverse back and that is what was taking time so can I do it without traversing back? I can do it if someone comes up and says me hey for 3 we know the previous greater elt was 7 and it was found at index 0 and we are currently at index 4 so (current index - previous greater elt index) so current elt index minus wherever the previous greater elt was found that's 0 here gives you the number of consecutive days which we could actually take into our answer , now we got an intuition
// all I need to do is figure out the previous greater elt index for a current elt which we know how to get we done problems like "next greater elt" and "previous smaller elt" so similarly we do "previous greater elt" what we will be doing is we not be storing anything in an array rather because we know in order to compute previous greater elt we will have to traverse from left to right because whenever we are at 3 we would have  elts somewhere in the stack data structure and from the stack we could easily figure out the previous greater elt, all I need to store is at which index the previous greater elt appeared so that I could subtract and get the maximum consecutive days

// dry run:
// example-
// StockSpanner()
// next->7
// next->2
// next->1
// next->3
// next->3
// next->1
// next->8
// array of next call - [7,2,1,3,3,1,8]
// taking a stack data structure which store a pair of (value,index) so initially it is empty
// index           value              stack
// empty
// so whenever first next() function call we check the stack and the stack doesn't have anything so we return the value=-1 and index=-1 which means it doesn't have anything so the current index is 0 so for next(7) we get (0-(-1))=1. Can I say that the consecutive number of days will be for next(7)? 1 , which is correct it itself and after that we push (7,0) in stack
//  0                7                 (7,0)
// go to the next, next(2) when we look at the stack there is 7 which is greate than 2 and 7 occurs at index 0 and currently I am at index 1 so we get previous greater elt for 2 which is 7 at index 0 so next(2) return (1-0)=1 which is itself denote 2 with the consecutive day and push (2,1) in stack
//  1               2                  (7,0),(2,1)
// next we go the next(1) when we look at the stack there is 2 which is greater than 1 so we get previous greater elt 2 at index 1 and current index is 2 so next(1) return (2-1)=1 which is for itself with the consecutive day and push (1,3) in the stack
//  2               1                  (7,0),(2,1),(1,2)
// next we go the next(3) when we look at the stack we have (1,2) at top means we have value=1 at top which is smaller that currrent 3 so we pop (1,2) from stack next we have (2,1) again 2 is smaller than 3 so we pop it also from the stack next we have (7,0) now 7 is greater than 3 so we get previous greater elt for 3 is 7 at index 0 so next(3) return (3-0)=3 and push(3,3) in stack
//  3               3                  (7,0),(3,3)
// next we go the next(3) when we look at the stack we have (3,3) at top means we have value=3 at top which is equal to current value not greater so we pop it from stack next we have (7,0) where 7 is greater than 3 so we get previous greater elt at index 0 so next(3) return (4-0)=4 and push (3,4) in stack
// 4                 3                (7,0),(3,4)
// next we go the next(1) when we look at the stack we have(3,4) at top where 3 is greater than 1 so we get previous greater elt at index 4 so next(1) returns (5-4)=1 and push(1,5) in stack
//  5                1               (7,0),(3,4),(1,5)
// next we go the next(8) when  we look at the stack we have (1,5) at top means we have value=1 at top which is smaller to current value  so we pop it from stack next we have (3,4) where 3  is again smaller than 8 so pop it from stack, next we get (7,0) where 7 is again smaller than 8 so pop it from the stack now stack is empty so in that case we get value=-1 and index=-1 means we have nothin  so next(8) return (6-(-1))=7 and push (8,7) in stack
// finish all the next call so we get answer for each call by (current index- previous greater elt index) if stack is empty in that case previous greater elt is -1

// Algorithm
// Initialize an empty stack to maintain elts in decreasing order
// Traverse through the given stock prices array i.e given next(val) function call
// For each elt, pop elts from the stack until the current price is greater than the price at the top of the stack
// If the stack is not empty, the index at the top of the stack is the previous freater elt
// Calculate the stock span as the difference between the current index and the index of the previous greater elt
// If the stack is empty, the current stock price is the largest so far, and the span is the current index + 1 because in that case value=-1 and previous greater elt index =-1 so we get (current index -(-1)) which is current index + 1
// Push the current index onto the stack
// After completing the traversal or all next calls, return the array of answer of stock spans if we store all answers in array otherwise we immdiately return answer for each next(val) function call

// here we return answer for each next call

// if there are overall 'n' next calls then
// t.c-O(2n) because in order to compute previous greater elt it takes O(2n) for n elts so here for overall n next calls t.c-O(2n)
// and the overall s.c-O(n)in worst case for stack space, stack store all n elts given to me throughtout the n next calls
// Can I figure out the t.c for individual calls? It is not practical enough to say that individual calls take this much because we never know what if every time we don't need to pop anything and the stack always keeps giving you the previous greater elt so for all the next calls it is O(1) because every time we just check back we get someone who's greater so I cannot say for individual calls but I can say it for overall next calls
class Stockspanner
{
  // stack to store previous greater elt
  // here stack store pair of (value,index) means store both value and index of previous greater elt
  stack<pair<int, int>> st;
  // and having index which is initially -1
  // we use index to remember the previous next call with index and value to store in stack because here we don't use an array of price of each day so we have to store index separately
  // current index is represented by index
  int index = -1;
  // constructor initialize the stack and index for each object from starting means with empty and -1
public:
  Stockspanner()
  {
    index = -1;
    // stack with pair value don't have a clear function
    // so we have to make sure the stack is empty when we make a new object
    while (!st.empty())
    {
      st.pop();
    }
  }
  // function that return span which is maximum consecutive days for which the stock price was less than or equal to the current day in past means we want number of consecutive days in past whose stock price was less than or equal to current day price including the current day price also and it is called the span

  // here val represents the current day value/price

  int next(int val)
  {
    // current index is represented by index
    index = index + 1; // update to the current index because here we don't have an array of prices so we have to update it for each next call means currently we are at this index like in above example I mention
    // we want previous greater elt so we pop out equal value also
    while (!st.empty() && st.top().first <= val)
    {
      st.pop();
    }
    // ans=current index - previous greater elt index if stack is not empty otherwise current index -(-1)
    // current index is represented by index
    // first we compute the answer then we push current val in stack because if we push first then we don't get previous greater elt at top because at top at that time we have current val if we push it before calculating the answer so we first calculate answer then we push
    int ans = index - (st.empty() ? -1 : st.top().second);
    // push the current value and current index in stack
    st.push({val, index});
    return ans;
  }
};

// function to find the indices of previous greater elt for each elt in the array
// t.c-O(n)(for outer for loop)+O(n)(for inner while loop throughout the whole process not for each i)=O(2n)
// s.c-O(n)(for stack in worst case)+O(n)(for ans array)=O(2n)
vector<int> findPGE(vector<int> &arr)
{
  int n = arr.size();
  // to store the previous greater elts indices
  vector<int> ans(n);
  // stack to store indices of previous greater elt
  // here we have an array of next(val) call so we don't need to store val in stack we get it from arr
  stack<int> st;
  // start traversing from the fornt
  for (int i = 0; i < n; i++)
  {
    // current elt
    int currElt = arr[i];
    // pop the elts in the stack until the stack is not empty and the top elt is not the greater elt
    while (!st.empty() && arr[st.top()] <= currElt)
    {
      st.pop();
    }
    // if the greater is not found, stack will be empty
    if (st.empty())
    {
      ans[i] = -1;
    }
    // else store the top of the stack
    else
    {
      ans[i] = st.top();
    }
    // push the current index in the stack
    st.push(i);
  }
  return ans;
}
// function that return answers in an array form means collect answer of each next call and retuan as an array
// and function takes all next(val) function parameter as an array
// t.c-O(2n)(for findPGE)+O(n)(for traverse the arr once to compute the stock span)=O(3n)
// s.c-O(2n)(stack space  in worst case and ans array in findPGE function)+O(n)(for answer array)+O(n)(for PGE array)=O(4n)
vector<int> stockSpan(vector<int> &arr, int n)
{

  // get the indices of previous greater elts
  vector<int> PGE = findPGE(arr);
  // to store the answer
  vector<int> ans(n); // for each next(val) call
  // compute the result
  // traverse an array arr where arr[i]  represents next(val) call
  for (int i = 0; i < n; i++)
  {
    ans[i] = i - PGE[i];
  }
  return ans;
}
int main()
{
  // StockSpanner *obj = new StockSpanner();
  Stockspanner *obj = new Stockspanner();
  cout << obj->next(100) << " ";
  cout << obj->next(80) << " ";
  cout << obj->next(60) << " ";
  cout << obj->next(70) << " ";
  cout << obj->next(60) << " ";
  cout << obj->next(75) << " ";
  cout << obj->next(85) << " ";

  // answer in array form for all next(val) call
  // int n;
  // cin >> n;
  // vector<int> arr(n); // arr represents all next(val) call
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> arr[i];
  // }
  // vector<int> ans = stockSpan(arr, n);
  // for (int it : ans)
  // {
  //   cout << it << " ";
  // }
  return 0;
}