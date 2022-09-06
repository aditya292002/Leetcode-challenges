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

bool pruneTreeUitl(TreeNode* &root) {
    if(root == NULL) return false;

    bool ansL = pruneTreeUitl(root->left);
    bool ansR = pruneTreeUitl(root->right);

    if(!ansL) root->left = NULL;
    if(!ansR) root->right = NULL;


    if(ansL || ansR || root->val) return true;
    return false;
}

TreeNode* pruneTree(TreeNode* root) {
    if(!pruneTreeUitl(root)){ 
        return NULL;
    }

    return root;
}

int main() {
    TreeNode* root = new TreeNode(0);
    
    // root->left = new TreeNode(2);
    root->right = new TreeNode(0);

    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(5);    
    
    // root->left->left->left = new TreeNode(6);
    // root->left->left->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(0);
    // root->right->right->left = new TreeNode(9);
}

