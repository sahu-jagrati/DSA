// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.


#include<bits/stdc++.h>
using namespace std;

// here in this approach we are using recursion with data structure and map 
// suppose given that nums=[1,2,3] so size=3 so we will have n! permutations total 
// so here we have 3! = 6 permutations
// so we will use recursion to get all the permutations and we will use map to check which element is already used in the current permutation and which is not used so we will use map to check that 
// and using vector data structure to store the current permutation and when we reach the base case we will push that current permutation into the final answer vector of vector data structure
//  here base case is when the current vector size is equal to given vector size then we push the current vector in answer vector and return from that function call and backtrack to the previous function call and check for the next element which is not used in the current permutation and we will repeat this process until we get all the permutations.

// example: nums=[1,2,3] so we will have 3!=6 permutations so we will have 6 function calls and in each function call we will check for the next element which is not used in the current permutation and we will repeat this process until we get all the permutations.
// initially we will have an empty vector and we will have one freq map data structure that check we have that elt already or notin the current permutation and we will have a final answer vector of vector data structure to store all the permutations

// initially curr={} and freq={0,0,0}
// so initially we have three choices 1,2,3 so 
// i) first we will push 1 in curr nad mark 1 in freq as used then we will call the reucrsive function again and now we have two choices 2 and 3 because 1 we already take in current permutation
// now we will push 2 in curr and mark 2 as used then we again all function and noww e push 3 in curr so againg when we call function we have curr size==nums size so we get one permuation and push it in ans array and return back
// so now we backtrack it 
//        [1,2,3]
//      /     |       \
//     1      2        3  
//   /   \    /   \    /    \
//   2    3   1    3   1    2
//  /     \   /    \   /     \
//  3      2   3    1   2     1

// here in above diagram we can see that first if I choose 1 then I have two choices 2 and 3 and if I choose 2 then I have only one choice 3 so we get {1,2,3} one permutation and then we backtrack and choose 3 then we have only one choice 2 
// so we get {1,3,2} another permutation so here we say that when we backtrack we have to unmark the last elt and pop it from the current vector to get another permutation and we will repeat this process until we get all the permuations


// time complexity:
// we have total n! permutations so n! recursive function call  and for each permuation/function call  we run a for loop nums.size() times so
// total t.c- O(n! * n) where n is the size of given nums array
// s.c - 
// for ans vector we have n! permutations
// and current permutation size is n
// and for each current we mark the freq array so its size is alose n
// total s.c-O(n!)+O(n)+O(n)


// recursive function to get all the permutations
void recurPermute(vector<int>&curr,vector<vector<int>>&ans,vector<int>&nums,vector<int>&freq){

    // base case when current vector size is equal to given vector size then we push the current vector in answer vector and return from that function call and backtrack to the previous function call and check for the next element which is not used in the current permutation and we will repeat this process until we get all the permutations.
    if(curr.size()==nums.size()){
        ans.push_back(curr);
        return ;
    }
    // push elements in current vector from the given vector and check check for the next element which is not used in the current permutation and we will repeat this process until we get all the permutations.
for(int i=0;i<nums.size();i++){
    // if current elt is not used in the current permutation then we will push that elt in current vector and mark that elt as used in freq map and call the recursive function again to get the next elt 
    if(freq[i]==0){
        curr.push_back(nums[i]);
        freq[i]=1;
        recurPermute(curr,ans,nums,freq);
        // now when we backtrack to the previous function call then we will pop the last elt from currnt vector and mark that elt as not used in freq map and check for the next elt which is not used in the current permuation
        freq[i]=0;
        curr.pop_back();
    }
}    
}
vector<vector<int>>permute(vector<int>&nums){
    int n=nums.size();
    // answer vector
    vector<vector<int>>ans;
    // current vector to store the current permutation
    vector<int>curr;
    // freq map vector to check which element is already used in the current permutation and which is not used
    // initially all the elts are not used so we will initialize all the elements of freq map vector to 0
    vector<int>freq(n,0);
    // recursive function to get all the permutations
    recurPermute(curr,ans,nums,freq);
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>ans=permute(nums);
    for(auto vec: ans){
        for(auto it:vec){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}