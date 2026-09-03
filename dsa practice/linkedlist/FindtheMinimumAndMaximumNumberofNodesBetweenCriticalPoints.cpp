// A critical point in a linked list is defined as either a local maxima or a local minima.

// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

// Example 1:

// Input: head = [3,1]
// Output: [-1,-1]
// Explanation: There are no critical points in [3,1].
// Example 2:

// Input: head = [5,3,1,2,5,1,2]
// Output: [1,3]
// Explanation: There are three critical points:
// - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
// - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
// - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
// The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
// The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
// Example 3:

// Input: head = [1,3,2,2,3,2,2,2,7]
// Output: [3,3]
// Explanation: There are two critical points:
// - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
// - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
// Both the minimum and maximum distances are between the second and the fifth node.
// Thus, minDistance and maxDistance is 5 - 2 = 3.
// Note that the last node is not considered a local maxima because it does not have a next node.

// Constraints:

// The number of nodes in the list is in the range [2, 10^5].
// 1 <= Node.val <= 10^5

#include <bits/stdc++.h>
using namespace std;

// I solved this problem full by me

// Solution: simply traverse a linked list from second node because for first node there is no previous node so we start from second node and check for both local minima and local maxima if it is either of one then we push the nodeNumber in our temp array and we traverse the whole linked list similarly upto second last becase for last node there is no next node

// here for distance calculation we want nodeNumber means suppose we have [5,3,1,2,5,1,2] so here total we have 7 nodes and we say nodeNumber it is the node count for that node means like for first node , nodeNo=1 , for second node , nodeNo=2 and so on

// the node that is either local minima or local maxima we push the nodeNo for that node in our temp array

// after traverse given linked list
// if temp array size < 2 means there are fewer than two critical points , so we return [-1,-1]

// otherwise as we traverse linked list from starting to last so nodeNo is sorted so when we push nodeNo for a particular node that is either local minima or local maxima is also sorted
// so maxDistance must be the distance between the first and last critical point i.e maxDistance= temp[m-1]-temp[0]
// and for minDistance we have to check for each adjacent critical point means we have to check for each adjacent nodeNo in temp array and get the minDistance because nodeNo are sorted

struct Node
{
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};

// if linked list size=n and temp size =m
// t.c-O(n)(for traverse linked list , each node traverse once)+O(m)(for temp to calculate minDistance)=O(n+m)
// s.c-O(m)(for temp array)+O(2)(for ans array)=O(m)
vector<int> nodesBetweenCriticalPoints(Node *head)
{
  Node *prev = head;
  Node *curr = head->next;  // we start checking from second node because for first node there is no previous node
  Node *front = curr->next; // this is the next node for current node
  int nodeNo = 2;           // because w estart from second node so for that it is 2
  vector<int> temp;         // to store critical point means nodeNo
  // we go upto when front != NULL
  while (front != NULL)
  {
    // check for local minima
    if ((prev->data > curr->data) && (curr->data < front->data))
    {
      temp.push_back(nodeNo); // means that node is a critical point
    }
    // check for local maxima
    if ((prev->data < curr->data) && (curr->data > front->data))
    {
      temp.push_back(nodeNo); // means that node is a critical point
    }
    // update nodes
    prev = curr;
    curr = front;
    front = front->next;
    // and also nodeNo increase
    nodeNo++;
  }
  int m = temp.size();
  vector<int> ans(2, -1); // initially [-1,-1]
  if (m < 2)
    return ans;              // means there are fewer than two critical points, return [-1, -1].
  int minDistance = INT_MAX; // as temp is already sorted because we push nodeNo which is in sorted order so for minDistance we check for each adjacent critical point i.e nodeno for getting minDistance
  for (int i = 0; i < m - 1; i++)
  {
    int dist = temp[i + 1] - temp[i]; // sorted already so no need of abs()
    minDistance = min(minDistance, dist);
  }
  // maxDistance is temp[m-1]-temp[0] means distance between first and last critical point
  int maxDistance = temp[m - 1] - temp[0]; // no abs() because temp already sorted and store critical points in there order
  ans[0] = minDistance;
  ans[1] = maxDistance;
  return ans;
}

int main()
{
  Node *head = new Node(5);
  head->next = new Node(3);
  head->next->next = new Node(1);
  head->next->next->next = new Node(2);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(1);
  head->next->next->next->next->next->next = new Node(2);
  vector<int> ans = nodesBetweenCriticalPoints(head);
  cout << ans[0] << " " << ans[1];
  return 0;
}