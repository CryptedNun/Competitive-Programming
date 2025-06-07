#include <bits/stdc++.h>
using namespace std;
long long binexpmod(int base, int power, int mod);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, o; cin>>m>>n>>o;
    cout<<binexpmod(m, n, o);
}

long long binexpmod(int base, int power, int mod) {
    base %= mod;
    long long result = 1;
    while(power > 0) {
        if(power&1) result = result*base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return result;
}