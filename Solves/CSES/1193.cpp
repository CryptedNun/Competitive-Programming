#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char stepDir[] = {'U', 'D', 'L', 'R'};



// ? Perform BFS
vector<vector<int>> get_path_data(int n, int m, const vector<vector<char>>& grid, pair<int, int> start) {
    // ! -1 = UNVISITED
    vector<vector<int>> parentDir(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    q.push(start);
    parentDir[start.first][start.second] = 9; // * Whatever value for start

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] != '#' && parentDir[nr][nc] == -1) {
                
                parentDir[nr][nc] = i;
                q.push({nr, nc});
            }
        }
    }

    return parentDir;
}



// ? Backtracker
string reconstruct_path(const vector<vector<int>>& parentDir, pair<int, int> start, pair<int, int> end) {
    string path = "";
    pair<int, int> curr = end;

    while (curr != start) {
        int d = parentDir[curr.first][curr.second];
        path += stepDir[d];
        // REVERSE MOVE TO GO BACK TO PREVCELL
        curr.first -= dr[d];
        curr.second -= dc[d];
    }
    
    reverse(path.begin(), path.end());
    return path;
}

void solve() {
    // ! INIT
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }



    // ? Step 1: Run BFS to map out the paths
    // ? parentDir[i][j] = direction (as idx) to reach that node from its parent in BFS Tree.
    vector<vector<int>> parentDir = get_path_data(n, m, grid, start);



    // ? Step 2: Check if 'B' was reachable
    if (parentDir[end.first][end.second] == -1) {
        cout << "NO" << endl;
    } else {
        // ? Step 3: Reconstruct and print
        string path = reconstruct_path(parentDir, start, end);
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}