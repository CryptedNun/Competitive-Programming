#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin>>c[i];

    vector<long long> minDP(x+1, LLONG_MAX);
    minDP[0] = 0;

    for(int i=1; i<=x; i++) {
        for(int coin : c) {
            if(i-coin>=0 && minDP[i-coin] != LLONG_MAX) minDP[i] = min(minDP[i], minDP[i-coin] + 1);
        }
    }
    if(minDP[x] == LLONG_MAX) cout<<-1<<endl;
    else cout<<minDP[x]<<endl;
}