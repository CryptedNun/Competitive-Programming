#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> price(n), discount(k);
        for(int i = 0; i < n; i++) cin >> price[i];
        for(int i = 0; i < k; i++) cin >> discount[i];

        // Implementing Greedy idea:
        // Obs-1 : The smaller the voucher value, the more powerful it is. So we sort vouchers ascending
        // Obs-2 : The higher the price, the faster we group it into smaller vouchers.

        sort(price.begin(), price.end(), greater<int>());
        sort(discount.begin(), discount.end());
        int l = 0;
        long long total = 0;
        for(auto& voucher : discount) {
            int r = l + voucher - 1;
            if(r >= n) break;
            for(int i = l; i < r; i++) {
                total += price[i];
            }
            l = r+1;
        }
        if(l < n) {
            for(int i = l; i < n; i++) total += price[i];
        }

        cout << total << endl;
   }
}