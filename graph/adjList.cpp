#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int> arr[5];
    
    for(int i=0; i<6; i++){
        int a , b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    cout<<endl;
    
    // print the graph
    for(int i=0; i<5; i++){
        cout<<i<<"->";
        for(auto val:arr[i]){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}
