#include <bits/stdc++.h>
using namespace std;

enum color {
    WHITE, GRAY, BLACK
};

struct Node {
    int pi;             // parent in BFS Tree
    int d;              // Shortest dist from a specified root node
    enum color colour;  // BFS color state
};

void BFS(const vector<vector<int>>& adj, vector<Node>& node, int s) {
    // ! 1. WHITENING
    for(int i = 1; i < node.size(); i++) {
        if(i == s) continue;
        node[i].colour = WHITE;
        node[i].d = INT_MAX;
        node[i].pi = 0;
    }

    // ! 2. INIT AT S
    node[s].colour = GRAY;
    node[s].pi = 0;
    node[s].d = 0;

    queue<int> Queue;
    Queue.push(s);
    while(!Queue.empty()) {
        int u = Queue.front();
        Queue.pop();
        
        for(int v : adj[u]) {
            if(node[v].colour == WHITE) {
                node[v].colour = GRAY;
                node[v].pi = u;
                node[v].d = node[u].d + 1;
                Queue.push(v); 
            }
        }
        node[u].colour = BLACK;
    }
}

void DFS(const vector<vector<int>>& adj, vector<Node>& node, int s) {
    // ! 1. WHITENING
    for(int i = 1; i < node.size(); i++) {
        // if(i == s) continue;
        node[i].colour = WHITE;
        node[i].d = INT_MAX;
        node[i].pi = 0;
    }

    // ! 2. INIT AT S
    node[s].colour = GRAY;
    node[s].pi = 0;
    node[s].d = 0;

    stack<int> Stack;
    Stack.push(s);
    while(!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();
        for(int v : adj[u]) {
            if(node[v].colour == WHITE) {
                node[v].colour = GRAY;
                node[v].pi = u;
                node[v].d = node[u].d + 1;
                Stack.push(v);
            }
        }
        node[u].colour = BLACK;
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<Node> node(n + 1);
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(adj, node, 1);
    for(int i = 1; i <= n; i++) {
        printf("Node %d:\n", i);

        printf("Parent: %d.\n", node[i].pi);
        printf("Min. Distance: %d\n", node[i].d);

        printf("Colour (for checking BFS): ");
        switch (node[i].colour) {
            case WHITE: cout << "WHITE" << '\n'; break;
            case GRAY:  cout << "GRAY" << '\n'; break;
            case BLACK: cout << "BLACK" << '\n'; break;
        }
        cout << '\n';
    }
}