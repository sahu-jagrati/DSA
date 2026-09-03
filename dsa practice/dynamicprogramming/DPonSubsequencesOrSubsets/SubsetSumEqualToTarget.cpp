// We are given an array ‘ARR’ with N positive integers. We need to find if there is a subset in “ARR” with a sum equal to K. If there is, return true else return false.

// Input :  N = 4, ARR = [4, 3, 5, 2], K = 6
// Output : true
// Explanation : One possible subset with sum = 6 is [4, 2]. There’s also [3, 3] but that doesn’t exist in the array. As soon as we find one subset whose sum is equal to K, the answer is true.

// Input : N = 3, ARR = [1, 2, 5], K = 4
// Output : false
// Explanation : Possible subsets and their sums: [1] → 1, [2] → 2, [5] → 5, [1,2] → 3, [1,5] → 6, [2,5] → 7, [1,2,5] → 8. None of them equal 4, so the answer is false.

// greedy can't be apply
// Why a Greedy Solution doesn’t work?
// A Greedy Solution doesn’t make sense because we are not looking to optimize anything. We can rather try to generate all subsequences using recursion and whenever we get a single subsequence whose sum is equal to the given target, we can return true.

// how do you solve this problem
// i) generate all the subsequences and check sum equal to target

// how can you generate all the subsequences there are two ways-i) power set,  ii) Recursion to generate all the subsequences

// but the question arises over here what is the question does it ask us to generate all the subsequences and the answer to that is no so what's the question states does there exist a single subset if i get a single subset my job is done so i don't need to generate all the subsequences that's where we think of okay so instead of generating all the subsequences we just need to keep a check if there is any subset right so thereby we decide that okay we will follow the recursion method because we don't need to print all we will just follow the recursion method and hypothetically when we just get one subsequence with the same subset target we will return and we will stop so we know recursion can help us to generate all the subsequences

// the rule of writing the recurrence any recurrence

// 1. express everything in terms of index
// and here every array problem will always have an index so we definitely have an index do we have any other parameter on every index we need to take care of the target that we are looking for so we can say we definitely have a target that we are looking for so always remember this whatever may be the problem on dp on subsequences and these subsets and target problems we will always try to express everything in terms of index and everything in terms of target like in grid it was i and j, in subsequences it is index and it is target thumb rule okay

// f(index,target)

// 2. explore possibilites of that index
// what can be the possibilites?
// there will be two possibilities-
// i) whether that arr[index] is the part of the subsequence
// ii) that arr[index] is not part of the subsequence
// logically only these paths will be there. we have written all the possibilities i don't see any other possibilities for a given index right

// 3. return True/False

// now the question arises how do i start with index how do i start with target?

// What I am looking for? I am looking for the entire array and if there exists a subsequence with the target

// important-

// i'll try to express it in terms of - f(n-1,target(i.e k))- saying in the entire array till index (n-1) does there exist a target that is what the recurrence will tell you in the entire array till index (n-1) does there exist any target. f(n-1,target)

// f(index,target){

// base case
// what are the base cases here
// i)  it might happen we have achieved the target like if arr=[1,2,3,4] and target =4 and we start f(n-1,target)-f(3,4) so we get ar[3]=4 so now target =4-4=0 so for index 0 to 2, target=0, so the target is no more, there is no further target to be achieved

// if(target==0)return true; // so we have written the base case for target

// ii) what about the other one index. so where is the call starting from (n-1) and we know we will go till the 0th index because in an array it's from n-1 at index till the 0th index so if you are standing at an index zero and you have a certain target value like assume target=4 and you are standing at 0th index so how can you determine if arr[0]==target then we achieved otherwise not make sense because f(0,target) signify till 0th index can we achieve this target and if it's 0th index it's only single element so how can i achieve that target if it's the target itself so thereby

// if(index==0)return arr[0]==target; // true if it is otherwise it return false
//  so first step express and write the base cases is completed always if you're writing a base case first think about the target don't think about the index

