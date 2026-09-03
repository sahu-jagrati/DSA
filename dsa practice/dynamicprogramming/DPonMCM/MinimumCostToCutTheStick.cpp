// Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:

// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

// You should perform the cuts in order, you can change the order of the cuts as you wish.

// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

// Return the minimum total cost of the cuts.

// Example 1:

// Input: n = 7, cuts = [1,3,4,5]
// Output: 16
// Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

// The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
// Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
// Example 2:

// Input: n = 9, cuts = [5,6,1,4,2]
// Output: 22
// Explanation: If you try the giv en cuts ordering the cost will be 25.
// There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.

// Constraints:

// 2 <= n <= 10^6
// 1 <= cuts.length <= min(n - 1, 100)
// 1 <= cuts[i] <= n - 1
// All the integers in cuts array are distinct.

#include <bits/stdc++.h>
using namespace std;

// we want a minimum total cost to cuts

// and cost = length of stick that we cut

// if we take an example:
// cuts[]=[1,3,4,5] and n=7
// total length of stick is 7 so stick is labelled from 0 to 7 so we have [0,1,2,3,4,5,6,7] then
// length from 0 to 1 is 1
// length from 0 to 2 is 2
// length from 0 to 3 is 3
// length from 0 to 4 is 4
// length from 0 to 5 is 5
// length from 0 to 6 is 6
// length from 0 to 7 is 7

// so the cut array given is [1,3,4,5]
// i) so first if we cut the stick from 1 then the cost = 7 is the length of the stick before cut and after cut stick is divided into two parts: [0,1] & [1,2,3,4,5,6,7]
// ii) next we cut the stick from 3 so now we have : [0,1],[1,2,3] & [3,4,5,6,7] these parts now we get and cost for cut the stick from 3 is (7-1)=6 because 3 is in second part of the stick and the length of that part before cut is 6
// iii) next we cut the stick from 4 so now we have: [0,1], [1,2,3],[3,4] & [4,5,6,7] these parts we get and cost for cut the stick from 4 is (7-3)=4 because 4 is a part of third partition and its length befoe cut is (7-3)=4
// iv) now we cut the stick from 5 so we have : [0,1],[1,2,3],[3,4],[4,5]&[5,6,7] and cost for cutting that part is (7-4)=3

// so total cost for cutting stick according to given cut array is : 7+6+4+3=20
// but we want minimum cost and also given that we can  change the order of cuts as we wish

// so if we change the order of given cut and cut the stick in this order [3,5,1,4] then :
// i) first we have whole stick and cut it from 3 so we have two partition: [0,1,2,3]&[3,4,5,6,7] and cost is (7-0)=7
// ii) we cut from 5 so now we have : [0,1,2,3],[3,4,5]&[5,6,7] and cost for that is (7-3)=4
// iii) we cut from 1 so now we have: [0,1],[1,2,3],[3,4,5]&[5,6,7] and cost for that is (3-0)=3
// iv) we cut from 4 so now we have: [0,1],[1,2,3],[3,4],[4,5]&[5,6,7] and cost for that is (5-3)=2

// so now total cost is 7+4+3+2=16 which is minimum than 20
// we can also check for other order of cuts array but the minimum cost we get is 16 by the order of cuts [3,5,1,4] so answer is 16

