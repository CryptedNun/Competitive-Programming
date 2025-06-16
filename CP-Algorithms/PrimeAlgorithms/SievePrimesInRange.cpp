#include <bits/stdc++.h>
using namespace std;

//! Classic sieve up to floor-sqrt(n)
vector<long long> simpleSieve(long long n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector<long long> primes;
    // Handle 2 separately
    if (n >= 2) primes.push_back(2);

    // Mark all even numbers > 2 as non-prime
    for (long long i = 4; i <= n; i += 2)
        is_prime[i] = false;

    // Process only odd numbers
    for (long long i = 3; i*i <= n; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);

            for (long long j = i * i; j <= n; j += 2 * i)
                is_prime[j] = false;
            
        }
    }
    return primes;
}

//! Returns the primes within l--h range
vector<long long> sieveRange(long long l, long long h) {
    vector<long long> primes_h = simpleSieve(h);
    vector<bool> range(h-l+1, true);

    for (long long p : primes_h) {
        long long start = max(p * p, ((l + p - 1) / p) * p);  // (l + p - 1) / p) gives the ceil(l/p).
        for (long long j = start; j <= h; j += p) {
            range[j - l] = false;
        }
    }

    vector<long long> result;
    for (long long i = 0; i <= h - l; ++i) {
        if (range[i] && (l + i) > 1)
            result.push_back(l + i);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, h; cin>>l>>h;
    vector<long long> primes = sieveRange(l, h);
    for(long long& num: primes) cout<<num<<" ";
}