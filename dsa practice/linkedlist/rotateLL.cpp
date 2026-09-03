// Given the head of a linked list, rotate the list to the right by k places.

// for example if LL is {1->2->3->4->5} and k=2
// for k=1 LL rotate is {5->1->2->3->4}
// for k=2 LL rotate is {4->5->1->2->3->4} this is the answer return updated head

// 0 <= k can be anything, k can be greater than length of LL

// if k is multiple of length of LL then return original LL no need to rotate because after rotate it will give original LL
// so if(k%length==0)return head; // original LL
// for larger value of k- k=k%length means if we solve for smaller value of k then large value of k will aso solve easily
// large value means when it is greater than length of LL

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

// solution is simple-
// if (k%len==0)return head
// else k=k%len
// first find length of LL and tail of LL
// connect tail->next=head
// find new Tail node i.e (N-k) where N is length of LL
// so get newTail Node at (N-k)
// updated head is newTailNode->next and then newTailNode->next=NULL
// return head;

Node *findNewTailNode(Node *temp, int t)
{              // t is N-k
  int cnt = 1; // cnt temp;
  while (temp != NULL)
  {
    if (cnt == t)
      return temp;
    cnt++;
    temp = temp->next;
  }
  return temp;
}

// t.c-O(N)(for finding length and tail of LL)+O(N)(in worst case for finding newTailNode when k=1)=O(2N)
// s.c-O(1) where N is length of LL
Node *rotate(Node *head, int k)
{
  if (head == NULL || k == 0)
    return head;
  Node *tail = head;
  int N = 1; // cnt head
  while (tail->next != NULL)
  {
    N++;
    tail = tail->next;
  }
  if (k % N == 0)
    return head; // original LL
  k = k % N;
  // attach tail to head
  tail->next = head;
  Node *newTailNode = findNewTailNode(head, N - k);
  head = newTailNode->next; // updated head
  newTailNode->next = NULL;
  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  Node *head = convertArrToLL(arr);
  traverselInLL(head);
  cout << endl;
  int k;
  cout << "Enter the value of k i.e rotate LL from right by place: ";
  cin >> k;
  head = rotate(head, k);
  cout << "After rotate LL by k place: ";
  traverselInLL(head);
  cout << endl;
  return 0;
}