#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// void solve() {
//     int n; cin >> n;
//     vector<int> x(n);
//     for(auto& e : x) cin >> e;

//     vector<set<int>> dp(n);
//     // define dp[i] = collection of moneysum of all coins upto idx i (0-based), we maintain this using a set as the internal collection
//     dp[0].insert(x[0]);
//     for(int i = 1; i < n; i++) {
//         dp[i].insert(x[i]);
//         for(auto& e : dp[i - 1]) { 
//             dp[i].insert(e); 
//             dp[i].insert(e + x[i]);
//         }
//     }

//     cout << dp[n - 1].size() << endl;
//     for(auto& e : dp[n - 1]) cout << e << " ";
//     cout << endl;
// }

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    for(auto& e : x) cin >> e;

    // int n; cin >> n;
    // vector<int> x(n);
    // for(int i = 1; i <= n; i++) cin >> x[i - 1];

    vector<vector<int>> dp(n);
    dp[0].push_back(x[0]);
    for(int i = 1; i < n; i++) {
        dp[i].push_back(x[i]);
        for(auto& e : dp[i - 1]) {
            dp[i].push_back(e); 
            dp[i].push_back(e + x[i]);
        }

        // dp[i - 1].clear();
        sort(dp[i].begin(), dp[i].end());
        dp[i].erase(unique(dp[i].begin(), dp[i].end()), dp[i].end());
    }

    cout << dp[n - 1].size() << endl;
    for(auto& e : dp[n - 1]) cout << e << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}