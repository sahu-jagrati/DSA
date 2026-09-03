// definition of loop in LL- if there exists a minimum of one node where you start and reach back then we can say that the linked list has a loop
// we want minimum one node for loop
// there can be multiple nodes you can start from any of them and you will reach back

// you can take any node and it is guranteed that there will be one loop so the length of loop is same from each node of loop
// you can start counting at with any node and each of them will be giving you a length of loop
// if linear LL then there is no loop so length is 0

// we detect loop by hashing and by tortoise and hare algo

#include <bits/stdc++.h>
using namespace std;

class Node
{ // or you can use struct
public:
  int data;
  Node *next;
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

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

// naive solution-by hashing using timer
// in this we traverse LL in insert it in map if it is not in map, so one step take one second
// when we first reach to node we memorize that time and if there is loop then we visit the node again so at we get current time then length is (current time - already reach time)

// map store entire node(address) not data because data can be same for more than one node and take integer as timer

// t.c-O(N*2*logN) where N is length of LL and 2*logN-one for insert and one for finding in map using map or if we use unordered map then it is O(1) in average or O(N) in worst
// s.c-O(N) for map
int lengthOfLoop(Node *head)
{
  map<Node *, int> mpp;
  Node *temp = head;
  int timer = 1;
  while (temp != NULL)
  { // if LL is linear so
    // first we check node is in mpp already or not, if not then insert
    if (mpp.find(temp) != mpp.end())
    { // we have node alredy
      int alreadyTime = mpp[temp];
      return (timer - alreadyTime); // length of loop
    }
    // else insert in mpp
    mpp[temp] = timer;
    timer++;
    temp = temp->next;
  }
  return 0; // if no loop
}

// optimized solution-tortoise and hare algo
// we know we  take two pointer slow and fast pointt initially to head and slow jump by 1 and fast jump by 2 and both move simultaneously togther
// we get cycle when slow == fast means if they are meeting then there is a loop
// when slow and fast both point to same node means definitely there was a loop that's why they standing at same Node
// if I start from that node where they both meet and came back to it, so we will keep a counter and we start moving the fast pointer or slow pointer move any one for count reach back to node then the cnt is our length

// after knowing there ie loop, we move only one pointer for count and by one jump only

// if we have linear linked list then they will never collide
// for odd length linear LL fast go to last node
// for even length linear LL fast->next==NULL

int findLength(Node *slow, Node *fast)
{
  // we move only one pointer for count
  // for initial one step
  int cnt = 1;
  fast = fast->next;
  // move until they meet together
  while (slow != fast)
  {
    cnt++;
    fast = fast->next;
  }
  return cnt;
}

// t.c-O(N) where N is length of LL because for linera LL we travel whole LL
// s.c-O(1)
int lengthOfCycle(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  // first we detect cycle
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return findLength(slow, fast); // get loop then find length
  }
  return 0; // if no loop
}
void makeCycle(Node *head, int pos)
{
  if (pos == -1)
    return;
  Node *temp = head;
  Node *loopNode = NULL;
  int indx = 1;
  while (temp->next != NULL)
  {
    if (indx == pos)
    {
      loopNode = temp; // make cycle
    }
    temp = temp->next;
    indx++;
  }
  // last node connects to loop node
  temp->next = loopNode;
}

int main()
{
  vector<int> arr = {1, 2, 15, 4, 13, 6, 7, 8, 9};
  Node *head = convertArrToLL(arr);
  int pos;
  cout << "Enter the position where the cycle start: ";
  cin >> pos;
  makeCycle(head, pos);
  cout << "Length of cycle is: ";
  // cout << lengthOfLoop(head) << endl;
  cout << lengthOfCycle(head) << endl;
  return 0;
}