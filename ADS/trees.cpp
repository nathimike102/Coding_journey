// #include<bits/stdc++.h>
// using namespace std;

// struct TreeNode{
//     int data;
//     struct TreeNode *left;
//     struct TreeNode *right;

//     TreeNode(int val){
//         root->data = val;
//         root->left = NULL;
//         root->right = NULL;
//     }
// };

// int main(){
//     TreeNode *root = new TreeNode(101);
//     TreeNode *left_root = new TreeNode(10);
//     root->left = left_root;
// }

//BFS
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

TreeNode *CreateATreeDFS(vector<string>& nodes, int idx){
    if(idx >= nodes.size() || nodes[idx] == "N"){
        return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(nodes[idx]));
    root->left = CreateATreeDFS(nodes, 2*idx+1);
    root->right = CreateATreeDFS(nodes, 2*idx+2);
    return root;
}

void In_order(TreeNode *root){
    if(root == nullptr){
        return;
    }
    In_order(root->left);
    cout<<root->data<<" ";
    In_order(root->right);
}

TreeNode* CreateATreeBFS(vector<string>& nodes, int &idx){
    //first step
    if(nodes[idx] == "N"){
        return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(nodes[idx]));
    queue<TreeNode*> Q; //Q.pop, Q.front(), Q.empty(), Q.size()
    Q.push(root);
    while(!Q.empty() && idx < nodes.size()){
        TreeNode *temp = Q.front();
        Q.pop();
        idx++;

        //first left take care
        if(idx < nodes.size() && nodes[idx]!="N"){
            TreeNode *nn = new TreeNode(stoi(nodes[idx]));
            temp->left = nn;
            Q.push(nn);
        }

        //insert right
        idx++;
        if(idx < nodes.size() && nodes[idx]!="N"){
            TreeNode *nn = new TreeNode(stoi(nodes[idx]));
            temp->right = nn;
            Q.push(nn);
        }
    }
    return root;
}
int main(){
    string s;
    getline(cin, s); //Reading a string with spaces
    vector<string> nodes; //vector --> dynamic array
    stringstream ss(s);
    
    string temp;
    while(ss >> temp){
        nodes.push_back(temp);
    }
    int idx=0;
    TreeNode *root = CreateATreeDFS(nodes, idx);
    In_order(root);
    printf("\n");
    TreeNode *root2 = CreateATreeBFS(nodes, idx);
    In_order(root2);
}