// so how do we approach this problem?
// we will be given something like [1,3,4,5] these are the cuts given and the length of the stick is n=7
// so how do we start approaching because we can either start with 1 as the cut, we can either start with 3 as the cut , we can start with 5 as the cut or we can start with 4 as the cut so we have a lot of options to start so Can I treat this [1,3,4,5] as a complete stuff? I can  and then can I say if I make a cut at 4 if I am making a cut for sure I can also start with 5 or I can say I can also start with 3 so I know if I treat this as a partition like if I treat this as an like i is at 1 and j is at 5 like an entire array:
//       [1, 3, 4, 5]
//        i     j
// I can say I can either start with 1, I can either start with 3, I can either start with 4, I can either start with 5 so what if I start with 4? I know the initial length of the stick is 7 so I will add up 7 to the answer so can I say now I'm solving only these cuts [1,3] and [5] because these are the remaining cuts if I solve them independently will this work? Yes. Why? because  it is sorted let's understand what does this mean? Now if we have made a cut at 4 then we have something like this as a stick in two parts : [0,1,2,3,4] & [4,5,6,7] so if I segregated them no matter if we perform cut =5 at first or cut =3 at first because they both are not connected now to the stick  even if we are performing 5 it's nowhere connected to the stick [0,1,2,3,4] and even performinh 1 and 3 it's nowhere connected to the stick [4,5,6,7] because the stick has been separated and WHy can we solve this subproblem [1,3] and [5] cuts independently? because they are not connected but if we do a slight change like now if we have cut array like this : [1,3,4,5,2] now i is at 1 and j is at 2 and after start with 4 we have subproblem like this : [1,3] and [5,2] now we cannot solve them independently because 2 in right subproblem is dependent on the left subproblem because cut =2 is lie on the stick [0,1,2,3,4] side so here we are dependent on the left stick thereby it's very important to have it sorted so that whenever we solve a subproblem they will not be dependent

// so when we sort the given cuts array and either start with cut=4 so we have : [0,1,2,3,4] and [4,5,6,7] and now whether we are gonna make a cut at 4 or 5 we won't be dependent on the left part of the stick, we don't have to decide whether we want to make a cut in order [1,3,2] or make a cut in order [1,2,3] because we will not be dependent

// so it's very important that the cut array is sorted so we don't have to decide in which order we have to cut because now after sorting they are not dependent

// now how do we find the length of the sticks?
// let's visualize we have [1,3,4,5] this is a partition that I'm solving i is at 1 and j is at 5 and I want to find how are these cuts going to give me the minimal cost and the length of the stick :
// so I put : 0 [1,3,4,5] 7 here I put 0 at the left and 7 at the right and    i     j   so here I just put 0 on the left and (length of the stick) on the right Why I do this? Imagine I'm making a cut at 4 I knowe I can make a cut at 3 or at 5 or at 1 anyway imagine I'm making a cut at 4 but what is the cost? the cost is the length of that stick in which 4 is. How do I get the cost? cuts[j+1]-cuts[i-1] = 7-0=7 this is the length of the stick if I apply this formula : cuts[j+1]-cuts[i-1] it will give me the length of the stick  Why? we learned later. If I'm taking 4 as a first cut then I need to solve [1,3] so imagine 4 is at index=ind so I need to solve this subproblem f(i,ind-1) and need to solve the right subproblem which is f(ind+1,j) because we did a partition on ind  so I need to solve this smaller partition (i,ind-1) and partition (ind+1,j) I just you can cut ind and I'll be solving these couple of partition and since they are sorted they are independent I can just solve them independently and add up the answer with the current answer which is (cuts[j+1]-cuts[i-1]) is the current answer and we add up the partition answer with it so we have: (cuts[j+1]-cuts[i-1])+f(i,ind-1)+f(ind+1,j)

// so we understood that it's going to be a partition problem
// like  [1,3,4,5] was give to us and we will insert a 0 at left and the length of the stick that is 7 here insert at right so:  0 [1,3,4,5] 7 that is we have now 0,1,2,3,4,5,7 and if we do indexing then we have :
// index:   0  1  2  3  4  5
//          0  1  3  4  5  7
//             i        j

// and start i from index=1 and j from index=4 which we can call it as f(1,4) where 4 is the initial length of the cuts array before inserting 0 and 7 so initial partition will start of it f(1,4) here

// f(i,j){
// now I know I can either start with cut=1, either start with cut=3, either start with cut=4, either start with cut=5 which eventually means I can take any one as the first cut so thereby what I say is okay now in partition dp we know if because we are solving a portion if it is crosses over there is nothing to  solve so we can just return a zero the cost will be zero so
// if(i>j)return 0; // if there is no partition to be solved

