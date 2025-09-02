#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t; 
    while(t--) {
        int n; cin>>n;
        vector<int> vec(n+1);
        for(int i=1; i<=n; i++) cin>>vec[i];

        vector<int> dp(n+1, 0);
        unordered_map<int, vector<int>> position;

        for(int i=1; i<=n; i++) {
            dp[i] = dp[i-1];
            int current = vec[i];
            position[current].push_back(i);
            int count = position[current].size();
            if(count >= current) {
                int idx = position[current][count-current];
                dp[i] = max(dp[i-1], dp[idx-1] + current);
            }
        }

        cout<<dp[n]<<endl;
    }
}