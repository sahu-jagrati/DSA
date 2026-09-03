// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:

// Input: heights = [2,4]
// Output: 4

// Constraints:

// 1 <= heights.length <= 10^5
// 0 <= heights[i] <= 10^4

#include <bits/stdc++.h>
using namespace std;

// brute force
// solution is that for each given height we try to find the maximum rectangle that we can make by that height

// for an example we have: heights=[2,1,5,6,2,3]

// heights[0]=2 so can I go left with height=2 no because in left there is no block , can we go in right with height=2 no because beyond this there is a height=1 so I cannot extend height so the maximum width that I can get for a height =2 is width=1 so area=2*1=2 so area[0]=2

// heights[1]=1 so with height=1 can I go left - Yes I can go because in left there is height=2 which is greater than 1 so I can go till height =1 in left and in right can we go with height=1 yes we can go throughout every block because each block has height>1 so for height=1 we can have maximum width=6 so area[1]=1*6=6

// heights[2]=5 so with height=5 can we go left- No, can we go on the right with height=5 - yes because in right there is one block just after height=5 which has height=6 beyond that I don't have a height 5 so I can say with height=5 I have a maximum width=2 so are[2]=5*2=10

// remember one thing that we can take a consecutive rectangle only

// so that's why height=5 we have only maximum width=2

// heights[3]=6 for this I definitely cannot have anything on the left as well as cannot have anything on the right so for height=6 area will be area[3]=6*1=6

// heights[4]=2 for this in left we have two consecutive  block height=5 and height=6 in which we can go till height=2 and in right there is also we have one block with height=3 so in that we can also go with height=2 so maximum width we get is width=4 so area[4]=2*4=8

// heights[5]=3 in left there is no consecutive block in with height>=3 and in right also there is nothing so width=1 and area[5]=3*1=3

// so here I have considered every block to be the height of that rectangle and what is the larget area that we can figure out is?  the largest area that we get is 10

// so in our brute force solution we try out each block and remember one thing that we can consider the width of the block if it is consecutive otherwise we cannot take

// so for each block / height we had to figure out in left upto where I have to go and in right upto where I have to go
// so let's take an above example heights=[2,1,5,6,2,3]
// in that heights[4]=2 for that in right we can go till which is the first element that is smaller than 2 - on the right can I say - I can definitely take till upto last index because here in this example no one in right is smaller than 2 and in left also similar we figure out which is the smaller guy so here 1 is the smaller guy we get if we start from index=4 so we get 1 as first smaller guy so for every elt we have to find the right smaller guy and left smaller guy once we figured out then width = (right smaller index - left smaller index -1) and we know the height so we get area easily for each block/histogram

// The approach is to find the right smaller(i.e next smaller just after the current) and left smaller(i.e previous smaller just before the current ) element and find the largest Rectangle area in Histogram.

// This is done by taking different bars and finding the maximum width possible using the bar.

// Dry Run

// Considering the width of each bar as 1 unit.
// For first bar, area possible = 2* 1 =2 sq.units
// For second bar, area possible = 1 * 6 =6 sq.units
// For third bar , area possible = 5 *2 = 10 sq.units
// For fourth bar , area possible = 6 * 1 = 6 sq.units
// For Fifth bar , area possible = 2 * 4 = 8 sq.units
// For Sixth bar , area possible = 3 * 1 =3 sq.units
// So, the maximum area possible = 10 sq units.

// take i=2(height=5):
// left smaller =index 1(height=1)
// right smaller=index 4(height=2)
// width=4-1-1=2
// area=5*2=10

// For every bar i:

// Find the first smaller bar on the left just before the current bar.
// Find the first smaller bar on the right just after the current bar.
// The current bar is the smallest in that range, so
// width = rightSmaller - leftSmaller - 1
// area = heights[i] * width

