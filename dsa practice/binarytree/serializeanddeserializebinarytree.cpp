// serialize-encodes a tree into a single string. in this if the node can have their null we assign it "#"

// deserialize- decodes your encoded data to tree

// you can use many ways of logic like inorder,preorder,postorder,level order

// we use here level order traversal and try to do other by own

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left, *right;
  TreeNode(int value)
  {
    data = value;
    left = right = NULL;
  }
};

// time complexity-O(N)(for level order traversal)
// s.c -O(N)(for queue)

// // encodes a tree into a single string
// string serialize(TreeNode *root)
// {
//   if (!root)
//     return "#";
//   string s = "";
//   queue<TreeNode *> q;
//   q.push(root);
//   while (!q.empty())
//   {
//     TreeNode *current = q.front();
//     q.pop();
//     if (current == NULL)
//       s.append("#,");
//     else
//     {
//       s.append(to_string(current->data) + ",");
//     }
//     if (current != NULL) // this is only different from level order because in level order we don't check Null
//     {
//       q.push(current->left);
//       q.push(current->right);
//     }
//   }
//   return s;
// }

// // decodes your encoded data to tree
// TreeNode *deserialize(string data)
// {
//   if (data.size() == 0)
//     return NULL;
//   stringstream s(data); // is a library learn in notes or in google
//   string str;
//   getline(s, str, ',');                     // here , is separator and by getline we go to next integer after ,
//   TreeNode *root = new TreeNode(stoi(str)); // stoi is a function used to convert a string representation of an integer into an actual integer value and stoi - string to integer
//   queue<TreeNode *> q;
//   q.push(root);
//   while (!q.empty())
//   {
//     TreeNode *node = q.front();
//     q.pop();
//     getline(s, str, ','); // by this go to next
//     if (str == "#")
//     {
//       node->left = NULL;
//     }
//     else
//     {
//       TreeNode *leftNode = new TreeNode(stoi(str));
//       node->left = leftNode;
//       q.push(leftNode);
//     }
//     getline(s, str, ','); // again move to next
//     if (str == "#")
//     {
//       node->right = NULL;
//     }
//     else
//     {
//       TreeNode *rightNode = new TreeNode(stoi(str));
//       node->right = rightNode;
//       q.push(rightNode);
//     }
//   }
//   return root;
// }

// this code satisfy all the case, the above code does not fullfill the all case
// Encodes a tree to a single string.

// getline(s, str, ',') is a C++ function call that reads characters from a stream s into the string str until it encounters a comma ,.

// ✔ Full Meaning

// getline(stream, string_variable, delimiter)

// stream → where input comes from (cin, file stream, stringstream, etc.)

// string_variable → where the extracted text is stored

// delimiter → stop reading when this character appears
string serialize(TreeNode *root)
{
  if (root == NULL)
    return "#";
  string s = "";
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *curr = q.front();
    q.pop();
    if (curr == NULL)
      s.append("#,");
    else
    {
      s.append(to_string(curr->data) + ",");

      // this is only different from level order because in level order we don't check Null
      q.push(curr->left);
      q.push(curr->right);
    }
  }
  return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
  if (data == "[]" || data == "" || data == "#")
    return NULL;

  stringstream s(data); // is a library learn in notes or in google
  string str;

  getline(s, str, ',');
  if (str == "#" || str == "")
    return NULL;

  TreeNode *root = new TreeNode(stoi(str)); // stoi is a function used to convert a string representation of an integer into an actual integer value and stoi - string to integer
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();

    if (!getline(s, str, ','))
      break;
    if (str == "#" || str == "" || str == "\r")
    {
      node->left = NULL;
    }
    else
    {
      TreeNode *leftNode = new TreeNode(stoi(str));
      node->left = leftNode;
      q.push(leftNode);
    }

    if (!getline(s, str, ','))
      break;
    if (str == "#" || str == "" || str == "\r")
    {
      node->right = NULL;
    }
    else
    {
      TreeNode *rightNode = new TreeNode(stoi(str));
      node->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}
void printpreorder(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  printpreorder(root->left);
  printpreorder(root->right);
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(13);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  string result = serialize(root);
  cout << result << endl;

  TreeNode *node = deserialize(result);
  printpreorder(node);

  return 0;
}