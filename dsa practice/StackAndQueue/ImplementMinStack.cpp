// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int value) pushes the element value onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

// Constraints:

// -2^31 <= val <= 2^31 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 10^4 calls will be made to push, pop, top, and getMin.

#include <bits/stdc++.h>
using namespace std;

// here in this problem we have extra function of stack for getting minimum from all valus of the stack

// brute force whenever it ask for getMin() traverse whole stack and get minimum so t.c-O(n) each time  which is not good if we ask getMin() many times

// better solution:

// A stack of pairs is used, where each pair contains the elt itself and the minimum elt at the time the elt was pushed onto the stack.
// The MinStack class is initialized with an empty stack.

// Push operation:
// When a new elt is pushed, it is compared with the current minimum.
// The new elt and the updated minimum are stored as a pair and pushed onto the stack.

// Pop Operation:
// The top elt(which is a pair) is removed from the stack.

// Top Operation:
// The top elt of the stack is accessed to get the actual value(first component) stored in the pair.

// GetMin Operation:
// The second value of the pair at the top of the stack,which represents the minimum elt at that point, is accessed

// example:
// Initialize am empty MinStack st store pair <curr,min>

//                                             stack

//                                             empty
// st.push(-2)
// currently stack is empty so minimu would be -2 itself so <-2,-2> push in stack
//                                              <-2,-2>
// s.push(0)
// Current minimum is -2 which is less than 0 so <0,-2> push in stack
//                                             <-2,-2>,<0,-2>
// s.push(-3)
// current minimum is -2 which is greater than -3 we have new min value so <-3,-3> push in stack
//                                              <-2,-2>,<0,-2>,<-3,-3>
// s.getMin()
// get the topmost elt of stack and return min value which is -3
//                                                <-2,-2>,<0,-2>,<-3,-3>
// s.pop()
// remove the top most elt from the stack so remove <-3,-3>
//                                                   <-2,-2>,<0,-2>
// s.top()
// get the top most elt of stack and return curr value which is 0
//                                                <-2,-2>,<0,-2>
// s.pop()
// remove the top most elt from the stack which is <0,-2>
//                                                  <-2,-2>
// s.getMin()
// get the topmost elt of stack and return min value which is -2
//                                                  <-2,-2>

// class to implement Minimum stack
// t.c-O(1) for all operations  (push, pop, top, getMin) as they involve constant time operations on the stack.
// s.c-O(2*n) because we store pair of values <curr,min> in stack, where n is the number of elts in the stack
class MinStack
{
private:
  // initialize a stack store pair value <curr,min>
  stack<pair<int, int>> st;

public:
  // empty constructor
  MinStack()
  {
  }
  // push operation
  void push(int value)
  {
    // if stack is empty
    if (st.empty())
    {
      // psuh current value as minimum
      st.push({value, value});
      return;
    }
    // update the current minimum
    int mini = min(getMin(), value);
    // add the pair to the stack
    st.push({value, mini});
  }
  // pop operation
  void pop()
  {
    if (st.empty())
    {
      cout << "stack is empty";
    }
    // using built-in pop method so not require above edge case to check stack empty
    st.pop();
  }
  // top operation
  int top()
  {
    if (st.empty())
    {
      cout << "Stack is empty";
      return -1;
    }
    // return the top value
    return st.top().first;
  }
  // method to get the minimum in stack
  int getMin()
  {
    if (st.empty())
    {
      cout << "Stack is empty";
      return -1;
    }
    // return the minimum
    return st.top().second;
  }
};

// optimal solution:

// Use a stack to store elts and maintain a variable to keep track of the current minimum value

// Push Operation:
// If the stack is empty, push the value and set it as the current minimum
// If the value is greater than or equal to the current minimum, simply push the value onto the stack.
// If the value is less than the current minimum, push a modified value calculated using the new value(there is a formul for that) and update the current minimum.

// Pop operation:
// if the stack is empty, do nothing.
// Otherwise, retrieve and pop the top value from the stack.
// If the popped value indicates it was used to store a new minimum,update the current minimum using the retrieved value ( for this there is also formula).

