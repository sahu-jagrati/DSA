// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment or decrement an element of the array by 1.

// Test cases are designed so that the answer will fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 2
// Explanation:
// Only two moves are needed (remember each move increments or decrements one element):
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
// Example 2:

// Input: nums = [1,10,2,9]
// Output: 16
 

// Constraints:

// n == nums.length
// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9

#include<bits/stdc++.h>
using namespace std;

// we want minimum number of moves to make all array elts equal
// so we want an all array elts equals to such elt so that we get minimum number of moves
// so for that first we sort the array and equal all elts to the middle elt
// because in one move we can either increment or decrement an elt of the array by 1
// so we make all array elt eqaul to middle elt because for left hand size elts we increase them for making them equal to middle elt
// and for right side elts we decrese them for making them equal to middle elt 
// by this we get minimum number of moves

// if we take maximum elt or minimum elt of an array and equal all elts to it take more moves 
// so we first sort array and make all elts equal to the middle elt because it is in middle not in either end of the side so we get minimum moves

// t.c-O(nlogn)(for sorting)+O(n)(for moves)
// s.c-O(1)
int minMoves2(vector<int>&nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int middleElt=nums[n/2];
    int minMoves=0;
    for(int i=0;i<n;i++){
        // moves to make elt equal to middle elt after sort
        int moves=abs(nums[i]-middleElt);
        minMoves+=moves;
    }
    return minMoves;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<minMoves2(nums);
    return 0;
}