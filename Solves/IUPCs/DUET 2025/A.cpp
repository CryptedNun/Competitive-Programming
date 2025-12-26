#include <bits/stdc++.h>
using namespace std;

vector<long long> fact(800 + 1, 1); // fact[t] = (t)! MOD M, since we need (2n)! where n<=400.
vector<long long> P(400 + 1, 1);
vector<long long> DP(400+1, 1);

// long long Permutation(long long n, long long r) {
//     if(r > n) return 0;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n;
        long long M; 
        cin >> n >> M;

        // Step-1: Prepare factorial lookup table
        for(int i = 1; i <= 800; i++) fact[i] = (fact[i - 1] * i) % M;

        // Step-2: Prepare formula for number of permutations P(n) for given n. O(n)
        // P(n) = (2n)! / 2^n MOD M;
        //      = [ (2n)*(2n-1)*(2n-2)! ] / 2*2^(n-1)
        // p(n) = n*(2n - 1) * P(n-1)
        for(int i = 1; i <= 400; i++) P[i] = (i * (2*i - 1) * P[i - 1]) % M;

        // Step-3: Prepare main DP table

    }
}