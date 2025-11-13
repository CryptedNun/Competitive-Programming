
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        vector<int> idx(n + 1, -1);
        int numberOf0s = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            idx[a[i]] = i;
            if(a[i] == 0) numberOf0s++;
        }

        if(numberOf0s == 1) {
            for(int i = 1; i <= n; i++) {
                if(idx[i] == -1) {
                    a[idx[0]] = i;
                }
            }
        }

        int l = 1, r = n;
        while(l <= n && a[l] == l) l++;
        while(r >= 1 && a[r] == r) r--;

        cout << max(0, r - l + 1) << endl;
    }
}