#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    long long x, a, b, c; cin >> x >> a >> b >> c;
    vector<long long> arr(n);
    vector<long long> prefix(n);
    vector<long long> suffix(n);

    arr[0] = x;
    for (int i = 1; i < n; i++) arr[i] = (a * arr[i - 1] + b) % c;

    prefix[0] = x;
    for (int i = 1; i < n; i++) {
        if (i % k == 0) prefix[i] = arr[i];
        else prefix[i] = prefix[i - 1] | arr[i];
    }

    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (i % k == k - 1) suffix[i] = arr[i];
        else suffix[i] = suffix[i + 1] | arr[i];
    }

    long long ans = 0;
    int l = 0, r = k - 1;
    while (r < n) {
        if (r % k == k - 1) ans ^= prefix[r];
        else ans ^= (prefix[r] | suffix[l]);
        r++, l++;
    }

    cout << ans << "\n";
}