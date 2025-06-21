//? DP + 2D Prefix Sum approach
//! T_p = A_p + B_p - C_p + gcd(x,y) - 1
#include <bits/stdc++.h>
using namespace std;

long long dp[1001][1001] = {0};
long long ans[1001][1001] = {0};

void fillDP(int m, int n) {
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + __gcd(i, j) - 1;
        }
    }
}

void fillAns (int m, int n) {
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1] + dp[i][j];
        }
    }
}

long long nC3(long long n) {
    if (n<3) return 0;
    return (n*(n-1)*(n-2))/6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //! Precompute DP and Ans lookup table, time complexity O(mnlog(min(m,n))) ~~ 200ms, fastest time possible!
    fillDP(1000, 1000);
    fillAns(1000, 1000);

    //! Parse inputs until (0, 0)
    long long m, n;
    for(int i=1; ;i++) {
        cin>>m>>n;
        if(m==0 || n==0) break;

        cout <<"Case "<<i<<  ": "<< nC3((m+1)*(n+1)) - (m+1)*nC3(n+1) - (n+1)*nC3(m+1) - 2 * ans[m][n] << "\n";
    }
}