#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


void specCase(int n, int k, const vector<int>& a) {
    int even_cnt = 0;
    for(auto& e : a) if(e%2 == 0) even_cnt++;
    even_cnt = max(0, 2 - even_cnt); // ! CAPPING

    int ans = INT_MAX;
    for(auto& e : a) {
        int quot = (e%k == 0) ? e/k - 1 : e/k;
        ans = min(ans, k * (quot + 1) - e);
    }

    cout << min(even_cnt, ans) << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto& e : a) cin >> e;

    if(k == 4) { specCase(n, k, a); }
    else {
        int ans = INT_MAX;
        for(auto& e : a) {
            int quot = (e%k == 0) ? e/k - 1 : e/k;
            ans = min(ans, k * (quot + 1) - e);
        }
        cout << ans << endl;
    }

    // if(k == 4) {
    //     int even_cnt = 0;
    //     for(auto& e : a) {
    //         if(e % 4 == 0) {
    //             cout << 0 << endl;
    //             return;
    //         }
    //         if(e % 2 == 0) even_cnt++;
    //     }
    //     cout << max(0, 2 - even_cnt) << endl;
    // }
    // else {
    //     int ans = INT_MAX;
    //     for(auto& e : a) {
    //         int quot = (e%k == 0) ? e/k - 1 : e/k;
    //         ans = min(ans, k * (quot + 1) - e);
    //     }
    //     cout << ans << endl;
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}