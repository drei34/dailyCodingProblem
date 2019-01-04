/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
  int k;
  int val;
    
  void getKth(TreeNode * root) {
    if(root->left && k) {
      getKth(root->left);        
    }
        
    if(k == 0) {
      return;
    }
        
    val = root->val;
    k -= 1;
        
    if(k == 0) {
      return;
    }
        
    if(root->right && k) {
      getKth(root->right);    
    }
  }
    
  int kthSmallest(TreeNode* root, int k) {
    this->k = k;
        
    getKth(root);
        
    return val;
  }
};
