// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

// Example 1:

// Input: head = [5,4,2,1]
// Output: 6
// Explanation:
// Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
// There are no other nodes with twins in the linked list.
// Thus, the maximum twin sum of the linked list is 6.
// Example 2:

// Input: head = [4,2,2,3]
// Output: 7
// Explanation:
// The nodes with twins present in this linked list are:
// - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
// - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
// Thus, the maximum twin sum of the linked list is max(7, 4) = 7.
// Example 3:

// Input: head = [1,100000]
// Output: 100001
// Explanation:
// There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.

// Constraints:

// The number of nodes in the list is an even integer in the range [2, 10^5].
// 1 <= Node.val <= 10^5

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

// I solved this problem fully by own as a optimal solution directly

// in question it said we pairs elt of ith node with (n-1-i) th node where n is even so one elt is from front of LL and other elt is from back of LL
// as we are working on singly LL now so we don't have back pointer

// so what we do is? we reverse the second half of the LL
// like we have example : 5->4->2->1 here pair are (5,1) and (4,2)
// after reversing second half, it become: 5->4->1->2. now if we get middle elt then we easily make pair and move to next in both half of LL .
// so for getting middle elt we use "Tortoise and Hare Algo" i.e slow and fast pointers algo so we by getting middle elt we reverse the second half first and then take pairsum

// t.c:
// finding middle: O(n/2)
// reverse second half: O(n/2)
// pair sum: O(n/2)
// total t.c-O(n/2)=O(n)
// s.c-O(1) where n is number of nodes
int pairSum(Node *head)
{
  // first we find middle elt to reverse second half of LL
  // and also here we have to take extra pointer prev1 so that after reversing it connect first half to second half
  // we get middle elt at slow so its previous elt is prev1 which connects both half of LL
  Node *prev1 = NULL; // move one step i.e take place of slow
  Node *slow = head;  // move one step
  Node *fast = head;  // move two step
  while (fast != NULL && fast->next != NULL)
  {
    prev1 = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  // now reverse second half
  // we want three pointers that record previous elt, current elt , next elt
  Node *prev2 = NULL; // because when we reverse the last -> next=NULL and after reverse last=slow elt i.e middle elt
  Node *temp = slow;  // because we start reverse from second half
  while (temp != NULL)
  {
    // poniter for next elt
    Node *front = temp->next;
    temp->next = prev2;
    prev2 = temp;
    temp = front;
  }
  // now connect both half so
  prev1->next = prev2; // where prev1 is last elt of first half and prev2 is first elt of second half

  // now for pair sum: first elt is from first half and second elt is from second half
  temp = head; // from first half and prev2 is already first elt of second half as we reverse the second half so it is
  int maxSum = 0;
  while (prev2 != NULL)
  {
    maxSum = max(maxSum, temp->data + prev2->data);
    temp = temp->next;
    prev2 = prev2->next;
  }
  return maxSum;
}
Node *convertArrToLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp; // or mover=mover->next because mover->next = temp now
  }
  return head;
}

void traverselInLL(Node *head)
{
  Node *temp = head;
  while (temp) // not nullptr run
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  Node *head = convertArrToLL(arr);
  // traverselInLL(head);
  cout << pairSum(head);
  return 0;
}