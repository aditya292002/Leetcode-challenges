#include<bits/stdc++.h>
using namespace std;


class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            val = data;
            left = NULL;
            right = NULL;
        }
};

// inorder iterative
vector<int> inorder(TreeNode* root) {

    vector<int> ans;
    if(root == NULL) return ans;

    stack<pair<TreeNode*,int>> st;
    st.push({root,0});

    while(!st.empty()) {
        int flag = 0;

        auto node = st.top().first;
        int leftDone = st.top().second;

        if(node->left == NULL and node->right == NULL) {st.pop(); ans.push_back(node->val);  continue;}

        if(leftDone) {
            ans.push_back(node->val); st.pop();
            if(node->right) {
                st.push({node->right,0});
            }
            continue;
        }


        else {
            st.pop();
            st.push({node,1});
            if(node->left) {
                st.push({node->left,0});
            }
        }
    }

    return ans;
}

vector<int> inorder_(TreeNode* root) {
    vector<int> ans; 
    if(root == NULL) return ans;
    stack<TreeNode*> st;

    TreeNode* node = root;

    while(1) {
        if(node) {
            st.push(node);
            node = node->left;
            continue;
        }

        if(st.empty()) break;
        node = st.top(); st.pop();
        ans.push_back(node->val);
        node = node->right;
    }

    return ans;
}


void preorderTraversalUtil(TreeNode* root, vector<int>& ans){
    if(root == NULL)return;
    
    preorderTraversalUtil(root->left, ans);
    ans.push_back(root->val);
    preorderTraversalUtil(root->right, ans);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans = {};
    preorderTraversalUtil(root, ans);
    return ans;
}


int main(){
    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    auto ans = inorder_(root);

    for(auto it : ans) {
        cout<<it<<" ";
    }cout<<endl;
}