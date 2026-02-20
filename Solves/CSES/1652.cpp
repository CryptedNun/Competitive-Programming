#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    int mat[n + 1][n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char ch; cin >> ch;
            mat[i][j] = (ch == '*');
        }
    }

    // def dp[i][j] = total trees in grid i*j (one-based i,j)
    int dp[n+1][n+1];
    for(int i = 0; i <= n; i++) dp[i][0] = dp[0][i] = 0;

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (mat[i][j] == 1);

    while(q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1] << '\n';
    }
}