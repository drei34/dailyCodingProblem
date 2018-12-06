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
    
   bool isUnivariate(TreeNode * root) {
     int val = root->val;
        
     bool left = true;
     bool right = true;
        
     if(root->left) {
       if(root->left->val != val) {
	 return false;
       }
       left = isUnivariate(root->left);
     }
        
     if(root->right) {
       if(root->right->val != val) {
	 return false;
       }
       right = isUnivariate(root->right);
     }
        
     if(!root->left && !root->right) {
       return true;
     }
        
     return left && right;
   }
    
   int countUnivalSubtrees(TreeNode* root, bool is_univariate) {
        
     if(!root){
       return 0;
     }
        
     if(!is_univariate) {
       is_univariate = isUnivariate(root);
     }
        
     if(is_univariate) {
       return 1 + countUnivalSubtrees(root->left, is_univariate) + countUnivalSubtrees(root->right, is_univariate);
     }
        
     return countUnivalSubtrees(root->left, is_univariate) + countUnivalSubtrees(root->right, is_univariate);
   }
    
   int countUnivalSubtrees(TreeNode* root) {
     return countUnivalSubtrees(root, false);
   }
    
 };
