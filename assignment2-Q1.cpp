#include <iostream>

using namespace std;


struct TreeNode {
  int data;
  TreeNode* right;
  TreeNode* left;
};

bool printAncestors(TreeNode* root, int key) {
  if(root == NULL)
    return false;
  if(root->data == key)
    return true;
  if(printAncestors(root->right, key) || printAncestors(root->left, key)) {
    cout << root->data << endl;
    return true;
  }
  return false; 
}
