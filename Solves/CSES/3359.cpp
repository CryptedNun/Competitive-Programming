#include <bits/stdc++.h>
#include <ext/rope>

#define endl '\n'

using namespace std;
using namespace __gnu_cxx;

struct ij { int i, j; };

void solve() {
    int n; cin >> n;
    vector<string> mat(n);
    for(auto& e : mat) cin >> e;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string ans;
    queue<ij> front;
    queue<ij> curr_front;

    front.push({0, 0});
    ans.reserve(2 * n - 1);

    while(ans.length() < 2 * n - 1) {
        // 1. Peek on `front` for the min char, to append.
        ij a = front.front();
        ans.push_back(mat[a.i][a.j]);

        // 2. Prepare next iteration's `front`, which is named `curr_front`
        //      Make sure the minmost char(s) from the `front`_nodes' branches are selected for curr_front
        char min_ch = 'Z' + 1;
        while(!front.empty()) {
            ij b = front.front();
            front.pop();

            if((b.i + 1 < n) && (mat[b.i + 1][b.j] <= min_ch) && !visited[b.i + 1][b.j]) {
                if(mat[b.i + 1][b.j] < min_ch) curr_front = {};

                curr_front.push({b.i + 1, b.j});
                min_ch = mat[b.i + 1][b.j];

                visited[b.i + 1][b.j] = true;
            }

            if((b.j + 1 < n) && (mat[b.i][b.j + 1] <= min_ch) && !visited[b.i][b.j + 1]) {
                if(mat[b.i][b.j + 1] < min_ch) curr_front = {};

                curr_front.push({b.i, b.j + 1});
                min_ch = mat[b.i][b.j + 1];

                visited[b.i][b.j + 1] = true;
            }
        }

        // 3. front = curr_front;
        front = move(curr_front);
        curr_front = {};
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}