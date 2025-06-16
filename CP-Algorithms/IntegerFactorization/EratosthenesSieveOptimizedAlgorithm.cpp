// ! The goal of the sieve() function is to PRE-COMPUTE all the prime numbers upto some number, namely the highest possible input value
// ! DO NOT use that function to compute primes AT RUN TIME, that is NOT efficient, rather use sieving till root, Pollard's Rho, QS etc etc
// ! Once precomputed, use that prime vector for further factorization. 
// ! The Time Complexity is namely O(nlogn) [HEAVILY SIMPLIFIED]

#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;
// ! Further optimized Sieve code, fills global "primes" with all primes upon call.
void sieve(long long n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    //* Removed local declaration to global scope
    if (n >= 2) primes.push_back(2);

    //* Mark all even numbers > 2 as non-prime
    for (long long i = 4; i <= n; i += 2)
        is_prime[i] = false;

    for (long long i = 3; i <= n; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);

            //* Mark odd multiples of i as non-prime
            if (i * i <= n) {
                for (long long j = i * i; j <= n; j += 2 * i)
                    is_prime[j] = false;
            }
        }
    }
}

vector<long long> factorization(long long input) {
    vector<long long> factors;
    for(long long i=0; primes[i] * primes[i] <= input; i++) {
        while(input % primes[i] == 0) {
            factors.push_back(primes[i]);
            input /= primes[i];
        }
    }
    if(input > 1) factors.push_back(input);
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //! WARNING: sieve() FUNCTION IS NOT SUITABLE FOR USAGE AT RUNTIME, IT'S FOR DEMONSTRATING PRECOMPUTED VALUES
    //* Fill the primes array upto 1e8
    sieve(1e8);

    //* Take input and then store the factors of d and print
    long long d; cin>>d;
    vector<long long> factors = factorization(d);
    for(long long& factor: factors) cout<<factor<<" ";
}