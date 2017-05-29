#include <iostream>

using namespace std;

struct TreeNode {
  int key;
  TreeNode* right;
  TreeNode* left;
};



TreeNode* lowestCommonAncestor(TreeNode* root, int key1, int key2) {
  if(root == NULL)
    return NULL;
  if(root->key == key1 || root->key == key2)
  	return root;
  TreeNode* lca_rightSubTree = lowestCommonAncestor(root->right, key1, key2);
  TreeNode* lca_leftSubTree = lowestCommonAncestor(root->left, key1, key2);
  if(lca_leftSubTree and lca_rightSubTree)  
    return root;
  else {
  	if(lca_rightSubTree)
  	  return lca_rightSubTree;
  	else
  	  return lca_leftSubTree;
  }
}