// int mini=1e9;
// I know one thing for sure that I can take any one from i to j and when I am taking anyone the costing that i'll incurr is (cuts[j+1]-cuts[i-1]) this is the cost if I cut it at that index= ind and we know we can take anyone from i to j as a first cut and I have to solve the left portion  f(i,ind-1) and solve the right portion f(ind+1,j)
// for(ind =i to j){
// cost=(cuts[j+1]-cuts[i-1])+f(i,ind-1)+f(ind+1,j) // here I get the cost for every index and take the minimum of all the indexes so I try all partitions and return the partition that gives me the minimal answer
// since we need the minimal cost so
// mini=min(mini,cost);
//}
// retrun mini;
//}

// so now let's understand the formula that we use for getting cost when we cut the stick : cuts[j+1]-cuts[i-1]

// let's take an example: we have cuts[]=[1,2,3,5,7,8] and length of the stick is n=12
// we have already sorted cuts array here now we insert 0 and length of the stick in the cuts array so we have now:
//          0, 1, 2, 3, 5 , 7, 8, 12
//             i               j
// and we are starting to solving this portion [1,2,3,5,7,8], just for an example imagine the first cut that we made was at 5 or we can make the first cut at 3 so let's we are making a cut at 3 we know the length is obviously 12-0=12 which is j+1 and i-1 for sure but whenever we are making a cut at 3 we are having a subproblem as:
// left portion is : 0 [1,2] 3
//                      i  j
// right portion is : 3 [5,7,8] 12
//                       i   j
// now if we carefully observe if we are making a cut at 3 then in the stick in left partition we have label : 0 , 1, 2, 3 and the length of that part of the stick is 3 so if we see our left portion of the above cut- 3 was the last cut on the right and 0 was on the left in that partition so 3-0 again gave us length of the stick
// similarly if we observe the right parttion of the stick after cut at 3 then it have label : 3, 4 ,5 ,6,7,8, 9,10,11,12 and the length of that part of the stick is 9 so if we see the right portion of the above cut - 3 was in the left and 12 was in the right of that partition so 12-3 again gave us the length of the stick which is cuts[j+1]-cuts[i-1]

// imagine now I take right portion we have : 3,[5,7,8],12 and I'll do a cut at 7 so I have a subproblem as:
// left portion is: 3,[5],7
//           both i and j is at 5
// right portion is: 7,[8],12
// both i and j is at 8
// so If I doing a cut at 7 then in the stick in left part we have label: 3,4,5,6,7 so if we see our left portion of cut 7 : 3 was in the left and 7 was in the right and the length is 7-3=4 again gave us the length of the stick
// and in right portion the stick label: 7,8,9,10,11,12 so if we see our right portion of cut 7: we have 7 in left and 12 in right so length is 12-7=5 again gave us the length of the stick

// so this is the reason why we take i-1 and j+1 because if we know  the left  last cut and right last cut and if we just subtract it we get the length so now we understood why we take cuts[j+1]-cut[i-1] a sthe length of the stick and why we take the subproblem : f(i,ind-1) and f(ind+1,j)

// recursion
// t.c-exponential in nature - O(2^c) as we try all possible cuts between the current boundary
// s.c-O(c) auxiliary stack space where c is size of cuts array
int f1(int i, int j, vector<int> &cuts)
{
  // base case when i crosses j so we have no partition to solve
  if (i > j)
    return 0;

  int mini = INT_MAX;

  // we try out all partition i.e we can start cut from any index i to j because each subproblem are independent
  for (int ind = i; ind <= j; ind++)
  {
    // cost = length of the stick and add the subproblem
    // Cost of making the current cut plus
    // cost of cutting left and right sub-segments recursively
    int cost = (cuts[j + 1] - cuts[i - 1]) + f1(i, ind - 1, cuts) + f1(ind + 1, j, cuts);
    mini = min(mini, cost);
  }
  return mini;
}

// memoization
// we have two changing parameters i and j
// i can be from 1 to cuts.size() and j can be from cuts.size() to 1 so i can max go to c and j max go to c so  we declare dp[c+1][c+1]

