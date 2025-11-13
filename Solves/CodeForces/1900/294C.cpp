// Precompute upto 1000! MOD 1e9 + 7
// Step - 1: Get the middle bulb counts, then the front and back count
 
#include <bits/stdc++.h>
using namespace std;
long long fact[1001];
 
const int MOD = 1e9 + 7;
 
void precompute() {
    fact[0] = 1;
    for(int i = 1; i < 1001; i++) fact[i] = (fact[i - 1] * i) % MOD;
}
 
long long binexpmod(long long base, long long power, long long mod) {
    base %= mod;
    long long result = 1;
    while(power > 0) {
        if(power&1) result = result*base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return result;
}
 
long long modinv(long long input) {
    return binexpmod(input, MOD - 2, MOD);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    precompute();
 
    long long n, m; cin >> n >> m;
    vector<long long> bulbs(m);
    for(int i = 0; i < m; i++) cin >> bulbs[i];
    sort(bulbs.begin(), bulbs.end());
 
    long long offBulbs = n - m;
    // Step - 1.1:
    vector<long long> middleBulbCount;
    for(int i = 1; i < m; i++){
        middleBulbCount.push_back(bulbs[i] - bulbs[i-1] - 1);
    }
 
    // Step - 1.2:
    long long frontBulbCount = bulbs[0] - 1;
    long long backBulbCount = n - bulbs[m - 1];
 
    // Evaluate the Numerator and Denominator
    long long numerator = 1, denominator = 1;
 
    // Numerator
    numerator *= fact[offBulbs];
    for(auto& element : middleBulbCount) {
        if(element != 0) {
            numerator = (numerator * binexpmod(2, element - 1, MOD)) % MOD;
        }
    }
 
    // Denominator
    denominator *= (modinv(fact[frontBulbCount]) * modinv(fact[backBulbCount])) % MOD;
    for(auto& element : middleBulbCount) {
        denominator = (denominator * modinv(fact[element])) % MOD;
    }
 
    long long answer = (numerator * denominator) % MOD;
 
    cout << answer << endl;
}