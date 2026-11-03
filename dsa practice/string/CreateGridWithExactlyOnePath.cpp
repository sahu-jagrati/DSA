// You are given two integers m and n, representing the number of rows and columns of a grid.

// Construct any m x n grid consisting only of the characters '.' and '#', where:

// '.' represents a free cell.
// '#' represents an obstacle cell.
// A valid path is a sequence of free cells that:

// Starts at the top-left cell (0, 0).
// Ends at the bottom-right cell (m - 1, n - 1).
// Moves only:
// Right, from (i, j) to (i, j + 1), or
// Down, from (i, j) to (i + 1, j).
// Return any grid such that there is exactly one valid path from the top-left cell to the bottom-right cell.

 

// Example 1:

// Input: m = 2, n = 3

// Output: ["..#","#.."]

// Explanation:



// The only valid path is: (0,0) → (0,1) → (1,1) → (1,2)

// Example 2:

// Input: m = 3, n = 3

// Output: ["..#","#..","##."]

// Explanation:



// The only valid path is: (0,0) → (0,1) → (1,1) → (1,2) → (2,2)

// Example 3:

// Input: m = 1, n = 4

// Output: ["...."]

// Explanation:

// The only valid path is: (0,0) → (0,1) → (0,2) → (0,3)

 

// Constraints:

// 1 <= m, n <= 25

#include<bits/stdc++.h>
using namespace std;

// as we can return any valid path and we can move only right and in down direction
// so our valid path is for i=0 row move right until last column then for j=(n-1) col move down until last row is our valid path

// t.c-O(m*n)
// s.c-ans. size()= O(m*n)
vector<string>createGrid(int m,int n){
    vector<string>ans;
    for(int i=0;i<m;i++){
        string temp="";
        for(int j=0;j<n;j++){
            // move till last column first(i.e in right direction)
            //  then move till last row (i.e in down direction)
            if(i==0 || j==(n-1)){
                temp+='.';
            }
            else{
                temp+='#';
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<string>ans=createGrid(m,n);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}