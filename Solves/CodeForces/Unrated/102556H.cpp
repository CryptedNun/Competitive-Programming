// Step - 1: Decompose M into prime factors including each power.
// Step - 2: (1) Compute the gcd of all prime's powers. (2) Then compute that gcd's divisors.
// Step - 3: (1) Check each divisors {They are K candidates}, (2) once found reconstruct N, otherwise -1
// !  We are dealing with M <= 1e15, use long long EVERYWHERE.


#include <bits/stdc++.h>
using namespace std;

long long binexp(long long base, long long power) {
    long long result = 1;
    while(power > 0) {
        if(power&1) result = result * base;
        base = base*base;
        power >>=1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long M; cin >> M;
    if(M == 1) { // The algo breaks for 1, edge case I guess.
        cout << 1 << endl;
        return 0;
    }

    // Step - 1:
    map<long long, long long> factors;
    for (long long p = 2; p * p <= M; p++) {
        while (M % p == 0) {
            factors[p]++;
            M /= p;
        }
    }
    if (M > 1) factors[M]++; // leftover prime

    // Step - 2.1:
    long long _gcd_ = 0;
    for(auto& [prime, exp] : factors) {
        _gcd_ = __gcd(_gcd_, exp);
    }
    _gcd_ *= 2;

    // Step - 2.2:
    vector<long long> divisors;
    for(long long i = 1; i * i <= _gcd_; i++) {
        if(_gcd_ % i == 0) {
            divisors.push_back(i);
            if(i != _gcd_ / i) divisors.push_back(_gcd_ / i); // avoid double-counting square root
        }
    }

    // sort(divisors.begin(), divisors.end());

    // Step - 3.1:
    long long targetDivisor = -1;
    for(auto& divisor : divisors) {
        long long mult = 1;
        for(auto& [prime, exp] : factors) {
            mult *= (2 * exp) / divisor + 1;
        }
        if(mult == divisor) {
            targetDivisor = divisor; 
            break;
        }
    }

    // Step - 3.2:
    if(targetDivisor == -1) cout << targetDivisor << endl;
    else {
        long long answer = 1;
        for(auto& [prime, exp] : factors) {
            long long newExp = (2 * exp) / targetDivisor;
            answer *= binexp(prime, newExp);
        }
        cout << answer << endl;
    }
}