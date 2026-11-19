#include<iostream>
#include<vector>
#include<queue>
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


Node* buildTree(vector<int> &arr, int& ind){
   ind++;
   if(arr.empty() || ind >= arr.size() || arr[ind]== -1) return nullptr;

   Node* node = new Node(arr[ind]);
   node->left = buildTree(arr,ind);
   node->right = buildTree(arr,ind);
   return node;
}

void inorder(Node* root){
    if(root==nullptr) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return ;
}

void levelOrder(Node* root){
    if(root== nullptr) return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != nullptr){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        } 
        else if(!q.empty()){
            q.push(nullptr);
        }
    }
}
void preOrder(Node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return ;
}

void postOrder(Node* root){
    if(root==nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    return ;
}
int main(){
    vector<int> arr = {1,2,3,-1,4,5,-1,2};
    int ind = -1;
    Node* root = buildTree(arr,ind);
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder: ";
    preOrder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postOrder(root);
    cout<<endl;

    levelOrder(root);
    cout<<endl;
    return 0;
}