// ? Finding length and Constructing the lCS of two arbitrary arrays.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];

    // dp[i][j] == length of LCS of first i elements of arr1 and first j of arr2
    // base case : dp[i][0] = dp[0][j] = dp[0][0] = 0
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Transition : If a_i = b_j then dp[i][j] = dp[i-1][j-1] + 1, else max of dp[i-1][j], dp[i][j-1]
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << endl;

    // ! Backtracking : 
    vector<int> LCS;
    int firstptr = n, secondptr = m;
    while(firstptr >= 1 && secondptr >= 1) {
        if(a[firstptr - 1] == b[secondptr - 1]) {
            LCS.push_back(a[firstptr - 1]);
            firstptr--, secondptr--;
        } else {
            if(dp[firstptr][secondptr - 1] >= dp[firstptr - 1][secondptr]) secondptr--;
            else firstptr--;
        }
    }

    reverse(LCS.begin(), LCS.end());
    for(auto& element : LCS) cout << element << " ";
}