#include <bits/stdc++.h>
#define MOD ((int)1e9 + 7)
using namespace std;

// Function to multiply two HUGE numbers under modulo using binary method
long long multiplyMod(long long a, long long b) {
    long long result = 0;
    a %= MOD;
    while (b > 0) {
        if (b & 1) result = (result + a) % MOD;
        a = (2 * a) % MOD;
        b >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n; cin>>m>>n;
    cout<<multiplyMod(m, n);
}