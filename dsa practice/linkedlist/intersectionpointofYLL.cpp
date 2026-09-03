// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
// there are no cycles anywhere in the entire linked structure.
// Note that the linked lists must retain their original structure after the function returns.

// intersection!=same values
// intersection=same node(same memory address)
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

// naive solution- we try to memoize one LL by hashing and see which is common in another LL by traversing another LL and match

// we do not store value of node because it can be same for more than one node
// so we store Node itself with some integer

// when we traverse second LL and match we match the Node not by value

// The time complexity for insertion into a map is typically O(log N), while for an unordered map (hash map), it is O(1) on average and Worst Case: O(N)
// N" is the number of elements currently in the map/unordered map.
// t.c-O(N1*logN1)(for traverse LL1 and insert in map)+O(N2*logN2)(for traversing and finding in LL2)
// s.c-O(N1) if we store LL1 in map
// or s.c-O(N2) if we store LL2 in map
Node *intersection(Node *head1, Node *head2)
{
  map<Node *, int> mpp; // integer only record, we do nothing with it
  // traverse LL1
  Node *temp = head1;
  while (temp != NULL)
  {
    mpp[temp] = 1;
    temp = temp->next;
  }
  // now match with LL2
  temp = head2;
  while (temp != NULL)
  {
    // means we find intersection point that is first common Node
    // we match Node not data
    if (mpp.find(temp) != mpp.end())
    {
      return temp;
    }
    // else move forward
    temp = temp->next;
  }
  return NULL; // if no intersection point
}

// optimized solution-Ist
// can we move together both LLs?
// No,because length of both are different.
// but if we stand at same length then we can move together and compare
// so if we try for longer length LL come to same level of shorted length LL

// step-1 calculate length of both LLs
// step-2 if length equal then compare or if length are not equal then find difference of length and make longer length LL to same level

// we pass first smaller length LL then longer length LL and difference
Node *collisionPoint(Node *t1, Node *t2, int diff)
{
  // here we take longer LL to same level of shorter LL
  while (diff)
  {
    diff--;
    t2 = t2->next;
  }
  // when we at same level, we start comparing node and get intersection
  while (t1 != t2)
  {
    t1 = t1->next;
    t2 = t2->next;
  }
  return t1; // or either t2 both are at same point
}

// t.c-O(N1)(length of LL1)+O(N2)(length of LL2)+O(N2-N1)(when LL1 is smaller than LL2 else it is N1-N2)+O(N1)(shorter length when we start compare from same level)
// so total t.c-O(N1+2*N2) when N2>N1 or O(2*N1+N2) when N1>N2
// s.c-O(1)
Node *intersectionPoint(Node *head1, Node *head2)
{
  // step-1 calculate length
  Node *temp1 = head1;
  int N1 = 0;
  while (temp1 != NULL)
  {
    N1++;
    temp1 = temp1->next;
  }
  Node *temp2 = head2;
  int N2 = 0;
  while (temp2 != NULL)
  {
    N2++;
    temp2 = temp2->next;
  }
  if (N1 < N2)
  {
    // we pass first smaller length LL then longer length LL and difference
    return collisionPoint(head1, head2, N2 - N1);
  }
  // or in case N1>N2 or N1=N2
  else
  {
    return collisionPoint(head2, head1, N1 - N2);
  }
}

// optimized solution-IInd most effective
// we move together both LLs without shorting longer length LL, start tem1 for head1 and temp2 for head2
// if length(LL1)!=length(LL2) so see how temp1 and temp2 meet on same level
// whenever any temp go to NULL move them to opposite head and go with traversal until they meet on same level
// if length(LL1)==length(LL2) we start compare and they meet automatically, not reach end, not got to opposite head if there is intersection point

// if there is no intersection point then tab bhi ham yahi karege and we figure out when both temp get to NULL together so stop means no collision point

// why temp1 and temp2 meet at same level when they move simultaneously
// see starting difference and start move temp1 and temp2 simultaneously
// when temp1 reach to null then see temp2 is difference step behind the temp1 that is also in initial
// so now take temp1 to head2 and start traverse
// when temp2 reaches Null, temp1 cover that difference steps and tmep2 go to head1 and both are at same level
// so that's why move simultaneously and meet at same level

// t.c-O(N1+N2) both temp1 and temp2 travel each node of both LLs
//.sc-O(1)
Node *intersectionPointOfYLL(Node *head1, Node *head2)
{
  // when either LL1 is empty or LL2 is empty, there is no intersection point
  if (head1 == NULL || head2 == NULL)
    return NULL;

  // we start to traverse when both linked lists are different that is if both is same means head1==head2 then the head is first intersection point no need to move forward so
  Node *temp1 = head1;
  Node *temp2 = head2;
  // both LLs are different
  while (temp1 != temp2)
  {
    temp1 = temp1->next;
    temp2 = temp2->next;
    // if get same
    if (temp1 == temp2)
    {
      return temp1; // or temp2, also when no intersection point it return NULL
    }
    if (temp1 == NULL)
      temp1 = head2; // move to opposite head
    if (temp2 == NULL)
      temp2 = head1;
  }
  return temp1; // or temp2 when LLs are same
}

int main()
{
  vector<int> arr1 = {3, 1, 4, 6, 2};
  vector<int> arr2 = {1, 2, 4, 5};
  Node *head1 = convertArrToLL(arr1);
  Node *head2 = convertArrToLL(arr2);
  traverselInLL(head1);
  cout << endl;
  traverselInLL(head2);
  cout << endl;
  // position where LL2 should intersect LL1
  // for above linked lists pos=3
  int pos;
  cout << "Position where LL2 should intersect LL1: ";
  cin >> pos;
  if (pos != -1)
  {
    Node *temp1 = head1;
    while (temp1 != NULL)
    {
      pos--;
      if (pos == 0)
        break;
      temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
      temp2 = temp2->next;
    }
    temp2->next = temp1;
  }
  // Node *firstCommonPoint = intersection(head1, head2);
  // Node *firstCommonPoint = intersectionPoint(head1, head2);
  Node *firstCommonPoint = intersectionPointOfYLL(head1, head2);
  if (firstCommonPoint != NULL)
  {
    cout << "First common point: ";
    cout << firstCommonPoint->data << endl;
  }
  else
  {
    cout << "No intersection" << endl;
  }
  return 0;
}