#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    bitset<100000 + 1> dp;
    dp[0] = 1;
    for(int i = 0 ; i < n; i++) {
        int v; cin >> v;
        dp |= dp << v;
    }

    // vector<int> results;
    int count = 0;
    for(int i = 1; i <= 100000; i++) if(dp[i]) count++;
    cout << count << endl;
    for(int i = 1; i <= 100000; i++) {
        if(dp[i]) {
            cout << i << " ";
        }
    }
}