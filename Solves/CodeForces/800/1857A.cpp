#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    ll sum = 0;
    while(n--) { int x; cin >> x; sum += x; }

    if(sum % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}