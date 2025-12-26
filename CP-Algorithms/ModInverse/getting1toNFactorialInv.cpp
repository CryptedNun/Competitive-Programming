// Get the inverse of factorials of numbers from 1 to n.
// ! Important restriction: n < P must.
#include <bits/stdc++.h>
#define M 401
using namespace std;

vector<long long> fact(400 + 1, 1);
vector<long long> invFact(400 + 1);

long long modpow(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;

    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Fill fact[]: base case for 0 and 1 is 1.
    for(int i = 1; i <= 400; i++) fact[i] = (i * fact[i - 1]) % M; 

    // Fill invFact[]: base case starts at invFact[n] then we go down.
    // inv[400] = (400!)^ -1 = (400! mod M) ^ -1, since gcd(M, 400!) = 1 here.
    invFact[400] = modpow(fact[400], M - 2, M);
    for (int i = 400; i >= 1; i--) invFact[i-1] = (invFact[i] * i) % M;

    for(int i = 0; i <= 400; i++) cout << i << ": " << invFact[i] << endl;
}