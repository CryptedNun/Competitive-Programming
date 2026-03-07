#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0; // Base case initialised
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i] = max(dp[i], p[j] + dp[i - j]);
    
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}