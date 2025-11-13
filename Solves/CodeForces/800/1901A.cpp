#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<int> pumps(n);
        for(int i = 0; i < n; i++) cin >> pumps[i];

        // Last segment is two-ways, so 2*(x - .back()), so I appended an extra k + (k - .back()).
        pumps.push_back(2 * x - pumps.back());

        int maxi = pumps[0];
        for(int i = 1; i <= n; i++) {
            maxi = max(maxi, pumps[i] - pumps[i - 1]);
        }

        cout << maxi << endl;
    }
}