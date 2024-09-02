#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;

}TreeNode;
TreeNode *CreataNode(int key){
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = key;
    node->left = node->right = NULL;
    node->height = 1;
    return (node);
}
int Height(TreeNode *root){
    if(root==NULL)return 0;
    return root->height;
}
int getBalance(TreeNode *root){
    if(root==NULL)return 0;
    return (Height(root->left) - Height(root->right));
}
int max(int a, int b){
    return (a > b) ? a : b;
}
TreeNode *LeftR(TreeNode *x){
    TreeNode *y = x->right;
    TreeNode *T1 = y->left;

    //rotations
    y->left = x;
    x->right = T1;
    
    x->height = 1 + max(Height(x->left),Height(x->right));
    y->height = 1 + max(Height(y->left),Height(y->right));

    return y;
}
TreeNode *RightR(TreeNode *x){
    TreeNode *y = x->left;
    TreeNode *T1 = y->right;

    //rotations
    y->right = x;
    x->left = T1;

    x->height = 1 + max(Height(x->left),Height(x->right));
    y->height = 1 + max(Height(y->left),Height(y->right));

    return y;
}
TreeNode *Insert(TreeNode *root, int key){
    if(root == NULL){
        return (CreataNode(key));

    }
    if(key < root->data){
        root->left = Insert(root->left,key);
    }
    else if(key > root->data){
        root->right = Insert(root->right,key);
    }
    else{
        return root;
    }

    //first important height
    root->height = 1 + max(Height(root->left),Height(root->right));

    //second find the balence factor
    int balencefactor = getBalance(root);

    //4 cases
    //left left
    if(balencefactor > 1 && key < root->left->data){
        return RightR(root);
    }
    //left right
    if(balencefactor > 1 && key > root->left->data){
        root->left = LeftR(root->left);
        return RightR(root);
    }
    //right right
    if(balencefactor < -1 && key > root->right->data){
        return LeftR(root);
    }
    //right left
    if(balencefactor < -1 && key < root->right->data){
        root->right = RightR(root->right);
        return LeftR(root);
    }
    return root;

}
TreeNode *minValue(TreeNode *root){
    TreeNode *temp = root->right;
    while(temp && temp->left){
        temp = temp->left;
    }
    return temp;
}
TreeNode *Delete(TreeNode *root, int key){
    if(root == NULL)return NULL;

    if(key < root->data){
        root->left  = Delete(root->left,key);
    }
    else if(key > root->data){
        root->right = Delete(root->right, key);
    }
    else{
        //no child or one child
        if(root->left == NULL){
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL){
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        //two child
        TreeNode *curr = minValue(root);
        root->data = curr->data;
        root->right = Delete(root->right,curr->data);
    }

    //update the height

    root->height = 1 + max(Height(root->left),Height(root->right));

    int balencefactor = getBalance(root);

    //left left
    if(balencefactor > 1 && getBalance(root->left) >= 0){
        return RightR(root);
    }
    
    //left right
    if(balencefactor > 1 && getBalance(root->left) < 0){
        root->left = LeftR(root->left);
        return RightR(root);
    }

    //right right

    if(balencefactor < -1 && getBalance(root->right) <= 0){
        return LeftR(root);
    }

    //right left

    if(balencefactor < -1 && getBalance(root->right) > 0){
        root->right = RightR(root->right);
        return LeftR(root);
    }
    return root;
}
void inorder(TreeNode* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(TreeNode* root){
    if(!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){

    int n;
    scanf("%d",&n);
    int nodes[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&nodes[i]);
    }
     TreeNode *root = NULL;
    for(int i = 0 ; i < n ; i++){
        root = Insert(root,nodes[i]);
    }
    
    inorder(root);
    printf("\n");
    preorder(root);
    root = Delete(root,20);
    root = Delete(root,40);
    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);
}