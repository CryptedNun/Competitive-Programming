#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;

    // DP[i] = # of i such that s_i = s_i+1, base: dp[0] = dp[1] = 0
    vector<int> dp(s.size() + 1, 0);
    for(int i = 2; i <= s.size(); i++) {
        if(s[i - 1] == s[i - 2]) dp[i] = dp[i - 1] + 1;
        else dp[i] = dp[i - 1];
    }

    // for(int i = 1; i <= s.size(); i++) cout << dp[i] << endl;
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << dp[r] - dp[l] << endl;
    }
}