// outer loop run n times and both inner loop together runs approx. n times so total t.c-O(n^2)
// s.c-O(1)
int largestArea(vector<int> &heights, int n)
{
  // variable to store maximum area
  int maxArea = 0;

  // we go with each index/height/bar
  for (int i = 0; i < n; i++)
  {
    int left = i - 1;
    while (left >= 0 && heights[left] >= heights[i])
    {
      left--;
    }
    int right = i + 1;
    while (right < n && heights[right] >= heights[i])
    {
      right++;
    }
    int width = right - left - 1;
    int area = heights[i] * width;
    maxArea = max(maxArea, area);
  }
  return maxArea;
}

// brute force by checking every subarray
// The idea is:

// Choose a starting index i.
// Extend the rectangle to every possible ending index j.
// While extending, keep track of the minimum height in that interval.
// Area = minimum height × width.

// t.c-
// outer loop-O(n)
// inner loop-O(n)
// so total - O(n^2)
// s.-c-O(1)

int largestRectangleArea(vector<int> &heights, int n)
{
  int maxArea = 0;
  // Outer loop to set the starting index of the subarray
  for (int i = 0; i < n; i++)
  {
    // To track minimum height in the subarray
    int minHeight = heights[i];
    // Inner loop to set the ending index of the subarray
    for (int j = i; j < n; j++)
    {
      // Update minimum height in the current window
      minHeight = min(minHeight, heights[j]);
      int width = j - i + 1;
      int area = minHeight * width;
      maxArea = max(maxArea, area);
    }
  }
  return maxArea;
}

// better solution
// in this we find the previous smaller just before the current and next smaller just after the current by using a monotonic stack

// the intuition behind the approach is the sama as finding the smaller element on both sides but in an optimized way using the concept of the next greater elt and the next smaller elt and formula is  for getting area - (right smaller index- left smaller index+1)*heights[i]

// so here let's create a left array of a size same as given of heights array size and we create a stack and in this stack we store index

// for an example heights=[2,1,5,6,2,3,1]
// we create left array=[]
// we create a stack
// first we find the left smaller elt for all heights
// we start from the 0th index
// i) index=0: we look on the stack is there any greater elt on the stack - no greater elt for this 0th index so we can say left boundary of left smaller for 0th index is left[0]=0 because the left boundary is 0 itself so we will put 0 index in left[0] and in stack also put index 0 which represents value 2
// ii) index=1: we look on the stack and we see we have a index=0 with value 2 which is greater than 1 but we require left smaller so will we keep that on our stack - not so we will not keep index=0 on our stack pop it after that there is no other in stack means for 1 we do not have any smaller elts so if on the left I do not have any smaller elts than my boundary is again index 0 so left[1]=0 and put index 1 onto the stack which represents value 1

// iii) next index=2: we look on the stack and we see we have a index=1 with value 1 and current we have value=5 so 1 is smaller than 5 so can I say 1 is the left smaller for 5 so for 5 left smaller is 1 so left boundary is index =1 and we will add 1 because when we draw heights as a histogram we see our boundary starts from second index our boundary will start from left smaller so we will simple add one so left[2]=1+1=2, we add one because when we draw boundary you see this and in stack we put also index=2 with value 5

// index=3: we look on the stack at top we have index=2 with value=5 and current we have value=6 so 5 is smaller that 6 so can I say 5 is the left smaller for 6 so for 6 left smaller is 5 so left boundary is index =2 and we will add 1 because when we draw heights as a histogram we see our boundary starts from second index our boundary will start from left smaller so we will simple add one so left[3]=2+1=3, we add one because when we draw boundary you see this and in stack we put also index=3 with value 6

// next index=4 with value 2 : we look on the stack at top we have index=3 with value=6 which is greater than 2 so we pop it next at top of stack we have 5 which is also greater than 2 so pop it next we have 1 which is smaller than 2 so  so can I say 1 is the left smaller for 2 so for 2 left smaller is 1 so left boundary is index =1 and we will add 1 because when we draw heights as a histogram we see our boundary starts from second index our boundary will start from left smaller so we will simple add one so left[4]=1+1=2, we add one because when we draw boundary you see this and in stack we put also index=4 with value 2