// Top operation:
// If the stack is empty, return -1 indicating the stack is empty.
// Retrieve the top value. If it is greater than or equal to the current minimum,return it.
// If the top value indicates it was used to store a new minimum, return the current minimum as a top value.

// GetMin Operation:
// Simply return the current minimum.

// Now I simplify what above I say:
// First I tell how we reached to above solution:

// Initialize an empty Minstack st and a mini variable
// mini=INT_MAX
//          mini                              stack

//          INT_MAX                           empty
// s.push(-2)
// currently stack is mepty so update mini and push it to the stack
//          -2                                    -2
// s.push(0)
// currently mini is less than 0 so simply push 0 to the stack, no change in mini
//          -2                                    -2,0
// s.push(-3)
// currently mini is greater than -3 so update mini so mini=-3 and we push -3 in stack also
//          -3                                     -2,0,-3
//  s.getMin() so we return mini=-3

// s.pop()
// currently top is -3 so we pop out it from the stack so we don't have -3 in stack and we have mini=-3 also but when we pop out -3 from the stack we don't have mini = -3 so there is a problem how we get the previous mini because previous mini here for now is -2 but we don't store it so how we get mini after pop so this is problem

// here we have a formula : 2*currentValue - prevMini = newValue    <- this formula that we used to get the previous mini and this is also used that we mention in above pop ,push,top operation

// example:
// Initialize an empty Minstack st and a mini variable

// mini=INT_MAX

//          mini                              stack

//          INT_MAX                           empty
// s.push(-2)
// currently stack is empty so update mini and push it to the stack
//          -2                                    -2
// s.push(0)
// currently mini is less than 0 so simply push 0 to the stack, no change in mini
//          -2                                    -2,0
// s.push(-3)
// currently mini is greater than -3 so update mini so mini=-3 and we push newValue according to the formula , 2*currValue - prevmini = 2*(-3)-(-2)=-6+2 = -4 so we psuh -4 in stack
//          -3                                     -2,0,-4
//  s.getMin() so we return mini=-3

// s.pop()
// The value of the top elt, x, of stack is less than mini. Update mini to new value given by formula: 2*mini-x=2*(-3)-(-4)=-6+4=-2 so now mini=-2 and we simply pop -4 from the stack
//         -2                                      -2,0
// s.top()
// the value of the top elt,x, of stack is greater than mini so we simply return it so return 0
//          -2                                      -2,0

// s.pop()
// the value of top elt,x,of stack is greater than mini. No need to update mini so we simply pop out 0 from the stack
//          -2                                      -2
// s.getMin()
// mini=-2 return

// formula we have: 2*currentValue-prevMini=newValue
// so newValue is the modified value that is push in stack and update mini=currentValue
// so prevMini=2*currentValue-newValue

// class to implement Minimum Stack
// t.c-O(1)  for all operations (push, pop, top, getMin) as they involve constant time operations on the stack.
// s.c-O(n) for stack here we are storing only one elt in stack not a pair so O(n) which is optimize then better solution, where n is the number of elements in the stack

// for more clear about formula I explain example below
class MiniStack
{
private:
  // Initialize a stack
  stack<int> st; // according to leetcode, constraints are very large so use long long insted of int  and also for mini use long long mini
  // to store the minimum value
  int mini; // for large constraints use long long, I give the code after int main function

public:
  // Empty Constructor
  MiniStack()
  {
  }

  // Method to push a value in stack
  void push(int value)
  {
    // if stack is empty
    if (st.empty())
    {
      // update the minimum value
      mini = value;
      // push current value as minimum
      st.push(value);
      return;
    }
    // if the current value is greater than the minimum so no update in mini so simply push value  in stack
    if (value > mini)
    {
      st.push(value);
    }
    // when current value is less than or equal to minimum so we use formula to push modifies value in stack
    else
    {
      // add the modified value to stack
      st.push(2 * value - mini);
      // update the minimum
      mini = value;
    }
  }
  // pop method
  void pop()
  {
    // base case
    if (st.empty())
    {
      return;
    }
    // get the top
    int x = st.top();
    st.pop(); // built in pop method
    // if the top was the  modified value which was added to the stack then we have to update the minimum value to the previous minimum by formula
    if (x < mini)
    {
      mini = 2 * mini - x; // how this happen I explain it below
    }
  }
  // top method
  int top()
  {
    // base case
    if (st.empty())
      return -1;
    // get the top
    int x = st.top();
    // return top if minimum is less than the top
    if (mini < x)
      return x;
    // otherwise return mini as a top because we added modified value in stack
    return mini;
  }
  // getMin method
  int getMin()
  {
    // return the minimum
    return mini;
  }
};

