/*
DFS:
    In-order, Pre-order, Post-order
    In-order : [left, root, right]
    Pre-order : [root, left, right]
    Post-order : [left, right, root]    

    ###
    void Post(Node* root, vector<int> &resPostOrder){
        if(!root) return;
        Post(root->left, resPostOrder);
        Post(root->right, resPostOrder);
        resPostOrder.push_back(root->data);
    }
    vector<int> postOrder(Node* root){
        vector<int> resPostOrder;
        Post(root, resPostOrder);
        return resPostOrder;
    }

    ###
    int height(struct Node* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    ###
    struct info{
        int height;
    }

    info Find_height(Node *root){
        if(!root) return {0};
        if(root->left == NULL && root->right == NULL) return {1};
        info leftPart = Find_height(root->left);
        info rightPart = Find_height(root->right);
        info curr = max(leftPart.height, rightPart.height) + 1;
        return curr;
    }

    int height(struct Node* root){
        return Find_height(node).height;
    }

    ###
    int height(struct Node* root){
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        ans = max (ans, l+r+1);
        return max(l,r)+1;
    }
    int diameter(struct Node* root){
        height(root);
        return ans;
    }

    ###
    struct Info{
        int h;
        int d;
    };
    
    Info Find_Diameter(Node *root){
        if(!root) return {0,0};
        Info leftPart = Find_Diameter(root->left);
        Info rightPart = Find_Diameter(root->right);
        
        Info curr;
        curr.h = max(leftPart.h, rightPart.h) + 1;
        curr.d = max(leftPart.d, rightPart.d);
        curr.d = max(curr.d, leftPart.h + rightPart.h + 1);
        return curr;
    }

    int diameter(struct Node* root){
        return Find_Diameter(root).d;
    }

    
BFS:
    Level order
*/