// next index=5 with value=3: we look on the stack at top we have index=4 with value=2 which is smaller than 3 so can I say 2 is the left smaller for 3 so for 3 left smaller is 2 so left boundary is index =4 and we will add 1 because when we draw heights as a histogram we see our boundary starts from second index our boundary will start from left smaller so we will simple add one so left[5]=4+1=5, we add one because when we draw boundary you see this and in stack we put also index=5 with value 3

// next index=6 with value=1: we look on the stack at top we have index=5 with value=3 which is greater than 1 so we pop it next at top of stack we have 2 which is also greater than 1 so pop it next we have 1 which is  equal to 1 not smaller so pop it also now there is no elt in stack so for 1 left boundary is 0 left[6]=0

// so now we have left array left=[0,0,2,3,2,5,0]

// similarly we find right smaller
// so we make right array and for this we start from last index
// index=6 with value=1 stack is empty no one is smaller than 1 in right so right[6]=6 which is the right boundary
// index=5 with value=3 : in stack at top we have index=1 with value=1 which is smaller than 3 so can I say for 3 right smaller is 1 so right boundary is index=6 but when we draw histogram we take miuns 1 so right[5]=6-1=5 and in stack we put index=5 with value 3

// index=4 with value=2:in stack at top we have index=5 with value=3 which is greater than2 so pop it next at top we have index-6 with value 1 which is smaller than 2 so can I say for 2 right smaller is 1 so right[4]=6-1=5 and in stack we put index=4 with value=2

// next index=3 with value=6: in stack at top we have index=4 with value=2 which is smaller than 6 so for 6 right smaller is 2 so right[3]=4-1=3 and in tsack we put index=3 with value=6

// next index=2 with value=5 : in stack at top we have index=3 with value=6 which is greater than 5 so pop it next at top we have index-4 with value 2 which is smaller than 5 so can I say for 5 right smaller is 2 so right[2]=4-1=3 and in stack we put index=2 with value=5

// next index=1 with value=1: in stack at top we have index=2 with value=5 which is greater than 1 so pop it next at top we have index-4 with value 2 which is greater than 1 so pop it next we have index=6 with value 1 which is equal to 1 so pop it now stack is empty so for 1 right boundary is index=6  so  so right[1]=6 and in stack we put index=1 with value=1

// next index=0 with value=2: in stack at top we have index=1 with value=1 which is smaller than 2 so right[0]=1-1=0 and in stack we put index=0 with value=2

// so now we get right array : right=[0,6,3,3,5,5,6]

// so now we have left smaller and right smaller for each histogram so now we can easily find out max area with formula: width*height=(right smaller index-left smaller index+1)*heights[i]

// left smaller=[0,0,2,3,2,5,0]
// right smaller=[0,6,3,3,5,5,6]

// Area for first index - ( 0 - 0 +1 ) * 2 = 2
// Area for second index - (6 - 0 + 1) * 1 = 6
// Area for third index - (3 - 2 +1 ) * 5 = 10
// Area for fourth index - (3 - 3 + 1 ) * 6 = 6
// Area for fifth index - (5 - 2 +1 ) * 2 = 8
// Area for sixth index - (5 - 5 + 1) * 3 = 3
// Area for seventh index - (6 - 0 +1) * 1 = 7
// So, the maximum area out of these is 10 sq units.

