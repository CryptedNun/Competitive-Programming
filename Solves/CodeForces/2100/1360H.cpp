#include <bits/stdc++.h>
using namespace std;

long long binToDec(const string &bin) {
    long long result = 0;
    for (char c : bin) {
        result = (result << 1) | (c - '0');
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<long long> removed(n);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            removed[i] = binToDec(s);       // ! Convert the binString to Decimal long long.
        }
        sort(removed.begin(), removed.end());

        // ! Get the new array's median
        long long total = (1LL << m) - n; 
        long long k = (total - 1) / 2;

        // ! Core logic: 
        // ! At each step, check if x_removed is <= k, if so, the median shifts to the right by 1, 
        // ! then we check next x_removed if that is <= k (Which got shifted)
        // ! if otherwise (x_removed > k), then the next elements will also be greater, since vector<ll> removed is sorted.
        for (long long x : removed) {
            if (x <= k) k++;
            else break; 
        }

        // ! Convert acquired k to binString
        string ans;
        for (int i = m - 1; i >= 0; i--) {
            ans.push_back(((k >> i) & 1) + '0');
        }

        cout << ans << "\n";
    }
}