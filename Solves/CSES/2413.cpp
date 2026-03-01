#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000000
#define endl '\n'
using namespace std;

long long dp[MAXN + 1][2];

void precompute() {
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2;  i <= MAXN; i++) {
        dp[i][0] = ((2LL * dp[i - 1][0] % MOD) + dp[i - 1][1]) % MOD;
        dp[i][1] = ((4LL * dp[i - 1][1] % MOD) + dp[i - 1][0]) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    // define dp[i][0/1] = number of towers upto length i (1<=i<=n) when 
    // block at i-th height is of width 2 (j = 0) or two blocks of width 1 (j = 1).
    // Block can be standalone OR attached to the block below as per problem statement.

    // base case, dp[1][0] = dp[1][1] = 1
    // state transition: dp[i][0] = 2*dp[i - 1][0] + dp[i - 1][1]
    // dp[i][1] = dp[i - 1][0] + 4 * dp[i - 1][1]

    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t; cin >> t;
    while(t--) solve();
}