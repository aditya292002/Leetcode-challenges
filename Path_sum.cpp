
class Solution {
public:
    bool hasPathSum(TreeNode* root, int &targetSum) {
        if(root == NULL) return false;
        if(root->left == NULL and root->right == NULL) {
            if(targetSum - root->val == 0) return true;
            return false;
        }
        
        targetSum -= root->val;
        bool l = hasPathSum(root->left, targetSum);
        bool r = hasPathSum(root->right, targetSum);
        targetSum += root->val;
    
        return l | r;
    }
};