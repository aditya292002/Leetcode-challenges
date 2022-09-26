class Solution {
public:
vector<vector<int>> ans;
void f(TreeNode* &root, int &sum, vector<int> &path, int &targetSum) {
    if(root == NULL) return;
    if(root->left == NULL and root->right == NULL) {
        if(sum + root->val == targetSum) {
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
        }
        return;
    }


    sum += root->val;
    path.push_back(root->val);
    f(root->left, sum , path, targetSum);
    f(root->right, sum, path, targetSum);
    sum -= root->val;
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    vector<int> path;
    f(root, sum, path, targetSum);
    return ans;
}
   