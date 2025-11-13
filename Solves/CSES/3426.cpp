#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;

    vector<long long> arr(n);
    arr[0] = x;
    for(int i = 1; i < n; i++) arr[i] = (arr[i - 1] * a + b) % c;

    vector<long long> prefix(n + 1);  // prefix[i] = the xor of first i many elements
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] ^ arr[i - 1];

    long long allXOR = 0;
    for(int i = k; i <= n; i++) {
        allXOR ^= (prefix[i] ^ prefix[i - k]);
    }

    cout << allXOR << endl;
}