#include <iostream>
#include <vector>
using namespace std;

int main() {
    int node;
    cout << "enter the number of nodes->";
    cin >> node;
    
    int edges;
    cout << "enter the number of edges->";
    cin >> edges;
    
    vector<vector<int>> gp(node, vector<int>(node, 0));
    
    // Fix 1: Use '<' instead of '<='
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        gp[a][b] = 1;
        gp[b][a] = 1;
    }
    
    // Fix 2: Use '<' instead of '<='
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << gp[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