// t.c-
// we have two changing parameters i and j so c^2 and we try all possible cuts btw i and j so (c^2)*(c)
// so total t.c-O(c^3),  for every state in our dp table i.e. c^2 states, we try all possible cuts between i and j.
// s.c-O(c^2)(for dp)+O(c) for auxiliary stack space where c is size of cuts array
int f2(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
  // base case when i crosses j so we have no partition to solve
  if (i > j)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];
  int mini = INT_MAX;

  // we try out all partition i.e we can start cut from any index i to j because each subproblem are independent
  for (int ind = i; ind <= j; ind++)
  {
    // cost = length of the stick and add the subproblem
    // Cost of making the current cut plus
    // cost of cutting left and right sub-segments recursively
    int cost = (cuts[j + 1] - cuts[i - 1]) + f1(i, ind - 1, cuts) + f1(ind + 1, j, cuts);
    mini = min(mini, cost);
  }
  return dp[i][j] = mini;
}

// tabulation
// rules:
// i) copy the base case
// ii) write down the changing parameter in opposite fashion of recursion
// iii) copy the recurrence

// so if we say about base case in recursion we have if(i>j)return 0 so here in tabulation we declare dp[c+1][c+1] with initial value 0 so we have to do nothing because w elaready initialize with 0
// now for changing parameters
// in recursion i go from 1 to c and j go from c to 1 but j is always in right of i we start recursion with f(1,c) so here in tabulation it go opposite so i go from c to 1 and j is always in right of i so j go from i to c and we already discuss when i>j return 0 in base case

// t.c-O(c^3)
// s.c-O(c^2) for dp array where c is size of original cuts array before inserting 0 and n in it
int f3(int n, int c, vector<int> &cuts)
{
  // initialize a dp with 0
  vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0)); // we declare with c+2 because when i=c so in that case ind=c so ind+1=c+1 so we want c+2 size of dp

  // don't need to write base case separately because we already initialize dp with 0
  // i traverse from c to 1 opposite fashion of recursion
  for (int i = c; i >= 1; i--)
  {
    // and j is always in right of i so j traverse from i to c opposite fashion of recursion
    for (int j = i; j <= c; j++)
    {
      // copy the recurrence
      int mini = INT_MAX;
      // Try making a cut at every position between i and j
      for (int ind = i; ind <= j; ind++)
      {
        // Cost of making the current cut plus costs of left and right subproblems
        int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][ind - 1] + dp[ind + 1][j]; // here when i=c then ind also c then ind+1=c+1 so for storin c+1 we want dp of size c+2
        mini = min(mini, cost);
      }
      dp[i][j] = mini;
    }
  }
  return dp[1][c]; // The answer is the minimum cost to cut between indices 1 and c
}

int minCost(int n, vector<int> &cuts)
{
  // n is the length of the stick
  int c = cuts.size();
  // now we insert 0 at the begining of the array and n i.e length of the stick at the end of the cuts array because for getting length of the cuts at each cut
  cuts.push_back(n);
  cuts.insert(cuts.begin(), 0);
  // we sort the cuts array because we solved each subproblem independently
  sort(cuts.begin(), cuts.end());

  // now initially we have i at the first index  and j is at the length of the cut i.e index= c because when we insert 0 in starting so now last elt of original cuts array come at index=c so where c is the size of original given cuts array

  // recursion
  // return f1(1, c, cuts); // where c is the size of original cuts array before inserting 0 and n in it

  // memoization
  // vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
  // return f2(1, c, cuts, dp);

  // tabulation
  return f3(n, c, cuts);
}

int main()
{
  int n;
  cout << "Enter the length of the stick:";
  cin >> n;
  int c;
  cout << "Enter the size of cuts array:";
  cin >> c;
  vector<int> cuts(c);
  cout << "enter the value of cuts array: ";
  for (int i = 0; i < c; i++)
  {
    cin >> cuts[i];
  }
  cout << minCost(n, cuts);
  return 0;
}