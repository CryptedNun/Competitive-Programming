#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int prime = 1e9 + 7;
    int n; cin>>n;
    vector<vector<bool>> banned(n, vector<bool>(n, false));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            char ch; cin>>ch;
            if(ch == '*') {
                banned[i][j] = true;
            }
        }
    }

    if(!banned[0][0]) dp[0][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!banned[i][j]) {
                if(i-1 >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % prime;
                if(j-1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % prime;
            }
        }
    }

    cout<<dp[n-1][n-1]<<endl;
}