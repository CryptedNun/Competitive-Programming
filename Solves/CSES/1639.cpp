#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
    string str1, str2; cin >> str1 >> str2;

    // define dp[i][j] = ED of str1 & str2 upto len i and j respectively
    // base case, dp[0][0] = 0, dp[0][i] = i, dp[j][0] = j for all i, j
    int dp[str1.size() + 1][str2.size() + 1];
    dp[0][0] = 0;
    for(int i = 1; i <= str1.size(); i++) dp[i][0] = i;
    for(int i = 1; i <= str2.size(); i++) dp[0][i] = i;

    for(int i = 1; i <= str1.size(); i++) {
        for(int j = 1; j <= str2.size(); j++) {
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }

    cout << dp[str1.size()][str2.size()] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}