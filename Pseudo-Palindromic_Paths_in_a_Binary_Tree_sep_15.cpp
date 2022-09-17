/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


int cnt = 0;
void helper(TreeNode* root, vector<int> &numCnt) {
    if(root->left == NULL and root->right == NULL) {
        numCnt[root->val]++;
        int odd = 0;
        for(int i = 1 ; i <= 9; i++) {
            if(numCnt[i] % 2 != 0) {
                if(odd == 1) {
                    numCnt[root->val]--;
                    return;
                }
                else odd = 1;
            }
        }
        numCnt[root->val]--;
        cnt++; return;
    }
    numCnt[root->val] += 1;
    if(root->left)
        helper(root->left, numCnt);
    if(root->right)
        helper(root->right, numCnt);
    numCnt[root->val] -= 1;
}

int pseudoPalindromicPaths (TreeNode* root) {
    vector<int> numCnt(10,0);
    helper(root, numCnt);
    return cnt;
}
};