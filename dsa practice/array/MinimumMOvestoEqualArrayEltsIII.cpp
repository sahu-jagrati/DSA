// You are given an integer array nums.

// In one move, you may increase the value of any single element nums[i] by 1.

// Return the minimum total number of moves required so that all elements in nums become equal.

 

// Example 1:

// Input: nums = [2,1,3]

// Output: 3

// Explanation:

// To make all elements equal:

// Increase nums[0] = 2 by 1 to make it 3.
// Increase nums[1] = 1 by 1 to make it 2.
// Increase nums[1] = 2 by 1 to make it 3.
// Now, all elements of nums are equal to 3. The minimum total moves is 3.

// Example 2:

// Input: nums = [4,4,5]

// Output: 2

// Explanation:

// To make all elements equal:

// Increase nums[0] = 4 by 1 to make it 5.
// Increase nums[1] = 4 by 1 to make it 5.
// Now, all elements of nums are equal to 5. The minimum total moves is 2.

 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

#include<bits/stdc++.h>
using namespace std;

// here in this problem we can only increase the value of any single elt by 1
// we cannot apply decrease operation
// so first we find the maximum elt of an array then make all elts of an array equal to it by increasing all elts 
// we want minimum number of moves and we can increase only by 1 in one move so we make all elts equalt to maximum elt it will give minimum moves 
// we cann't take minimum elt of an array because for making other elt to equal to it we have to do decrease operation which is not given, same in other cases also so we chhose maximum elt of an array and make all equal to it


// t.c-O(n)(for getting maximum)+O(n)(for moves)=O(2n)
// s.c-(1)
 int minMoves(vector<int>& nums) {
        int n=nums.size();
        int maximumElt=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maximumElt){
                maximumElt=nums[i];
            }
        }
        int miniMoves=0;
        for(int i=0;i<n;i++){
            int moves=abs(nums[i]-maximumElt);
            miniMoves+=moves;
        }
        return miniMoves;
    }

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<minMoves(nums);
    return 0;
}