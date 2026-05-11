#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left=right=NULL;
    }
    
};

static int ind=-1;
Node* build_tree(vector<int> arr){
    ind++;
    if(ind >= arr.size() || arr[ind] == -1) return NULL;
    Node* node = new Node(arr[ind]);
    node->left = build_tree(arr);
    node->right = build_tree(arr);
    return node;
}

void preorderer_trav(Node* root)
{
    if(root == NULL) return ;
    cout<<root->data<<endl;
    preorderer_trav(root->left);
    preorderer_trav(root->right);
}


int main()
{
    vector<int> arr = {1,3,-1,-1,4,5,-1,-1,6};
    Node* root =  build_tree(arr);
    preorderer_trav(root);
   
    return 0;
}