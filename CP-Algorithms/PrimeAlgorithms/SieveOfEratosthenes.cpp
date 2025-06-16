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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long input; cin>>input;
    vector<bool> primes = sieve(input);

    for(long long i=2; i<primes.size(); i++) 
        if(primes[i]) cout<<i<<" ";
}