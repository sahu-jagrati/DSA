// definition of loop in LL- if there exists a minimum of one node where you start and reach back then we can say that the linked list has a loop
// we want minimum one node for loop
// there can be multiple nodes you can start from any of them and you will reach back

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

// naive solution- if any one node visited more than one times then there is a loop
// so we have to memoize, for this we use hashing
// before inserting in map first we check is it already in map or not, if not then insert

// map store entire node(address) not data because data can be same for more than one node and take integer/boolean with it

// t.c-O(N*2*logN) where N is length of LL and 2*logN-one for insert and one for finding in map using map or if we use unordered map then it is O(1) in average or O(N) in worst
// s.c-O(N) for map
bool detectCycle(Node *head)
{
  map<Node *, int> mpp;
  Node *temp = head;
  while (temp != NULL)
  { // beacuse if there is linear LL then
    // first check in map
    if (mpp.find(temp) != mpp.end())
    {
      return true; // means there is loop, node is already visit
    }
    mpp[temp] = 1; // else insert it in map
    temp = temp->next;
  }
  return false;
}
// optimized solution-Tortoise and hare algo
// take two pointer slow and fast pointt initially to head and slow jump by 1 and fast jump by 2 and both move simultaneously togther
// we get cycle when slow == fast means if they are meeting then there is a loop
// when slow and fast both point to same node means definitely there was a loop that's why they standing at same Node and return true;

//  but how we sure that they will be colliding at a single node, what if they crossover
// intution is we see distance btw fast and slow, not slow and fast
// as fast move by 2 and slow move by 1
// fast move by 2 towards slow and slow moves by 1 away fast so overall reduction will be one so fast will be closer by one
// so when fast move it will be one less than the previous distance btw them
// diiference of distance btw fast and slow is d initially then after meve next step it is d-1 and then d-2 and become 0 one time when they collide
// so that's why we get collide point

// fast can be jump by 3 but at that case we cannot reduce by 1

// if we have linear linked list then they will never collide
// for odd length linear LL fast go to last node
// for even length linear LL fast->next==NULL

// t.c-O(N) because we can find loop in starting or in middle or at last
// where N is length of LL
// s.c-O(1)
bool findCycle(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
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
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Node *head = convertArrToLL(arr);
  int pos;
  cout << "enter position where the cycle start: ";
  cin >> pos;
  makeCycle(head, pos);
  cout << "Cycle or not in LL: ";
  // cout << detectCycle(head) << endl;
  cout << findCycle(head) << endl;
  return 0;
}