// we have to find starting point of loop/cycle in LL
// you have to return entire node, not only value
// if linear LL then return null
// we know for detect loop we do - by hashing or by tortoise and Hare algo

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

// naive solution- by hashing we memoize it and traverse LL and see if node is visited already or not
// we store Node(address) in map, not data because data can be same for more than one node
// befor inserting in map first we check it is already in map or not, if not then insert it

// when we get first node that is already in mpp is the starting point

// t.c-O(N*2*logN), N for traversing and 2*logN for insert and finding in map or if we use unordered map then O(1) in average or O(N) in worst
Node *findStartingPointOfLoop(Node *head)
{
  map<Node *, int> mpp;
  Node *temp = head;
  while (temp != NULL)
  { // if linear LL
    // first we check in map
    if (mpp.find(temp) != mpp.end())
    {
      return temp; // there is loop and temp is starting point
    }
    mpp[temp] = 1;
    temp = temp->next;
  }
  return NULL; // if no loop
}

// optimized solution-tortoise and hare algo
// take two pointer slow and fast point initially to head and slow jump by 1 and fast jump by 2 and both move simultaneously together
// we get cycle when slow == fast means if they are meeting then there is a loop
// when slow and fast both point to same node means definitely there was a loop that's why they standing at same Node
// when they first collide we get there is loop
// now for starting point of loop

// step-1 detect a loop
// step-2 find the starting point of the loop
// in step-2 when first time slow == fast there is a loop
// now take any one pointer from the first collide point and place it to head and other is at collide point. Now,move both simulatneously together by step 1i.e slow=slow->next and fast = fast ->next in step-2
// the point where they collide again is starting point

// summary is - when they first collide they say there is loop and when we place one from them to head and other is at first collide point and both move simultaneously by step 1

// for intution see notes L-17
// how are we sure that they will collide again?
// how are we sure that the collision point will be starting point?
// see in notes- somehow similar to intution of tortoise and hare algo

// t.c-O(N)when first they collide they travel one traverse(i.e to detect loop) +O(N)(for finding the starting point of the loop Both pointers move one step at a time
// They meet at the start of the loop after k steps
// ✅ Time = O(k), and since k ≤ N, this is O(N))
// toatl time complexity-O(2*N)=O(N)
// sc.-O(1)
Node *findTheStartingPointOfLoop(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL)
  { // if there is linear LL of odd length or even length

    slow = slow->next;
    fast = fast->next->next;
    // first time collide then there is a loop
    if (slow == fast)
    {
      // then step-2
      slow = head; // any one of them place
      // fast already in their first collide place
      // move by step 1 until they collide again
      while (slow != fast)
      {
        slow = slow->next;
        fast = fast->next;
      }
      return slow; // or fast means they collide again
    }
  }
  return NULL; // if no loop
}

int main()
{
  vector<int> arr = {1, 2, 3, 15, 4, 13, 6, 7, 8, 9};
  Node *head = convertArrToLL(arr);
  int pos;
  cout << "Enter position where the cycle start: ";
  cin >> pos;
  makeCycle(head, pos);
  // Node *startingPoint = findStartingPointOfLoop(head);
  Node *startingPoint = findTheStartingPointOfLoop(head);
  cout << "Starting point of Loop if there is Loop: " << startingPoint->data << endl;
  return 0;
}