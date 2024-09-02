//Binary Search tree
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

struct TreeNode* CreateANode(int val){
    struct TreeNode *root = new TreeNode(val);
    return root;
}

struct TreeNode* insert(struct TreeNode *root, int key){
    if(root==NULL){
        return CreateANode(key);
    }
    if(root->data == key) return root;
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    if(key > root->data){
        root->right = insert(root->right, key);
    }
    return root;
}

struct TreeNode* BSTinsert(int l, int h, int nodes[]){
    if(l>h) return NULL;
    if(l==h) return CreateANode(nodes[l]);
    int mid = (l+h)/2;
    struct TreeNode *root2 = CreateANode(nodes[mid]);
    root2->left = BSTinsert(l, mid-1, nodes);
    root2->right = BSTinsert(mid+1, h, nodes);
    return root2;
}

struct TreeNode* successor(struct TreeNode *root){
    struct TreeNode* temp = root;
    temp = temp->right;
    while(temp && temp->left){
        temp = temp->left;
    }
    return temp;
}

strcut TreeNode* Delete(struct TreeNode *root, int key){
    if(root==NULL) return root;
    if(key < root->data){
        root->left = Delete(root->left, key);
    } else if(key > root->data){
        root->data = Delete(root->right, key);
    } else{
        //one child no child
        if(root->left == NULL){
            struct TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            struct TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        //two children
        struct TreeNode *curr = successor(root);
        root->data = curr->data;
        root->right = Delete(root->right, curr->data);

    }
    
}

void in_order(struct TreeNode *root){
    if(root==NULL) return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

int main(){
    int n;
    cin>>n;
    int nodes[n];
    for(int i=0;i<n;i++){
        cin>>nodes[i];
    }
    struct TreeNode *root = CreateANode(nodes[0]); // Call CreateANode if data is not in sorted order
    for(int i=1;i<n;i++){
        insert(root, nodes[i]); 
    }
    in_order(root);
    cout<<endl;
    struct TreeNode *root2 = BSTinsert(0, n-1, nodes); // Call BSTinsert if data is in sorted order
    in_order(root2);
    cout<<endl;
}

