#include <bits/stdc++.h>
#define BIGNUM 1e9
#define MAXN 500
#define endl '\n'
using namespace std;

int dp[MAXN + 1][MAXN + 1];

void precompute(int a, int b) {
    // define dp[i][j] = min # of cuts to get squares upto len i and j
    // base case: dp[1][i] = dp[i][1] = i - 1; for all i withing a, b bounds
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            dp[i][j] = BIGNUM;

    for(int i = 1; i <= a; i++) dp[i][1] = i - 1;
    for(int i = 1; i <= b; i++) dp[1][i] = i - 1;

    for(int i = 2; i <= a; i++) {
        for(int j = 2; j <= b; j++) {
            if(i == j) {dp[i][j] = 0; continue; }
            for(int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
            for(int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
        }
    }
}

void solve() {
    int a, b; cin >> a >> b;
    precompute(a, b);

    cout << dp[a][b] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}