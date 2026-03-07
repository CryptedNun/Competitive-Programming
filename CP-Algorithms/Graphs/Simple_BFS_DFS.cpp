#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>>& graph, int startNode) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        // ? Current node's code portion
        cout << current << " "; 

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                // ? Upcoming node's code portion
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void dfs(const vector<vector<int>>& graph, int startNode) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(startNode);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            // ? Curr_node's code portion
            cout << current << " ";

            for (auto it = graph[current].rbegin(); it != graph[current].rend(); ++it) {
                if (!visited[*it]) {    
                    // ? Upcoming node's code portion
                    s.push(*it);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
}