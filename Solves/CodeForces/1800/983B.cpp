#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int dp1[n][n], dp2[n][n];
    for(int i = 0; i < n; i++) dp1[0][i] = dp2[0][i] = a[i];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            dp1[i][j] = dp1[i - 1][j] ^ dp1[i - 1][j + 1];
            dp2[i][j] = max({dp1[i][j], dp2[i - 1][j], dp2[i - 1][j + 1]});
        }
    }

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        cout << dp2[r - l][l] << endl;
    }
}