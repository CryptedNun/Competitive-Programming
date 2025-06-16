#include <bits/stdc++.h>
using namespace std;

vector<long long> sieveRange(long long l, long long h) {

}

// Classic sieve up to sqrt(n)
vector<long long> simpleSieve(long long n) {
    vector<bool> is_prime(n + 1, true);
    vector<long long> primes;
    is_prime[0] = is_prime[1] = false;

    // Handle 2 separately
    if (n >= 2) primes.push_back(2);

    // Mark all even numbers > 2 as non-prime
    for (long long i = 4; i <= n; i += 2)
        is_prime[i] = false;

    // Process only odd numbers
    for (long long i = 3; i <= n; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);
            
            // Mark odd multiples of i as non-prime
            if (i * i <= n) {
                for (long long j = i * i; j <= n; j += 2 * i)
                    is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, h; cin>>l>>h;
}

// Get primes from 2 to floorroot(h)
// Cross multiples of those primes in the l -- h range (inclusive)