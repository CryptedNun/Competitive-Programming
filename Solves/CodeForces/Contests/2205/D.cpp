#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> idx(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}