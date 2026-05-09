#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;

Node(int val)
{
    data=val;
    left=right=NULL;
}
};


Node* build_tree(vector<int> arr){
    static int ind = -1;
   ++ind;
   if(arr[ind] == -1 || ind == arr.size()) return NULL;
   Node* node = new Node(arr[ind]);
   
   node->left = build_tree(arr);
   node->right = build_tree(arr);
   
   return node;
 }

 void inorder(Node* root)
 {
     if(root == NULL) return;
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
 }

int main()
{
    vector<int> arr = {1,3,-1,-1,4,5,-1,-1,6,-1,-1};
    Node* root = build_tree(arr);
    cout<<root->data<<endl;
    
    return 0;
}