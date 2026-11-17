#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};


Node* buildTree(vector<int> arr, int& ind){
   ind++;
   if(arr.empty() || ind >= arr.size() || arr[ind]== -1) return nullptr;

   Node* node = new Node(arr[ind]);
   node->left = buildTree(arr,ind);
   node->right = buildTree(arr,ind);
   return node;
}

Node* inorder(Node* root){
    if(root==nullptr) return nullptr;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return root;
}

int main(){
    vector<int> arr = {1,2,3,-1,4,5,-1,2};
    int ind = -1;
    Node* root = buildTree(arr,ind);
    inorder(root);
    return 0;
}