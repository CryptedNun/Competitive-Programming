#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(long long n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    return is_prime;
}

// ! Further optimized code, returns all primes instead of a bool array
// vector<long long> sieve(long long n) {
//     vector<bool> is_prime(n + 1, true);
//     is_prime[0] = is_prime[1] = false;

//     vector<long long> primes;
//     if (n >= 2) primes.push_back(2);

//     // * Mark all even numbers > 2 as non-prime
//     for (long long i = 4; i <= n; i += 2)
//         is_prime[i] = false;

//     for (long long i = 3; i <= n; i += 2) {
//         if (is_prime[i]) {
//             primes.push_back(i);
            
//             if (i * i <= n) {
//                 for (long long j = i * i; j <= n; j += 2 * i)
//                     is_prime[j] = false;
//             }
//         }
//     }

//     return primes;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long input; cin>>input;
    vector<bool> primes = sieve(input);

    for(long long i=2; i<primes.size(); i++) 
        if(primes[i]) cout<<i<<" ";
}