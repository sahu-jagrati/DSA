// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

// Example 1:

// Input: rooms = [[1],[2],[3],[]]
// Output: true
// Explanation:
// We visit room 0 and pick up key 1.
// We then visit room 1 and pick up key 2.
// We then visit room 2 and pick up key 3.
// We then visit room 3.
// Since we were able to visit every room, we return true.
// Example 2:

// Input: rooms = [[1,3],[3,0,1],[2],[0]]
// Output: false
// Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.

// Constraints:

// n == rooms.length
// 2 <= n <= 1000
// 0 <= rooms[i].length <= 1000
// 1 <= sum(rooms[i].length) <= 3000
// 0 <= rooms[i][j] < n
// All the values of rooms[i] are unique.

#include <bits/stdc++.h>
using namespace std;

// I do this problem fully by me.

// In this problem if we  visit every room then return true else false so I do bfs for that and A.T.Q room0 is open in starting so I start from that and go to its neighbour or we can say its adjacency list and mark them visited and do process in same way

void bfs(int room, vector<bool> &visited, vector<vector<int>> &rooms)
{
  visited[room] = true;
  queue<int> q;
  q.push(room);
  while (!q.empty())
  {
    int visit = q.front();
    q.pop();
    // now we go to rooms[visit] adjacency list means the key it give
    // for an example we have rooms=[[1,3],[3,0,1],[2],[0]] so here if visit = room0 then its adjacency list is [1,3] so we travel this
    for (int i = 0; i < rooms[visit].size(); i++)
    {
      int neighbour = rooms[visit][i];
      if (!visited[neighbour])
      {
        q.push(neighbour);
        visited[neighbour] = true;
      }
    }
  }
}

// s.c-O(n) for visited+O(n)for queue
// t.c-O(n*max(rooms[i].size))
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
  int n = rooms.size();
  // we have n rooms labeled from 0 to n-1 so I make visited array for it
  vector<bool> visited(n, false);
  // initially room0 is opened
  visited[0] = true;
  // we can go only on those room for which we have key so in starting we have only for room0 and for other it go with adajcency list
  bfs(0, visited, rooms);
  for (int i = 0; i < n; i++)
  {
    if (visited[i] == false)
      return false;
  }
  return true;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> rooms(n);
  for (int i = 0; i < n; i++)
  {
    int m;
    cin >> m;
    rooms[i].resize(m);
    for (int j = 0; j < m; j++)
    {
      cin >> rooms[i][j];
    }
  }
  cout << canVisitAllRooms(rooms);
  return 0;
}