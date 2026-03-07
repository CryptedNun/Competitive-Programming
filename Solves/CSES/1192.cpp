#include <bits/stdc++.h>
using namespace std;

// ! DIR VECTORS for UP(i = 0), DOWN(1), LEFT(2), RIGHT(3).
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int start_r, int start_c, int n, int m, vector<string>& grid, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while (!q.empty()) {
        // 1. Get the queue's first elem and pop!
        // int r, c;
        // tie(r, c) = q.front();
        // q.pop();
        auto curr = q.front();
        q.pop();
        int r, c;
        
        int r = curr.first;
        int c = curr.second;

        // Check all 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 1. Check boundary limits
            // 2. Check if it's a floor tile ('.')
            // 3. Check if we haven't visited it yet
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                grid[nr][nc] == '.' && !visited[nr][nc]) {
                
                visited[nr][nc] = true; // Mark visited immediately upon pushing
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    // Speed up I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    

    // 2D visited array initialized to false
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Found a new tile that isn't part of an existing room
            if (grid[i][j] == '.' && !visited[i][j]) {
                rooms++;
                // Do BFS to mark the adjacent floors as visited
                bfs(i, j, n, m, grid, visited);
            }
        }
    }

    cout << rooms << endl;
    return 0;
}