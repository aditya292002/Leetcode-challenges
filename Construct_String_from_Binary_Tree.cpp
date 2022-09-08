#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-string-from-binary-tree/submissions/


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


string s = "";
void tree2strUtil(TreeNode* root) {
    if(root == NULL) return;

    if(root->left == NULL and root->right == NULL) {s += to_string(root->val); return;}

    s += to_string(root->val);

    if(root->left || root->right) {
        s += "(";
        tree2strUtil(root->left);
        s += ")";
    }

    if(root->right) {
        s += "(";
        tree2strUtil(root->right);
        s += ")";
    }
}

string tree2str(TreeNode* root) {
    tree2strUtil(root);
    return s;
}


int main(){
    TreeNode* root = new TreeNode(1);
        
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);


    tree2str(root);
    cout<<s<<endl;
}