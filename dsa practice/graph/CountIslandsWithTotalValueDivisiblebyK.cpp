// You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).

// The total value of an island is the sum of the values of all cells in the island.

// Return the number of islands with a total value divisible by k.

 

// Example 1:


// Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5

// Output: 2

// Explanation:

// The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

// Example 2:


// Input: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3

// Output: 6

// Explanation:

// The grid contains six islands, each with a total value that is divisible by 3.

 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 1000
// 1 <= m * n <= 10^5
// 0 <= grid[i][j] <= 10^6
// 1 <= k <= 10^6

#include<bits/stdc++.h>
using namespace std;

// we are solving this problem using bfs

// t.c -N*M(for for loops) + (N*M*4)(for bfs run)
// s.c-(N*M)(for visited)+(N*M)(for queue in worst case)-O(N*M)

long long bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited){
    int n=grid.size();
    int m=grid[0].size();
    long long totalValue=0;
    visited[row][col]=1;
    totalValue+=grid[row][col];
    queue<pair<int,int>>q;
    q.push({row,col});
    // we can move in 4 directions so
    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        // neighbours
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!visited[nrow][ncol]&&grid[nrow][ncol]!=0){
                q.push({nrow,ncol});
                visited[nrow][ncol]=1;
                totalValue+=grid[nrow][ncol];
            }
        }
    }
    return totalValue;
}
int countIslands(vector<vector<int>>&grid,int k){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&grid[i][j]!=0){
                long long totalValue=bfs(i,j,grid,visited);
                if(totalValue%k==0){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int k;
    cin>>k;
    cout<<countIslands(grid,k);
    return 0;
}