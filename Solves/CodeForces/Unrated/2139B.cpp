#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end(), greater<long long>());

        long long ans = 0;
        int k = min(n, m);
        for (int i = 0; i < k; i++) {
            ans += a[i] * (m - i);
        }

        cout << ans << "\n";
    }
}