// 2. explore  possibilities of that index- because as of now you're standing at an index so you are at an index and they are asking can i form a subsequence from 0 to that index that gives me the target.  i'll be like okay there are two ways

// i) I will not take that index so that guy is not taken so i'll move to one less index always and we'll say same target
// bool notTake=f(index-1,target)

// ii) other case take that index
// bool take=false // initially because we have to check that arr[index] is enough to get that target means if arr[index]=3 and target=2 so we can't take that index so we have to check that also, if I take it(index) I will move to the previous index and what will happen to this particular target if I take that arr[index] then target will become (target-arr[index]) for the next index
// take=f(index-1,target-arr[index]);

// now either not take or either take i'll just keep on trying and the moment it reaches index zero if i can have this as the target it will return me true or return me a false or if any of the moment the target is achieved it'll return me true so there are two choices one was the take and the other one was the not take so i can say i'm trying two possible ways and i'm looking is there a possibility so if i'm looking for is there a possibility can i say it will be or of both of them  because i'll try both the possibilities if any one of them returns true i return a true because i'm looking for one subset only

// return take || notTake
//}

// if we see an example-
// arr=[2,3,1,1] and target-4
// initial call is f(3,4)=f(n-1,target)
// for f(3,4)- take=f(2,4-1)=f(2,3)
// notTake=f(2,4)

// now for f(2,3)
// take=f(1,3-1)=f(1,2)
// notTake=f(1,3)

// now for f(1,2)
// for take target=2 and arr[1]=3 which is greater than target so we can't take it so it return false
// for notTake-f(0,2)- arr[0]=2 so arr[0]==target which return true

// for f(1,2)- false || true=true

// similarly we calculate f(1,3)

// and we know we gets true so not necessary
// overall answer is True

// there aill be overlapping subproblem also
// when we go for f(2,4) then for take=f(1,3) which we already calculate so there is overlapping subproblem

// t.c for recursion - O(2^n) because for every array element you have couple of options either you take that element into consideration or you say i'm not going to take this element so you just have couple of considerations

// s.c for recursion-O(n) auxiliary stack space

// memoization
// the first thing is figure out the changing states so there is an index and there is a target that might change
// index constraint is about <=10^3 +1
// and same for target

// we initialized with dp matrix of size n*(k+1)
// dp[n][k+1] with value -1 and it is a int matrix
// index go from (0 to n-1)
// target go from (0 to k)

// t.c for memoization- O(n*target)
// s.c-O(n*target)(for dp matrix)+O(n)(for auxiliary stack space)

// tabulation-bottom-up
// first declare the dp matrix of same size dp[n][k+1] and it is a bool matrix
// next step was base case so what are the base case in recursion
// i) base case is-  if(target==0) so for any index if target==0 we return true so index are from (0 to n-1)
// for(int i=0;i<n;i++){
// dp[i][0]=True
// }
// ii) base case is- if(index==0) return true if arr[0]=target now  index is zero and target can be anything okay but when will it be true for every target what can be the possible values of target at index zero it can be anything target=(1 to target) it can't be zero. The first row dp[0][] indicates that only the first element of the array is considered, therefore for the target value equal to arr[0], only cell with that target will be true, so explicitly set dp[0][arr[0]] =true, (dp[0][arr[0]] means that we are considering the first element of the array with the target equal to the first element itself). Please note that it can happen that arr[0]>target, so we first check it: if(arr[0]<=target) then set dp[0][arr[0]] = true.

// now next is nested loop
// how many states are there - two states- one is index and other is target

// bottom-up
// index is from(1 to n-1) we already done with index==0 as a base case
// target =  from(target to 1) over here what will happen you go opposite from (1 to target) because target==0 has already been done

// so these are the nested loop and now copy paste the recurrence inside them

// only two steps you have to remember write the base cases then just think of the nested states remember the number of states is equal to the number of the nested loops