int main()
{
  // MinStack s;
  MiniStack s;

  // Function calls
  s.push(-2);
  s.push(0);
  s.push(-3);
  cout << s.getMin() << " ";
  s.pop();
  cout << s.top() << " ";
  s.pop();
  cout << s.getMin();

  return 0;
}

// example to clear formula
// formula : 2*currentValue-previousMini=newValue
// so newValue is the modified value that is push in stack and update mini=currentValue
// use this formula according to above mention optimal solution:

// // Initialize an empty Minstack st and a mini variable

// mini=INT_MAX
// push 12
// mini=12 and st=12
// push 15
// 15>mini so simple push it in stack
// mini=12 and st=12,15
// push 10
// 10<mini=12
// so we use formula here : newValue=2*10-12=8 so now mini=currentValue=10 and we  push newValue in stack which is 8 so we insrt the modified value in stackand at the same time we replace minimum to 10 so we can say that the minimum is storing the minimum and at the same time storing the top as well because 10 is the current top elt
// mini=10 and st=12,15,8
// getMin=10
// pop
// so whenever someone is asking to pop out it is simple we take out the top from the stack which is here 8 and what else I need to do I need to make sure the mnimum goes back to previous which is 12 , do I have the formula which I used to insert into the stack so can I get previous minimum from that so if I have to get the previous minimum what will the formual look like:
// previousMini=2*currentVal-newVal(that we insert)
// we can easily get the newVal that we insert : top of the stack
// but what about this currentVal ? can we say the current minimum is the currentVal that originally came to be inserted  it did
// so previous minim= 2*currentMini-xtopStack
// prevMini=2*10-8=12

// so after pop operation
// mini=12          and st=12,15
// getMin=mini=12
// top
// Is your top =12 or Is your top =15?
// top is 15 not 12 because this value-15 was not modified so I'll just take top =15
// push 10
// Will be push 10? no because it is going to modify because 10< currentmini=12
// newVal=2*10-12=8
// so we push newVal in stack which is 8 and update mini=current Val which is 10
// remember whenever we modify the minimum is our top value which is cuurent value
// mini=10                and st=12,15,8
// top
// whenever someone is asking the top
// Is your top 8 or Is your top 10?
// top is 8 No we don't take top=8 instead we take top=10
// but how we know that
// if st.top() > currentMini then we return st.top()
// else we return currentMini
// but how is this possible?
// Why were we modify the value because 10 was less than 12 where 12 was the previous minimum and we had to replace it
// 10<12 can I say 10 is the currentVal and 12 is the previous mini
// currentVal<mini
// can I say
// currentVal - mini < 0
// can I add currentVal both side
// currentVal + currentVal - mini < currentVal
// that is
// 2*currentVal - mini < currentVal
// from formual 2*currentVal - mini = newVal
// newVal < currentVal
// so we are very sure that the new value(8 here) which is to be inserted is always going to be lesser than the currentVal(10 here) which is going to replace thereby at any moment newVal is lesser than currentVal always so in that case top will always the minimum value

// for very large constraints
// class MinStack {
//     private:
//     stack<long long>st;
//     long long mini;

// public:
//     MinStack() {

//     }

//     void push(int value) {
//         if(st.empty()){
//             mini=value;
//             st.push(value);
//             return ;
//         }
//         if(value>mini)st.push(value);
//         else{
//             long long temp=2LL*value-mini;

//             st.push(temp);
//             mini=value;
//         }
//     }

//     void pop() {
//         if(st.empty())return ;
//         long long x=st.top();
//         st.pop();
//         if(x<mini){
//             mini=2LL*mini-x;
//         }
//     }

//     int top() {
//         if(st.empty())return -1;
//         long long x=st.top();
//         if(mini<x)return (int)x;
//         return (int)mini;
//     }

//     int getMin() {
//         return (int)mini;
//     }
// };