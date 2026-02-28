#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;

    bool hasInversion = false;
    for(int i = 1; i < n; i++) 
        if(a[i - 1] > a[i]) { 
            hasInversion = true; 
            break; 
        }

    if(hasInversion) cout << 1 << endl;
    else cout << n << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}