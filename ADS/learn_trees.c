#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

TreeNode *CreateATreeNode(int val){
    struct TreeNode *root;
    root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int main(){

}
