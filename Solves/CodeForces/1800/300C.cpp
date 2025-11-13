#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
const int MOD = 1e9 + 7;
long long fact[MAX + 1];

bool checker(long long input, int a, int b) {
    while(input > 0) {
        if(!(input % 10 == a || input % 10 == b)) return false;
        input /= 10;
    }
    return true;
}

void precompute() {
    fact[0] = 1;
    for(int i = 1; i <= MAX; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

long long binexpmod(long long base, long long power, long long mod) {
    base %= mod;
    long long result = 1;
    while(power > 0) {
        if(power&1) result = result*base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return result;
}

long long modinv(long long input) {
    return binexpmod(input, MOD - 2, MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int a, b; cin >> a >> b;
    long long n; cin >> n;

    long long answer = 0;
    for(long long i = 0; i <= n; i++) {
        long long sum = a * i + b * (n - i);
        if(checker(sum, a, b)) {
            long long numerator = fact[n]; // n! mod MOD
            long long denominator = (modinv(fact[i]) * modinv(fact[n - i])) % MOD; // (i!)^-1 * ((n-i)!)^-1 mod MOD
            long long term = (numerator * denominator) % MOD;
            answer = (answer + term) % MOD;
        }
    }

    cout << answer << endl;
}