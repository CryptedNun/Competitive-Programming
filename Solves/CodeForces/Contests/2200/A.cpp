#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;

    int maxi = *max_element(a.begin(), a.end());
    int ans = 0;
    for(auto& e : a) if(e == maxi) ans++;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}