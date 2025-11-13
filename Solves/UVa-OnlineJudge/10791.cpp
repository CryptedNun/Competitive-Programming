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

    int i = 1;
    while(true) {
        int m; cin >> m;
        if(!m) return 0;
        else if(m == 1) {
            cout << "Case " << i++ << ": " << 2 << endl;
            continue;
        }

        int n = m;
        unordered_map<long long, long long> factors; // [prime, power]
        for(long long p = 2; p * p <= n; p++) {
            while (n % p == 0) {
                n /= p;
                factors[p]++;
            }
        }
        if(n > 1) factors[n]++;

        long long sum = 0;
        for(auto& [prime, power] : factors) {
            sum += binexp(prime, power);
        }
        if(sum == m) sum++;

        cout << "Case " << i++ << ": " << sum << endl;
    }
}