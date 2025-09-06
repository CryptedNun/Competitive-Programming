#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int prime = 1e9 + 7;
    int n; cin>>n;
    vector<int> dice = {1, 2, 3, 4, 5, 6};
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    // // This loop structure counts COMBINATIONS
    // for(int dot : dice) {
    //     for(int i=dot; i<=n; i++) {
    //         dp[i] = (dp[i] + dp[i-dot]) % prime;
    //     }
    // }

    // This loop counts PERMUTATIONS
    for(int i=1; i<=n; i++) {
        for(int dot : dice) {
            if(i-dot >= 0) dp[i] = (dp[i] + dp[i-dot]) % prime;
        }
    }

    cout<<dp[n]<<endl;
}