// in simple LL each node has only next pointer while here we have LL where each node has next pointer as well as child pointer
// and each child pointer list is sorted and
// and each child pointer node -> next point to NULL

// given like
// 3->2->1->4->5->NULL this is horizontal LL nodes, and now we make child of each node
// |  |  |  |  |
// Nul 10 7  9  6
//    |  |  |  |
//   NUl 11 NUl 8
//       |      |
//       12     Null
//       |
//       NULL

// here see 3->next=2 and 3->child=NULL
// 2->next=1 and 2->child=10 whose next is NULL and 10->child is NULL
// 1->next=4 and 1->child=7 whose next is NULL and 7->child is 11 whose next is NULL and 11->child is 12 whode next is Null and 12->child=NULL
// and so on

// Our task is to flatten the this give LL in one child LL in sorted order
// child LL means return vertical LL having next=NULL for each node

// for above example after flattening answer is
// 1->child=2 and 2->child=3 and 3->child=4 and so on and last node is 12->child=NULL and each node's next =NULL this is our answer

// in given we have head of this LL i.e for above question head is node having value 3

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *child; // child pointer
  Node(int x)
  {
    data = x;
    next = NULL;
    child = NULL;
  }
};

// naive solution- put all data in array and sort it and convert it into vertical LL,not horizontal LL
Node *convertArrIntoVerticalLL(vector<int> &arr)
{
  if (arr.size() == 0)
    return NULL;
  Node *head = new Node(arr[0]);
  Node *temp = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *newNode = new Node(arr[i]); // this is child node whose next is NULL and initially child also NULL
    temp->child = newNode;
    temp = newNode; // or temp->child
  }
  return head; // head of vertical LL which is our answer
}
Node *flattenGivenLL(Node *head)
{
  vector<int> arr;
  Node *temp = head; // this points to horizontal nodes of LL
  while (temp != NULL)
  {
    Node *t2 = temp; // this goes to child node of each horizontal nodes LL
    while (t2 != NULL)
    {
      arr.push_back(t2->data);
      t2 = t2->child; // go to next child pointer of that horizontal nodes
    }
    temp = temp->next; // go to next horizontal node
  }
  sort(arr.begin(), arr.end());
  head = convertArrIntoVerticalLL(arr);
  return head;
}

// optimize solution-
// given each vertical LL is sorted so we use two pointer approach and we can reuse the same nodes,not creating a new list so this optimize s.c also for this we use concept of dummynode
// we use recursion here- first we solve two vertical list and merge them in one vertical list and merge it with another vertical list and so on

// this is function that merge two vertical lists,here we use dummynode to reuse same nodes

// t.c-O(N1+N2) where N1 is length of vertical list1 and N2 is length of vertical list2
Node *flatten2Lists(Node *list1, Node *list2) // list1 and list2 are heads of individually vertical list and now we travel them vertically
{
  Node *dummyNode = new Node(-1); // its next and child pointer initially point NULL
  Node *curr = dummyNode;

  // when both lists are not empty
  while (list1 != NULL && list2 != NULL)
  {
    if (list1->data < list2->data)
    {
      curr->child = list1; // we want vertical list as answer
      curr = list1;
      list1 = list1->child; // we travel vertically
    }
    else
    {
      curr->child = list2;
      curr = list2;
      list2 = list2->child;
    }
    curr->next = nullptr; // in answer all nodes next is NULL
  }
  // when only list1 nodes remain, connect it as it is
  if (list1 != NULL)
  {
    curr->child = list1;
  }
  // when only list2 nodes remain, connect it as it is
  else
  {
    curr->child = list2;
  }
  if (dummyNode->child != NULL)
  { // means there is a vertical list
    dummyNode->child->next = nullptr;
  }
  return dummyNode->child; // return head of vertical merge list
}

// assume there is N no.of nodes in horizontal and M is length of each vertical List
// N(recursive call for each nodes in horizontal)*merge 2 lists(which take O(N1+N2)=O(M+M)=O(2M))=O(2*N*M)
// total t.c-O(2*N*M)
// s.c-O(N)recursive stack space

Node *flattenGivenLinkedList(Node *head)
{ // head of given linked list with next and child pointer
  // base case of recursion from where backtracking start
  if (head == NULL || head->next == NULL)
    return head; // i.e return head of this vertical list if it is one and only

  Node *mergeHead = flattenGivenLinkedList(head->next); // recursive call for next horizontal nodes

  head = flatten2Lists(head, mergeHead); // merge two vertical lists

  return head;
}

// create given linked list
Node *takeInput()
{
  int n;
  cout << "Enter the size of horizontal nodes: ";
  cin >> n; // number of horizontal nodes
  Node *head = NULL;
  Node *prev = NULL;

  for (int i = 0; i < n; i++)
  {
    int m;
    cout << "Enter the size of vertical list for each horizontal node " << i + 1 << ": ";
    cin >> m; // size of vertical list
    vector<int> arr(m);
    cout << "Enter the elmt of vertical list(sorted) " << i + 1 << ": ";
    for (int j = 0; j < m; j++)
    {
      cin >> arr[j];
    }
    Node *verticalHead = convertArrIntoVerticalLL(arr);
    if (head == NULL)
    {
      head = verticalHead;
      prev = head;
    }
    else
    {
      prev->next = verticalHead;
      prev = prev->next;
    }
  }
  return head;
}

int main()
{
  Node *head = takeInput();
  // Node *flatHead = flattenGivenLL(head);
  Node *flatHead = flattenGivenLinkedList(head);
  // print flattened vertical list
  Node *temp = flatHead;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->child;
  }
  return 0;
}