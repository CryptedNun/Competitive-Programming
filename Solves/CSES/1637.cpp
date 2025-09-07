#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> dp(n+1, 0);
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        int minimum = 1e9;
        int currNumber = i;
        while(currNumber != 0) {
            int currDigit = currNumber%10;
            if(currDigit != 0) minimum = min(minimum, dp[i-currDigit]);
            currNumber /= 10;
        }

        dp[i] = 1+minimum;
    }

    cout<<dp[n]<<endl;
}