// t.c-
// for compute left smaller array : O(n)+O(n)
// for compute right smaller array: O(n)+O(n)
// O(n)(for traversing)+O(n)(for throughout the process to maintain the stack ), there is not O(n^2) because every time we are not removing every elt from the stack hence O(n)+O(n)=O(2n) for left smaller array and in same way for right smaller array
// so total O(4n)= approx. O(n) for understanding t.c see next Greater ELt video
// s.c-O(n)(for left array)+O(n)(for right array)+O(n)(for stack)=O(3n)
int largestrectangleArea(vector<int> &heights)
{
  int n = heights.size();
  stack<int> st;                               // in stack we store indexes
  vector<int> leftSmaller(n), rightSmaller(n); // both array also store indexes

  // compute nearest left smaller for each bar
  for (int i = 0; i < n; i++)
  {
    // we pop until a smaller elt is found or stack is empty
    while (!st.empty() && heights[st.top()] >= heights[i])
    {
      st.pop();
    }
    // if stack is empty then no smaller elt on the left so left[i]=0 else left[i]=st.top()+1
    leftSmaller[i] = st.empty() ? 0 : st.top() + 1;
    st.push(i); // push current index to stack
  }

  // empty the stack for reuse it to comput nearest right smaller
  while (!st.empty())
    st.pop();
  // Compute Nearest Smaller to Right (NSR) for each bar
  // we start from last index
  for (int i = n - 1; i >= 0; i--)
  {
    // we pop until a smaller elt is found or stack is empty
    while (!st.empty() && heights[st.top()] >= heights[i])
    {
      st.pop();
    }
    // if stack is empty then no smaller elt on the right so right[i]=n-1 else right[i]=st.top()-1
    rightSmaller[i] = st.empty() ? n - 1 : st.top() - 1;
    // push current index to stack
    st.push(i);
  }
  // calculate the max area using nearest left smaller index and nearest right smaller index
  int maxArea = 0;
  for (int i = 0; i < n; i++)
  {
    int width = rightSmaller[i] - leftSmaller[i] + 1;
    maxArea = max(maxArea, width * heights[i]);
  }
  return maxArea;
}

// optimized approach
// in better approach we do in two pass first we calculate the left smaller aray with stack then we reuse the stack to calculate the right smaller array instead of that now we do it in a single pass approach

// for an example we have heights=[3,2,10,11,5,10,6,3]
// now in previous better approach when we at last index here last index is 7 and when we calculating the left smaller then when we are at last index 7 then in our stack we have st(contains index)=[1,4,6] these are the indexes we have when we are at last index where 6 is at top where index 6 with value=6 , index 4 with value 5 and index 1 with value 2 this is the stack will contain when we reach a index 7 heiights[7]=3
// now what is the intuition of this approach is?
// the intuition is that instead of finding rectangular area for each heights[i] we will try to  find the rectangular area for these guys that we have in stack when we are at last index when we calculate the left smaller, we try to find rectangular areaa for here index 6 , index 4 , index 1 instead of all heights[i] now how will this work
// we are at last index with stack for going with left smaller
// heights[7]=3
// now in stack at top we have index=6 with value 5 so when we are at index 6 heights[6]=6 and now what will be its right smaller and what will be its left smaller?  Can I say right smaller will be nothing but for the 6 if we are comparing this with heights[7]=3 then that's gonna be a right smaller so we can say for height 6 right smaller index is 7 and for left smaller if we see in our stack then before index 6 we have index 4 because our stack is linearly increasing order so can I say index 4 will become my left smaller index for index 6 so without doing couple of passes for index 6 I could figure out the right smaller and left smaller
// so that's for index 6 next we go for next one now what we do in the next step we compare heights[7]=3 with heights[6]=6 now once we've got for the 6 we pop the 6 from the stack because 6 is greater than 3 next we compare heights[7]= 3 with index 4 having value 5 now when we are at the index 4 since we are comparing with 3 so can I again say that this index 7 with value 3 will become mine right smaller again for index 4 and for left smaller if we see in our stack then before index 4 we have index 1 so can I say index 1 will become my left smaller for index 4 so as we can see for index 4 we have the left smaller index is 1 and right smaller index is 7 so now we get the width and then get the area for index 4 again we find the left smaller and right smaller in one step let's do it for next what did we do with this heights[7]=3 we compare index 1 with value 2 and we pop out the index 4 so as of now at top in stack we have index 1 with value 5 and we compare that with heights[7]=3 so this is the moment we can say that this value 2 is no more comparable with 3 because 3 is greater than 2 means 2 is smaller than 3 so we will not do anything and we will pick this index 7 with value 3 and put in the stack so every element in the stack can actually tell you  which is your left smaller which is your right smaller now at index 7 is where our iteration will be overand we'll reach an index 8 so the moment we reach an index 8 we still have index 1 and 7 in our stack but the histogram is over doesn't matter even if your histogram is over you are at index 8 can I say for index 7 in stack that we have at top with value 3 can I say for that we don't have any one in right so can I say for this 3 right smaller will be index 8 because we don't have any one and left smaller will be the index 1 which is before index 7 in stack so for this index 7 we also figur out left smaller and right smaller so we need to do is just iterate till 8 so we can easily figure out for 3 and pop index 7 with value 3 from stack next we figur out for index 1 which is at top of the stack so for index 1 there is no one on the right so index 8 will be the right smaller and for left smaller there is no one in stack before index 1 so left index will be 0 so for index 1 we will also figure out left smaller and right smaller and now pop index 1 from stack and now stack is empty so finish
// so that's what will be  thought process in order to solve this problem how we get the right smaller and left smaller in single pass

