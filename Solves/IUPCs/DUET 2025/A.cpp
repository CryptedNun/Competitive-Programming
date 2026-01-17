#include <bits/stdc++.h>
using namespace std;

vector<long long> fact(800 + 1, 1);     // fact[t] = (t)!   MOD M, since we need (2n)! where n<=400.
vector<long long> invFact(800 + 1, 1);  // invFact[t] = (t!) ^ -1 mod M.
vector<long long> P(400 + 1, 1);        // P[i] = (2i)! / 2^i     mod M
vector<long long> DP(400+1, 0);         // Main lookup table

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    
    while (exp > 0) {
        if (exp % 2) {
            res = res * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n;
        long long M; 
        cin >> n >> M;

        fact[0] = 1;
        invFact[0] = 1;
        P[0] = 1;
        DP[0] = 0;

        // Step-1: Prepare all lookup tables; fact, invFact, P, main
        for(int i = 1; i <= 800; i++) fact[i] = (fact[i - 1] * i) % M;

        invFact[800] = power(fact[800], M - 2, M);
        for(int i = 799; i >= 1; i--) invFact[i] = ((i + 1) * invFact[i + 1]) % M;

        for(int i = 1; i <= 400; i++) {
            P[i] = (i * ((2 * i - 1) * P[i - 1] % M) ) % M;
        }

        for(int i = 1; i <= n; i++) {
            DP[i] = 0;          // RESET
            for(int k = 1; k <= i; k++) {
                // I have trust issues with big numbers so I do mod anywhere and everywhere
                long long first_term = ((fact[i] * invFact[i - k]) % M) * k % M;
                long long second_term = (fact[2*i - k - 1] * invFact[2*i - 2*k]) % M;
                first_term = first_term * second_term % M;

                long long third_term = (P[i - k] + DP[i - k]) % M;
                first_term = first_term * third_term % M;

                DP[i] = (DP[i] + first_term) % M;
            }
        }
        
        cout << DP[n] << '\n';
    }

    return 0;
}