// t.c for tabulation-O(n*target)
//  s.c-O(n*target) for dp where n is the array size

#include <bits/stdc++.h>
using namespace std;

// recursion
bool f1(int index, int target, vector<int> &arr)
{
  // base case
  // i) if target ==0
  if (target == 0)
    return true;
  // ii) if index ==0
  if (index == 0)
    return arr[0] == target;

  // explore all possibilities
  bool notTake = f1(index - 1, target, arr);
  bool take = false; // initially because we have to check that arr[index] is sufficient in comparision to target
  if (arr[index] <= target)
    take = f1(index - 1, target - arr[index], arr);

  return take || notTake; // if any one of true
}

// memoization
bool f2(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  // base case
  if (target == 0)
    return true;
  if (index == 0)
    return arr[0] == target;

  if (dp[index][target] != -1)
    return dp[index][target];

  bool notTake = f2(index - 1, target, arr, dp);
  bool take = false;
  if (arr[index] <= target)
    take = f2(index - 1, target - arr[index], arr, dp);

  return dp[index][target] = take || notTake; // boolean can be 0 or 1 it automatically return in integer
}

// tabulation-bottom-up
bool f3(vector<int> &arr, int n, int k)
{
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  // base case
  // i) if target==0 then index can be anything
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }
  // ii) if index==0 for that we also have to check that arr[index]<=target.  If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true because we go from bottom-up
  if (arr[0] <= k)
  {
    dp[0][arr[0]] = true;
  }

  // nested loops-equal to number of states which is two here one is index and other is target
  // for index
  for (int index = 1; index < n; index++)
  { // with i=0 already done in base case
    // for target in which target=0 also done in base case
    for (int target = 1; target <= k; target++)
    {
      bool notTake = dp[index - 1][target];
      bool take = false;
      if (arr[index] <= target)
      {
        take = dp[index - 1][target - arr[index]];
      }
      // Store the result in the DP array for the current subproblem
      dp[index][target] = take || notTake;
    }
  }
  return dp[n - 1][k]; // which is f1(n-1,k) A.T recursion
}

// space optimization
// If we closely look the relation,
// dp[ind][target] =  dp[ind-1][target] || dp[ind-1][target-arr[ind]]

// We see that to calculate a value of a cell of the dp array, we need only the previous row values (say prev). So, we don’t need to store an entire array. Hence we can space optimize it.
// Note: Whenever we create a new row ( say cur), we need to explicitly set its first element is true according to our base condition.

// in the base case when target==0 so for every index it is marked as true

// t.c-O(n*target)
// s.c-O(target) for prev and curr array
bool f4(vector<int> &arr, int n, int k)
{
  // prev row
  vector<bool> prev(k + 1, false);
  // Base case: target 0 can always be formed by empty subset
  prev[0] = true; // when target =0 so it is true

  // Base case: if first element <= k, mark true because we go bottom-up
  if (arr[0] <= k)
  {
    prev[arr[0]] = true;
  }
  // Iterate over all elements from second to last
  for (int index = 1; index < n; index++)
  {
    vector<bool> curr(k + 1, false);
    curr[0] = true; // when target=0 then always true
    for (int target = 1; target <= k; target++)
    {
      bool notTake = prev[target]; // means from index-1 which is prev
      bool take = false;
      if (arr[index] <= target)
      {
        take = prev[target - arr[index]]; // means from index-1 which is prev
      }
      curr[target] = take || notTake; // update current row which is index
    }
    prev = curr;
  }
  return prev[k]; // which is index-1 of k
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
  // recursion-top-down
  // return f1(n - 1, k, arr);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  // return f2(n - 1, k, arr, dp);

  // tabulation
  // return f3(arr, n, k);

  // space optimization
  return f4(arr, n, k);
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int k;
  cin >> k;
  cout << subsetSumToK(n, k, arr);
  return 0;
}