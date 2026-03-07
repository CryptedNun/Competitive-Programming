#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    ll max_b = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        if (b[i] > max_b) max_b = b[i];
    }

    // ! calc LCM of all elems in a
    ll lcm = 1;
    bool overflow = false;
    for (int i = 0; i < n; ++i) {
        ll g = gcd(lcm, a[i]);
        ll multiplier = a[i] / g;
        
        // overflow naki?
        if (multiplier > 0 && lcm > max_b / multiplier) {
            overflow = true;
            break; 
        }
        lcm *= multiplier;
    }

    if (overflow) cout << "Bob" << endl;
    else {
        bool alice = false;
        for (int i = 0; i < m; ++i) {
            if (b[i] % lcm == 0) {
                alice = true;
                break;
            }
        }
        cout << (alice ? "Alice" : "Bob") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}