// let's do dry run with an example
// heights=[3,1,5,6,2,3]
// we kept maxArea=0
// and we have stack which store indexes , no extra left smaller and right smaller array in this approach

// initially stack is empty
// we will start with index 0 with value =3 the stack is already empty so there is no one on the stack for which we can find the right smaller as  well as the left smaller so I'll take the index 0 and store it into stack next we'll come to the index 1 with value 1 and in stack at top we have index 0 with value 3 so we compare index 1 with index 0 value so 3 is greater than 1 hence for 3 the right smaller is 1 with index 1 and index 0 is removed from the stack so we know as of now height=3 and for this right smaller is index 1 and  for index 0 there is nothing before that so left smaller will be index 0 so in such cases we can say whatever is you right smaller the total will become your width so width will be 1 so area=3*1=3 so now maxArea=3 so once this is done we take the index 1 and put it in the stack so now in stack we have only index 1 with value 1 next we will come to the index 2 at index 2 we have value 5 we compare with top of the stack which is index 1 with value 1 so we don't find it greater than 5 so we'll do is just take index 2 and put it in stack so we put index 2 with value 5 in the stack whenever there is nothing as greater as take it and put it in the stack next we will come index 3 with value 5 and at top of the stakc we have index 2 with value 5 we compare this with 6 so 5 is not greater than 6 so we'll do is just take index 3 with value 6 and put it in the stack next we will come to the index 4 with value 2 and at top of the stack we have index 3 with value 6 so we compare 6 with 2 so 6 is greater than 2 so can I say 2 is right smaller value for 6 so for 6 right smaller index is 4 and for left smaller we have index 2 before index 3 in stack so for index 3 with value 6 left smaller index is 2 so we get both left smaller index =2 and right smaller index = 4 so width = right smaller-left smaller-1=(4-2-1)=1 and height =6 so area is 6*1=5 so now maxArea=6 so we done with index 3 so we pop out the index 3 with value 6 from the stack what is the next criteria ? we compare the heights[4]=2 with the top of the stack so now at top we have index 2 with value 5 so 5 is greater than 2 so can I say for index 2 right smaller is index 4 and for left smaller we have index 1 before index 2 so we have width =(4-1-1)=2 and height=5 so area=5*2=10 so now maxArea is 10 and we done with 5 so we pop out the index 2 from the stack next we compare the heights[4]=2 with the top of the stack so now at top we have index 1 with value 1 which is smaller than 2 so nothing has to done so we take index 4 with value 2 and put it in the stack  next we will come to index =5 with value 3 i.e heights[5]=3 and at top of the stack we have index 4 with value 2 which is smaller than 3 so nothing has to be done so we take index 5 with value 3 and put it in to the stack so I maintained the linearly increasing fashion but still for index 1,index 4, index 5 in stack has not been considered into the area so what we'll do is we just do one more iteration so we will come to index 6 we will go until 6 so of now as we can see we have just done for the histogram of height 3,5,6 still left for the height 1,2,3 and these are present in the stack so we are gonna use them so what we will do ? we will do one more iteration if the indexes are till 5 we are going to do one more iteration which is for index 6 so now what we'll do is since index 6 is the last index we don't need to do anything just pick up the top of the stack so at top we have index 5 with value 3 so we pop it from the stack and for this there is no right smaller so for thsi right smaller index is 6 and left smaller index is index 4 which is before the index 5 in stack so width is = (6-4-1)=1 and height = 3 so area=3*1=3 but maxArea=10 next we have index 4 with value 2 in stack at top so pop it and for this there is no right smaller so for index 4 right smallere index =6 and left smaller index is 1 which is before the index 4 in the stack so for index 4 we have width =(6-1-1)=4 and height =2 so area=2*4=8 but still maxArea=10 next we have index 1 with value 1 in our stack so for it also there is no right smaller so right smaller index =6 and there is no left smaller for index 1 because stack is now empty so left smaller index = 0 so width=(6-0)=6 in this case when left smaller index is 0 then the total right smaller index will become the width and height=1 so area=1*6=6 but still we have maxaere=10 and now stack is empty and there is no more iteration and now we are done with each height we have in our heights array
// so we get maxArea=10 here in this example
// so this is the process we solve the problem in one pass just we increae the iteration  we go from (0 to 6) instead of (0 to 5)

