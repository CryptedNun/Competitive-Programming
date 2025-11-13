/*
The number of non-decreasing arrays of size n with elements bounded between 1 and n is (2n - 1, n)
Why? == Assume that x_i = number of times i appeared in array
Then, x_1 + x_2 + ... x_i + .. x_n = n, where x_i >= 0
The number of solution sets to this equation is that previous nCr term.
Same for non-decreasing.

So we want both inc and dec, so twice of that nCr, also -n for accounting for the double count of {1,1,1...}, {3,3,...} type arrays.
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2*1e5 + 1;
long long fact[MAXN];

// For precomputing upto 2 * 1e5 - 1 factorial mod P
void precompute() {
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

// Computing power modulo
long long binexpmod(long long base, long long power, long long mod) {
    base %= mod;
    long long result = 1;
    while(power > 0) {
        if(power & 1) result = result*base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return result;
}

// Getting modulo inverse
long long modInv(long long input) {
    return binexpmod(input, MOD - 2, MOD);
}

// helper function
long long nCrMod(long long n) {
    long long upper = fact[2*n - 1];
    long long lower = (fact[n] * fact[n - 1]) % MOD;
    return (upper * modInv(lower)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    long long n; cin >> n;
    // ! Building the answer
    long long ans = (2 * nCrMod(n)) % MOD;
    ans = (ans - n) % MOD;

    cout << ans << endl;
}