#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Let dp[i][j] = # of length i prefixes that can be formed with last element j
    // Answer : we want sum of dp[n][m] from m=1 to m
    // Transition : dp[i][k] = dp[i - 1][k - 1] + dp[i - 1][k] + dp[i - 1][k + 1]

    
    // Base Case : dp[1][k] == 1, if a[0] = 0 or = k
    for(int i = 1; i <= m; i++) {
        if(a[0] == i || a[0] == 0) {
            dp[1][i] = 1;
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int k = 1; k <= m; k++) {
            // if there is not a[i-1] = 0 and not a[i-1] = k, then we cannot put k there for construction
            // Basically for constructing, a[i-1] has to be = 0 or k for putting k, this is checking if that's NOT the case
            if(a[i - 1] != 0 && a[i - 1] != k) {
                dp[i][k] = 0;
                continue;
            }

            for(int check = k - 1; check <= k + 1; check++) {
                if(!(check >= 1 && check <= m)) continue;
                // transition
                dp[i][k] = (dp[i][k] + dp[i - 1][check]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) ans = (ans + dp[n][i]) % MOD;
    cout << ans << endl;
}