// t.c-O(n)(for traversing)+O(n)(for throughout the process to maintain the stack ), there is not O(n^2) because every time we are not removing every elt from the stack hence O(n)+O(n)=O(2n)
// s.c-O(n) for stack

// so this solution tells only if interviewer ask for more optimization otherwise go till with better solution because this solution requires some skill to explain otherwise  it's going to be an entire mess the interview is going to be an entire mess so make sure you only tell this solution if he asks you to optimize the previous one

int largestrectanglearea(vector<int> &heights)
{
  int n = heights.size();
  // stack to store indexes of heights in where heights are in linearly increasing order, it is monotonic stack
  stack<int> st;
  int maxArea = 0;
  // we go one with n iteration instead of (0 to n-1) we go (0 to n)
  for (int i = 0; i <= n; i++)
  {
    // we compare the current height with the top of the stack and if st.top() has greater height than current than we calculate area for it and pop it from the stack else if st.top() has smaller height than current then we do nothing we just put current in the stack
    // and if i==n then we do nothing we just pop from stack and calculate area for those heights
    while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
    {
      int height = heights[st.top()];
      st.pop();
      int width;
      // if stack is empty means there is no left smaller means left smaller index=0 so in that case width is total right smaller index which is current index
      if (st.empty())
        width = i; // where i is the current index so i is the right smaller index for st.top() index
      else
        width = i - st.top() - 1; // where i is right smaller index and st.top() is left smaller index
      maxArea = max(maxArea, height * width);
    }
    // we push current height index in stack when in stack at top we have smaller height than current we do nothing we just put it in stack and move to next so with the help of stack we can maintain the linearly increasing order and whenever we get elts  that are greater we can just compute the area for that and pop it from the stack that we do in while loop
    st.push(i);
  }
  return maxArea;
}
int main()
{
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> heights[i];
  }
  cout << largestArea(heights, n) << endl;
  cout << largestRectangleArea(heights, n) << endl;
  cout << largestrectangleArea(heights) << endl;
  cout << largestrectanglearea(heights);
  return 0;
}