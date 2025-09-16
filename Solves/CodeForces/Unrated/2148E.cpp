#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        // freq arr "total"
        vector<int> total(n + 1, 0);
        for (int x : a) total[x]++;

        bool ok = true;
        vector<int> cap(n + 1, 0);
        for (int v = 1; v <= n; v++) {
            if (total[v] % k != 0) {
                ok = false;
                break;
            }
            cap[v] = total[v] / k;
        }

        if (!ok) {
            cout<<0<<endl;
            continue;
        }

        long long ans = 0;
        vector<int> freq(n + 1, 0);

        int L = 0;
        for (int R = 0; R < n; R++) {
            freq[a[R]]++;

            // shrink window if invalid
            while (freq[a[R]] > cap[a[R]]) {
                freq[a[L]]--;
                L++;
            }

            // Now [L,R] is valid. Add all subarrays ending at R
            ans += (R - L + 1);
        }

        cout<<ans<<endl;
    }
}