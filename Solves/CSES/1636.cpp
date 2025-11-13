#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(auto& coin : c) cin >> coin;

    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(auto& coin : c) {
        for(int i = coin; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    cout << dp[x] % MOD << endl;
}