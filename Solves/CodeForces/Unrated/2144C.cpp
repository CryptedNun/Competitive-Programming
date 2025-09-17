// ! DP Solution

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){    
        int n; cin >> n;
        vector<int> a(n+1), b(n+1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        // dp[i][s] = number of good subsets for prefix up to i
        // with s = 0 (no swap at i), s = 1 (swap at i)
        vector<array<int,2>> dp(n+1);
        dp[1][0] = 1;
        dp[1][1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int prev = 0; prev < 2; prev++) {
                for (int cur = 0; cur < 2; cur++) {
                    int Ai_prev = (prev == 0 ? a[i-1] : b[i-1]);
                    int Bi_prev = (prev == 0 ? b[i-1] : a[i-1]);
                    int Ai_cur  = (cur  == 0 ? a[i]   : b[i]);
                    int Bi_cur  = (cur  == 0 ? b[i]   : a[i]);

                    if (Ai_prev <= Ai_cur && Bi_prev <= Bi_cur) {
                        dp[i][cur] = (dp[i][cur] + dp[i-1][prev]) % MOD;
                    }
                }
            }
        }

        int ans = (dp[n][0] + dp[n][1]) % MOD;
        cout << ans << endl;
    }
}