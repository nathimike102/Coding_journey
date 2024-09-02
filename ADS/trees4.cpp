//AVL tree implementation
#include<bits/stdc++.h>
using namespace std;

// Balance factor {-1, 0, 1}
// Balance factor = height(left subtree) - height(right subtree)
struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int height(TreeNode* root){
    if(!root) return 0;
    return root->height;
}

int getBalance(TreeNode* root){
    if(!root) return 0;
    return height(root->left) - height(root->right);
}

//Rotations
TreeNode* leftRotate(TreeNode *root){
    TreeNode *temp1 = root->right;
    TreeNode *temp2 = temp1->left;

    //Perform rotation
    temp1->left = root;
    root->right = temp2;

    root->height = 1 + max(height(root->left), height(root->right));
    temp1->height = 1 + max(height(temp1->left), height(temp1->right));
    return temp1;
}

TreeNode* rightRotate(TreeNode* root){
    TreeNode* temp1 = root->left;
    TreeNode* temp2 = temp1->right;

    //Perform rotation
    temp1->right = root;
    root->left = temp2;

    root->height = 1 + max(height(root->left), height(root->right));
    temp1->height = 1 + max(height(temp1->left), height(temp1->right));
    return temp1;
}

void inorder(TreeNode* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(TreeNode* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

TreeNode *insert(TreeNode* root, int val){
    if(!root) return new TreeNode(val);
    if(val < root->data) root->left = insert(root->left, val);
    else if(val > root->data) root->right = insert(root->right, val);
    //else return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance_factor = getBalance(root);

    // left left case
    if(balance_factor > 1 && val < root->left->data){
        return rightRotate(root);
    }

    // right right case
    if(balance_factor < -1 && val > root->right->data){
        return leftRotate(root);
    }

    // left right case
    if(balance_factor > 1 && val > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right left case
    if(balance_factor < -1 && val < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

TreeNode* min_value(TreeNode* root){
    TreeNode *temp = root->right;
    while(temp && temp->left){
        temp = temp->left;
    }
    return temp;
}

TreeNode* delete_node(TreeNode* root, int key){
    if(!root) return nullptr;
    if(key < root->data){
        root->left = delete_node(root->left, key);
    }
    else if(key > root->data){
        root->right = delete_node(root->right, key);
    }
    else{
        //no child or one child
        if(!root->left || !root->right){
            TreeNode* temp = (root->left) ? root->left : root->right;
            delete root;
            return temp;
        }

        //two child
        TreeNode* curr = min_value(root);
        root->data = curr->data;
        root->right = delete_node(root->right, curr->data);
    }

    //update height
    root->height = 1 + max(height(root->left), height(root->right));
    int balance_factor = getBalance(root);

    //left left
    if(balance_factor > 1 && getBalance(root->left)>=0){
        rightRotate(root);
    }

    //left right
    if(balance_factor > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //right right
    if(balance_factor < -1 && getBalance(root->right)<= 0){
        return leftRotate(root);
    }

    //right left
    if(balance_factor < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main(){
    TreeNode* root = NULL;
    int n;
    cin>>n;
    int node[n];
    for(int i=0;i<n;i++){
        cin>>node[i];
    }
    for(int i=0;i<n;i++){
        root = insert(root, node[i]);
    }
    root = delete_node(root, 20);
    root = delete_node(root, 40);
    inorder(root);
    cout<<endl;
    preorder(root);
}