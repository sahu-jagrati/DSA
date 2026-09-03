// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *random;
  Node(int x)
  {
    data = x;
    next = NULL;
    random = NULL;
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
// naive solution-when we have simple LL we copy it by taking dummyNode and create new list and copy given LL
// but in our problem we have random pointer as well so I cannot just create a new node and initialize the value. I can probably mark the next pointer but I cannot mark the random pointer yet because we don't have all nodes in initial
// so first we do the deep copy of nodes and probably remember that
// first we just make new node with value not the next pointer not the random pointer
// we remember the new node address by taking hashmap which store address of origianl node as well copy new node
// then in next step we will be make sure that the next and random pointers are pointing to the correct nodes

// we use unordered map so O(1)in average or O(N) in worst for insert or for finding
// in map O(logN)
// t.c-O(N*logN)(for making new node)+O(N*(logN+logN)(for getting next and random pointer)) if we use simple map or if use unordered map then instead of logN it is O(1) in average
// s.c-O(N)(for mpp)+O(N)(for creating clone list)this is required we cann't avoid this it is needed in the queution
Node *cloneLL(Node *head)
{
  Node *temp = head;
  unordered_map<Node *, Node *> mpp; // we use unordered to avoid extra t.c
  // first we make  new node only
  while (temp != NULL)
  {
    Node *newNode = new Node(temp->data);
    mpp[temp] = newNode; // insert in map and  store address of origianl node as well copy new node
    temp = temp->next;
  }
  // now next and random pointer
  temp = head; // of original LL
  while (temp != NULL)
  {
    Node *copyNode = mpp[temp];
    copyNode->next = mpp[temp->next];     // jo temp ka next hoga uska copy copyNode ka next hoga
    copyNode->random = mpp[temp->random]; // we want copy of random pointer so mpp[temp->random] store copy of it
    temp = temp->next;
  }
  return mpp[head]; // return head of copy list that is store at mpp[head]
}

// optimized solution-we don't store created node in hashmap
//  step1-we insert a created node in between original node
// step2-then connect random pointers
// step3-then connect next pointer
//  then we initailize a dummyNode to separate copy list from original list
void insertCopyInBetween(Node *head)
{
  Node *temp = head; // of original LL
  while (temp != NULL)
  {
    Node *nextElement = temp->next;
    // create new node which is copy of temp
    Node *copy = new Node(temp->data);
    // insert copy node betwwen original node
    copy->next = nextElement;
    temp->next = copy;
    // update temp to next original node
    temp = nextElement;
  }
}

void connectRandomPointers(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    Node *copyNode = temp->next; // that we insert initially
    if (temp->random != NULL)
    {
      copyNode->random = temp->random->next; // next because copy connects with copy
    }
    else
    {
      copyNode->random = nullptr;
    }
    temp = temp->next->next; // update temp and next to next because in next we have copy so for original next to next
  }
}
// connect next pointer and separate copy list and original list
Node *getDeepCopyList(Node *head)
{
  Node *temp = head;              // of original LL
  Node *dummyNode = new Node(-1); // initially next points nullptr and for random it is also point nullptr and it doesnot matter for dummyNode we want only next of dummynode to get head of copy list
  Node *curr = dummyNode;
  while (temp != NULL)
  {
    curr->next = temp->next;
    curr = curr->next;
    temp->next = temp->next->next;
    // update temp to next original node
    temp = temp->next;
  }
  return dummyNode->next; // head of copy list
}

// t.c-O(3*N) because each function run N times
// s.c-O(N) for creating copy list not solving problem it is a question demand
//  where N is length of LL
Node *cloneLinkedList(Node *head)
{
  // we make separate function to make code clean and better
  insertCopyInBetween(head);   // step-1
  connectRandomPointers(head); // step-2

  return getDeepCopyList(head); // step-3 connect next pointer and separate original and copy list and return head of deep copy list
}

//  we give index of random node for each node
//  -1 means random=NULL
// 0-based indexing
Node *buildRandomLL(vector<int> &arr, vector<int> &randomIndex)
{
  // create normal LL first
  Node *head = convertArrToLL(arr);

  // store node addresses by index
  vector<Node *> nodes;
  Node *temp = head;
  while (temp != NULL)
  {
    nodes.push_back(temp);
    temp = temp->next;
  }
  // assign random pointers
  for (int i = 0; i < nodes.size(); i++)
  {
    if (randomIndex[i] != -1)
    {
      nodes[i]->random = nodes[randomIndex[i]];
    }
  }
  return head;
}

int main()
{
  vector<int> arr = {7, 13, 11, 10, 1};
  vector<int> randomIndex = {-1, 0, 4, 2, 0}; // 0-based indexing
  Node *head = buildRandomLL(arr, randomIndex);

  // print clone list
  // Node *cloneHead = cloneLL(head);
  Node *cloneHead = cloneLinkedList(head);
  Node *temp = cloneHead;
  while (temp != NULL)
  {
    cout << "Data = " << temp->data << ", Random = ";
    if (temp->random)
      cout << temp->random->data;
    else
      cout << "NULL";
    cout << endl;
    temp = temp->next;
  }
  return 0;
}